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
        $.funcFieldBody,
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

    literal: $ => choice($.NAT, $.INT, $.FLOAT),

    module: $ => choice(seq($._LPAR, $._MODULE, optional($._moduleVar), repeat($.moduleField), $._RPAR)),

    moduleField: $ => choice($.func),

    _moduleVar: $ => $.VAR,

    typeUse: $ => seq($._LPAR, $._TYPE, $._var, $._RPAR),

    /**********/
    /* lexers */
    /**********/

    _digit: $ => /[0-9]/,

    _float: $ =>
      choice(
        seq(optional($._sign), $._num, ".", optional($._frac)),
        seq(
          optional($._sign),
          $._num,
          optional(seq(".", optional($._frac))),
          choice("e", "E"),
          optional($._sign),
          $._num,
        ),
        seq(optional($._sign), "0x", $._hexnum, ".", optional($._hexfrac)),
        seq(
          optional($._sign),
          "0x",
          $._hexnum,
          optional(seq(".", optional($._hexfrac))),
          choice("p", "P"),
          optional($._sign),
          $._num,
        ),
        seq(optional($._sign), "inf"),
        seq(optional($._sign), "nan"),
        seq(optional($._sign), "nan:", "0x", $._hexnum),
      ),

    _frac: $ => $._num,

    _hexdigit: $ => /[0-9a-fA-F]/,

    _hexfrac: $ => $._hexnum,

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

    CONST: $ => "const",

    FLOAT: $ => $._float,

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
