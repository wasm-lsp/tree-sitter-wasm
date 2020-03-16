module.exports = grammar({
  name: "webassembly",

  inline: $ => [],

  rules: {
    /***********/
    /* parsers */
    /***********/

    file: $ => choice($.module),

    _bindVar: $ => $.VAR,

    expr: $ => "expr",

    func: $ => seq($._LPAR, $._FUNC, optional($._bindVar), optional($.funcField), $._RPAR),

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

    module: $ => choice(seq($._LPAR, $._MODULE, optional($._moduleVar), repeat($.moduleField), $._RPAR)),

    moduleField: $ => choice($.func),

    _moduleVar: $ => $.VAR,

    typeUse: $ => seq($._LPAR, $._TYPE, $._var, $._RPAR),

    /**********/
    /* lexers */
    /**********/

    _digit: $ => /[0-9]/,

    _hexdigit: $ => /[0-9a-fA-F]/,

    _hexnum: $ => seq($._hexdigit, repeat(seq(optional("_"), $._hexdigit))),

    _int: $ => seq($._sign, $._nat),

    _name: $ => {
      const digit = /[0-9]/;
      const letter = /[a-zA-Z]/;
      const symbol = /[-+*/\\^~=<>!?@#$%&|:`.']/;
      return seq("$", repeat1(choice(letter, digit, "_", symbol)));
    },

    _nat: $ => choice($._num, seq("0x", $._hexnum)),

    _num: $ => seq($._digit, repeat(seq(optional("_"), $._digit))),

    _sign: $ => choice("+", "-"),

    _var: $ => choice($.NAT, $.VAR),

    /**********/
    /* tokens */
    /**********/

    _FUNC: $ => "func",

    INT: $ => $._int,

    _LPAR: $ => "(",

    _MODULE: $ => "module",

    NAT: $ => $._nat,

    _RPAR: $ => ")",

    _TYPE: $ => "type",

    VAR: $ => $._name,
  },
});
