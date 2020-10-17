/// <reference types="tree-sitter-cli/dsl" />

const wat = require("../wat/grammar");

module.exports = grammar(wat, {
  name: "wast",

  rules: {
    ROOT: $ => choice(repeat($._command), repeat1($._module_field)),

    _action: $ => choice($.action_invoke, $.action_get),

    action_get: $ => seq("(", "get", optional($.identifier), $.name, ")"),

    action_invoke: $ => seq("(", "invoke", optional($.identifier), $.name, repeat($._expr_plain_const), ")"),

    assert_exhaustion: $ => seq("(", "assert_exhaustion", $._action, $._string, ")"),

    assert_invalid: $ => seq("(", "assert_invalid", $._script_module, $._string, ")"),

    assert_malformed: $ => seq("(", "assert_malformed", $._script_module, $._string, ")"),

    assert_return: $ => seq("(", "assert_return", $._action, repeat($._result), ")"),

    // proposal: annotations
    assert_return_arithmetic_nan: $ => seq("(", "assert_return_arithmetic_nan", $._action, repeat($._result), ")"),

    // proposal: annotations
    assert_return_canonical_nan: $ => seq("(", "assert_return_canonical_nan", $._action, repeat($._result), ")"),

    assert_trap_action: $ => seq("(", "assert_trap", $._action, $._string, ")"),

    assert_trap_module: $ => seq("(", "assert_trap", $._script_module, $._string, ")"),

    assert_unlinkable: $ => seq("(", "assert_unlinkable", $._script_module, $._string, ")"),

    _assertion: $ =>
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

    _command: $ => choice($._action, $._assertion, $._meta, $.register, $._script_module),

    _expr_plain_const: $ => seq("(", choice($.op_const, $.op_simd_const), ")"),

    _literal_nan: $ => choice($.literal_nan_arithmetic, $.literal_nan_canonical),

    literal_nan_arithmetic: $ => "nan:arithmetic",

    literal_nan_canonical: $ => "nan:canonical",

    _meta: $ => choice($.meta_script, $.meta_input, $.meta_output),

    meta_script: $ => seq("(", "script", optional($.identifier), repeat($._command), ")"),

    meta_input: $ => seq("(", "input", optional($.identifier), $._string, ")"),

    meta_output: $ => seq("(", "output", optional($.identifier), optional($._string), ")"),

    register: $ => seq("(", "register", $.name, optional($.identifier), ")"),

    _result: $ =>
      seq(
        "(",
        choice($.result_const, $.result_const_nan, $.result_ref_func, $.result_ref_extern, $.result_ref_null),
        ")",
      ),

    result_const: $ => choice($.op_const, $.op_simd_const),

    result_const_nan: $ =>
      seq(choice("f32", "f64", "i32", "i64"), token.immediate("."), token.immediate(/const/), $._literal_nan),

    result_ref_func: $ => "ref.func",

    result_ref_extern: $ => "ref.extern",

    result_ref_null: $ => "ref.null",

    _script_module: $ => choice($.module, $.script_module_binary, $.script_module_quote),

    script_module_binary: $ => seq("(", "module", optional($.identifier), "binary", repeat($._string), ")"),

    script_module_quote: $ => seq("(", "module", optional($.identifier), "quote", repeat($._string), ")"),
  },
});
