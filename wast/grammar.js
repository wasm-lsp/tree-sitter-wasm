const wat = require("../wat/grammar");

module.exports = grammar(wat, {
  name: "wast",

  rules: {
    ENTRYPOINT: $ => alias(repeat(field("command", $.command)), "script"),

    // ====================================================== //
    // ======================= Script ======================= //
    // ====================================================== //

    // NOTE: we inline this because it matches the empty string
    // script: $ => repeat($.command),

    // ====================================================== //
    // ====================== Commands ====================== //
    // ====================================================== //

    command: $ => choice($._module_ext, $.register, $._action, $._assertion, $._meta),

    register: $ => seq("(", "register", field("name", $.name), field("id", optional($.id)), ")"),

    // ====================================================== //
    // ================== Module Extensions ================= //
    // ====================================================== //

    _module_ext: $ => choice($.module, $.module_binary, $.module_quote),

    module_binary: $ => seq("(", $.MODULE, optional(field("id", $.id)), "binary", repeat(field("data", $.string)), ")"),

    module_quote: $ => seq("(", $.MODULE, optional(field("id", $.id)), "quote", repeat(field("data", $.string)), ")"),

    // ====================================================== //
    // ======================= Actions ====================== //
    // ====================================================== //

    _action: $ => choice($.action_get, $.action_invoke),

    action_get: $ => seq("(", "get", optional(field("id", $.id)), field("name", $.name), ")"),

    action_invoke: $ =>
      seq("(", "invoke", optional(field("id", $.id)), field("name", $.name), repeat(field("instr", $._instr)), ")"),

    // ====================================================== //
    // ===================== Assertions ===================== //
    // ====================================================== //

    _assertion: $ =>
      choice(
        $.assertion_return,
        $.assertion_trap_action,
        $.assertion_exhaustion,
        $.assertion_malformed,
        $.assertion_invalid,
        $.assertion_unlinkable,
        $.assertion_trap_module,
      ),

    assertion_return: $ =>
      seq("(", "assert_return", field("action", $._action), field("result", repeat($.result_value)), ")"),

    assertion_trap_action: $ => seq("(", "assert_trap", field("action", $._action), field("failure", $.string), ")"),

    assertion_exhaustion: $ =>
      seq("(", "assert_exhaustion", field("action", $._action), field("failure", $.string), ")"),

    assertion_malformed: $ =>
      seq("(", "assert_malformed", field("module", $._module_ext), field("failure", $.string), ")"),

    assertion_invalid: $ => seq("(", "assert_invalid", field("module", $._module_ext), field("failure", $.string), ")"),

    assertion_unlinkable: $ =>
      seq("(", "assert_unlinkable", field("module", $._module_ext), field("failure", $.string), ")"),

    assertion_trap_module: $ =>
      seq("(", "assert_trap", field("module", $._module_ext), field("failure", $.string), ")"),

    // ====================================================== //
    // ======================= Results ====================== //
    // ====================================================== //

    result_value: $ => seq("(", field("const", choice($.I32_CONST, $.I64_CONST, $.F32_CONST, $.F64_CONST)), ")"),

    _numpat: $ => choice($.iN, $.fN, $.numpat_nan_canonical, $.numpat_nan_arithmetic),

    numpat_nan_canonical: $ => "nan:canonical",

    numpat_nan_arithmetic: $ => "nan:arithmetic",

    // ====================================================== //
    // ==================== Meta-Commands =================== //
    // ====================================================== //

    _meta: $ => choice($.meta_script, $.meta_input, $.meta_output),

    meta_script: $ =>
      seq("(", "script", optional(field("id", $.id)), field("script", alias(repeat($.command), "script")), ")"),

    meta_input: $ => seq("(", "input", optional(field("id", $.id)), field("file", $.string), ")"),

    meta_output: $ => seq("(", "output", optional(field("id", $.id)), optional(field("file", $.string)), ")"),
  },
});
