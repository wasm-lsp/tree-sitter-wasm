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
    [$.instr_plain_simd_binary, $.instr_plain_simd_store, $.instr_plain_simd_unary],
    [$.module_field_elem],
  ],

  rules: {
    PARSE: $ => choice($.module, alias(repeat(field("module_field", $.module_field)), $.inline_module)),

    FLOAT: $ => seq(optional(field("sign", $.sign)), $.FLOAT_MAG),

    FLOAT_MAG: $ => choice($.float, $.hexfloat, "inf", $.NAN),

    INTEGER: $ => choice($.SIGNED, $.UNSIGNED),

    NAN: $ =>
      seq(
        "nan",
        optional(
          seq(
            token.immediate(":"),
            field("kind", choice("arithmetic", "canonical", seq("0x", token.immediate(pattern_hexnum)))),
          ),
        ),
      ),

    UNSIGNED: $ => choice($.decnum, seq("0x", token.immediate(pattern_hexnum))),

    SIGNED: $ => seq(field("sign", $.sign), $.UNSIGNED),

    align_value: $ =>
      seq("align=", field("value", token.immediate(/[0-9]+(?:_?[0-9]+)*|0x[0-9A-Fa-f]+(?:_?[0-9A-Fa-f]+)*/))),

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
        optional(field("identifier0", $.identifier)),
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
        optional(field("identifier0", $.identifier)),
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
        optional(field("identifier0", $.identifier)),
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
    instr_plain_atomic_fence: $ =>
      seq(token.immediate("atomic"), token.immediate("."), field("op", token.immediate("fence"))),

    // proposal: threads
    instr_plain_atomic_load: $ =>
      choice(
        seq(
          field("type", $.instr_type_int),
          token.immediate("."),
          token.immediate("atomic"),
          token.immediate("."),
          field("op", alias(token.immediate("load"), $.op)),
          optional(
            seq(
              field("bits", alias(choice(token.immediate("8"), token.immediate("16")), $.bits)),
              token.immediate("_"),
              field("sign", alias(token.immediate("u"), $.sign)),
            ),
          ),
        ),
        seq(
          field("type", $.instr_type_int_64),
          token.immediate("."),
          token.immediate("atomic"),
          token.immediate("."),
          field("op", alias(token.immediate("load"), $.op)),
          field("bits", alias(token.immediate("32"), $.bits)),
          token.immediate("_"),
          field("sign", alias(token.immediate("u"), $.sign)),
        ),
      ),

    // proposal: threads
    instr_plain_atomic_notify: $ =>
      seq(
        token("memory"),
        token.immediate("."),
        token.immediate("atomic"),
        token.immediate("."),
        field("op", alias(token.immediate("notify"), $.op)),
      ),

    // proposal: threads
    instr_plain_atomic_store: $ =>
      choice(
        seq(
          field("type", $.instr_type_int),
          token.immediate("."),
          token.immediate("atomic"),
          token.immediate("."),
          field("op", alias(token.immediate("store"), $.op)),
          optional(field("bits", alias(choice(token.immediate("8"), token.immediate("16")), $.bits))),
        ),
        seq(
          field("type", $.instr_type_int_64),
          token.immediate("."),
          token.immediate("atomic"),
          token.immediate("."),
          field("op", alias(token.immediate("store"), $.op)),
          field("bits", alias(token.immediate("32"), $.bits)),
        ),
      ),

    // proposal: threads
    instr_plain_atomic_rmw: $ =>
      choice(
        seq(
          field("type", $.instr_type_int),
          token.immediate("."),
          token.immediate("atomic"),
          token.immediate("."),
          choice(
            seq(
              field("rmw", alias(token.immediate("rmw"), $.rmw)),
              token.immediate("."),
              field("op", alias(token.immediate(/add|and|cmpxchg|or|sub|xchg|xor/), $.op)),
            ),
            seq(
              field("rmw", alias(token.immediate("rmw"), $.rmw)),
              field("bits", alias(choice(token.immediate("8"), token.immediate("16")), $.bits)),
              token.immediate("."),
              field("op", alias(token.immediate(/add|and|cmpxchg|or|sub|xchg|xor/), $.op)),
              token.immediate("_"),
              field("sign", alias(token.immediate("u"), $.sign)),
            ),
          ),
        ),
        seq(
          field("type", $.instr_type_int_64),
          token.immediate("."),
          token.immediate("atomic"),
          token.immediate("."),
          seq(
            field("rmw", alias(token.immediate("rmw"), $.rmw)),
            field("bits", alias(token.immediate("32"), $.bits)),
            token.immediate("."),
            field("op", alias(token.immediate(/add|and|cmpxchg|or|sub|xchg|xor/), $.op)),
            token.immediate("_"),
            field("sign", alias(token.immediate("u"), $.sign)),
          ),
        ),
      ),

    // proposal: threads
    instr_plain_atomic_wait: $ =>
      seq(
        token("memory"),
        token.immediate("."),
        token.immediate("atomic"),
        token.immediate("."),
        field("op", alias(token.immediate("wait"), $.op)),
        field("bits", alias(token.immediate(/32|64/), $.bits)),
      ),

    instr_plain_binary: $ =>
      choice(
        seq(
          field("type", $._instr_type),
          token.immediate("."),
          field("op", alias(token.immediate(/add|sub|mul/), $.op)),
        ),
        seq(
          field("type", $.instr_type_int),
          token.immediate("."),
          field("op", alias(token.immediate(/and|or|xor|shl|rotl|rotr/), $.op)),
        ),
        seq(
          field("type", $.instr_type_int),
          token.immediate("."),
          field("op", alias(token.immediate(/div|rem|shr/), $.op)),
          token.immediate("_"),
          field("sign", alias(token.immediate(/[su]/), $.sign)),
        ),
        seq(
          field("type", $.instr_type_float),
          token.immediate("."),
          field("op", alias(token.immediate(/add|sub|mul|div|min|max|copysign/), $.op)),
        ),
      ),

    instr_plain_br: $ => field("op", alias(seq("br", field("index", $.index)), $.op)),

    instr_plain_br_if: $ => field("op", alias(seq("br_if", field("index", $.index)), $.op)),

    // proposal: function-references
    instr_plain_br_on_null: $ => field("op", alias(seq("br_on_null", field("index", $.index)), $.op)),

    instr_plain_br_table: $ =>
      field("op", alias(seq("br_table", field("index_head", $.index), repeat(field("index_tail", $.index))), $.op)),

    instr_plain_call: $ => field("op", alias(seq("call", field("index", $.index)), $.op)),

    // proposal: function-references
    instr_plain_call_ref: $ => field("op", alias("call_ref", $.op)),

    instr_plain_compare: $ =>
      choice(
        seq(field("type", $._instr_type), token.immediate("."), field("op", alias(token.immediate(/eq|ne/), $.op))),
        seq(
          field("type", $.instr_type_int),
          token.immediate("."),
          field("op", alias(token.immediate(/lt|le|gt|ge/), $.op)),
          token.immediate("_"),
          field("sign", alias(token.immediate(/[su]/), $.sign)),
        ),
        seq(
          field("type", $.instr_type_float),
          token.immediate("."),
          field("op", alias(token.immediate(/lt|le|gt|ge/), $.op)),
        ),
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

    instr_plain_const_num: $ =>
      seq(
        field("type", $._instr_type),
        token.immediate("."),
        field("op", alias(token.immediate(/const/), $.op)),
        field("num", $.num),
      ),

    instr_plain_ref_as_non_null: $ =>
      seq(token("ref"), token.immediate("."), field("op", alias(token.immediate(/as_non_null/), $.op))),

    instr_plain_ref_extern: $ =>
      seq(
        token("ref"),
        token.immediate("."),
        field("op", alias(token.immediate(/extern/), $.op)),
        field("nat", $.UNSIGNED),
      ),

    instr_plain_ref_null: $ =>
      seq(
        token("ref"),
        token.immediate("."),
        field("op", alias(token.immediate(/null/), $.op)),
        choice(field("ref_kind", $.ref_kind), field("index", $.index)),
      ),

    instr_plain_convert: $ =>
      choice(
        seq(
          field("type", $.instr_type_int_32),
          token.immediate("."),
          field("op", alias(token.immediate("wrap"), $.op)),
          token.immediate("_i"),
          field("bits", alias(token.immediate("64"), $.bits)),
        ),
        seq(
          field("type", $.instr_type_int_64),
          token.immediate("."),
          field("op", alias(token.immediate("extend"), $.op)),
          token.immediate("_i"),
          field("bits", alias(token.immediate("32"), $.bits)),
          token.immediate("_"),
          field("sign", alias(token.immediate(/[su]/), $.sign)),
        ),
        seq(
          field("type", $.instr_type_float_32),
          token.immediate("."),
          field("op", alias(token.immediate("demote"), $.op)),
          token.immediate("_f"),
          field("bits", alias(token.immediate("64"), $.bits)),
        ),
        seq(
          field("type", $.instr_type_float_64),
          token.immediate("."),
          field("op", alias(token.immediate("promote"), $.op)),
          token.immediate("_f"),
          field("bits", alias(token.immediate("32"), $.bits)),
        ),
        seq(
          field("type", $.instr_type_int),
          token.immediate("."),
          field("op", alias(token.immediate("trunc"), $.op)),
          optional(seq(token.immediate("_"), field("sat", alias(token.immediate("sat"), $.sat)))),
          token.immediate("_f"),
          field("bits", alias(token.immediate(/32|64/), $.bits)),
          token.immediate("_"),
          field("sign", alias(token.immediate(/[su]/), $.sign)),
        ),
        seq(
          field("type", $.instr_type_float),
          token.immediate("."),
          field("op", alias(token.immediate("convert"), $.op)),
          token.immediate("_i"),
          field("bits", alias(token.immediate(/32|64/), $.bits)),
          token.immediate("_"),
          field("sign", alias(token.immediate(/[su]/), $.sign)),
        ),
        seq(
          field("type", $.instr_type_int_32),
          token.immediate("."),
          field("op", alias(token.immediate("reinterpret"), $.op)),
          token.immediate("_f"),
          field("bits", alias(token.immediate("32"), $.bits)),
        ),
        seq(
          field("type", $.instr_type_int_64),
          token.immediate("."),
          field("op", alias(token.immediate("reinterpret"), $.op)),
          token.immediate("_f"),
          field("bits", alias(token.immediate("64"), $.bits)),
        ),
        seq(
          field("type", $.instr_type_float_32),
          token.immediate("."),
          field("op", alias(token.immediate("reinterpret"), $.op)),
          token.immediate("_i"),
          field("bits", alias(token.immediate("32"), $.bits)),
        ),
        seq(
          field("type", $.instr_type_float_64),
          token.immediate("."),
          field("op", alias(token.immediate("reinterpret"), $.op)),
          token.immediate("_i"),
          field("bits", alias(token.immediate("64"), $.bits)),
        ),
      ),

    // proposal: bulk-memory-operations
    instr_plain_data_drop: $ => seq(field("op", alias(token("data.drop"), $.op)), field("index", $.index)),

    instr_plain_drop: $ => field("op", alias(token("drop"), $.op)),

    // proposal: bulk-memory-operations
    instr_plain_elem_drop: $ => seq(field("op", alias(token("elem.drop"), $.op)), field("index", $.index)),

    // proposal: function-references
    instr_plain_func_bind: $ =>
      seq(
        field("op", alias(token("func.bind"), $.op)),
        optional(field("type", seq("(", "type", field("index", $.index), ")"))),
      ),

    instr_plain_global_get: $ => seq(field("op", alias("global.get", $.op)), field("index", $.index)),

    instr_plain_global_set: $ => seq(field("op", alias("global.set", $.op)), field("index", $.index)),

    // proposal: function-references
    instr_plain_let: $ =>
      seq(
        field("op", alias("let", $.op)),
        optional(field("index", $.index)),
        repeat(field("params", $._func_type_params)),
        repeat(field("results", $.func_type_results)),
        repeat(field("locals", $._func_locals)),
      ),

    instr_plain_load: $ =>
      seq(
        choice(
          seq(field("type", $._instr_type), token.immediate("."), field("op", alias(token.immediate("load"), $.op))),
          seq(
            field("type", $.instr_type_int),
            token.immediate("."),
            field("op", alias(token.immediate("load"), $.op)),
            field("bits", alias(token.immediate(/(?:8|16)/), $.bits)),
            token.immediate("_"),
            field("sign", alias(token.immediate(/[su]/), $.sign)),
          ),
          seq(
            field("type", $.instr_type_int_64),
            token.immediate("."),
            field("op", alias(token.immediate("load"), $.op)),
            field("bits", alias(token.immediate("32"), $.bits)),
            token.immediate("_"),
            field("sign", alias(token.immediate(/[su]/), $.sign)),
          ),
        ),
        // proposal: multi-memory
        optional(field("index", $.index)),
        optional(field("offset_value", $.offset_value)),
        optional(field("align_value", $.align_value)),
      ),

    instr_plain_local_get: $ => seq(field("op", alias("local.get", $.op)), field("index", $.index)),

    instr_plain_local_set: $ => seq(field("op", alias("local.set", $.op)), field("index", $.index)),

    instr_plain_local_tee: $ => seq(field("op", alias("local.tee", $.op)), field("index", $.index)),

    // proposal: bulk-memory-operations
    instr_plain_memory_copy: $ => field("op", alias(token("memory.copy"), $.op)),

    // proposal: bulk-memory-operations
    instr_plain_memory_fill: $ => field("op", alias(token("memory.fill"), $.op)),

    instr_plain_memory_grow: $ =>
      seq(
        field("op", alias(token("memory.grow"), $.op)),
        // proposal: multi-memory
        optional(field("index", $.index)),
      ),

    // proposal: bulk-memory-operations
    instr_plain_memory_init: $ => seq(field("op", alias(token("memory.init"), $.op)), field("index", $.index)),

    instr_plain_memory_size: $ =>
      seq(
        field("op", alias(token("memory.size"), $.op)),
        // proposal: multi-memory
        optional(field("index", $.index)),
      ),

    instr_plain_nop: $ => field("op", alias(token("nop"), $.op)),

    // proposal: reference-types
    instr_plain_ref_func: $ => seq(field("op", alias("ref.func", $.op)), optional(field("index", $.index))),

    // proposal: reference-types
    instr_plain_ref_is_null: $ => field("op", alias(token("ref.is_null"), $.op)),

    instr_plain_return: $ => field("op", alias(token("return"), $.op)),

    // proposal: function-references
    instr_plain_return_call_ref: $ => field("op", alias("return_call_ref", $.op)),

    instr_plain_select: $ =>
      seq(
        field("op", alias(token("select"), $.op)),
        // proposal: reference-types
        repeat(field("results", $.func_type_results)),
      ),

    // proposal: simd
    instr_plain_simd_binary: $ =>
      choice(
        seq(
          field("type", alias(token("v128"), $.type)),
          token.immediate("."),
          choice(
            field("op", alias(token.immediate(/and|andnot|not|or|xor/), $.op)),
            seq(
              field("op", alias(token.immediate("store"), $.op)),
              optional(field("offset_value", $.offset_value)),
              optional(field("align_value", $.align_value)),
            ),
          ),
        ),
        seq(
          field("type", alias(choice(token("f32x4"), token("f64x2")), $.type)),
          token.immediate("."),
          field("op", alias(token.immediate(/div|min|max|sqrt/), $.op)),
        ),
        seq(
          field("type", alias(choice(token("i8x16"), token("i16x8")), $.type)),
          token.immediate("."),
          field("op", alias(token.immediate(/(add|sub)_saturate|avgr/), $.op)),
          token.immediate("_"),
          field("sign", alias(token.immediate(/[su]/), $.sign)),
        ),
        seq(
          field("type", alias(choice(token("i8x16"), token("i16x8"), token("i32x4")), $.type)),
          token.immediate("."),
          field("op", alias(token.immediate(/min|max/), $.op)),
          token.immediate("_"),
          field("sign", alias(token.immediate(/[su]/), $.sign)),
        ),
        seq(
          field("type", alias(choice(token("i8x16"), token("i16x8"), token("i32x4"), token("i64x2")), $.type)),
          token.immediate("."),
          field("op", alias(token.immediate("shl"), $.op)),
        ),
        seq(
          field("type", alias(choice(token("i8x16"), token("i16x8"), token("i32x4"), token("i64x2")), $.type)),
          token.immediate("."),
          field("op", alias(token.immediate("shr"), $.op)),
          token.immediate("_"),
          field("sign", alias(token.immediate(/[su]/), $.sign)),
        ),
        seq(
          field(
            "type",
            alias(
              choice(token("f32x4"), token("f64x2"), token("i8x16"), token("i16x8"), token("i32x4"), token("i64x2")),
              $.type,
            ),
          ),
          token.immediate("."),
          field("op", alias(token.immediate(/add|sub/), $.op)),
        ),
        seq(
          field(
            "type",
            alias(choice(token("f32x4"), token("f64x2"), token("i16x8"), token("i32x4"), token("i64x2")), $.type),
          ),
          token.immediate("."),
          field("op", alias(token.immediate(/mul/), $.op)),
        ),
      ),

    // proposal: simd
    instr_plain_simd_compare: $ =>
      choice(
        seq(
          field("type", alias(choice(token("f32x4"), token("f64x2")), $.type)),
          token.immediate("."),
          field("op", alias(token.immediate(/ge|gt|le|lt/), $.op)),
        ),
        seq(
          field(
            "type",
            alias(choice(token("f32x4"), token("f64x2"), token("i8x16"), token("i16x8"), token("i32x4")), $.type),
          ),
          token.immediate("."),
          field("op", alias(token.immediate(/eq|ne/), $.op)),
        ),
        seq(
          field("type", alias(choice(token("i8x16"), token("i16x8"), token("i32x4")), $.type)),
          token.immediate("."),
          field("op", alias(token.immediate(/ge|gt|le|lt/), $.op)),
          token.immediate("_"),
          field("sign", alias(token.immediate(/[su]/), $.sign)),
        ),
      ),

    // proposal: simd
    instr_plain_simd_const: $ =>
      seq(
        field("type", alias(token("v128"), $.type)),
        token.immediate("."),
        field("op", alias(token.immediate("const"), $.op)),
        token.immediate(/[\s\uFEFF\u2060\u200B\u00A0]/),
        choice(
          seq(
            field("kind", alias(token.immediate("f"), $.kind)),
            field("bits", alias(token.immediate("32"), $.bits)),
            token.immediate("x"),
            field("lanes", alias(token.immediate("4"), $.lanes)),
            ...Array(4).fill(field("value", $.FLOAT)),
          ),
          seq(
            field("kind", alias(token.immediate("f"), $.kind)),
            field("bits", alias(token.immediate("64"), $.bits)),
            token.immediate("x"),
            field("lanes", alias(token.immediate("2"), $.lanes)),
            ...Array(2).fill(field("value", $.FLOAT)),
          ),
          seq(
            field("kind", alias(token.immediate("i"), $.kind)),
            field("bits", alias(token.immediate("8"), $.bits)),
            token.immediate("x"),
            field("lanes", alias(token.immediate("16"), $.lanes)),
            ...Array(16).fill(field("value", $.INTEGER)),
          ),
          seq(
            field("kind", alias(token.immediate("i"), $.kind)),
            field("bits", alias(token.immediate("16"), $.bits)),
            token.immediate("x"),
            field("lanes", alias(token.immediate("8"), $.lanes)),
            ...Array(8).fill(field("value", $.INTEGER)),
          ),
          seq(
            field("kind", alias(token.immediate("i"), $.kind)),
            field("bits", alias(token.immediate("32"), $.bits)),
            token.immediate("x"),
            field("lanes", alias(token.immediate("4"), $.lanes)),
            ...Array(4).fill(field("value", $.INTEGER)),
          ),
          seq(
            field("kind", alias(token.immediate("i"), $.kind)),
            field("bits", alias(token.immediate("64"), $.bits)),
            token.immediate("x"),
            field("lanes", alias(token.immediate("2"), $.lanes)),
            ...Array(2).fill(field("value", $.INTEGER)),
          ),
        ),
      ),

    // proposal: simd
    instr_plain_simd_convert: $ =>
      choice(
        seq(
          field("type", alias(token("f32x4"), $.type)),
          token.immediate("."),
          field("op", alias(token.immediate("convert"), $.op)),
          token.immediate("_"),
          field("shape", alias(token.immediate("i32x4"), $.shape)),
          token.immediate("_"),
          field("sign", alias(token.immediate(/[su]/), $.sign)),
        ),
        seq(
          field("type", alias(token("i8x16"), $.type)),
          token.immediate("."),
          field("op", alias(token.immediate("narrow"), $.op)),
          token.immediate("_"),
          field("shape", alias(token.immediate("i16x8"), $.shape)),
          token.immediate("_"),
          field("sign", alias(token.immediate(/[su]/), $.sign)),
        ),
        seq(
          field("type", alias(token("i16x8"), $.type)),
          token.immediate("."),
          choice(
            seq(
              field("op", alias(token.immediate("narrow"), $.op)),
              token.immediate("_"),
              field("shape", alias(token.immediate("i32x4"), $.shape)),
              token.immediate("_"),
              field("sign", alias(token.immediate(/[su]/), $.sign)),
            ),
            seq(
              field("op", alias(token.immediate("widen"), $.op)),
              token.immediate("_"),
              field("kind", alias(token.immediate(/high|low/), $.kind)),
              token.immediate("_"),
              field("shape", alias(token.immediate("i8x16"), $.shape)),
              token.immediate("_"),
              field("sign", alias(token.immediate(/[su]/), $.sign)),
            ),
          ),
        ),
        seq(
          field("type", alias(token("i32x4"), $.type)),
          token.immediate("."),
          choice(
            seq(
              field("op", alias(token.immediate("trunc_sat"), $.op)),
              token.immediate("_"),
              field("shape", alias(token.immediate("f32x4"), $.shape)),
              token.immediate("_"),
              field("sign", alias(token.immediate(/[su]/), $.sign)),
            ),
            seq(
              field("op", alias(token.immediate("widen"), $.op)),
              token.immediate("_"),
              field("kind", alias(token.immediate(/high|low/), $.kind)),
              token.immediate("_"),
              field("shape", alias(token.immediate("i16x8"), $.shape)),
              token.immediate("_"),
              field("sign", alias(token.immediate(/[su]/), $.sign)),
            ),
          ),
        ),
      ),

    // proposal: simd
    instr_plain_simd_lane: $ =>
      choice(
        seq(
          field("type", alias(token("v8x16"), $.type)),
          token.immediate("."),
          choice(
            field("op", alias(token.immediate("swizzle"), $.op)),
            seq(field("op", alias(token.immediate("shuffle"), $.op)), ...Array(16).fill(field("value", $.FLOAT))),
          ),
        ),
        seq(
          field("type", alias(choice(token("i8x16"), token("i16x8")), $.type)),
          token.immediate("."),
          field("op", alias(token.immediate("extract_lane"), $.op)),
          token.immediate("_"),
          field("sign", alias(token.immediate(/[su]/), $.sign)),
          field("arg", $.INTEGER),
        ),
        seq(
          field("type", alias(choice(token("f32x4"), token("f64x2"), token("i32x4"), token("i64x2")), $.type)),
          token.immediate("."),
          field("op", alias(token.immediate("extract_lane"), $.op)),
          field("arg", $.INTEGER),
        ),
        seq(
          field(
            "type",
            alias(
              choice(token("f32x4"), token("f64x2"), token("i8x16"), token("i16x8"), token("i32x4"), token("i64x2")),
              $.type,
            ),
          ),
          token.immediate("."),
          field("op", alias(token.immediate("replace_lane"), $.op)),
          field("arg", $.INTEGER),
        ),
      ),

    // proposal: simd
    instr_plain_simd_load: $ =>
      choice(
        seq(
          choice(
            choice(
              seq(token("i16x8"), token.immediate("."), token.immediate("load8x8_"), token.immediate(/[su]/)),
              seq(token("i32x4"), token.immediate("."), token.immediate("load16x4_"), token.immediate(/[su]/)),
              seq(token("i64x2"), token.immediate("."), token.immediate("load32x2_"), token.immediate(/[su]/)),
            ),
            choice(
              seq(token("v8x16"), token.immediate("."), token.immediate("load_splat")),
              seq(token("v16x8"), token.immediate("."), token.immediate("load_splat")),
              seq(token("v32x4"), token.immediate("."), token.immediate("load_splat")),
              seq(token("v64x2"), token.immediate("."), token.immediate("load_splat")),
            ),
            seq(token("v128"), token.immediate("."), token.immediate("load")),
          ),
          optional(field("offset_value", $.offset_value)),
          optional(field("align_value", $.align_value)),
        ),
      ),

    // proposal: simd
    instr_plain_simd_store: $ =>
      seq(
        seq(token("v128"), token.immediate("."), token.immediate("store")),
        optional(field("offset_value", $.offset_value)),
        optional(field("align_value", $.align_value)),
      ),

    // proposal: simd
    instr_plain_simd_trinary: $ => choice(seq(token("v128"), token.immediate("."), token.immediate("bitselect"))),

    // proposal: simd
    instr_plain_simd_unary: $ =>
      choice(
        seq(
          choice(token("f32x4"), token("f64x2"), token("i8x16"), token("i16x8"), token("i32x4"), token("i64x2")),
          token.immediate("."),
          token.immediate(/abs|neg|splat/),
        ),
        seq(
          choice(token("i8x16"), token("i16x8"), token("i32x4")),
          token.immediate("."),
          token.immediate(/all_true|any_true/),
        ),
        seq(token("v128"), token.immediate("."), token.immediate("not")),
        seq(
          choice(
            choice(
              seq(token("i16x8"), token.immediate("."), token.immediate("load8x8_"), token.immediate(/[su]/)),
              seq(token("i32x4"), token.immediate("."), token.immediate("load16x4_"), token.immediate(/[su]/)),
              seq(token("i64x2"), token.immediate("."), token.immediate("load32x2_"), token.immediate(/[su]/)),
            ),
            choice(
              seq(token("v8x16"), token.immediate("."), token.immediate("load_splat")),
              seq(token("v16x8"), token.immediate("."), token.immediate("load_splat")),
              seq(token("v32x4"), token.immediate("."), token.immediate("load_splat")),
              seq(token("v64x2"), token.immediate("."), token.immediate("load_splat")),
            ),
            seq(token("v128"), token.immediate("."), token.immediate(/load|store/)),
          ),
          optional(field("offset_value", $.offset_value)),
          optional(field("align_value", $.align_value)),
        ),
      ),

    instr_plain_store: $ =>
      seq(
        choice(
          seq(field("type", $._instr_type), token.immediate("."), field("op", alias(token.immediate("store"), $.op))),
          seq(
            field("type", $.instr_type_int),
            token.immediate("."),
            field("op", alias(token.immediate("store"), $.op)),
            field("bits", alias(token(/(?:8|16)/), $.bits)),
          ),
          seq(
            field("type", $.instr_type_int_64),
            token.immediate("."),
            field("op", alias(token.immediate("store"), $.op)),
            field("bits", alias(token.immediate("32"), $.bits)),
          ),
        ),
        // proposal: multi-memory
        optional(field("index", $.index)),
        optional(field("offset_value", $.offset_value)),
        optional(field("align_value", $.align_value)),
      ),

    // proposal: bulk-memory-operations
    instr_plain_table_copy: $ =>
      seq(
        field("op", alias(token("table.copy"), $.op)),
        optional(seq(field("index", $.index), field("index", $.index))),
      ),

    // proposal: reference-types
    instr_plain_table_fill: $ => seq(field("op", alias("table.fill", $.op)), optional(field("index", $.index))),

    // proposal: reference-types
    instr_plain_table_get: $ => seq(field("op", alias("table.get", $.op)), optional(field("index", $.index))),

    // proposal: reference-types
    instr_plain_table_grow: $ => seq(field("op", alias("table.grow", $.op)), optional(field("index", $.index))),

    // proposal: bulk-memory-operations
    instr_plain_table_init: $ =>
      seq(field("op", alias(token("table.init"), $.op)), field("index", $.index), optional(field("index", $.index))),

    // proposal: reference-types
    instr_plain_table_set: $ => seq(field("op", alias("table.set", $.op)), optional(field("index", $.index))),

    // proposal: reference-types
    instr_plain_table_size: $ => seq(field("op", alias("table.size", $.op)), optional(field("index", $.index))),

    instr_plain_test: $ =>
      seq(field("type", $._instr_type), token.immediate("."), field("op", alias(token.immediate(/eqz/), $.op))),

    instr_plain_unary: $ =>
      choice(
        seq(
          field("type", $.instr_type_int),
          token.immediate("."),
          field("op", alias(token.immediate(/clz|ctz|popcnt/), $.op)),
        ),
        seq(
          field("type", $.instr_type_int),
          token.immediate("."),
          field("op", alias(token.immediate("extend"), $.op)),
          field("bits", alias(token.immediate(/8|16/), $.bits)),
          token.immediate("_"),
          field("sign", alias(token.immediate("s"), $.sign)),
        ),
        seq(
          field("type", $.instr_type_int_64),
          token.immediate("."),
          field("op", alias(token.immediate("extend"), $.op)),
          field("bits", alias(token.immediate("32"), $.bits)),
          token.immediate("_"),
          field("sign", alias(token.immediate("s"), $.sign)),
        ),
        seq(
          field("type", $.instr_type_float),
          token.immediate("."),
          field("op", alias(token.immediate(/neg|abs|sqrt|ceil|floor|trunc|nearest/), $.op)),
        ),
      ),

    instr_plain_unreachable: $ => field("op", alias(token("unreachable"), $.op)),

    _instr_type: $ => choice($.instr_type_int, $.instr_type_float),

    instr_type_float: $ => choice(token("f32"), token("f64")),

    instr_type_float_32: $ => token("f32"),

    instr_type_float_64: $ => token("f64"),

    instr_type_int: $ => choice(token("i32"), token("i64")),

    instr_type_int_32: $ => token("i32"),

    instr_type_int_64: $ => token("i64"),

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
    ref_type_externref: $ => token("externref"),

    // proposal: reference-types
    ref_type_funcref: $ => token("funcref"),

    // proposal: function-references
    ref_type_ref: $ =>
      seq(
        "(",
        "ref",
        optional(field("null", alias(token("null"), $.null))),
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
