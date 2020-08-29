const PREC = {
  STRING: 2,
};

const pattern_decnum = /[0-9]+(_?[0-9]+)*/;
const pattern_hexnum = /[0-9A-Fa-f]+(_?[0-9A-Fa-f]+)*/;
const pattern_identifier = /[0-9A-Za-z!#$%&'*+-./:<=>?@\\^_'|~]+/;
const pattern_num_type = /[fi](32|64)|v128/;
const pattern_sign = /[+-]/;

module.exports = grammar({
  name: "wat",

  extras: $ => [$.annotation, $.comment_block, $.comment_line, /[\s\uFEFF\u2060\u200B\u00A0]/],

  conflicts: $ => [
    [$.instr_type_int, $.instr_type_int_32],
    [$.instr_type_int, $.instr_type_int_64],
    [$.instr_type_float, $.instr_type_float_32],
    [$.instr_type_float, $.instr_type_float_64],
    [$._instr_type, $.instr_plain_binary, $.instr_plain_compare, $.instr_plain_convert, $.instr_plain_unary],
    [
      $._instr_type,
      $.instr_plain_atomic_load,
      $.instr_plain_atomic_rmw,
      $.instr_plain_atomic_store,
      $.instr_plain_binary,
      $.instr_plain_compare,
      $.instr_plain_convert,
      $.instr_plain_load,
      $.instr_plain_store,
      $.instr_plain_unary,
    ],
    [$.instr_plain, $.instr_plain_const],
    [$.instr_plain_func_bind],
    [$.instr_plain_let],
    [$.instr_plain_select],
    [$.instr_plain_simd_load, $.instr_plain_simd_unary],
    [$.instr_plain_simd_binary, $.instr_plain_simd_store],
  ],

  rules: {
    PARSE: $ => choice($.module, alias(repeat(field("module_field", $.module_field)), $.inline_module)),

    FLOAT: $ => seq(optional($.sign), $.FLOAT_MAG),

    FLOAT_MAG: $ => choice($.float, $.hexfloat, "inf", $.NAN),

    INTEGER: $ => choice($.SIGNED, $.UNSIGNED),

    NAN: $ =>
      seq(
        "nan",
        optional(
          seq(
            token.immediate(":"),
            choice(
              token.immediate("arithmetic"),
              token.immediate("canonical"),
              seq(token.immediate("0x"), token.immediate(pattern_hexnum)),
            ),
          ),
        ),
      ),

    UNSIGNED: $ => choice($.decnum, seq("0x", token.immediate(pattern_hexnum))),

    SIGNED: $ => seq($.sign, $.UNSIGNED),

    align_value: $ => seq("align=", token.immediate(/[0-9]+(?:_?[0-9]+)*|0x[0-9A-Fa-f]+(?:_?[0-9A-Fa-f]+)*/)),

    // proposal: annotations
    annotation: $ =>
      seq(
        "(@",
        field("identifier", alias(token.immediate(pattern_identifier), $.identifier)),
        repeat(field("annot_part", $._annotation_part)),
        ")",
      ),

    // proposal: annotations
    annotation_parens: $ => seq("(", repeat(field("annot_part", $._annotation_part)), ")"),

    // proposal: annotations
    _annotation_part: $ =>
      choice($.comment_block_annot, $.comment_line_annot, $.annotation_parens, $.reserved, $.identifier, $.string),

    // proposal: threads
    atomicop: $ => choice("add", "and", "cmpxchg", "or", "sub", "xchg", "xor"),

    block_block: $ =>
      seq(
        "block",
        optional(field("identifier", $.identifier)),
        field(
          "block",
          alias(
            seq(
              optional(field("type_use", $.type_use)),
              repeat(field("params", $.func_type_params_many)),
              repeat(field("results", $.func_type_results)),
              optional($._instr_list),
            ),
            $.block,
          ),
        ),
        "end",
        optional(field("identifier1", $.identifier)),
      ),

    block_if: $ =>
      seq(
        "if",
        optional(field("identifier", $.identifier)),
        field(
          "block",
          alias(
            seq(
              optional(field("type_use", $.type_use)),
              repeat(field("params", $.func_type_params_many)),
              repeat(field("results", $.func_type_results)),
              optional($._instr_list),
            ),
            $.block,
          ),
        ),
        optional(
          seq("else", optional(field("identifier1", $.identifier)), optional(field("instr_list", $._instr_list))),
        ),
        "end",
        optional(field("identifier2", $.identifier)),
      ),

    block_loop: $ =>
      seq(
        "loop",
        optional(field("identifier", $.identifier)),
        field(
          "block",
          alias(
            seq(
              optional(field("type_use", $.type_use)),
              repeat(field("params", $.func_type_params_many)),
              repeat(field("results", $.func_type_results)),
              optional($._instr_list),
            ),
            $.block,
          ),
        ),
        "end",
        optional(field("identifier", $.identifier)),
      ),

    comment_block: $ => seq("(;", repeat(choice($.comment_block, /[^(;]+/, "(", ";")), ";)"),

    comment_line: $ => prec.left(token(seq(";;", /.*/))),

    comment_block_annot: $ => seq("(;", repeat(choice($.comment_block_annot, /[^(;]+/, "(", ";")), ";)"),

    comment_line_annot: $ => prec.left(token(seq(";;", /.*/))),

    decnum: $ => token(pattern_decnum),

    // proposal: reference-types
    _elem_expr: $ => choice($.elem_expr_item, $.elem_expr_expr),

    // proposal: reference-types
    elem_expr_expr: $ => $._expr,

    // proposal: reference-types
    elem_expr_item: $ =>
      seq("(", "item", field("const_expr", alias(repeat(field("instr", $.instr)), $.const_expr)), ")"),

    // proposal: reference-types
    elem_kind: $ => token(/func/),

    // proposal: reference-types
    elem_list: $ =>
      choice(
        seq(field("elem_kind", $.elem_kind), field("elem_var_list", repeat(field("index", $.index)))),
        seq(field("ref_type", $._ref_type), field("elem_expr_list", repeat(field("elem_exr", $._elem_expr)))),
      ),

    escape_sequence: $ => token.immediate(seq("\\", choice(/[^u0-9a-fA-F]/, /[0-9a-fA-F]{2}/, /u{[0-9a-fA-F]+}/))),

    _export_desc: $ => choice($.export_desc_func, $.export_desc_table, $.export_desc_memory, $.export_desc_global),

    export_desc_func: $ => seq("(", "func", field("index", $.index), ")"),

    export_desc_global: $ => seq("(", "global", field("index", $.index), ")"),

    export_desc_memory: $ => seq("(", "memory", field("index", $.index), ")"),

    export_desc_table: $ => seq("(", "table", field("index", $.index), ")"),

    _expr: $ => seq("(", $._expr1, ")"),

    _expr1: $ => choice($._expr1_plain, $.expr1_call, $.expr1_block, $.expr1_loop, $.expr1_if),

    expr1_block: $ =>
      seq(
        "block",
        optional(field("identifier", $.identifier)),
        field(
          "block",
          alias(
            seq(
              optional(field("type_use", $.type_use)),
              repeat(field("params", $.func_type_params_many)),
              repeat(field("results", $.func_type_results)),
              optional($._instr_list),
            ),
            $.block,
          ),
        ),
      ),

    expr1_call: $ =>
      seq(
        "call_indirect",
        // proposal: reference-types
        optional(field("index", $.index)),
        optional(field("type_use", $.type_use)),
        repeat(field("params", $.func_type_params_many)),
        repeat(field("results", $.func_type_results)),
        repeat(field("expr", $._expr)),
      ),

    expr1_if: $ => seq("if", optional(field("identifier", $.identifier)), field("if_block", $._if_block)),

    expr1_loop: $ =>
      seq(
        "loop",
        optional(field("identifier", $.identifier)),
        field(
          "block",
          alias(
            seq(
              optional(field("type_use", $.type_use)),
              repeat(field("params", $.func_type_params_many)),
              repeat(field("results", $.func_type_results)),
              optional($._instr_list),
            ),
            $.block,
          ),
        ),
      ),

    _expr1_plain: $ => seq(field("instr", $.instr_plain), repeat(field("expr", $._expr))),

    float: $ =>
      token(
        seq(
          pattern_decnum,
          optional(seq(".", optional(pattern_decnum))),
          optional(seq(/[Ee]/, optional(pattern_sign), pattern_decnum)),
        ),
      ),

    _func_locals: $ => choice($.func_locals_one, $.func_locals_many),

    func_locals_many: $ => seq("(", "local", repeat(field("value_type", $.value_type)), ")"),

    func_locals_one: $ => seq("(", "local", field("identifier", $.identifier), field("value_type", $.value_type), ")"),

    _func_type: $ => choice($._func_type_params, $.func_type_results),

    _func_type_params: $ => choice($.func_type_params_one, $.func_type_params_many),

    func_type_params_many: $ => seq("(", "param", repeat(field("value_type", $.value_type)), ")"),

    func_type_params_one: $ =>
      seq("(", "param", field("identifier", $.identifier), field("value_type", $.value_type), ")"),

    func_type_results: $ => seq("(", "result", repeat(field("value_type", $.value_type)), ")"),

    global_type: $ => choice($.global_type_imm, $.global_type_mut),

    global_type_imm: $ => field("value_type", $.value_type),

    global_type_mut: $ => seq("(", "mut", field("value_type", $.value_type), ")"),

    hexfloat: $ =>
      token(
        seq(
          "0x",
          pattern_hexnum,
          optional(seq(".", optional(pattern_hexnum))),
          optional(seq(/[Pp]/, optional(pattern_sign), pattern_decnum)),
        ),
      ),

    identifier: $ => token(seq(token.immediate("$"), pattern_identifier)),

    _if_block: $ =>
      seq(
        optional(field("type_use", $.type_use)),
        repeat(field("params", $.func_type_params_many)),
        repeat(field("results", $.func_type_results)),
        repeat(field("if_expr", $._expr)),
        seq("(", "then", optional(field("then_instr_list", $._instr_list)), ")"),
        optional(seq("(", "else", optional(field("else_instr_list", $._instr_list)), ")")),
      ),

    _import_desc: $ =>
      choice(
        $.import_desc_type_use,
        $.import_desc_func_type,
        $.import_desc_table_type,
        $.import_desc_memory_type,
        $.import_desc_global_type,
      ),

    import_desc_func_type: $ =>
      seq("(", "func", optional(field("identifier", $.identifier)), repeat(field("func_type", $._func_type)), ")"),

    import_desc_global_type: $ =>
      seq("(", "global", optional(field("identifier", $.identifier)), field("global_type", $.global_type), ")"),

    import_desc_memory_type: $ =>
      seq("(", "memory", optional(field("identifier", $.identifier)), field("memory_type", $.memory_type), ")"),

    import_desc_table_type: $ =>
      seq("(", "table", optional(field("identifier", $.identifier)), field("table_type", $.table_type), ")"),

    import_desc_type_use: $ =>
      seq("(", "func", optional(field("identifier", $.identifier)), field("type_use", $.type_use), ")"),

    index: $ => choice($.UNSIGNED, $.identifier),

    inline_export: $ => seq("(", "export", field("name", $.name), ")"),

    inline_import: $ => seq("(", "import", field("module_name", $.name), field("item_name", $.name), ")"),

    instr: $ => choice($.instr_plain, $.instr_call, $.instr_block, $._expr),

    instr_block: $ => choice($.block_block, $.block_loop, $.block_if),

    instr_call: $ =>
      seq(
        field("op", alias("call_indirect", $.op)),
        optional(field("type_use", $.type_use)),
        repeat(field("params", $.func_type_params_many)),
        repeat(field("results", $.func_type_results)),
        field("instr", $.instr),
      ),

    // NOTE: this must be wrapped in "optional"
    _instr_list: $ => repeat1(choice($.instr_list_call, $.instr)),

    instr_list_call: $ =>
      prec.right(
        seq(
          "call_indirect",
          optional(field("type_use", $.type_use)),
          repeat(field("params", $.func_type_params_many)),
          repeat(field("results", $.func_type_results)),
        ),
      ),

    instr_plain: $ =>
      choice(
        $.instr_plain_unreachable,
        $.instr_plain_nop,
        $.instr_plain_drop,
        $.instr_plain_select,
        $.instr_plain_br,
        $.instr_plain_br_if,
        $.instr_plain_br_table,
        $.instr_plain_return,
        $.instr_plain_local_get,
        $.instr_plain_local_set,
        $.instr_plain_local_tee,
        $.instr_plain_global_get,
        $.instr_plain_global_set,

        // proposal <start>: reference-types
        $.instr_plain_table_get,
        $.instr_plain_table_set,
        $.instr_plain_table_size,
        $.instr_plain_table_grow,
        $.instr_plain_table_fill,
        $.instr_plain_table_size,
        $.instr_plain_table_grow,
        $.instr_plain_table_fill,
        $.instr_plain_ref_is_null,
        $.instr_plain_ref_func,
        // proposal <stop>: reference-types

        // proposal <start>: function-references
        $.instr_plain_br_on_null,
        $.instr_plain_call_ref,
        $.instr_plain_func_bind,
        $.instr_plain_let,
        $.instr_plain_ref_as_non_null,
        $.instr_plain_return_call_ref,
        // proposal <stop>: function-references

        $.instr_plain_memory_size,
        $.instr_plain_memory_grow,
        $.instr_plain_const,
        $.instr_plain_test,
        $.instr_plain_compare,
        $.instr_plain_unary,
        $.instr_plain_binary,
        $.instr_plain_convert,
        $.instr_plain_load,
        $.instr_plain_store,
        $.instr_plain_call,

        // proposal <start>: threads
        $.instr_plain_atomic_wait,
        $.instr_plain_atomic_notify,
        $.instr_plain_atomic_load,
        $.instr_plain_atomic_store,
        $.instr_plain_atomic_rmw,
        // proposal <stop>: threads

        // proposal <start>: bulk-memory-operations
        $.instr_plain_data_drop,
        $.instr_plain_elem_drop,
        $.instr_plain_memory_copy,
        $.instr_plain_memory_fill,
        $.instr_plain_memory_init,
        $.instr_plain_table_copy,
        $.instr_plain_table_init,
        // proposal <stop>: bulk-memory-operations

        // proposal <start>: simd
        $.instr_plain_simd_compare,
        $.instr_plain_simd_const,
        $.instr_plain_simd_convert,
        $.instr_plain_simd_binary,
        $.instr_plain_simd_trinary,
        $.instr_plain_simd_lane,
        $.instr_plain_simd_load,
        $.instr_plain_simd_store,
        $.instr_plain_simd_unary,
        // proposal <stop>: simd
      ),

    // proposal: threads
    instr_plain_atomic_fence: $ => seq(token.immediate("atomic"), token.immediate("."), token.immediate("fence")),

    // proposal: threads
    instr_plain_atomic_load: $ =>
      choice(
        seq(
          $.instr_type_int,
          token.immediate("."),
          token.immediate("atomic"),
          token.immediate("."),
          token.immediate("load"),
          optional(
            seq(
              choice(token.immediate("8"), token.immediate("16")),
              token.immediate("_"),
              alias(token.immediate("u"), $.sign),
            ),
          ),
        ),
        seq(
          $.instr_type_int_64,
          token.immediate("."),
          token.immediate("atomic"),
          token.immediate("."),
          token.immediate("load"),
          token.immediate("32"),
          token.immediate("_"),
          token.immediate("u"),
        ),
      ),

    // proposal: threads
    instr_plain_atomic_notify: $ =>
      seq("memory", token.immediate("."), token.immediate("atomic"), token.immediate("."), token.immediate("notify")),

    // proposal: threads
    instr_plain_atomic_store: $ =>
      choice(
        seq(
          $.instr_type_int,
          token.immediate("."),
          token.immediate("atomic"),
          token.immediate("."),
          token.immediate("store"),
          optional(choice(token.immediate("8"), token.immediate("16"))),
        ),
        seq(
          $.instr_type_int_64,
          token.immediate("."),
          token.immediate("atomic"),
          token.immediate("."),
          token.immediate("store"),
          token.immediate("32"),
        ),
      ),

    // proposal: threads
    instr_plain_atomic_rmw: $ =>
      choice(
        seq(
          $.instr_type_int,
          token.immediate("."),
          token.immediate("atomic"),
          token.immediate("."),
          choice(
            seq(token.immediate("rmw"), token.immediate("."), token.immediate(/add|and|cmpxchg|or|sub|xchg|xor/)),
            seq(
              token.immediate("rmw"),
              choice(token.immediate("8"), token.immediate("16")),
              token.immediate("."),
              token.immediate(/add|and|cmpxchg|or|sub|xchg|xor/),
              token.immediate("_"),
              token.immediate("u"),
            ),
          ),
        ),
        seq(
          $.instr_type_int_64,
          token.immediate("."),
          token.immediate("atomic"),
          token.immediate("."),
          seq(
            token.immediate("rmw"),
            token.immediate("32"),
            token.immediate("."),
            token.immediate(/add|and|cmpxchg|or|sub|xchg|xor/),
            token.immediate("_"),
            token.immediate("u"),
          ),
        ),
      ),

    // proposal: threads
    instr_plain_atomic_wait: $ =>
      seq(
        "memory",
        token.immediate("."),
        token.immediate("atomic"),
        token.immediate("."),
        token.immediate("wait"),
        token.immediate(/32|64/),
      ),

    instr_plain_binary: $ =>
      choice(
        seq($._instr_type, token.immediate("."), token.immediate(/add|sub|mul/)),
        seq($.instr_type_int, token.immediate("."), token.immediate(/and|or|xor|shl|rotl|rotr/)),
        seq(
          $.instr_type_int,
          token.immediate("."),
          token.immediate(/div|rem|shr/),
          token.immediate("_"),
          token.immediate(/[su]/),
        ),
        seq($.instr_type_float, token.immediate("."), token.immediate(/add|sub|mul|div|min|max|copysign/)),
      ),

    instr_plain_br: $ => seq("br", field("index", $.index)),

    instr_plain_br_if: $ => seq("br_if", field("index", $.index)),

    // proposal: function-references
    instr_plain_br_on_null: $ => seq("br_on_null", field("index", $.index)),

    instr_plain_br_table: $ => seq("br_table", field("index_head", $.index), repeat(field("index_tail", $.index))),

    instr_plain_call: $ => seq("call", field("index", $.index)),

    // proposal: function-references
    instr_plain_call_ref: $ => "call_ref",

    instr_plain_compare: $ =>
      choice(
        seq($._instr_type, token.immediate("."), token.immediate(/eq|ne/)),
        seq(
          $.instr_type_int,
          token.immediate("."),
          token.immediate(/lt|le|gt|ge/),
          token.immediate("_"),
          token.immediate(/[su]/),
        ),
        seq($.instr_type_float, token.immediate("."), token.immediate(/lt|le|gt|ge/)),
      ),

    instr_plain_const: $ =>
      choice(
        $.instr_plain_const_num,
        // proposal: reference-types
        $.instr_plain_ref_extern,
        // proposal: reference-types
        $.instr_plain_ref_null,
        // proposal: function-references
        $.instr_plain_ref_func,
      ),

    instr_plain_const_num: $ => seq($._instr_type, token.immediate("."), token.immediate(/const/), $.num),

    instr_plain_ref_as_non_null: $ => seq("ref", token.immediate("."), token.immediate(/as_non_null/)),

    instr_plain_ref_extern: $ => seq("ref", token.immediate("."), token.immediate(/extern/), $.UNSIGNED),

    instr_plain_ref_null: $ =>
      seq(
        "ref",
        token.immediate("."),
        token.immediate(/null/),
        choice(field("ref_kind", $.ref_kind), field("index", $.index)),
      ),

    instr_plain_convert: $ =>
      choice(
        seq(
          $.instr_type_int_32,
          token.immediate("."),
          token.immediate("wrap"),
          token.immediate("_i"),
          token.immediate("64"),
        ),
        seq(
          $.instr_type_int_64,
          token.immediate("."),
          token.immediate("extend"),
          token.immediate("_i"),
          token.immediate("32"),
          token.immediate("_"),
          token.immediate(/[su]/),
        ),
        seq(
          $.instr_type_float_32,
          token.immediate("."),
          token.immediate("demote"),
          token.immediate("_f"),
          token.immediate("64"),
        ),
        seq(
          $.instr_type_float_64,
          token.immediate("."),
          token.immediate("promote"),
          token.immediate("_f"),
          token.immediate("32"),
        ),
        seq(
          $.instr_type_int,
          token.immediate("."),
          token.immediate("trunc"),
          optional(seq(token.immediate("_"), token.immediate("sat"))),
          token.immediate("_f"),
          token.immediate(/32|64/),
          token.immediate("_"),
          token.immediate(/[su]/),
        ),
        seq(
          $.instr_type_float,
          token.immediate("."),
          token.immediate("convert"),
          token.immediate("_i"),
          token.immediate(/32|64/),
          token.immediate("_"),
          token.immediate(/[su]/),
        ),
        seq(
          $.instr_type_int_32,
          token.immediate("."),
          token.immediate("reinterpret"),
          token.immediate("_f"),
          token.immediate("32"),
        ),
        seq(
          $.instr_type_int_64,
          token.immediate("."),
          token.immediate("reinterpret"),
          token.immediate("_f"),
          token.immediate("64"),
        ),
        seq(
          $.instr_type_float_32,
          token.immediate("."),
          token.immediate("reinterpret"),
          token.immediate("_i"),
          token.immediate("32"),
        ),
        seq(
          $.instr_type_float_64,
          token.immediate("."),
          token.immediate("reinterpret"),
          token.immediate("_i"),
          token.immediate("64"),
        ),
      ),

    // proposal: bulk-memory-operations
    instr_plain_data_drop: $ => seq("data.drop", field("index", $.index)),

    instr_plain_drop: $ => "drop",

    // proposal: bulk-memory-operations
    instr_plain_elem_drop: $ => seq(token("elem.drop"), field("index", $.index)),

    // proposal: function-references
    instr_plain_func_bind: $ => seq(token("func.bind"), optional(seq("(", "type", field("index", $.index), ")"))),

    instr_plain_global_get: $ => seq("global.get", field("index", $.index)),

    instr_plain_global_set: $ => seq("global.set", field("index", $.index)),

    // proposal: function-references
    instr_plain_let: $ =>
      seq(
        "let",
        optional(field("index", $.index)),
        repeat(field("params", $._func_type_params)),
        repeat(field("results", $.func_type_results)),
        repeat(field("locals", $._func_locals)),
      ),

    instr_plain_load: $ =>
      seq(
        choice(
          seq($._instr_type, token.immediate("."), token.immediate("load")),
          seq(
            $.instr_type_int,
            token.immediate("."),
            token.immediate("load"),
            token.immediate(/(?:8|16)/),
            token.immediate("_"),
            token.immediate(/[su]/),
          ),
          seq(
            $.instr_type_int_64,
            token.immediate("."),
            token.immediate("load"),
            token.immediate("32"),
            token.immediate("_"),
            token.immediate(/[su]/),
          ),
        ),
        // proposal: multi-memory
        optional(field("index", $.index)),
        optional(field("offset_value", $.offset_value)),
        optional(field("align_value", $.align_value)),
      ),

    instr_plain_local_get: $ => seq("local.get", field("index", $.index)),

    instr_plain_local_set: $ => seq("local.set", field("index", $.index)),

    instr_plain_local_tee: $ => seq("local.tee", field("index", $.index)),

    // proposal: bulk-memory-operations
    instr_plain_memory_copy: $ => token("memory.copy"),

    // proposal: bulk-memory-operations
    instr_plain_memory_fill: $ => token("memory.fill"),

    instr_plain_memory_grow: $ =>
      seq(
        token("memory.grow"),
        // proposal: multi-memory
        optional(field("index", $.index)),
      ),

    // proposal: bulk-memory-operations
    instr_plain_memory_init: $ => seq(token("memory.init"), field("index", $.index)),

    instr_plain_memory_size: $ =>
      seq(
        token("memory.size"),
        // proposal: multi-memory
        optional(field("index", $.index)),
      ),

    instr_plain_nop: $ => "nop",

    // proposal: reference-types
    instr_plain_ref_func: $ => seq("ref.func", optional(field("index", $.index))),

    // proposal: reference-types
    instr_plain_ref_is_null: $ => token("ref.is_null"),

    instr_plain_return: $ => "return",

    // proposal: function-references
    instr_plain_return_call_ref: $ => "return_call_ref",

    instr_plain_select: $ =>
      seq(
        "select",
        // proposal: reference-types
        repeat(field("results", $.func_type_results)),
      ),

    // proposal: simd
    instr_plain_simd_binary: $ =>
      choice(
        seq(
          "v128",
          token.immediate("."),
          choice(
            token.immediate(/and|andnot|not|or|xor/),
            seq(
              token.immediate("store"),
              optional(field("offset_value", $.offset_value)),
              optional(field("align_value", $.align_value)),
            ),
          ),
        ),
        seq(choice("f32x4", "f64x2"), token.immediate("."), token.immediate(/div|min|max|sqrt/)),
        seq(
          choice("i8x16", "i16x8"),
          token.immediate("."),
          token.immediate(/(add|sub)_saturate|avgr/),
          token.immediate("_"),
          token.immediate(/[su]/),
        ),
        seq(
          choice("i8x16", "i16x8", "i32x4"),
          token.immediate("."),
          token.immediate(/min|max/),
          token.immediate("_"),
          token.immediate(/[su]/),
        ),
        seq(choice("i8x16", "i16x8", "i32x4", "i64x2"), token.immediate("."), token.immediate("shl")),
        seq(
          choice("i8x16", "i16x8", "i32x4", "i64x2"),
          token.immediate("."),
          token.immediate("shr"),
          token.immediate("_"),
          token.immediate(/[su]/),
        ),
        seq(
          choice("f32x4", "f64x2", "i8x16", "i16x8", "i32x4", "i64x2"),
          token.immediate("."),
          token.immediate(/add|sub/),
        ),
        seq(choice("f32x4", "f64x2", "i16x8", "i32x4", "i64x2"), token.immediate("."), token.immediate(/mul/)),
      ),

    // proposal: simd
    instr_plain_simd_compare: $ =>
      choice(
        seq(choice("f32x4", "f64x2"), token.immediate("."), token.immediate(/ge|gt|le|lt/)),
        seq(choice("f32x4", "f64x2", "i8x16", "i16x8", "i32x4"), token.immediate("."), token.immediate(/eq|ne/)),
        seq(
          choice("i8x16", "i16x8", "i32x4"),
          token.immediate("."),
          token.immediate(/ge|gt|le|lt/),
          token.immediate("_"),
          token.immediate(/[su]/),
        ),
      ),

    // proposal: simd
    instr_plain_simd_const: $ =>
      seq(
        "v128",
        token.immediate("."),
        token.immediate("const"),
        token.immediate(/[\s\uFEFF\u2060\u200B\u00A0]/),
        choice(
          seq(
            token.immediate("f"),
            token.immediate("32"),
            token.immediate("x"),
            token.immediate("4"),
            ...Array(4).fill(field("arg", $.FLOAT)),
          ),
          seq(
            token.immediate("f"),
            token.immediate("64"),
            token.immediate("x"),
            token.immediate("2"),
            ...Array(2).fill(field("arg", $.FLOAT)),
          ),
          seq(
            token.immediate("i"),
            token.immediate("8"),
            token.immediate("x"),
            token.immediate("16"),
            ...Array(16).fill(field("arg", $.INTEGER)),
          ),
          seq(
            token.immediate("i"),
            token.immediate("16"),
            token.immediate("x"),
            token.immediate("8"),
            ...Array(8).fill(field("arg", $.INTEGER)),
          ),
          seq(
            token.immediate("i"),
            token.immediate("32"),
            token.immediate("x"),
            token.immediate("4"),
            ...Array(4).fill(field("arg", $.INTEGER)),
          ),
          seq(
            token.immediate("i"),
            token.immediate("64"),
            token.immediate("x"),
            token.immediate("2"),
            ...Array(2).fill(field("arg", $.INTEGER)),
          ),
        ),
      ),

    // proposal: simd
    instr_plain_simd_convert: $ =>
      choice(
        seq(
          "f32x4",
          token.immediate("."),
          token.immediate("convert"),
          token.immediate("_"),
          token.immediate("i32x4"),
          token.immediate("_"),
          token.immediate(/[su]/),
        ),
        seq(
          "i8x16",
          token.immediate("."),
          token.immediate("narrow"),
          token.immediate("_"),
          token.immediate("i16x8"),
          token.immediate("_"),
          token.immediate(/[su]/),
        ),
        seq(
          "i16x8",
          token.immediate("."),
          choice(
            seq(
              token.immediate("narrow"),
              token.immediate("_"),
              token.immediate("i32x4"),
              token.immediate("_"),
              token.immediate(/[su]/),
            ),
            seq(
              token.immediate("widen"),
              token.immediate("_"),
              token.immediate(/high|low/),
              token.immediate("_"),
              token.immediate("i8x16"),
              token.immediate("_"),
              token.immediate(/[su]/),
            ),
          ),
        ),
        seq(
          "i32x4",
          token.immediate("."),
          choice(
            seq(
              token.immediate("trunc_sat"),
              token.immediate("_"),
              token.immediate("f32x4"),
              token.immediate("_"),
              token.immediate(/[su]/),
            ),
            seq(
              token.immediate("widen"),
              token.immediate("_"),
              token.immediate(/high|low/),
              token.immediate("_"),
              token.immediate("i16x8"),
              token.immediate("_"),
              token.immediate(/[su]/),
            ),
          ),
        ),
      ),

    // proposal: simd
    instr_plain_simd_lane: $ =>
      choice(
        seq(
          "v8x16",
          token.immediate("."),
          choice(token.immediate("swizzle"), seq(token.immediate("shuffle"), ...Array(16).fill(field("arg", $.FLOAT)))),
        ),
        seq(
          choice("i8x16", "i16x8"),
          token.immediate("."),
          token.immediate("extract_lane"),
          token.immediate("_"),
          token.immediate(/[su]/),
          field("arg", $.INTEGER),
        ),
        seq(
          choice("f32x4", "f64x2", "i32x4", "i64x2"),
          token.immediate("."),
          token.immediate("extract_lane"),
          field("arg", $.INTEGER),
        ),
        seq(
          choice("f32x4", "f64x2", "i8x16", "i16x8", "i32x4", "i64x2"),
          token.immediate("."),
          token.immediate("replace_lane"),
          field("arg", $.INTEGER),
        ),
      ),

    // proposal: simd
    instr_plain_simd_load: $ =>
      choice(
        seq(
          choice(
            choice(
              seq("i16x8", token.immediate("."), token.immediate("load8x8_"), token.immediate(/[su]/)),
              seq("i32x4", token.immediate("."), token.immediate("load16x4_"), token.immediate(/[su]/)),
              seq("i64x2", token.immediate("."), token.immediate("load32x2_"), token.immediate(/[su]/)),
            ),
            choice(
              seq("v8x16", token.immediate("."), token.immediate("load_splat")),
              seq("v16x8", token.immediate("."), token.immediate("load_splat")),
              seq("v32x4", token.immediate("."), token.immediate("load_splat")),
              seq("v64x2", token.immediate("."), token.immediate("load_splat")),
            ),
            seq("v128", token.immediate("."), token.immediate("load")),
          ),
          optional(field("offset_value", $.offset_value)),
          optional(field("align_value", $.align_value)),
        ),
      ),

    // proposal: simd
    instr_plain_simd_store: $ =>
      seq(
        seq("v128", token.immediate("."), token.immediate("store")),
        optional(field("offset_value", $.offset_value)),
        optional(field("align_value", $.align_value)),
      ),

    // proposal: simd
    instr_plain_simd_trinary: $ => choice(seq("v128", token.immediate("."), token.immediate("bitselect"))),

    // proposal: simd
    instr_plain_simd_unary: $ =>
      choice(
        seq(
          choice("f32x4", "f64x2", "i8x16", "i16x8", "i32x4", "i64x2"),
          token.immediate("."),
          token.immediate(/abs|neg|splat/),
        ),
        seq(choice("i8x16", "i16x8", "i32x4"), token.immediate("."), token.immediate(/all_true|any_true/)),
        seq("v128", token.immediate("."), token.immediate("not")),
        seq(
          choice(
            choice(
              seq("i16x8", token.immediate("."), token.immediate("load8x8_"), token.immediate(/[su]/)),
              seq("i32x4", token.immediate("."), token.immediate("load16x4_"), token.immediate(/[su]/)),
              seq("i64x2", token.immediate("."), token.immediate("load32x2_"), token.immediate(/[su]/)),
            ),
            choice(
              seq("v8x16", token.immediate("."), token.immediate("load_splat")),
              seq("v16x8", token.immediate("."), token.immediate("load_splat")),
              seq("v32x4", token.immediate("."), token.immediate("load_splat")),
              seq("v64x2", token.immediate("."), token.immediate("load_splat")),
            ),
            seq("v128", token.immediate("."), token.immediate(/load|store/)),
          ),
          optional(field("offset_value", $.offset_value)),
          optional(field("align_value", $.align_value)),
        ),
      ),

    instr_plain_store: $ =>
      seq(
        choice(
          seq($._instr_type, token.immediate("."), token.immediate("store")),
          seq($.instr_type_int, token.immediate("."), token.immediate("store"), token(/(?:8|16)/)),
          seq($.instr_type_int_64, token.immediate("."), token.immediate("store"), token.immediate("32")),
        ),
        // proposal: multi-memory
        optional(field("index", $.index)),
        optional(field("offset_value", $.offset_value)),
        optional(field("align_value", $.align_value)),
      ),

    // proposal: bulk-memory-operations
    instr_plain_table_copy: $ =>
      seq(token("table.copy"), optional(seq(field("index", $.index), field("index", $.index)))),

    // proposal: reference-types
    instr_plain_table_fill: $ => seq("table.fill", optional(field("index", $.index))),

    // proposal: reference-types
    instr_plain_table_get: $ => seq("table.get", optional(field("index", $.index))),

    // proposal: reference-types
    instr_plain_table_grow: $ => seq("table.grow", optional(field("index", $.index))),

    // proposal: bulk-memory-operations
    instr_plain_table_init: $ => seq(token("table.init"), field("index", $.index), optional(field("index", $.index))),

    // proposal: reference-types
    instr_plain_table_set: $ => seq("table.set", optional(field("index", $.index))),

    // proposal: reference-types
    instr_plain_table_size: $ => seq("table.size", optional(field("index", $.index))),

    instr_plain_test: $ => seq($._instr_type, token.immediate("."), token.immediate(/eqz/)),

    instr_plain_unary: $ =>
      choice(
        seq($.instr_type_int, token.immediate("."), token.immediate(/clz|ctz|popcnt/)),
        seq(
          $.instr_type_int,
          token.immediate("."),
          token.immediate("extend"),
          token.immediate(/8|16/),
          token.immediate("_"),
          token.immediate("s"),
        ),
        seq(
          $.instr_type_int_64,
          token.immediate("."),
          token.immediate("extend"),
          token.immediate("32"),
          token.immediate("_"),
          token.immediate("s"),
        ),
        seq($.instr_type_float, token.immediate("."), token.immediate(/neg|abs|sqrt|ceil|floor|trunc|nearest/)),
      ),

    instr_plain_unreachable: $ => "unreachable",

    _instr_type: $ => choice($.instr_type_int, $.instr_type_float),

    instr_type_float: $ => choice("f32", "f64"),

    instr_type_float_32: $ => "f32",

    instr_type_float_64: $ => "f64",

    instr_type_int: $ => choice("i32", "i64"),

    instr_type_int_32: $ => "i32",

    instr_type_int_64: $ => "i64",

    limits: $ =>
      seq(
        field("min", $.UNSIGNED),
        optional(field("max", $.UNSIGNED)),
        // proposal: threads
        optional(field("share", $.share)),
      ),

    memory_fields_data: $ => seq("(", "data", repeat(field("string", $.string)), ")"),

    memory_fields_type: $ => seq(optional(field("import", $.inline_import)), field("type", $.memory_type)),

    memory_type: $ => field("limits", $.limits),

    memory_use: $ => seq("(", "memory", field("index", $.index), ")"),

    module: $ =>
      seq(
        "(",
        "module",
        optional(field("identifier", $.identifier)),
        repeat(field("module_field", $.module_field)),
        ")",
      ),

    module_field: $ =>
      choice(
        $.module_field_type,
        $.module_field_global,
        $.module_field_table,
        $.module_field_memory,
        $.module_field_func,
        $.module_field_elem,
        $.module_field_data,
        $.module_field_start,
        $.module_field_import,
        $.module_field_export,
      ),

    module_field_data: $ =>
      seq(
        "(",
        "data",
        optional(field("index", $.index)),
        optional(seq(optional(field("memory_use", $.memory_use)), field("offset", $._offset))),
        repeat(field("string", $.string)),
        ")",
      ),

    module_field_elem: $ =>
      seq(
        "(",
        "elem",
        optional(field("index_head", $.index)),
        choice(
          field("elem_list", $.elem_list),
          seq(
            field("table_use", $.table_use),
            field("offset", $._offset),
            choice(
              field("elem_list", $.elem_list),
              // proposal: multi-memory
              field("elem_var_list", repeat(field("index", $.index))),
            ),
          ),
          seq(field("declare", alias("declare", $.declare)), field("elem_list", $.elem_list)),
          seq(field("offset", $._offset), field("elem_list", $.elem_list)),
          seq(field("offset", $._offset), field("elem_var_list", repeat(field("index", $.index)))),
        ),
        ")",
      ),

    module_field_export: $ => seq("(", "export", field("name", $.name), field("export_desc", $._export_desc), ")"),

    module_field_func: $ =>
      seq(
        "(",
        "func",
        optional(field("identifier", $.identifier)),
        repeat(field("exports", $.inline_export)),
        optional(field("import", $.inline_import)),
        optional(field("type_use", $.type_use)),
        repeat(field("params", $._func_type_params)),
        repeat(field("results", $.func_type_results)),
        repeat(field("locals", $._func_locals)),
        optional($._instr_list),
        ")",
      ),

    module_field_global: $ =>
      seq(
        "(",
        "global",
        optional(field("identifier", $.identifier)),
        repeat(field("export", $.inline_export)),
        optional(field("import", $.inline_import)),
        field("global_type", $.global_type),
        field("expr", alias(repeat($.instr), $.expr)),
        ")",
      ),

    module_field_import: $ =>
      seq(
        "(",
        "import",
        field("module_name", $.name),
        field("item_name", $.name),
        field("import_desc", $._import_desc),
        ")",
      ),

    module_field_memory: $ =>
      seq(
        "(",
        "memory",
        optional(field("identifier", $.identifier)),
        repeat(field("export", $.inline_export)),
        choice($.memory_fields_data, $.memory_fields_type),
        ")",
      ),

    module_field_start: $ => seq("(", "start", field("index", $.index), ")"),

    module_field_table: $ =>
      seq(
        "(",
        "table",
        optional(field("identifier", $.identifier)),
        repeat(field("export", $.inline_export)),
        choice($.table_fields_elem, $.table_fields_type),
        ")",
      ),

    module_field_type: $ =>
      seq("(", "type", optional(field("identifier", $.identifier)), field("type_field", $._type_field), ")"),

    name: $ => $.string,

    num: $ => choice($.UNSIGNED, $.SIGNED, $.FLOAT),

    _offset: $ => choice($.offset_const_expr, $.offset_expr),

    offset_const_expr: $ =>
      seq("(", "offset", field("const_expr", alias(repeat(field("instr", $.instr)), $.const_expr)), ")"),

    offset_expr: $ => field("expr", $._expr),

    offset_value: $ =>
      seq("offset=", field("value", token.immediate(/[0-9]+(?:_?[0-9]+)*|0x[0-9A-Fa-f]+(?:_?[0-9A-Fa-f]+)*/))),

    // proposal: reference-types
    ref_kind: $ => choice(/extern|func/),

    // proposal: reference-types
    _ref_type: $ => choice($.ref_type_externref, $.ref_type_funcref, $.ref_type_ref),

    // proposal: reference-types
    ref_type_externref: $ => "externref",

    // proposal: reference-types
    ref_type_funcref: $ => "funcref",

    // proposal: function-references
    ref_type_ref: $ =>
      seq(
        "(",
        "ref",
        optional(field("null", alias("null", $.null))),
        choice(field("ref_kind", $.ref_kind), field("index", $.index)),
        ")",
      ),

    // eslint-disable-next-line no-useless-escape
    reserved: $ => token(choice(pattern_identifier, /[,;\[\]{}]/)),

    // proposal: threads
    share: $ => choice("shared", "unshared"),

    sign: $ => token(/[+-]/),

    string: $ =>
      seq('"', repeat(choice(token.immediate(prec(PREC.STRING, /[^"\\\n]+|\\\r?\n/)), $.escape_sequence)), '"'),

    table_fields_elem: $ =>
      seq(
        field("ref_type", $._ref_type),
        "(",
        "elem",
        choice(
          field("elem_var_list", repeat(field("index", $.index))),
          seq(field("elem_expr", $._elem_expr), field("elem_expr_list", repeat(field("elem_expr", $._elem_expr)))),
        ),
        ")",
      ),

    table_fields_type: $ => seq(optional(field("import", $.inline_import)), field("table_type", $.table_type)),

    table_type: $ => seq(field("limits", $.limits), field("ref_type", $._ref_type)),

    table_use: $ => seq("(", "table", field("index", $.index), ")"),

    _type_field: $ => seq("(", "func", repeat(field("func_type", $._func_type)), ")"),

    type_use: $ => seq("(", "type", field("index", $.index), ")"),

    value_type: $ => choice($.value_type_num_type, $._value_type_ref_type),

    value_type_num_type: $ => token(pattern_num_type),

    _value_type_ref_type: $ => $._ref_type,
  },
});
