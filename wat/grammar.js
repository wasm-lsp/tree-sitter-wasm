module.exports = grammar({
  name: "wat",

  // NOTE: The default value of `extras` for tree-sitter grammars includes
  // whitespace. However, we want to handle whitespace directly through the
  // grammar defined below so we override this value.
  extras: $ => [],

  conflicts: $ => [[$.blockinstr], [$.limits], [$.plaininstr], [$.foldedinstr, $.instr]],

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

    _blockchar: $ => choice(/[^;(]/, /;[^)]/, /\([^;]/, $.blockcomment),

    // ====================================================== //
    // ======================= Tokens ======================= //
    // ====================================================== //

    _ALIGN_EQ: $ => seq(repeat($._space), "align="),
    _BLOCK: $ => seq(repeat($._space), "block"),
    _BR: $ => seq(repeat($._space), "br"),
    _BR_IF: $ => seq(repeat($._space), "br_if"),
    _BR_TABLE: $ => seq(repeat($._space), "br_table"),
    _CALL: $ => seq(repeat($._space), "call"),
    _CALL_INDIRECT: $ => seq(repeat($._space), "call_indirect"),
    _DATA: $ => seq(repeat($._space), "data"),
    _DROP: $ => seq(repeat($._space), "drop"),
    _ELEM: $ => seq(repeat($._space), "elem"),
    _ELSE: $ => seq(repeat($._space), "else"),
    _END: $ => seq(repeat($._space), "end"),
    _EXPORT: $ => seq(repeat($._space), "export"),
    _F32_ABS: $ => seq(repeat($._space), "f32.abs"),
    _F32_ADD: $ => seq(repeat($._space), "f32.add"),
    _F32_CEIL: $ => seq(repeat($._space), "f32.ceil"),
    _F32_CONVERT_I32_S: $ => seq(repeat($._space), "f32.convert_i32_s"),
    _F32_CONVERT_I32_U: $ => seq(repeat($._space), "f32.convert_i32_u"),
    _F32_CONVERT_I64_S: $ => seq(repeat($._space), "f32.convert_i64_s"),
    _F32_CONVERT_I64_U: $ => seq(repeat($._space), "f32.convert_i64_u"),
    _F32_CONST: $ => seq(repeat($._space), "f32.const"),
    _F32_COPYSIGN: $ => seq(repeat($._space), "f32.copysign"),
    _F32_DEMOTE_F64: $ => seq(repeat($._space), "f32.demote_f64"),
    _F32_DIV: $ => seq(repeat($._space), "f32.div"),
    _F32_EQ: $ => seq(repeat($._space), "f32.eq"),
    _F32_FLOOR: $ => seq(repeat($._space), "f32.floor"),
    _F32_GE: $ => seq(repeat($._space), "f32.ge"),
    _F32_GT: $ => seq(repeat($._space), "f32.gt"),
    _F32_LE: $ => seq(repeat($._space), "f32.le"),
    _F32_LOAD: $ => seq(repeat($._space), "f32.load"),
    _F32_LT: $ => seq(repeat($._space), "f32.lt"),
    _F32_MAX: $ => seq(repeat($._space), "f32.max"),
    _F32_MIN: $ => seq(repeat($._space), "f32.min"),
    _F32_MUL: $ => seq(repeat($._space), "f32.mul"),
    _F32_NE: $ => seq(repeat($._space), "f32.ne"),
    _F32_NEAREST: $ => seq(repeat($._space), "f32.nearest"),
    _F32_NEG: $ => seq(repeat($._space), "f32.neg"),
    _F32_REINTERPRET_I32: $ => seq(repeat($._space), "f32.reinterpret_i32"),
    _F32_REINTERPRET_I64: $ => seq(repeat($._space), "f32.reinterpret_i64"),
    _F32_SQRT: $ => seq(repeat($._space), "f32.sqrt"),
    _F32_STORE: $ => seq(repeat($._space), "f32.store"),
    _F32_SUB: $ => seq(repeat($._space), "f32.sub"),
    _F32_TRUNC: $ => seq(repeat($._space), "f32.trunc"),
    _F64_ABS: $ => seq(repeat($._space), "f64.abs"),
    _F64_ADD: $ => seq(repeat($._space), "f64.add"),
    _F64_CEIL: $ => seq(repeat($._space), "f64.ceil"),
    _F64_CONST: $ => seq(repeat($._space), "f64.const"),
    _F64_CONVERT_I32_S: $ => seq(repeat($._space), "f64.convert_i32_s"),
    _F64_CONVERT_I32_U: $ => seq(repeat($._space), "f64.convert_i32_u"),
    _F64_CONVERT_I64_S: $ => seq(repeat($._space), "f64.convert_i64_s"),
    _F64_CONVERT_I64_U: $ => seq(repeat($._space), "f64.convert_i64_u"),
    _F64_COPYSIGN: $ => seq(repeat($._space), "f64.copysign"),
    _F64_DIV: $ => seq(repeat($._space), "f64.div"),
    _F64_EQ: $ => seq(repeat($._space), "f64.eq"),
    _F64_FLOOR: $ => seq(repeat($._space), "f64.floor"),
    _F64_GE: $ => seq(repeat($._space), "f64.ge"),
    _F64_GT: $ => seq(repeat($._space), "f64.gt"),
    _F64_LE: $ => seq(repeat($._space), "f64.le"),
    _F64_LOAD: $ => seq(repeat($._space), "f64.load"),
    _F64_LT: $ => seq(repeat($._space), "f64.lt"),
    _F64_MAX: $ => seq(repeat($._space), "f64.max"),
    _F64_MIN: $ => seq(repeat($._space), "f64.min"),
    _F64_MUL: $ => seq(repeat($._space), "f64.mul"),
    _F64_NE: $ => seq(repeat($._space), "f64.ne"),
    _F64_NEAREST: $ => seq(repeat($._space), "f64.nearest"),
    _F64_NEG: $ => seq(repeat($._space), "f64.neg"),
    _F64_PROMOTE_F32: $ => seq(repeat($._space), "f64.promote_f32"),
    _F64_REINTERPRET_I32: $ => seq(repeat($._space), "f64.reinterpret_i32"),
    _F64_REINTERPRET_I64: $ => seq(repeat($._space), "f64.reinterpret_i64"),
    _F64_SQRT: $ => seq(repeat($._space), "f64.sqrt"),
    _F64_STORE: $ => seq(repeat($._space), "f64.store"),
    _F64_SUB: $ => seq(repeat($._space), "f64.sub"),
    _F64_TRUNC: $ => seq(repeat($._space), "f64.trunc"),
    _FUNC: $ => seq(repeat($._space), "func"),
    _FUNCREF: $ => seq(repeat($._space), "funcref"),
    _GLOBAL: $ => seq(repeat($._space), "global"),
    _GLOBAL_GET: $ => seq(repeat($._space), "global.get"),
    _GLOBAL_SET: $ => seq(repeat($._space), "global.set"),
    _I32_ADD: $ => seq(repeat($._space), "i32.add"),
    _I32_AND: $ => seq(repeat($._space), "i32.and"),
    _I32_CLZ: $ => seq(repeat($._space), "i32.clz"),
    _I32_CONST: $ => seq(repeat($._space), "i32.const"),
    _I32_CTZ: $ => seq(repeat($._space), "i32.ctz"),
    _I32_DIV_S: $ => seq(repeat($._space), "i32.div_s"),
    _I32_DIV_U: $ => seq(repeat($._space), "i32.div_u"),
    _I32_EQ: $ => seq(repeat($._space), "i32.eq"),
    _I32_EQZ: $ => seq(repeat($._space), "i32.eqz"),
    _I32_GE_S: $ => seq(repeat($._space), "i32.ge_s"),
    _I32_GE_U: $ => seq(repeat($._space), "i32.ge_u"),
    _I32_GT_S: $ => seq(repeat($._space), "i32.gt_s"),
    _I32_GT_U: $ => seq(repeat($._space), "i32.gt_u"),
    _I32_LE_S: $ => seq(repeat($._space), "i32.le_s"),
    _I32_LE_U: $ => seq(repeat($._space), "i32.le_u"),
    _I32_LOAD: $ => seq(repeat($._space), "i32.load"),
    _I32_LOAD8_S: $ => seq(repeat($._space), "i32.load8_s"),
    _I32_LOAD8_U: $ => seq(repeat($._space), "i32.load8_u"),
    _I32_LOAD16_S: $ => seq(repeat($._space), "i32.load16_s"),
    _I32_LOAD16_U: $ => seq(repeat($._space), "i32.load16_u"),
    _I32_LT_S: $ => seq(repeat($._space), "i32.lt_s"),
    _I32_LT_U: $ => seq(repeat($._space), "i32.lt_u"),
    _I32_MUL: $ => seq(repeat($._space), "i32.mul"),
    _I32_NE: $ => seq(repeat($._space), "i32.ne"),
    _I32_OR: $ => seq(repeat($._space), "i32.or"),
    _I32_POPCNT: $ => seq(repeat($._space), "i32.popcnt"),
    _I32_REINTERPRET_F32: $ => seq(repeat($._space), "i32.reinterpret_f32"),
    _I32_REINTERPRET_F64: $ => seq(repeat($._space), "i32.reinterpret_f64"),
    _I32_REM_S: $ => seq(repeat($._space), "i32.rem_s"),
    _I32_REM_U: $ => seq(repeat($._space), "i32.rem_u"),
    _I32_ROTL: $ => seq(repeat($._space), "i32.rotl"),
    _I32_ROTR: $ => seq(repeat($._space), "i32.rotr"),
    _I32_SHL: $ => seq(repeat($._space), "i32.shl"),
    _I32_SHR_S: $ => seq(repeat($._space), "i32.shr_s"),
    _I32_SHR_U: $ => seq(repeat($._space), "i32.shr_u"),
    _I32_STORE: $ => seq(repeat($._space), "i32.store"),
    _I32_STORE8: $ => seq(repeat($._space), "i32.store8"),
    _I32_STORE16: $ => seq(repeat($._space), "i32.store16"),
    _I32_SUB: $ => seq(repeat($._space), "i32.sub"),
    _I32_TRUNC_F32_S: $ => seq(repeat($._space), "i32.trunc_f32_s"),
    _I32_TRUNC_F32_U: $ => seq(repeat($._space), "i32.trunc_f32_u"),
    _I32_TRUNC_F64_S: $ => seq(repeat($._space), "i32.trunc_f64_s"),
    _I32_TRUNC_F64_U: $ => seq(repeat($._space), "i32.trunc_f64_u"),
    _I32_WRAP_I64: $ => seq(repeat($._space), "i32.wrap_i64"),
    _I32_XOR: $ => seq(repeat($._space), "i32.xor"),
    _I64_ADD: $ => seq(repeat($._space), "i64.add"),
    _I64_AND: $ => seq(repeat($._space), "i64.and"),
    _I64_CLZ: $ => seq(repeat($._space), "i64.clz"),
    _I64_CONST: $ => seq(repeat($._space), "i644.const"),
    _I64_CTZ: $ => seq(repeat($._space), "i64.ctz"),
    _I64_DIV_S: $ => seq(repeat($._space), "i64.div_s"),
    _I64_DIV_U: $ => seq(repeat($._space), "i64.div_u"),
    _I64_EXTEND_I32_S: $ => seq(repeat($._space), "i64.extend_i32_s"),
    _I64_EXTEND_I32_U: $ => seq(repeat($._space), "i64.extend_i32_u"),
    _I64_EQ: $ => seq(repeat($._space), "i64.eq"),
    _I64_EQZ: $ => seq(repeat($._space), "i64.eqz"),
    _I64_GE_S: $ => seq(repeat($._space), "i64.ge_s"),
    _I64_GE_U: $ => seq(repeat($._space), "i64.ge_u"),
    _I64_GT_S: $ => seq(repeat($._space), "i64.gt_s"),
    _I64_GT_U: $ => seq(repeat($._space), "i64.gt_u"),
    _I64_LE_S: $ => seq(repeat($._space), "i64.le_s"),
    _I64_LE_U: $ => seq(repeat($._space), "i64.le_u"),
    _I64_LOAD: $ => seq(repeat($._space), "i64.load"),
    _I64_LOAD8_S: $ => seq(repeat($._space), "i64.load8_s"),
    _I64_LOAD8_U: $ => seq(repeat($._space), "i64.load8_u"),
    _I64_LOAD16_S: $ => seq(repeat($._space), "i64.load16_s"),
    _I64_LOAD16_U: $ => seq(repeat($._space), "i64.load16_u"),
    _I64_LOAD32_S: $ => seq(repeat($._space), "i64.load32_s"),
    _I64_LOAD32_U: $ => seq(repeat($._space), "i64.load32_u"),
    _I64_LT_S: $ => seq(repeat($._space), "i64.lt_s"),
    _I64_LT_U: $ => seq(repeat($._space), "i64.lt_u"),
    _I64_MUL: $ => seq(repeat($._space), "i64.mul"),
    _I64_NE: $ => seq(repeat($._space), "i64.ne"),
    _I64_OR: $ => seq(repeat($._space), "i64.or"),
    _I64_POPCNT: $ => seq(repeat($._space), "i64.popcnt"),
    _I64_REINTERPRET_F32: $ => seq(repeat($._space), "i64.reinterpret_f32"),
    _I64_REINTERPRET_F64: $ => seq(repeat($._space), "i64.reinterpret_f64"),
    _I64_REM_S: $ => seq(repeat($._space), "i64.rem_s"),
    _I64_REM_U: $ => seq(repeat($._space), "i64.rem_u"),
    _I64_ROTL: $ => seq(repeat($._space), "i64.rotl"),
    _I64_ROTR: $ => seq(repeat($._space), "i64.rotr"),
    _I64_SHL: $ => seq(repeat($._space), "i64.shl"),
    _I64_SHR_S: $ => seq(repeat($._space), "i64.shr_s"),
    _I64_SHR_U: $ => seq(repeat($._space), "i64.shr_u"),
    _I64_STORE: $ => seq(repeat($._space), "i64.store"),
    _I64_STORE8: $ => seq(repeat($._space), "i64.store8"),
    _I64_STORE16: $ => seq(repeat($._space), "i64.store16"),
    _I64_STORE32: $ => seq(repeat($._space), "i64.store32"),
    _I64_SUB: $ => seq(repeat($._space), "i64.sub"),
    _I64_TRUNC_F32_S: $ => seq(repeat($._space), "i64.trunc_f32_s"),
    _I64_TRUNC_F32_U: $ => seq(repeat($._space), "i64.trunc_f32_u"),
    _I64_TRUNC_F64_S: $ => seq(repeat($._space), "i64.trunc_f64_s"),
    _I64_TRUNC_F64_U: $ => seq(repeat($._space), "i64.trunc_f64_u"),
    _I64_XOR: $ => seq(repeat($._space), "i64.xor"),
    _IF: $ => seq(repeat($._space), "if"),
    _IMPORT: $ => seq(repeat($._space), "import"),
    _LOCAL: $ => seq(repeat($._space), "local"),
    _LOCAL_GET: $ => seq(repeat($._space), "local.get"),
    _LOCAL_SET: $ => seq(repeat($._space), "local.set"),
    _LOCAL_TEE: $ => seq(repeat($._space), "local.tee"),
    _LOOP: $ => seq(repeat($._space), "loop"),
    _LEFT_PARENTHESIS: $ => seq(repeat($._space), "("),
    _MEMORY: $ => seq(repeat($._space), "memory"),
    _MEMORY_GROW: $ => seq(repeat($._space), "memory.grow"),
    _MEMORY_SIZE: $ => seq(repeat($._space), "memory.size"),
    _MODULE: $ => seq(repeat($._space), "module"),
    _MUT: $ => seq(repeat($._space), "mut"),
    _NOP: $ => seq(repeat($._space), "nop"),
    _OFFSET: $ => seq(repeat($._space), "offset"),
    _OFFSET_EQ: $ => seq(repeat($._space), "offset="),
    _PARAM: $ => seq(repeat($._space), "param"),
    _RESULT: $ => seq(repeat($._space), "result"),
    _RETURN: $ => seq(repeat($._space), "return"),
    _RIGHT_PARENTHESIS: $ => seq(repeat($._space), ")"),
    _SELECT: $ => seq(repeat($._space), "select"),
    _START: $ => seq(repeat($._space), "start"),
    _TABLE: $ => seq(repeat($._space), "table"),
    _THEN: $ => seq(repeat($._space), "then"),
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

    _uN: $ => /(?:[0-9]|[0-9]+(?:_?[0-9]+)*)|(?:0x[0-9A-Fa-f]|[0-9A-Fa-f]+(?:_?[0-9A-Fa-f]+)*)/,

    _sN: $ => /(?:[+-]?[0-9]|[0-9]+(?:_?[0-9]+)*)|(?:[+-]?0x[0-9A-Fa-f]|[0-9A-Fa-f]+(?:_?[0-9A-Fa-f]+)*)/,

    _iN: $ => choice($._uN, $._sN),

    iN: $ => seq(repeat($._space), $._iN),

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

    fN: $ => seq(repeat($._space), $._fN),

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

    limits: $ => seq($.uN, optional(seq($._space, $._uN))),

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

    instr: $ => choice($.plaininstr, $.blockinstr, $.foldedinstr),

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
        seq($._BLOCK, alias(optional($.id), "label"), $.resulttype, repeat($.instr), $._END, optional($.id)),
        seq($._LOOP, alias(optional($.id), "label"), $.resulttype, repeat($.instr), $._END, optional($.id)),
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

    plaininstr: $ =>
      choice(
        $._UNREACHABLE,
        $._NOP,
        seq($._BR, $.labelidx),
        seq($._BR_IF, $.labelidx),
        seq($._BR_TABLE, repeat($.labelidx), $.labelidx),
        $._RETURN,
        seq($._CALL, $.funcidx),
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

        /***************************
         * Parametric Instructions *
         ***************************/

        $._DROP,
        $._SELECT,

        /*************************
         * Variable Instructions *
         *************************/

        seq($._LOCAL_GET, $.localidx),
        seq($._LOCAL_SET, $.localidx),
        seq($._LOCAL_TEE, $.localidx),
        seq($._GLOBAL_GET, $.globalidx),
        seq($._GLOBAL_SET, $.globalidx),

        /***********************
         * Memory Instructions *
         ***********************/

        seq($._F32_LOAD, alias(seq(optional(seq($._OFFSET_EQ, $._uN)), optional(seq($._ALIGN_EQ, $._uN))), "memarg")),
        seq($._F64_LOAD, alias(seq(optional(seq($._OFFSET_EQ, $._uN)), optional(seq($._ALIGN_EQ, $._uN))), "memarg")),
        seq($._I32_LOAD, alias(seq(optional(seq($._OFFSET_EQ, $._uN)), optional(seq($._ALIGN_EQ, $._uN))), "memarg")),
        seq(
          $._I32_LOAD8_S,
          alias(seq(optional(seq($._OFFSET_EQ, $._uN)), optional(seq($._ALIGN_EQ, $._uN))), "memarg"),
        ),
        seq(
          $._I32_LOAD8_U,
          alias(seq(optional(seq($._OFFSET_EQ, $._uN)), optional(seq($._ALIGN_EQ, $._uN))), "memarg"),
        ),
        seq(
          $._I32_LOAD16_S,
          alias(seq(optional(seq($._OFFSET_EQ, $._uN)), optional(seq($._ALIGN_EQ, $._uN))), "memarg"),
        ),
        seq(
          $._I32_LOAD16_U,
          alias(seq(optional(seq($._OFFSET_EQ, $._uN)), optional(seq($._ALIGN_EQ, $._uN))), "memarg"),
        ),
        seq($._I32_STORE, alias(seq(optional(seq($._OFFSET_EQ, $._uN)), optional(seq($._ALIGN_EQ, $._uN))), "memarg")),
        seq($._I32_STORE8, alias(seq(optional(seq($._OFFSET_EQ, $._uN)), optional(seq($._ALIGN_EQ, $._uN))), "memarg")),
        seq(
          $._I32_STORE16,
          alias(seq(optional(seq($._OFFSET_EQ, $._uN)), optional(seq($._ALIGN_EQ, $._uN))), "memarg"),
        ),
        seq($._I64_LOAD, alias(seq(optional(seq($._OFFSET_EQ, $._uN)), optional(seq($._ALIGN_EQ, $._uN))), "memarg")),
        seq(
          $._I64_LOAD8_S,
          alias(seq(optional(seq($._OFFSET_EQ, $._uN)), optional(seq($._ALIGN_EQ, $._uN))), "memarg"),
        ),
        seq(
          $._I64_LOAD8_U,
          alias(seq(optional(seq($._OFFSET_EQ, $._uN)), optional(seq($._ALIGN_EQ, $._uN))), "memarg"),
        ),
        seq(
          $._I64_LOAD16_S,
          alias(seq(optional(seq($._OFFSET_EQ, $._uN)), optional(seq($._ALIGN_EQ, $._uN))), "memarg"),
        ),
        seq(
          $._I64_LOAD16_U,
          alias(seq(optional(seq($._OFFSET_EQ, $._uN)), optional(seq($._ALIGN_EQ, $._uN))), "memarg"),
        ),
        seq(
          $._I64_LOAD32_S,
          alias(seq(optional(seq($._OFFSET_EQ, $._uN)), optional(seq($._ALIGN_EQ, $._uN))), "memarg"),
        ),
        seq(
          $._I64_LOAD32_U,
          alias(seq(optional(seq($._OFFSET_EQ, $._uN)), optional(seq($._ALIGN_EQ, $._uN))), "memarg"),
        ),
        seq($._I64_STORE, alias(seq(optional(seq($._OFFSET_EQ, $._uN)), optional(seq($._ALIGN_EQ, $._uN))), "memarg")),
        seq($._I64_STORE8, alias(seq(optional(seq($._OFFSET_EQ, $._uN)), optional(seq($._ALIGN_EQ, $._uN))), "memarg")),
        seq(
          $._I64_STORE16,
          alias(seq(optional(seq($._OFFSET_EQ, $._uN)), optional(seq($._ALIGN_EQ, $._uN))), "memarg"),
        ),
        seq(
          $._I64_STORE32,
          alias(seq(optional(seq($._OFFSET_EQ, $._uN)), optional(seq($._ALIGN_EQ, $._uN))), "memarg"),
        ),
        $._MEMORY_SIZE,
        $._MEMORY_GROW,

        /************************
         * Numeric Instructions *
         ************************/

        seq($._I32_CONST, $.iN),
        seq($._I64_CONST, $.iN),
        seq($._F32_CONST, $.fN),
        seq($._F64_CONST, $.fN),

        $._F32_ABS,
        $._F32_ADD,
        $._F32_CEIL,
        $._F32_CONVERT_I32_S,
        $._F32_CONVERT_I32_U,
        $._F32_CONVERT_I64_S,
        $._F32_CONVERT_I64_U,
        $._F32_COPYSIGN,
        $._F32_DEMOTE_F64,
        $._F32_DIV,
        $._F32_EQ,
        $._F32_FLOOR,
        $._F32_GE,
        $._F32_GT,
        $._F32_LE,
        $._F32_LT,
        $._F32_MAX,
        $._F32_MIN,
        $._F32_MUL,
        $._F32_NE,
        $._F32_NEAREST,
        $._F32_NEG,
        $._F32_REINTERPRET_I32,
        $._F32_REINTERPRET_I64,
        $._F32_SQRT,
        $._F32_SUB,
        $._F32_TRUNC,
        $._F64_ABS,
        $._F64_ADD,
        $._F64_CEIL,
        $._F64_CONVERT_I32_S,
        $._F64_CONVERT_I32_U,
        $._F64_CONVERT_I64_S,
        $._F64_CONVERT_I64_U,
        $._F64_COPYSIGN,
        $._F64_DIV,
        $._F64_EQ,
        $._F64_FLOOR,
        $._F64_GE,
        $._F64_GT,
        $._F64_LE,
        $._F64_LT,
        $._F64_MAX,
        $._F64_MIN,
        $._F64_MUL,
        $._F64_PROMOTE_F32,
        $._F64_NE,
        $._F64_NEAREST,
        $._F64_NEG,
        $._F64_REINTERPRET_I32,
        $._F64_REINTERPRET_I64,
        $._F64_SQRT,
        $._F64_SUB,
        $._F64_TRUNC,
        $._I32_ADD,
        $._I32_AND,
        $._I32_CLZ,
        $._I32_CTZ,
        $._I32_DIV_S,
        $._I32_DIV_U,
        $._I32_EQ,
        $._I32_EQZ,
        $._I32_GE_S,
        $._I32_GE_U,
        $._I32_GT_S,
        $._I32_GT_U,
        $._I32_LE_S,
        $._I32_LE_U,
        $._I32_LT_S,
        $._I32_LT_U,
        $._I32_MUL,
        $._I32_NE,
        $._I32_OR,
        $._I32_POPCNT,
        $._I32_REINTERPRET_F32,
        $._I32_REINTERPRET_F64,
        $._I32_REM_S,
        $._I32_REM_U,
        $._I32_ROTL,
        $._I32_ROTR,
        $._I32_SHL,
        $._I32_SHR_S,
        $._I32_SHR_U,
        $._I32_SUB,
        $._I32_TRUNC_F32_S,
        $._I32_TRUNC_F32_U,
        $._I32_TRUNC_F64_S,
        $._I32_TRUNC_F64_U,
        $._I32_WRAP_I64,
        $._I32_XOR,
        $._I64_ADD,
        $._I64_AND,
        $._I64_CLZ,
        $._I64_CTZ,
        $._I64_DIV_S,
        $._I64_DIV_U,
        $._I64_EQ,
        $._I64_EQZ,
        $._I64_EXTEND_I32_S,
        $._I64_EXTEND_I32_U,
        $._I64_GE_S,
        $._I64_GE_U,
        $._I64_GT_S,
        $._I64_GT_U,
        $._I64_LE_S,
        $._I64_LE_U,
        $._I64_LT_S,
        $._I64_LT_U,
        $._I64_MUL,
        $._I64_NE,
        $._I64_OR,
        $._I64_POPCNT,
        $._I64_REINTERPRET_F32,
        $._I64_REINTERPRET_F64,
        $._I64_REM_S,
        $._I64_REM_U,
        $._I64_ROTL,
        $._I64_ROTR,
        $._I64_SHL,
        $._I64_SHR_S,
        $._I64_SHR_U,
        $._I64_SUB,
        $._I64_TRUNC_F32_S,
        $._I64_TRUNC_F32_U,
        $._I64_TRUNC_F64_S,
        $._I64_TRUNC_F64_U,
        $._I64_XOR,
      ),

    // NOTE: we inline this because it matches the empty string
    // memarg: $ => seq(optional(seq("offset=", $._uN)), optional(seq("align=", $._uN))),

    /***********************
     * Folded Instructions *
     ***********************/

    foldedinstr: $ =>
      choice(
        seq($._LEFT_PARENTHESIS, $.plaininstr, repeat($.foldedinstr), $._RIGHT_PARENTHESIS),
        seq(
          $._LEFT_PARENTHESIS,
          $._BLOCK,
          alias(optional($.id), "label"),
          $.resulttype,
          repeat($.instr),
          $._RIGHT_PARENTHESIS,
        ),
        seq(
          $._LEFT_PARENTHESIS,
          $._LOOP,
          alias(optional($.id), "label"),
          $.resulttype,
          repeat($.instr),
          $._RIGHT_PARENTHESIS,
        ),
        seq(
          $._LEFT_PARENTHESIS,
          $._IF,
          alias(optional($.id), "label"),
          $.resulttype,
          repeat($.foldedinstr),
          seq($._LEFT_PARENTHESIS, $._THEN, repeat($.instr), $._RIGHT_PARENTHESIS),
          optional(seq($._LEFT_PARENTHESIS, $._ELSE, repeat($.instr), $._RIGHT_PARENTHESIS)),
          $._RIGHT_PARENTHESIS,
        ),
      ),

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
