/// <reference types="tree-sitter-cli/dsl" />

const wat = require("../wat/grammar");

module.exports = grammar(wat, {
  name: "wast",

  rules: {
    ROOT: $ => choice(repeat($.command), repeat1($.module_field)),

    action: $ => choice($.action_invoke, $.action_get),

    action_get: $ => seq("(", "get", optional($.identifier), $.name, ")"),

    action_invoke: $ => seq("(", "invoke", optional($.identifier), $.name, repeat($.expr_plain_const), ")"),

    assert_exhaustion: $ => seq("(", "assert_exhaustion", $.action, $.string, ")"),

    assert_invalid: $ => seq("(", "assert_invalid", $.script_module, $.string, ")"),

    assert_malformed: $ => seq("(", "assert_malformed", $.script_module, $.string, ")"),

    assert_return: $ => seq("(", "assert_return", $.action, repeat($.result), ")"),

    // proposal: annotations
    assert_return_arithmetic_nan: $ => seq("(", "assert_return_arithmetic_nan", $.action, repeat($.result), ")"),

    // proposal: annotations
    assert_return_canonical_nan: $ => seq("(", "assert_return_canonical_nan", $.action, repeat($.result), ")"),

    assert_trap_action: $ => seq("(", "assert_trap", $.action, $.string, ")"),

    assert_trap_module: $ => seq("(", "assert_trap", $.script_module, $.string, ")"),

    assert_unlinkable: $ => seq("(", "assert_unlinkable", $.script_module, $.string, ")"),

    assertion: $ =>
      choice(
        $.assert_malformed,
        $.assert_invalid,
        $.assert_unlinkable,
        $.assert_trap_action,
        $.assert_trap_module,
        $.assert_return,
        // proposal: annotations
        $.assert_return_canonical_nan,
        // proposal: annotations
        $.assert_return_arithmetic_nan,
        $.assert_exhaustion,
      ),

    command: $ => choice($.action, $.assertion, $.meta, $.register, $.script_module),

    expr_plain_const: $ => seq("(", choice($.op_const_ref, $.op_simd_const), ")"),

    literal_nan: $ => choice($.literal_nan_arithmetic, $.literal_nan_canonical),

    literal_nan_arithmetic: $ => "nan:arithmetic",

    literal_nan_canonical: $ => "nan:canonical",

    meta: $ => choice($.meta_script, $.meta_input, $.meta_output),

    meta_input: $ => seq("(", "input", optional($.identifier), $.string, ")"),

    meta_output: $ => seq("(", "output", optional($.identifier), optional($.string), ")"),

    meta_script: $ => seq("(", "script", optional($.identifier), repeat($.command), ")"),

    op_const_ref: $ =>
      choice(
        $.op_const,
        // proposal: reference-types
        seq("ref.null", choice($.ref_kind, $.index)),
        // proposal: reference-types
        seq("ref.extern", $.nat),
      ),

    register: $ => seq("(", "register", $.name, optional($.identifier), ")"),

    result: $ =>
      seq(
        "(",
        choice($.result_const, $.result_const_nan, $.result_ref_func, $.result_ref_extern, $.result_ref_null),
        ")",
      ),

    result_const: $ => choice($.op_const_ref, $.op_simd_const),

    result_const_nan: $ =>
      seq(choice("f32", "f64", "i32", "i64"), token.immediate("."), token.immediate("const"), $.literal_nan),

    result_ref_extern: $ => "ref.extern",

    result_ref_func: $ => "ref.func",

    result_ref_null: $ => "ref.null",

    script_module: $ => choice($.module, $.script_module_binary, $.script_module_quote),

    script_module_binary: $ => seq("(", "module", optional($.identifier), "binary", repeat($.string), ")"),

    script_module_quote: $ => seq("(", "module", optional($.identifier), "quote", repeat($.string), ")"),
  },
});
