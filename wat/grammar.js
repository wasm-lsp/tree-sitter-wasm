module.exports = grammar({
  name: "wat",

  extras: $ => [],

  rules: {
    start: $ => seq(repeat($._space), $.module, repeat($._space)),

    // ====================================================== //
    // =================== Lexical Format =================== //
    // ====================================================== //

    /**************
     * Whitespace *
     **************/

    _space: $ => choice(" ", $._format, $._comment),

    _format: $ => /[\t\n\r]/,

    /************
     * Comments *
     ************/

    _comment: $ => choice($.linecomment, $.blockcomment),

    linecomment: $ => seq(";;", repeat($._linechar), "\n"),

    _linechar: $ => $._utf8line,

    blockcomment: $ => seq("(;", repeat($._blockchar), ";)"),

    // FIXME: this is more liberal than the spec
    _blockchar: $ => choice(/[^;(]/, /;[^)]/, /\([^;]/, $.blockcomment),

    // ====================================================== //
    // ======================= Tokens ======================= //
    // ====================================================== //

    _FUNC: $ => seq(repeat($._space), "func"),

    _FUNCREF: $ => seq(repeat($._space), "funcref"),

    _LPAR: $ => seq(repeat($._space), "("),

    _MODULE: $ => seq(repeat($._space), "module"),

    _MUT: $ => seq(repeat($._space), "mut"),

    _PARAM: $ => seq(repeat($._space), "param"),

    _RESULT: $ => seq(repeat($._space), "result"),

    _RPAR: $ => seq(repeat($._space), ")"),

    _TYPE: $ => seq(repeat($._space), "type"),

    // ====================================================== //
    // ======================= Values ======================= //
    // ====================================================== //

    /************
     * Integers *
     ************/

    _sign: $ => /[+-]/,

    _digit: $ => /[0-9]/,

    _hexdigit: $ => /[0-9A-Fa-f]/,

    _num: $ => choice($._digit, seq($._num, optional("_"), $._digit)),

    _hexnum: $ => choice($._hexdigit, seq($._hexnum, optional("_"), $._hexdigit)),

    _uN: $ => choice($._num, seq("0x", $._hexnum)),

    _sN: $ => choice(seq(optional($._sign), $._num), seq(optional($._sign), "0x", $._hexnum)),

    _iN: $ => choice($._uN, $._sN),

    uN: $ => seq(repeat($._space), $._uN),

    /******************
     * Floating-Point *
     ******************/

    _frac: $ => choice(seq($._digit, optional($._frac)), seq($._digit, "_", $._digit, optional($._frac))),

    _hexfrac: $ =>
      choice(seq($._hexdigit, optional($._hexfrac)), seq($._hexdigit, "_", $._hexdigit, optional($._hexfrac))),

    _float: $ =>
      choice(
        $._num,
        seq($._num, ".", optional($._frac)),
        seq($._num, /[Ee]/, optional($._sign), $._num),
        seq($._num, ".", optional($._frac), /[Ee]/, optional($._sign), $._num),
      ),

    _hexfloat: $ =>
      choice(
        seq("0x", $._hexnum),
        seq("0x", $._hexnum, ".", optional($._hexfrac)),
        seq("0x", $._hexnum, /[Pp]/, optional($._sign), $._num),
        seq("0x", $._hexnum, ".", optional($._hexfrac), /[Pp]/, optional($._sign), $._num),
      ),

    _fN: $ => seq(optional($._sign), $._fNmag),

    _fNmag: $ => choice($._float, $._hexfloat, "inf", "nan", seq("nan:0x", $._hexnum)),

    /**********
     * String *
     **********/

    _string: $ => seq('"', repeat($._stringelem), '"'),

    // FIXME: using $._hexdigit here seems to allow invalid parses: "\00\gf"
    _stringelem: $ => choice($._stringchar, /\\[0-9A-Fa-f][0-9A-Fa-f]/),

    _stringchar: $ => choice($._char, seq("\\", /[tnr"'\\]/), seq("\\u{", $._hexnum, "}")),

    _char: $ => choice(/[^"\\\x00-\x1f\x7f-\xff]/, $._utf8enc),

    _ascii: $ => /[\x00-\x7f]/,

    _asciiline: $ => /[\x00-\x09\x0b-\x7f]/,

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

    _utf8line: $ => choice($._asciiline, $._utf8enc),

    /*********
     * Names *
     *********/

    _name: $ => $._string,

    /***************
     * Identifiers *
     ***************/

    _id: $ => seq("$", repeat1($._idchar)),

    _idchar: $ => /[0-9A-Za-z!#$%&'*+-./:<=>?@\\^_'|~]/,

    id: $ => seq(repeat($._space), $._id),

    // ====================================================== //
    // ======================== Types ======================= //
    // ====================================================== //

    valtype: $ => seq(repeat($._space), choice("i32", "i64", "f32", "f64")),

    /****************
     * Result Types *
     ****************/

    resulttype: $ => $.result,

    /******************
     * Function Types *
     ******************/

    functype: $ => seq($._LPAR, $._FUNC, repeat($.param), repeat($.result), $._RPAR),

    param: $ =>
      choice(
        // NOTE: re-factored to avoid conflict with abbreviation
        seq($._LPAR, $._PARAM, optional(seq($.id, $.valtype)), $._RPAR),
        // abbreviation
        seq($._LPAR, $._PARAM, repeat($.valtype), $._RPAR),
      ),

    result: $ => seq($._LPAR, $._RESULT, repeat($.valtype), $._RPAR),

    /**********
     * Limits *
     **********/

    limits: $ => choice($.uN, seq($.uN, $.uN)),

    /****************
     * Memory Types *
     ****************/

    memtype: $ => $.limits,

    /***************
     * Table Types *
     ***************/

    tabletype: $ => seq($.limits, $.elemtype),

    elemtype: $ => $._FUNCREF,

    /****************
     * Global Types *
     ****************/

    globaltype: $ => choice($.valtype, seq($._LPAR, $._MUT, $.valtype, $._RPAR)),

    // ====================================================== //
    // ======================= Modules ====================== //
    // ====================================================== //

    /***********
     * Indices *
     ***********/

    typeidx: $ => choice($.uN, $.id),

    funcidx: $ => choice($.uN, $.id),

    tableidx: $ => choice($.uN, $.id),

    memidx: $ => choice($.uN, $.id),

    globalidx: $ => choice($.uN, $.id),

    localidx: $ => choice($.uN, $.id),

    labellidx: $ => choice($.uN, $.id),

    /*********
     * Types *
     *********/

    type: $ => seq($._LPAR, $._TYPE, optional($.id), $.functype, $._RPAR),


    module: $ => seq("(", repeat($._space), "module", repeat($._space), optional(seq($._id, repeat($._space))), ")"),
  },
});
