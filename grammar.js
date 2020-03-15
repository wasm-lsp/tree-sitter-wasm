module.exports = grammar({
  name: "webassembly",

  inline: $ => [],

  rules: {
    file: $ => choice($.module),

    _bindVar: $ => $.VAR,

    expr: $ => "expr",

    func: $ => seq("(", "func", optional($._bindVar), optional($.funcField), ")"),

    funcBody: $ =>
      choice(
        repeat1($.instr),
        //
        //
      ),

    funcField: $ =>
      choice(
        seq($.typeUse, optional($.funcFieldBody)),
        seq($.inlineImport, $.typeUse, $.funcFieldImport),
        seq($.inlineImport, $.funcFieldImport),
        seq($.inlineExport, $.funcField),
      ),

    funcFieldBody: $ =>
      choice(
        $.funcResultBody,
        //
        //
      ),

    funcFieldImport: $ => "funcFieldImport",

    funcResultBody: $ =>
      choice(
        $.funcBody,
        //
        //
      ),

    inlineExport: $ => "inlineExport",

    inlineImport: $ => "inlineImport",

    instr: $ => choice($.instrCall, $.instrPlain, $.instrBlock, $.expr),

    instrCall: $ => "instrCall",

    instrPlain: $ => "instrPlain",

    instrBlock: $ => "instrBlock",

    module: $ => choice(seq("(", "module", optional($._moduleVar), repeat($.moduleField), ")")),

    moduleField: $ => choice($.func),

    _moduleVar: $ => $.VAR,

    typeUse: $ => seq("(", "type", $._var, ")"),

    // terminal

    NAT: $ => {
      const numeric = /[0-9]+/;
      return token(numeric);
    },

    VAR: $ => $._name,

    // lexical

    _digit: $ => /[0-9]/,

    _hexdigit: $ => /[0-9a-fA-F]/,

    _hexnum: $ => seq($._hexdigit, repeat(seq(optional("_"), $._hexdigit))),

    _name: $ => {
      const digit = /[0-9]/;
      const letter = /[a-zA-Z]/;
      const symbol = /[-+*/\\^~=<>!?@#$%&|:`.']/;
      return seq("$", repeat1(choice(letter, digit, "_", symbol)));
    },

    _nat: $ => choice($._num, seq("0x", $._hexnum)),

    _num: $ => seq($._digit, repeat(seq(optional("_"), $._digit))),

    _var: $ => choice($.NAT, $.VAR),
  },
});
