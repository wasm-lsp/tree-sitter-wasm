const wat = require("../wat/grammar");

module.exports = grammar(wat, {
  name: "wast",

  rules: {
    PARSE: $ =>
      choice(
        repeat(field("command", $.command)),
        alias(repeat1(field("module_field", $._module_field)), $.inline_module),
      ),

    _action: $ => choice($.action_invoke, $.action_get),

    action_get: $ => seq("(", "get", optional(field("identifier", $.identifier)), field("name", $.name), ")"),

    action_invoke: $ =>
      seq(
        "(",
        "invoke",
        optional(field("identifier", $.identifier)),
        field("name", $.name),
        repeat(field("const", $._expr_plain_const)),
        ")",
      ),

    assert_exhaustion: $ => seq("(", "assert_exhaustion", field("action", $._action), field("string", $.string), ")"),

    assert_invalid: $ => seq("(", "assert_invalid", field("module", $._script_module), field("string", $.string), ")"),

    assert_malformed: $ =>
      seq("(", "assert_malformed", field("module", $._script_module), field("string", $.string), ")"),

    assert_return: $ => seq("(", "assert_return", field("action", $._action), repeat(field("result", $.result)), ")"),

    assert_trap_action: $ => seq("(", "assert_trap", field("action", $._action), field("string", $.string), ")"),

    assert_trap_module: $ => seq("(", "assert_trap", field("module", $._script_module), field("string", $.string), ")"),

    assert_unlinkable: $ =>
      seq("(", "assert_unlinkable", field("module", $._script_module), field("string", $.string), ")"),

    _assertion: $ =>
      choice(
        $.assert_exhaustion,
        $.assert_invalid,
        $.assert_malformed,
        $.assert_return,
        $.assert_trap_action,
        $.assert_trap_module,
        $.assert_unlinkable,
      ),

    command: $ => choice($._action, $._assertion, $._meta, $.register, $._script_module),

    _expr_plain_const: $ => seq("(", $.instr_plain_const, ")"),

    _expr_plain_const_nan: $ =>
      seq(
        "(",
        field("type", $._instr_type),
        token.immediate("."),
        field("op", alias(token.immediate(/const/), $.op)),
        field("literal", $._literal_nan),
        ")",
      ),

    _literal_nan: $ => choice($.literal_nan_arithmetic, $.literal_nan_canonical),

    literal_nan_arithmetic: $ => "nan:arithmetic",

    literal_nan_canonical: $ => "nan:canonical",

    _meta: $ => choice($.meta_script, $.meta_input, $.meta_output),

    meta_script: $ =>
      seq("(", "script", optional(field("identifier", $.identifier)), repeat(field("command", $.command)), ")"),

    meta_input: $ => seq("(", "input", optional(field("identifier", $.identifier)), field("string", $.string), ")"),

    meta_output: $ =>
      seq("(", "output", optional(field("identifier", $.identifier)), optional(field("string", $.string)), ")"),

    register: $ => seq("(", "register", field("name", $.name), optional(field("identifier", $.identifier)), ")"),

    result: $ => choice($._expr_plain_const, $._expr_plain_const_nan),

    _script_module: $ => choice($.module, $.script_module_binary, $.script_module_quote),

    script_module_binary: $ =>
      seq("(", "module", optional(field("identifier", $.identifier)), "binary", repeat(field("string", $.string)), ")"),

    script_module_quote: $ =>
      seq("(", "module", optional(field("identifier", $.identifier)), "quote", repeat(field("string", $.string)), ")"),
  },
});
