module.exports = grammar({
  name: "webassembly_module",

  rules: {
    /***********/
    /* parsers */
    /***********/

    file: $ => choice($.module),

    _bindVar: $ => $.VAR,

    expr: $ => seq($._LPAR, $.expr1, $._RPAR),

    expr1: $ =>
      choice(
        seq($.instrPlain, repeat($.expr)),
        //
        //
        //
        //
      ),

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

    instrPlain: $ => choice(seq($.CONST, $.literal)),

    instrBlock: $ => "instrBlock",

    literal: $ => choice($.NAT, $.INT, $.FLOAT),

    module: $ => choice(seq($._LPAR, $._MODULE, optional($._moduleVar), repeat($.moduleField), $._RPAR)),

    moduleField: $ => choice($.func),

    _moduleVar: $ => $.VAR,

    typeUse: $ => seq($._LPAR, $._TYPE, $._var, $._RPAR),

    /**********/
    /* lexers */
    /**********/

    _ascii: $ => /[\x00-\x7f]/,

    _asciiNoNl: $ => /[\x00-\x09\x0b-\x7f]/,

    _character: $ =>
      choice(
        /[^"\\\x00-\x1f\x7f-\xff]/,
        $._utf8enc,
        seq("\\", $._escape),
        seq("\\", $._hexdigit, $._hexdigit),
        seq("\\u{", $._hexnum, "}"),
      ),

    _digit: $ => /[0-9]/,

    _escape: $ => /[nrt\\'"]/,

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

    _fxx: $ => seq("f", choice("32", "64")),

    _hexdigit: $ => /[0-9a-fA-F]/,

    _hexfrac: $ => $._hexnum,

    _hexnum: $ => seq($._hexdigit, repeat(seq(optional("_"), $._hexdigit))),

    _int: $ => seq($._sign, $._nat),

    _ixx: $ => seq("i", choice("32", "64")),

    _letter: $ => /[a-zA-Z]/,

    _memSize: $ => choice("8", "16", "32"),

    _mfxx: $ => seq("f", choice("32", "64")),

    _mixx: $ => seq("i", choice("8", "16", "32", "64")),

    _name: $ => seq("$", repeat1(choice($._letter, $._digit, "_", $._symbol))),

    _nat: $ => choice($._num, seq("0x", $._hexnum)),

    _nxx: $ => choice($._ixx, $._fxx),

    _num: $ => seq($._digit, repeat(seq(optional("_"), $._digit))),

    _reserved: $ => repeat1(seq(/[^"();]/, "#", $._space)),

    _sign: $ => choice("+", "-"),

    _signKind: $ => choice("s", "u"),

    _space: $ => /[\s\t\n\r]/,

    _string: $ => seq('"', repeat($._character), '"'),

    _symbol: $ => /[-+*/\\^~=<>!?@#$%&|:`.']/,

    _utf8cont: $ => /[\x80-\xbf]/,

    _utf8enc: $ =>
      choice(
        seq(/[\xc2-\xdf]/, $._utf8cont),
        seq(/[\xe0]/, /[\xa0-\xbf]/, $._utf8cont),
        seq(/[\xed]/, /[\x80-\x9f]/, $._utf8cont),
        seq(/[\xe1-\xec\xee-\xef]/, $._utf8cont, $._utf8cont),
        seq(/[\xf0]/, /[\x90-\xbf]/, $._utf8cont, $._utf8cont),
        seq(/[\xf4]/, /[\x80-\x8f]/, $._utf8cont, $._utf8cont),
        seq(/[\xf1-\xf3]/, $._utf8cont, $._utf8cont, $._utf8cont),
      ),

    _utf8: $ => choice($._ascii, $._utf8enc),

    _utf8NoNl: $ => choice($._ascii, $._utf8enc),

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
