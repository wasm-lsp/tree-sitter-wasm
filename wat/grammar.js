module.exports = grammar({
  name: "wat",

  extras: $ => [],

  rules: {
    ENTRYPOINT: $ => seq(field("module", $.module), repeat($._space)),

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

    _BLOCK: $ => seq(repeat($._space), "block"),

    _BR: $ => seq(repeat($._space), "br"),

    _BR_IF: $ => seq(repeat($._space), "br_if"),

    _BR_TABLE: $ => seq(repeat($._space), "br_table"),

    _CALL: $ => seq(repeat($._space), "call"),

    _CALL_INDIRECT: $ => seq(repeat($._space), "call_indirect"),

    _DATA: $ => seq(repeat($._space), "data"),

    _ELEM: $ => seq(repeat($._space), "elem"),

    _ELSE: $ => seq(repeat($._space), "else"),

    _END: $ => seq(repeat($._space), "end"),

    _EXPORT: $ => seq(repeat($._space), "export"),

    _FUNC: $ => seq(repeat($._space), "func"),

    _FUNCREF: $ => seq(repeat($._space), "funcref"),

    _GLOBAL: $ => seq(repeat($._space), "global"),

    _IF: $ => seq(repeat($._space), "if"),

    _IMPORT: $ => seq(repeat($._space), "import"),

    _LOCAL: $ => seq(repeat($._space), "local"),

    _LOOP: $ => seq(repeat($._space), "loop"),

    _LEFT_PARENTHESIS: $ => seq(repeat($._space), "("),

    _MEMORY: $ => seq(repeat($._space), "memory"),

    _MODULE: $ => seq(repeat($._space), "module"),

    _MUT: $ => seq(repeat($._space), "mut"),

    _NOP: $ => seq(repeat($._space), "nop"),

    _OFFSET: $ => seq(repeat($._space), "offset"),

    _PARAM: $ => seq(repeat($._space), "param"),

    _RESULT: $ => seq(repeat($._space), "result"),

    _RETURN: $ => seq(repeat($._space), "return"),

    _RIGHT_PARENTHESIS: $ => seq(repeat($._space), ")"),

    _START: $ => seq(repeat($._space), "start"),

    _TABLE: $ => seq(repeat($._space), "table"),

    _TYPE: $ => seq(repeat($._space), "type"),

    _UNREACHABLE: $ => seq(repeat($._space), "unreachable"),

    // ====================================================== //
    // ======================= Values ======================= //
    // ====================================================== //

    /************
     * Integers *
     ************/

    _sign: $ => /[+-]/,

    _digit: $ => /[0-9]/,

    _hexdigit: $ => /[0-9A-Fa-f]/,

    _num: $ => /[0-9]|[0-9]+(?:_?[0-9]+)*/,

    _hexnum: $ => /[0-9A-Fa-f]|[0-9A-Fa-f]+(?:_?[0-9A-Fa-f]+)*/,

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

    name: $ => seq(repeat($._space), $._name),

    /***************
     * Identifiers *
     ***************/

    idtrimmed: $ => /\$[0-9A-Za-z!#$%&'*+-./:<=>?@\\^_'|~]+/,

    id: $ => seq(repeat($._space), field("trim", $.idtrimmed)),

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

    functype: $ => seq($._LEFT_PARENTHESIS, $._FUNC, repeat($.param), repeat($.result), $._RIGHT_PARENTHESIS),

    param: $ =>
      choice(
        // NOTE: re-factored to avoid conflict with abbreviation
        seq($._LEFT_PARENTHESIS, $._PARAM, optional(seq($.id, $.valtype)), $._RIGHT_PARENTHESIS),
        // abbreviation
        seq($._LEFT_PARENTHESIS, $._PARAM, repeat1($.valtype), $._RIGHT_PARENTHESIS),
      ),

    result: $ => seq($._LEFT_PARENTHESIS, $._RESULT, repeat($.valtype), $._RIGHT_PARENTHESIS),

    /**********
     * Limits *
     **********/

    limits: $ => prec.left(seq($.uN, optional(seq($._space, $._uN)))),

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

    globaltype: $ => choice($.valtype, seq($._LEFT_PARENTHESIS, $._MUT, $.valtype, $._RIGHT_PARENTHESIS)),

    // ====================================================== //
    // ==================== Instructions ==================== //
    // ====================================================== //

    instr: $ => choice($.plaininstr, $.blockinstr),

    /**********
     * Labels *
     **********/

    // NOTE: we inline this because it matches the empty string
    // label: $ => optional($.id),

    /************************
     * Control Instructions *
     ************************/

    blockinstr: $ =>
      choice(
        prec.right(
          seq($._BLOCK, alias(optional($.id), "label"), $.resulttype, repeat($.instr), $._END, optional($.id)),
        ),
        prec.right(seq($._LOOP, alias(optional($.id), "label"), $.resulttype, repeat($.instr), $._END, optional($.id))),
        prec.right(
          seq(
            $._IF,
            alias(optional($.id), "label"),
            $.resulttype,
            repeat($.instr),
            choice(
              seq($._ELSE, optional($.id), repeat($.instr), $._END, optional($.id)),
              // abbreviation
              $._END,
            ),
          ),
        ),
      ),

    plaininstr: $ =>
      choice(
        $._UNREACHABLE,
        $._NOP,
        seq($._BR, $.labelidx),
        seq($._BR_IF, $.labelidx),
        prec.right(1, seq($._BR_TABLE, repeat($.labelidx), $.labelidx)),
        $._RETURN,
        seq($._CALL, $.funcidx),
        prec.right(
          seq(
            $._CALL_INDIRECT,
            alias(
              seq(
                optional(seq($._LEFT_PARENTHESIS, $._TYPE, $.typeidx, $._RIGHT_PARENTHESIS)),
                repeat($.param),
                repeat($.result),
              ),
              "typeuse",
            ),
          ),
        ),

        /***************************
         * Parametric Instructions *
         ***************************/

        /*************************
         * Variable Instructions *
         *************************/

        /***********************
         * Memory Instructions *
         ***********************/

        /************************
         * Numeric Instructions *
         ************************/
      ),

    /***********************
     * Folded Instructions *
     ***********************/

    /***************
     * Expressions *
     ***************/

    // NOTE: we inline this because it matches the empty string
    // expr: $ => repeat($.instr),

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

    labelidx: $ => choice($.uN, $.id),

    /*********
     * Types *
     *********/

    type: $ => seq($._LEFT_PARENTHESIS, $._TYPE, field("id", optional($.id)), $.functype, $._RIGHT_PARENTHESIS),

    /*************
     * Type Uses *
     *************/

    // NOTE: we inline this because it matches the empty string
    // typeuse: $ => seq(optional(seq($._LEFT_PARENTHESIS, $._TYPE, $.typeidx, $._RIGHT_PARENTHESIS)), repeat($.param), repeat($.result)),

    /***********
     * Imports *
     ***********/

    import: $ => seq($._LEFT_PARENTHESIS, $._IMPORT, $.name, $.name, $._importdesc, $._RIGHT_PARENTHESIS),

    _importdesc: $ =>
      choice(
        seq(
          $._LEFT_PARENTHESIS,
          $._FUNC,
          optional($.id),
          // NOTE: see typeuse
          alias(
            seq(
              optional(seq($._LEFT_PARENTHESIS, $._TYPE, $.typeidx, $._RIGHT_PARENTHESIS)),
              repeat($.param),
              repeat($.result),
            ),
            "typeuse",
          ),
          $._RIGHT_PARENTHESIS,
        ),
        seq($._LEFT_PARENTHESIS, $._TABLE, optional($.id), $.tabletype, $._RIGHT_PARENTHESIS),
        seq($._LEFT_PARENTHESIS, $._MEMORY, optional($.id), $.memtype, $._RIGHT_PARENTHESIS),
        seq($._LEFT_PARENTHESIS, $._GLOBAL, optional($.id), $.globaltype, $._RIGHT_PARENTHESIS),
      ),

    /*************
     * Functions *
     *************/

    func: $ =>
      choice(
        seq(
          $._LEFT_PARENTHESIS,
          $._FUNC,
          field("id", optional($.id)),
          // abbreviation
          optional(seq($.inlineExport, repeat(choice($.inlineImport, $.inlineExport)))),
          alias(
            seq(
              optional(seq($._LEFT_PARENTHESIS, $._TYPE, $.typeidx, $._RIGHT_PARENTHESIS)),
              repeat($.param),
              repeat($.result),
            ),
            "typeuse",
          ),
          repeat($.local),
          repeat($.instr),
          $._RIGHT_PARENTHESIS,
        ),
        // abbreviation
        seq(
          $._LEFT_PARENTHESIS,
          $._FUNC,
          field("id", optional($.id)),
          $.inlineImport,
          alias(
            seq(
              optional(seq($._LEFT_PARENTHESIS, $._TYPE, $.typeidx, $._RIGHT_PARENTHESIS)),
              repeat($.param),
              repeat($.result),
            ),
            "typeuse",
          ),
          $._RIGHT_PARENTHESIS,
        ),
      ),

    local: $ =>
      choice(
        // NOTE: re-factored to avoid conflict with abbreviation
        seq($._LEFT_PARENTHESIS, $._LOCAL, optional(seq($.id, $.valtype)), $._RIGHT_PARENTHESIS),
        // abbreviation
        seq($._LEFT_PARENTHESIS, $._LOCAL, repeat1($.valtype), $._RIGHT_PARENTHESIS),
      ),

    inlineImport: $ => seq($._LEFT_PARENTHESIS, $._IMPORT, $.name, $.name, $._RIGHT_PARENTHESIS),

    inlineExport: $ => seq($._LEFT_PARENTHESIS, $._EXPORT, $.name, $._RIGHT_PARENTHESIS),

    /**********
     * Tables *
     **********/

    table: $ =>
      choice(
        seq(
          $._LEFT_PARENTHESIS,
          $._TABLE,
          optional($.id),
          // abbreviation
          optional(seq($.inlineExport, repeat(choice($.inlineImport, $.inlineExport)))),
          choice(
            $.tabletype,
            // abbreviation
            // NOTE: are inline element segments allowed after inline imports?
            seq($.elemtype, $._LEFT_PARENTHESIS, $._ELEM, repeat($.funcidx), $._RIGHT_PARENTHESIS),
          ),
          $._RIGHT_PARENTHESIS,
        ),
        seq(
          $._LEFT_PARENTHESIS,
          $._TABLE,
          optional($.id),
          // abbreviation
          $.inlineImport,
          choice(
            $.tabletype,
            // abbreviation
            // NOTE: are inline element segments allowed after inline imports?
            seq($.elemtype, $._LEFT_PARENTHESIS, $._ELEM, repeat($.funcidx), $._RIGHT_PARENTHESIS),
          ),
          $._RIGHT_PARENTHESIS,
        ),
      ),

    /************
     * Memories *
     ************/

    mem: $ =>
      choice(
        seq(
          $._LEFT_PARENTHESIS,
          $._MEMORY,
          optional($.id),
          // abbreviation
          optional(seq($.inlineExport, repeat(choice($.inlineImport, $.inlineExport)))),
          choice(
            $.memtype,
            // abbreviation
            seq($._LEFT_PARENTHESIS, $._DATA, alias(repeat($._string), "datastring"), $._RIGHT_PARENTHESIS),
          ),
          $._RIGHT_PARENTHESIS,
        ),
        seq(
          $._LEFT_PARENTHESIS,
          optional($.id),
          // abbreviation
          $.inlineImport,
          choice(
            $.memtype,
            // abbreviation
            seq($._LEFT_PARENTHESIS, $._DATA, alias(repeat($._string), "datastring"), $._RIGHT_PARENTHESIS),
          ),
          $._RIGHT_PARENTHESIS,
        ),
      ),

    /***********
     * Globals *
     ***********/

    global: $ =>
      choice(
        seq(
          $._LEFT_PARENTHESIS,
          $._GLOBAL,
          optional($.id),
          // abbreviation
          optional(seq($.inlineExport, repeat(choice($.inlineImport, $.inlineExport)))),
          $.globaltype,
          alias(repeat($.instr), "expr"),
          $._RIGHT_PARENTHESIS,
        ),
        seq(
          $._LEFT_PARENTHESIS,
          $._GLOBAL,
          optional($.id),
          // abbreviation
          $.inlineImport,
          $.globaltype,
          $._RIGHT_PARENTHESIS,
        ),
      ),

    /***********
     * Exports *
     ***********/

    export: $ => seq($._LEFT_PARENTHESIS, $.name, $.exportdesc, $._RIGHT_PARENTHESIS),

    exportdesc: $ =>
      choice(
        seq($._LEFT_PARENTHESIS, $._FUNC, $.funcidx, $._RIGHT_PARENTHESIS),
        seq($._LEFT_PARENTHESIS, $._TABLE, $.tableidx, $._RIGHT_PARENTHESIS),
        seq($._LEFT_PARENTHESIS, $._MEMORY, $.memidx, $._RIGHT_PARENTHESIS),
        seq($._LEFT_PARENTHESIS, $._GLOBAL, $.globalidx, $._RIGHT_PARENTHESIS),
      ),

    /******************
     * Start Function *
     ******************/

    start: $ => seq($._LEFT_PARENTHESIS, $._START, $.funcidx, $._RIGHT_PARENTHESIS),

    /********************
     * Element Segments *
     ********************/

    elem: $ =>
      seq(
        $._LEFT_PARENTHESIS,
        $._ELEM,
        optional($.tableidx),
        choice(
          seq($._LEFT_PARENTHESIS, alias(repeat($.instr), "expr"), $._RIGHT_PARENTHESIS),
          // abbreviation
          $.instr,
        ),
        repeat($.funcidx),
        $._RIGHT_PARENTHESIS,
      ),

    /*****************
     * Data Segments *
     *****************/

    data: $ =>
      seq(
        $._LEFT_PARENTHESIS,
        $._DATA,
        optional($.memidx),
        choice(
          seq($._LEFT_PARENTHESIS, $._OFFSET, alias(repeat($.instr), "expr"), $._RIGHT_PARENTHESIS),
          // abbreviation
          $.instr,
        ),
        alias(repeat($._string), "datastring"),
        $._RIGHT_PARENTHESIS,
      ),

    // NOTE: we inline this because it matches the empty string
    // datastring: $ => repeat($._string),

    /***********
     * Modules *
     ***********/

    module: $ =>
      seq(
        $._LEFT_PARENTHESIS,
        $._MODULE,
        field("id", optional($.id)),
        repeat(field("modulefield", $._modulefield)),
        $._RIGHT_PARENTHESIS,
      ),

    _modulefield: $ => choice($.type, $.import, $.func, $.table, $.mem, $.global, $.export, $.start, $.elem, $.data),
  },
});
