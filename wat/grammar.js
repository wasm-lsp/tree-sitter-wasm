/// <reference types="tree-sitter-cli/dsl" />

const PREC = {
  STRING: 2,
};

const pattern_dec_nat = /[0-9]+(_?[0-9]+)*/;
const pattern_hex_nat = /[0-9A-Fa-f]+(_?[0-9A-Fa-f]+)*/;
const pattern_identifier = /[0-9A-Za-z!#$%&'*+-./:<=>?@\\^_'|~]+/;
const pattern_num_type = /[fi](32|64)|v128/;
const pattern_sign = /[+-]/;

module.exports = grammar({
  name: "wat",

  extras: $ => [$.annotation, $.comment_block, $.comment_line, /[\s\uFEFF\u2060\u200B\u00A0]/],

  conflicts: $ => [
    [$.instr_plain_let],
    [$.instr_plain_select],
  ],

  rules: {
    ROOT: $ => choice($.module, repeat($._module_field)),

    align_value: $ => seq("align=", token.immediate(/[0-9]+(_?[0-9]+)*|0x[0-9A-Fa-f]+(_?[0-9A-Fa-f]+)*/)),

    // proposal: annotations
    annotation: $ => seq("(@", token.immediate(pattern_identifier), repeat($._annotation_part), ")"),

    // proposal: annotations
    annotation_parens: $ => seq("(", repeat($._annotation_part), ")"),

    // proposal: annotations
    _annotation_part: $ =>
      choice($.comment_block_annot, $.comment_line_annot, $.annotation_parens, $.reserved, $.identifier, $.string),

    // proposal: threads
    atomicop: $ => choice("add", "and", "cmpxchg", "or", "sub", "xchg", "xor"),

    block_block: $ =>
      seq(
        "block",
        optional($.identifier),
        seq(
          optional($.type_use),
          repeat($.func_type_params_many),
          repeat($.func_type_results),
          optional($._instr_list),
        ),
        "end",
        optional($.identifier),
      ),

    block_if: $ =>
      seq(
        "if",
        optional($.identifier),
        seq(
          optional($.type_use),
          repeat($.func_type_params_many),
          repeat($.func_type_results),
          optional($._instr_list),
        ),
        optional(seq("else", optional($.identifier), optional($._instr_list))),
        "end",
        optional($.identifier),
      ),

    block_loop: $ =>
      seq(
        "loop",
        optional($.identifier),
        seq(
          optional($.type_use),
          repeat($.func_type_params_many),
          repeat($.func_type_results),
          optional($._instr_list),
        ),
        "end",
        optional($.identifier),
      ),

    comment_block: $ => seq("(;", repeat(choice($.comment_block, /[^(;]+/, "(", ";")), ";)"),

    comment_line: $ => prec.left(token(seq(";;", /.*/))),

    comment_block_annot: $ => seq("(;", repeat(choice($.comment_block_annot, /[^(;]+/, "(", ";")), ";)"),

    comment_line_annot: $ => prec.left(token(seq(";;", /.*/))),

    _dec_nat: $ => token(pattern_dec_nat),

    // proposal: reference-types
    _elem_expr: $ => choice($.elem_expr_item, $.elem_expr_expr),

    // proposal: reference-types
    elem_expr_expr: $ => $._expr,

    // proposal: reference-types
    elem_expr_item: $ => seq("(", "item", repeat($.instr), ")"),

    // proposal: reference-types
    elem_kind: $ => token(/func/),

    // proposal: reference-types
    elem_list: $ => choice(seq($.elem_kind, repeat($.index)), seq($._ref_type, repeat($._elem_expr))),

    escape_sequence: $ => token.immediate(seq("\\", choice(/[^u0-9a-fA-F]/, /[0-9a-fA-F]{2}/, /u{[0-9a-fA-F]+}/))),

    _export_desc: $ => choice($.export_desc_func, $.export_desc_table, $.export_desc_memory, $.export_desc_global),

    export_desc_func: $ => seq("(", "func", $.index, ")"),

    export_desc_global: $ => seq("(", "global", $.index, ")"),

    export_desc_memory: $ => seq("(", "memory", $.index, ")"),

    export_desc_table: $ => seq("(", "table", $.index, ")"),

    _expr: $ => seq("(", $._expr1, ")"),

    _expr1: $ => choice($._expr1_plain, $.expr1_call, $.expr1_block, $.expr1_loop, $.expr1_if),

    expr1_block: $ =>
      seq(
        "block",
        optional($.identifier),
        seq(
          optional($.type_use),
          repeat($.func_type_params_many),
          repeat($.func_type_results),
          optional($._instr_list),
        ),
      ),

    expr1_call: $ =>
      seq(
        "call_indirect",
        // proposal: reference-types
        optional($.index),
        optional($.type_use),
        repeat($.func_type_params_many),
        repeat($.func_type_results),
        repeat($._expr),
      ),

    expr1_if: $ => seq("if", optional($.identifier), $._if_block),

    expr1_loop: $ =>
      seq(
        "loop",
        optional($.identifier),
        seq(
          optional($.type_use),
          repeat($.func_type_params_many),
          repeat($.func_type_results),
          optional($._instr_list),
        ),
      ),

    _expr1_plain: $ => seq($.instr_plain, repeat($._expr)),

    _dec_float: $ =>
      token(
        seq(
          pattern_dec_nat,
          optional(seq(".", optional(pattern_dec_nat))),
          optional(seq(/[Ee]/, optional(pattern_sign), pattern_dec_nat)),
        ),
      ),

    float: $ => seq(optional($.sign), choice($._dec_float, $._hex_float, "inf", $.nan)),

    _func_locals: $ => choice($.func_locals_one, $.func_locals_many),

    func_locals_many: $ => seq("(", "local", repeat($.value_type), ")"),

    func_locals_one: $ => seq("(", "local", $.identifier, $.value_type, ")"),

    _func_type: $ => choice($._func_type_params, $.func_type_results),

    _func_type_params: $ => choice($.func_type_params_one, $.func_type_params_many),

    func_type_params_many: $ => seq("(", "param", repeat($.value_type), ")"),

    func_type_params_one: $ => seq("(", "param", $.identifier, $.value_type, ")"),

    func_type_results: $ => seq("(", "result", repeat($.value_type), ")"),

    global_type: $ => choice($.global_type_imm, $.global_type_mut),

    global_type_imm: $ => $.value_type,

    global_type_mut: $ => seq("(", "mut", $.value_type, ")"),

    _hex_float: $ =>
      token(
        seq(
          "0x",
          pattern_hex_nat,
          optional(seq(".", optional(pattern_hex_nat))),
          optional(seq(/[Pp]/, optional(pattern_sign), pattern_dec_nat)),
        ),
      ),

    _hex_nat: $ => seq("0x", token.immediate(pattern_hex_nat)),

    identifier: $ => token(seq(token.immediate("$"), pattern_identifier)),

    _if_block: $ =>
      seq(
        optional($.type_use),
        repeat($.func_type_params_many),
        repeat($.func_type_results),
        repeat($._expr),
        seq("(", "then", optional($._instr_list), ")"),
        optional(seq("(", "else", optional($._instr_list), ")")),
      ),

    _import_desc: $ =>
      choice(
        $.import_desc_type_use,
        $.import_desc_func_type,
        $.import_desc_table_type,
        $.import_desc_memory_type,
        $.import_desc_global_type,
      ),

    import_desc_func_type: $ => seq("(", "func", optional($.identifier), repeat($._func_type), ")"),

    import_desc_global_type: $ => seq("(", "global", optional($.identifier), $.global_type, ")"),

    import_desc_memory_type: $ => seq("(", "memory", optional($.identifier), $._memory_type, ")"),

    import_desc_table_type: $ => seq("(", "table", optional($.identifier), $.table_type, ")"),

    import_desc_type_use: $ => seq("(", "func", optional($.identifier), $.type_use, ")"),

    index: $ => choice($._nat, $.identifier),

    inline_export: $ => seq("(", "export", $.name, ")"),

    inline_import: $ => seq("(", "import", $.name, $.name, ")"),

    instr: $ => choice($.instr_plain, $.instr_call, $.instr_block, $._expr),

    instr_block: $ => choice($.block_block, $.block_loop, $.block_if),

    instr_call: $ =>
      seq("call_indirect", optional($.type_use), repeat($.func_type_params_many), repeat($.func_type_results), $.instr),

    // NOTE: this must be wrapped in "optional"
    _instr_list: $ => repeat1(choice($.instr_list_call, $.instr)),

    instr_list_call: $ =>
      prec.right(
        seq("call_indirect", optional($.type_use), repeat($.func_type_params_many), repeat($.func_type_results)),
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
        $.instr_plain_ref_null,
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
        $.instr_plain_const_num,
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
          choice("i32", "i64"),
          token.immediate("."),
          token.immediate("atomic"),
          token.immediate("."),
          token.immediate("load"),
          optional(
            seq(choice(token.immediate("8"), token.immediate("16")), token.immediate("_"), token.immediate("u")),
          ),
        ),
        seq(
          "i64",
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
          choice("i32", "i64"),
          token.immediate("."),
          token.immediate("atomic"),
          token.immediate("."),
          token.immediate("store"),
          optional(choice(token.immediate("8"), token.immediate("16"))),
        ),
        seq(
          "i64",
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
          choice("i32", "i64"),
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
          "i64",
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
        seq(choice("f32", "f64", "i32", "i64"), token.immediate("."), token.immediate(/add|sub|mul/)),
        seq(choice("i32", "i64"), token.immediate("."), token.immediate(/and|or|xor|shl|rotl|rotr/)),
        seq(
          choice("i32", "i64"),
          token.immediate("."),
          token.immediate(/div|rem|shr/),
          token.immediate("_"),
          token.immediate(/[su]/),
        ),
        seq(choice("f32", "f64"), token.immediate("."), token.immediate(/add|sub|mul|div|min|max|copysign/)),
      ),

    instr_plain_br: $ => seq("br", $.index),

    instr_plain_br_if: $ => seq("br_if", $.index),

    // proposal: function-references
    instr_plain_br_on_null: $ => seq("br_on_null", $.index),

    instr_plain_br_table: $ => seq("br_table", $.index, repeat($.index)),

    instr_plain_call: $ => seq("call", $.index),

    // proposal: function-references
    instr_plain_call_ref: $ => "call_ref",

    instr_plain_compare: $ =>
      choice(
        seq(choice("f32", "f64", "i32", "i64"), token.immediate("."), token.immediate(/eq|ne/)),
        seq(
          choice("i32", "i64"),
          token.immediate("."),
          token.immediate(/lt|le|gt|ge/),
          token.immediate("_"),
          token.immediate(/[su]/),
        ),
        seq(choice("f32", "f64"), token.immediate("."), token.immediate(/lt|le|gt|ge/)),
      ),

    instr_plain_const: $ =>
      choice(
        $.instr_plain_const_num,
        // proposal: reference-types
        $.instr_plain_ref_null,
        // proposal: reference-types
        $.instr_plain_ref_extern,
      ),

    instr_plain_const_num: $ =>
      seq(choice("f32", "f64", "i32", "i64"), token.immediate("."), token.immediate("const"), $.num),

    instr_plain_ref_as_non_null: $ => "ref.as_non_null",

    instr_plain_ref_extern: $ => seq("ref.extern", $._nat),

    instr_plain_ref_null: $ => seq("ref.null", choice($.ref_kind, $.index)),

    instr_plain_convert: $ =>
      choice(
        seq("i32", token.immediate("."), token.immediate("wrap"), token.immediate("_i"), token.immediate("64")),
        seq(
          "i64",
          token.immediate("."),
          token.immediate("extend"),
          token.immediate("_i"),
          token.immediate("32"),
          token.immediate("_"),
          token.immediate(/[su]/),
        ),
        seq("f32", token.immediate("."), token.immediate("demote"), token.immediate("_f"), token.immediate("64")),
        seq("f64", token.immediate("."), token.immediate("promote"), token.immediate("_f"), token.immediate("32")),
        seq(
          choice("i32", "i64"),
          token.immediate("."),
          token.immediate("trunc"),
          optional(seq(token.immediate("_"), token.immediate("sat"))),
          token.immediate("_f"),
          token.immediate(/32|64/),
          token.immediate("_"),
          token.immediate(/[su]/),
        ),
        seq(
          choice("f32", "f64"),
          token.immediate("."),
          token.immediate("convert"),
          token.immediate("_i"),
          token.immediate(/32|64/),
          token.immediate("_"),
          token.immediate(/[su]/),
        ),
        seq("i32", token.immediate("."), token.immediate("reinterpret"), token.immediate("_f"), token.immediate("32")),
        seq("i64", token.immediate("."), token.immediate("reinterpret"), token.immediate("_f"), token.immediate("64")),
        seq("f32", token.immediate("."), token.immediate("reinterpret"), token.immediate("_i"), token.immediate("32")),
        seq("f64", token.immediate("."), token.immediate("reinterpret"), token.immediate("_i"), token.immediate("64")),
      ),

    // proposal: bulk-memory-operations
    instr_plain_data_drop: $ => seq("data.drop", $.index),

    instr_plain_drop: $ => "drop",

    // proposal: bulk-memory-operations
    instr_plain_elem_drop: $ => seq(token("elem.drop"), $.index),

    // proposal: function-references
    instr_plain_func_bind: $ => prec.right(seq(token("func.bind"), optional(seq("(", "type", $.index, ")")))),

    instr_plain_global_get: $ => seq("global.get", $.index),

    instr_plain_global_set: $ => seq("global.set", $.index),

    // proposal: function-references
    instr_plain_let: $ =>
      seq("let", optional($.index), repeat($._func_type_params), repeat($.func_type_results), repeat($._func_locals)),

    instr_plain_load: $ =>
      seq(
        choice(
          seq(choice("f32", "f64", "i32", "i64"), token.immediate("."), token.immediate("load")),
          seq(
            choice("i32", "i64"),
            token.immediate("."),
            token.immediate("load"),
            token.immediate(/(8|16)/),
            token.immediate("_"),
            token.immediate(/[su]/),
          ),
          seq(
            "i64",
            token.immediate("."),
            token.immediate("load"),
            token.immediate("32"),
            token.immediate("_"),
            token.immediate(/[su]/),
          ),
        ),
        // proposal: multi-memory
        optional($.index),
        optional($.offset_value),
        optional($.align_value),
      ),

    instr_plain_local_get: $ => seq("local.get", $.index),

    instr_plain_local_set: $ => seq("local.set", $.index),

    instr_plain_local_tee: $ => seq("local.tee", $.index),

    // proposal: bulk-memory-operations
    instr_plain_memory_copy: $ => token("memory.copy"),

    // proposal: bulk-memory-operations
    instr_plain_memory_fill: $ => token("memory.fill"),

    instr_plain_memory_grow: $ =>
      seq(
        token("memory.grow"),
        // proposal: multi-memory
        optional($.index),
      ),

    // proposal: bulk-memory-operations
    instr_plain_memory_init: $ => seq(token("memory.init"), $.index),

    instr_plain_memory_size: $ =>
      seq(
        token("memory.size"),
        // proposal: multi-memory
        optional($.index),
      ),

    instr_plain_nop: $ => "nop",

    // proposal: reference-types
    instr_plain_ref_func: $ => seq("ref.func", $.index),

    // proposal: reference-types
    instr_plain_ref_is_null: $ => token("ref.is_null"),

    instr_plain_return: $ => "return",

    // proposal: function-references
    instr_plain_return_call_ref: $ => "return_call_ref",

    instr_plain_select: $ =>
      seq(
        "select",
        // proposal: reference-types
        repeat($.func_type_results),
      ),

    // proposal: simd
    instr_plain_simd_binary: $ =>
      choice(
        seq("v128", token.immediate("."), token.immediate(/and|andnot|not|or|xor/)),
        seq(choice("f32x4", "f64x2"), token.immediate("."), token.immediate(/div|p?(min|max)|sqrt/)),
        seq(
          choice("i8x16", "i16x8"),
          token.immediate("."),
          token.immediate(/(add|sub)_sat|avgr/),
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
            ...Array(4).fill($.float),
          ),
          seq(
            token.immediate("f"),
            token.immediate("64"),
            token.immediate("x"),
            token.immediate("2"),
            ...Array(2).fill($.float),
          ),
          seq(
            token.immediate("i"),
            token.immediate("8"),
            token.immediate("x"),
            token.immediate("16"),
            ...Array(16).fill($.integer),
          ),
          seq(
            token.immediate("i"),
            token.immediate("16"),
            token.immediate("x"),
            token.immediate("8"),
            ...Array(8).fill($.integer),
          ),
          seq(
            token.immediate("i"),
            token.immediate("32"),
            token.immediate("x"),
            token.immediate("4"),
            ...Array(4).fill($.integer),
          ),
          seq(
            token.immediate("i"),
            token.immediate("64"),
            token.immediate("x"),
            token.immediate("2"),
            ...Array(2).fill($.integer),
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
          "i8x16",
          token.immediate("."),
          choice(token.immediate("swizzle"), seq(token.immediate("shuffle"), ...Array(16).fill($.float))),
        ),
        seq(
          choice("i8x16", "i16x8"),
          token.immediate("."),
          token.immediate("extract_lane"),
          token.immediate("_"),
          token.immediate(/[su]/),
          $.integer,
        ),
        seq(
          choice("f32x4", "f64x2", "i32x4", "i64x2"),
          token.immediate("."),
          token.immediate("extract_lane"),
          $.integer,
        ),
        seq(
          choice("f32x4", "f64x2", "i8x16", "i16x8", "i32x4", "i64x2"),
          token.immediate("."),
          token.immediate("replace_lane"),
          $.integer,
        ),
      ),

    // proposal: simd
    instr_plain_simd_load: $ =>
      seq(
        "v128",
        token.immediate("."),
        token.immediate("load"),
        optional(
          choice(
            seq(token.immediate(/8x8|16x4|32x2/), token.immediate(/_[su]/)),
            seq(token.immediate(/8|16|32|64/), token.immediate("_splat")),
          ),
        ),
        optional($.offset_value),
        optional($.align_value),
      ),

    // proposal: simd
    instr_plain_simd_store: $ =>
      seq(
        seq("v128", token.immediate("."), token.immediate("store")),
        optional($.offset_value),
        optional($.align_value),
      ),

    // proposal: simd
    instr_plain_simd_trinary: $ => choice(seq("v128", token.immediate("."), token.immediate("bitselect"))),

    // proposal: simd
    instr_plain_simd_unary: $ =>
      choice(
        seq(choice("f32x4", "f64x2"), token.immediate("."), token.immediate(/abs|ceil|floor|nearest|neg|splat|trunc/)),
        seq(
          choice("i8x16", "i16x8", "i32x4"),
          token.immediate("."),
          token.immediate(/abs|all_true|any_true|bitmask|neg|splat/),
        ),
        seq("i64x2", token.immediate("."), token.immediate(/neg|splat/)),
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
          optional($.offset_value),
          optional($.align_value),
        ),
      ),

    instr_plain_store: $ =>
      seq(
        choice(
          seq(choice("f32", "f64", "i32", "i64"), token.immediate("."), token.immediate("store")),
          seq(choice("i32", "i64"), token.immediate("."), token.immediate("store"), token.immediate(/(8|16)/)),
          seq("i64", token.immediate("."), token.immediate("store"), token.immediate("32")),
        ),
        // proposal: multi-memory
        optional($.index),
        optional($.offset_value),
        optional($.align_value),
      ),

    // proposal: bulk-memory-operations
    instr_plain_table_copy: $ => seq(token("table.copy"), optional(seq($.index, $.index))),

    // proposal: reference-types
    instr_plain_table_fill: $ => seq("table.fill", optional($.index)),

    // proposal: reference-types
    instr_plain_table_get: $ => seq("table.get", optional($.index)),

    // proposal: reference-types
    instr_plain_table_grow: $ => seq("table.grow", optional($.index)),

    // proposal: bulk-memory-operations
    instr_plain_table_init: $ => seq(token("table.init"), $.index, optional($.index)),

    // proposal: reference-types
    instr_plain_table_set: $ => seq("table.set", optional($.index)),

    // proposal: reference-types
    instr_plain_table_size: $ => seq("table.size", optional($.index)),

    instr_plain_test: $ => seq(choice("f32", "f64", "i32", "i64"), token.immediate("."), token.immediate(/eqz/)),

    instr_plain_unary: $ =>
      choice(
        seq(choice("i32", "i64"), token.immediate("."), token.immediate(/clz|ctz|popcnt/)),
        seq(
          choice("i32", "i64"),
          token.immediate("."),
          token.immediate("extend"),
          token.immediate(/8|16/),
          token.immediate("_"),
          token.immediate("s"),
        ),
        seq(
          "i64",
          token.immediate("."),
          token.immediate("extend"),
          token.immediate("32"),
          token.immediate("_"),
          token.immediate("s"),
        ),
        seq(choice("f32", "f64"), token.immediate("."), token.immediate(/neg|abs|sqrt|ceil|floor|trunc|nearest/)),
      ),

    instr_plain_unreachable: $ => "unreachable",

    integer: $ => seq(optional($.sign), $._nat),

    limits: $ =>
      seq(
        alias($._nat, $.min),
        alias(optional($._nat), $.max),
        // proposal: threads
        optional($.share),
      ),

    memory_fields_data: $ => seq("(", "data", repeat($.string), ")"),

    _memory_fields_type: $ => seq(optional($.inline_import), $._memory_type),

    _memory_type: $ => $.limits,

    memory_use: $ => seq("(", "memory", $.index, ")"),

    module: $ => seq("(", "module", optional(field("identifier", $.identifier)), repeat($._module_field), ")"),

    _module_field: $ =>
      choice(
        alias($.module_field_type, $.type),
        alias($.module_field_global, $.global),
        alias($.module_field_table, $.table),
        alias($.module_field_memory, $.memory),
        alias($.module_field_func, $.func),
        alias($.module_field_elem, $.elem),
        alias($.module_field_data, $.data),
        alias($.module_field_start, $.start),
        alias($.module_field_import, $.import),
        alias($.module_field_export, $.export),
      ),

    module_field_data: $ =>
      seq("(", "data", optional($.index), optional(seq(optional($.memory_use), $._offset)), repeat($.string), ")"),

    module_field_elem: $ =>
      seq(
        "(",
        "elem",
        optional($.index),
        choice(
          $.elem_list,
          seq(
            $.table_use,
            $._offset,
            choice(
              $.elem_list,
              // proposal: multi-memory
              repeat($.index),
            ),
          ),
          seq("declare", $.elem_list),
          seq($._offset, $.elem_list),
          seq($._offset, repeat($.index)),
        ),
        ")",
      ),

    module_field_export: $ => seq("(", "export", $.name, $._export_desc, ")"),

    module_field_func: $ =>
      seq(
        "(",
        "func",
        optional(field("identifier", $.identifier)),
        repeat($.inline_export),
        optional($.inline_import),
        optional($.type_use),
        repeat($._func_type_params),
        repeat($.func_type_results),
        repeat($._func_locals),
        optional($._instr_list),
        ")",
      ),

    module_field_global: $ =>
      seq(
        "(",
        "global",
        optional(field("identifier", $.identifier)),
        repeat($.inline_export),
        optional($.inline_import),
        $.global_type,
        repeat($.instr),
        ")",
      ),

    module_field_import: $ => seq("(", "import", $.name, $.name, $._import_desc, ")"),

    module_field_memory: $ =>
      seq(
        "(",
        "memory",
        optional(field("identifier", $.identifier)),
        repeat($.inline_export),
        choice(alias($.memory_fields_data, $.data), $._memory_fields_type),
        ")",
      ),

    module_field_start: $ => seq("(", "start", $.index, ")"),

    module_field_table: $ =>
      seq(
        "(",
        "table",
        optional(field("identifier", $.identifier)),
        repeat($.inline_export),
        choice($.table_fields_elem, $.table_fields_type),
        ")",
      ),

    module_field_type: $ => seq("(", "type", optional(field("identifier", $.identifier)), $._type_field, ")"),

    name: $ => $.string,

    nan: $ =>
      seq(
        "nan",
        optional(
          seq(
            token.immediate(":"),
            choice(
              token.immediate("arithmetic"),
              token.immediate("canonical"),
              seq(token.immediate("0x"), token.immediate(pattern_hex_nat)),
            ),
          ),
        ),
      ),

    _nat: $ => choice($._dec_nat, $._hex_nat),

    num: $ => choice($.integer, $.float),

    _offset: $ => choice($.offset_const_expr, $.offset_expr),

    offset_const_expr: $ => seq("(", "offset", repeat($.instr), ")"),

    offset_expr: $ => $._expr,

    offset_value: $ => seq("offset=", token.immediate(/[0-9]+(_?[0-9]+)*|0x[0-9A-Fa-f]+(_?[0-9A-Fa-f]+)*/)),

    // proposal: reference-types
    ref_kind: $ => choice(/extern|func/),

    // proposal: reference-types
    _ref_type: $ => choice($.ref_type_externref, $.ref_type_funcref, $.ref_type_ref),

    // proposal: reference-types
    ref_type_externref: $ => "externref",

    // proposal: reference-types
    ref_type_funcref: $ => "funcref",

    // proposal: function-references
    ref_type_ref: $ => seq("(", "ref", optional("null"), choice($.ref_kind, $.index), ")"),

    // eslint-disable-next-line no-useless-escape
    reserved: $ => token(choice(pattern_identifier, /[,;\[\]{}]/)),

    // proposal: threads
    share: $ => choice("shared", "unshared"),

    sign: $ => token(/[+-]/),

    string: $ =>
      seq('"', repeat(choice(token.immediate(prec(PREC.STRING, /[^"\\\n]+|\\\r?\n/)), $.escape_sequence)), '"'),

    table_fields_elem: $ =>
      seq($._ref_type, "(", "elem", choice(repeat($.index), seq($._elem_expr, repeat($._elem_expr))), ")"),

    table_fields_type: $ => seq(optional($.inline_import), $.table_type),

    table_type: $ => seq($.limits, $._ref_type),

    table_use: $ => seq("(", "table", $.index, ")"),

    _type_field: $ => seq("(", "func", repeat($._func_type), ")"),

    type_use: $ => seq("(", "type", $.index, ")"),

    value_type: $ => choice($.value_type_num_type, $._value_type_ref_type),

    value_type_num_type: $ => token(pattern_num_type),

    _value_type_ref_type: $ => $._ref_type,
  },
});
