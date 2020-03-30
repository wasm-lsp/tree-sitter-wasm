module.exports = grammar({
  name: "wat",

  // NOTE: The default value of `extras` for tree-sitter grammars includes
  // whitespace. However, we want to handle whitespace directly through the
  // grammar defined below so we override this value.
  extras: $ => [],

  conflicts: $ => [[$.blockinstr], [$.blockinstr, $.foldedinstr], [$.limits], [$.plaininstr], [$.foldedinstr, $.instr]],

  rules: {
    ENTRYPOINT: $ => seq(field("module", $.module), repeat($._space)),

    // ====================================================== //
    // =================== Lexical Format =================== //
    // ====================================================== //

    /**************
     * Whitespace *
     **************/

    _space: $ => choice(" ", $._format, $.comment),

    _format: $ => /[\t\n\r]/,

    /************
     * Comments *
     ************/

    comment: $ => choice($.linecomment, $.blockcomment),

    linecomment: $ => seq(";;", repeat($._linechar), "\n"),

    _linechar: $ => $._utf8line,

    blockcomment: $ => seq("(;", repeat($._blockchar), ";)"),

    _blockchar: $ => choice(/[^;(]/, /;[^)]/, /\([^;]/, $.blockcomment),

    // ====================================================== //
    // ======================= Tokens ======================= //
    // ====================================================== //

    _DATA: $ => seq(repeat($._space), "data"),
    _ELEM: $ => seq(repeat($._space), "elem"),
    _END: $ => seq(repeat($._space), "end"),
    _EXPORT: $ => seq(repeat($._space), "export"),
    _FUNC: $ => seq(repeat($._space), "func"),
    _FUNCREF: $ => seq(repeat($._space), "funcref"),
    _GLOBAL: $ => seq(repeat($._space), "global"),
    _IMPORT: $ => seq(repeat($._space), "import"),
    _LEFT_PARENTHESIS: $ => seq(repeat($._space), "("),
    _LOCAL: $ => seq(repeat($._space), "local"),
    _MEMORY: $ => seq(repeat($._space), "memory"),
    _MODULE: $ => seq(repeat($._space), "module"),
    _MUT: $ => seq(repeat($._space), "mut"),
    _OFFSET: $ => seq(repeat($._space), "offset"),
    _PARAM: $ => seq(repeat($._space), "param"),
    _RESULT: $ => seq(repeat($._space), "result"),
    _RIGHT_PARENTHESIS: $ => seq(repeat($._space), ")"),
    _START: $ => seq(repeat($._space), "start"),
    _TABLE: $ => seq(repeat($._space), "table"),
    _TYPE: $ => seq(repeat($._space), "type"),

    FUNC: $ => seq(repeat($._space), "func"),
    GLOBAL: $ => seq(repeat($._space), "global"),
    MEMORY: $ => seq(repeat($._space), "memory"),
    TABLE: $ => seq(repeat($._space), "table"),

    ALIGN_EQ: $ => seq(repeat($._space), field("$text", "align=")),
    BLOCK: $ => seq(repeat($._space), field("$text", "block")),
    BR: $ => seq(repeat($._space), field("$text", "br")),
    BR_IF: $ => seq(repeat($._space), field("$text", "br_if")),
    BR_TABLE: $ => seq(repeat($._space), field("$text", "br_table")),
    CALL: $ => seq(repeat($._space), field("$text", "call")),
    CALL_INDIRECT: $ => seq(repeat($._space), field("$text", "call_indirect")),
    DROP: $ => seq(repeat($._space), field("$text", "drop")),
    ELSE: $ => seq(repeat($._space), field("$text", "else")),
    F32_ABS: $ => seq(repeat($._space), field("$text", "f32.abs")),
    F32_ADD: $ => seq(repeat($._space), field("$text", "f32.add")),
    F32_CEIL: $ => seq(repeat($._space), field("$text", "f32.ceil")),
    F32_CONVERT_I32_S: $ => seq(repeat($._space), field("$text", "f32.convert_i32_s")),
    F32_CONVERT_I32_U: $ => seq(repeat($._space), field("$text", "f32.convert_i32_u")),
    F32_CONVERT_I64_S: $ => seq(repeat($._space), field("$text", "f32.convert_i64_s")),
    F32_CONVERT_I64_U: $ => seq(repeat($._space), field("$text", "f32.convert_i64_u")),
    F32_CONST: $ => seq(repeat($._space), field("$text", "f32.const")),
    F32_COPYSIGN: $ => seq(repeat($._space), field("$text", "f32.copysign")),
    F32_DEMOTE_F64: $ => seq(repeat($._space), field("$text", "f32.demote_f64")),
    F32_DIV: $ => seq(repeat($._space), field("$text", "f32.div")),
    F32_EQ: $ => seq(repeat($._space), field("$text", "f32.eq")),
    F32_FLOOR: $ => seq(repeat($._space), field("$text", "f32.floor")),
    F32_GE: $ => seq(repeat($._space), field("$text", "f32.ge")),
    F32_GT: $ => seq(repeat($._space), field("$text", "f32.gt")),
    F32_LE: $ => seq(repeat($._space), field("$text", "f32.le")),
    F32_LOAD: $ => seq(repeat($._space), field("$text", "f32.load")),
    F32_LT: $ => seq(repeat($._space), field("$text", "f32.lt")),
    F32_MAX: $ => seq(repeat($._space), field("$text", "f32.max")),
    F32_MIN: $ => seq(repeat($._space), field("$text", "f32.min")),
    F32_MUL: $ => seq(repeat($._space), field("$text", "f32.mul")),
    F32_NE: $ => seq(repeat($._space), field("$text", "f32.ne")),
    F32_NEAREST: $ => seq(repeat($._space), field("$text", "f32.nearest")),
    F32_NEG: $ => seq(repeat($._space), field("$text", "f32.neg")),
    F32_REINTERPRET_I32: $ => seq(repeat($._space), field("$text", "f32.reinterpret_i32")),
    F32_REINTERPRET_I64: $ => seq(repeat($._space), field("$text", "f32.reinterpret_i64")),
    F32_SQRT: $ => seq(repeat($._space), field("$text", "f32.sqrt")),
    F32_STORE: $ => seq(repeat($._space), field("$text", "f32.store")),
    F32_SUB: $ => seq(repeat($._space), field("$text", "f32.sub")),
    F32_TRUNC: $ => seq(repeat($._space), field("$text", "f32.trunc")),
    F64_ABS: $ => seq(repeat($._space), field("$text", "f64.abs")),
    F64_ADD: $ => seq(repeat($._space), field("$text", "f64.add")),
    F64_CEIL: $ => seq(repeat($._space), field("$text", "f64.ceil")),
    F64_CONST: $ => seq(repeat($._space), field("$text", "f64.const")),
    F64_CONVERT_I32_S: $ => seq(repeat($._space), field("$text", "f64.convert_i32_s")),
    F64_CONVERT_I32_U: $ => seq(repeat($._space), field("$text", "f64.convert_i32_u")),
    F64_CONVERT_I64_S: $ => seq(repeat($._space), field("$text", "f64.convert_i64_s")),
    F64_CONVERT_I64_U: $ => seq(repeat($._space), field("$text", "f64.convert_i64_u")),
    F64_COPYSIGN: $ => seq(repeat($._space), field("$text", "f64.copysign")),
    F64_DIV: $ => seq(repeat($._space), field("$text", "f64.div")),
    F64_EQ: $ => seq(repeat($._space), field("$text", "f64.eq")),
    F64_FLOOR: $ => seq(repeat($._space), field("$text", "f64.floor")),
    F64_GE: $ => seq(repeat($._space), field("$text", "f64.ge")),
    F64_GT: $ => seq(repeat($._space), field("$text", "f64.gt")),
    F64_LE: $ => seq(repeat($._space), field("$text", "f64.le")),
    F64_LOAD: $ => seq(repeat($._space), field("$text", "f64.load")),
    F64_LT: $ => seq(repeat($._space), field("$text", "f64.lt")),
    F64_MAX: $ => seq(repeat($._space), field("$text", "f64.max")),
    F64_MIN: $ => seq(repeat($._space), field("$text", "f64.min")),
    F64_MUL: $ => seq(repeat($._space), field("$text", "f64.mul")),
    F64_NE: $ => seq(repeat($._space), field("$text", "f64.ne")),
    F64_NEAREST: $ => seq(repeat($._space), field("$text", "f64.nearest")),
    F64_NEG: $ => seq(repeat($._space), field("$text", "f64.neg")),
    F64_PROMOTE_F32: $ => seq(repeat($._space), field("$text", "f64.promote_f32")),
    F64_REINTERPRET_I32: $ => seq(repeat($._space), field("$text", "f64.reinterpret_i32")),
    F64_REINTERPRET_I64: $ => seq(repeat($._space), field("$text", "f64.reinterpret_i64")),
    F64_SQRT: $ => seq(repeat($._space), field("$text", "f64.sqrt")),
    F64_STORE: $ => seq(repeat($._space), field("$text", "f64.store")),
    F64_SUB: $ => seq(repeat($._space), field("$text", "f64.sub")),
    F64_TRUNC: $ => seq(repeat($._space), field("$text", "f64.trunc")),
    GLOBAL_GET: $ => seq(repeat($._space), field("$text", "global.get")),
    GLOBAL_SET: $ => seq(repeat($._space), field("$text", "global.set")),
    I32_ADD: $ => seq(repeat($._space), field("$text", "i32.add")),
    I32_AND: $ => seq(repeat($._space), field("$text", "i32.and")),
    I32_CLZ: $ => seq(repeat($._space), field("$text", "i32.clz")),
    I32_CONST: $ => seq(repeat($._space), field("$text", "i32.const")),
    I32_CTZ: $ => seq(repeat($._space), field("$text", "i32.ctz")),
    I32_DIV_S: $ => seq(repeat($._space), field("$text", "i32.div_s")),
    I32_DIV_U: $ => seq(repeat($._space), field("$text", "i32.div_u")),
    I32_EQ: $ => seq(repeat($._space), field("$text", "i32.eq")),
    I32_EQZ: $ => seq(repeat($._space), field("$text", "i32.eqz")),
    I32_GE_S: $ => seq(repeat($._space), field("$text", "i32.ge_s")),
    I32_GE_U: $ => seq(repeat($._space), field("$text", "i32.ge_u")),
    I32_GT_S: $ => seq(repeat($._space), field("$text", "i32.gt_s")),
    I32_GT_U: $ => seq(repeat($._space), field("$text", "i32.gt_u")),
    I32_LE_S: $ => seq(repeat($._space), field("$text", "i32.le_s")),
    I32_LE_U: $ => seq(repeat($._space), field("$text", "i32.le_u")),
    I32_LOAD: $ => seq(repeat($._space), field("$text", "i32.load")),
    I32_LOAD8_S: $ => seq(repeat($._space), field("$text", "i32.load8_s")),
    I32_LOAD8_U: $ => seq(repeat($._space), field("$text", "i32.load8_u")),
    I32_LOAD16_S: $ => seq(repeat($._space), field("$text", "i32.load16_s")),
    I32_LOAD16_U: $ => seq(repeat($._space), field("$text", "i32.load16_u")),
    I32_LT_S: $ => seq(repeat($._space), field("$text", "i32.lt_s")),
    I32_LT_U: $ => seq(repeat($._space), field("$text", "i32.lt_u")),
    I32_MUL: $ => seq(repeat($._space), field("$text", "i32.mul")),
    I32_NE: $ => seq(repeat($._space), field("$text", "i32.ne")),
    I32_OR: $ => seq(repeat($._space), field("$text", "i32.or")),
    I32_POPCNT: $ => seq(repeat($._space), field("$text", "i32.popcnt")),
    I32_REINTERPRET_F32: $ => seq(repeat($._space), field("$text", "i32.reinterpret_f32")),
    I32_REINTERPRET_F64: $ => seq(repeat($._space), field("$text", "i32.reinterpret_f64")),
    I32_REM_S: $ => seq(repeat($._space), field("$text", "i32.rem_s")),
    I32_REM_U: $ => seq(repeat($._space), field("$text", "i32.rem_u")),
    I32_ROTL: $ => seq(repeat($._space), field("$text", "i32.rotl")),
    I32_ROTR: $ => seq(repeat($._space), field("$text", "i32.rotr")),
    I32_SHL: $ => seq(repeat($._space), field("$text", "i32.shl")),
    I32_SHR_S: $ => seq(repeat($._space), field("$text", "i32.shr_s")),
    I32_SHR_U: $ => seq(repeat($._space), field("$text", "i32.shr_u")),
    I32_STORE: $ => seq(repeat($._space), field("$text", "i32.store")),
    I32_STORE8: $ => seq(repeat($._space), field("$text", "i32.store8")),
    I32_STORE16: $ => seq(repeat($._space), field("$text", "i32.store16")),
    I32_SUB: $ => seq(repeat($._space), field("$text", "i32.sub")),
    I32_TRUNC_F32_S: $ => seq(repeat($._space), field("$text", "i32.trunc_f32_s")),
    I32_TRUNC_F32_U: $ => seq(repeat($._space), field("$text", "i32.trunc_f32_u")),
    I32_TRUNC_F64_S: $ => seq(repeat($._space), field("$text", "i32.trunc_f64_s")),
    I32_TRUNC_F64_U: $ => seq(repeat($._space), field("$text", "i32.trunc_f64_u")),
    I32_WRAP_I64: $ => seq(repeat($._space), field("$text", "i32.wrap_i64")),
    I32_XOR: $ => seq(repeat($._space), field("$text", "i32.xor")),
    I64_ADD: $ => seq(repeat($._space), field("$text", "i64.add")),
    I64_AND: $ => seq(repeat($._space), field("$text", "i64.and")),
    I64_CLZ: $ => seq(repeat($._space), field("$text", "i64.clz")),
    I64_CONST: $ => seq(repeat($._space), field("$text", "i644.const")),
    I64_CTZ: $ => seq(repeat($._space), field("$text", "i64.ctz")),
    I64_DIV_S: $ => seq(repeat($._space), field("$text", "i64.div_s")),
    I64_DIV_U: $ => seq(repeat($._space), field("$text", "i64.div_u")),
    I64_EXTEND_I32_S: $ => seq(repeat($._space), field("$text", "i64.extend_i32_s")),
    I64_EXTEND_I32_U: $ => seq(repeat($._space), field("$text", "i64.extend_i32_u")),
    I64_EQ: $ => seq(repeat($._space), field("$text", "i64.eq")),
    I64_EQZ: $ => seq(repeat($._space), field("$text", "i64.eqz")),
    I64_GE_S: $ => seq(repeat($._space), field("$text", "i64.ge_s")),
    I64_GE_U: $ => seq(repeat($._space), field("$text", "i64.ge_u")),
    I64_GT_S: $ => seq(repeat($._space), field("$text", "i64.gt_s")),
    I64_GT_U: $ => seq(repeat($._space), field("$text", "i64.gt_u")),
    I64_LE_S: $ => seq(repeat($._space), field("$text", "i64.le_s")),
    I64_LE_U: $ => seq(repeat($._space), field("$text", "i64.le_u")),
    I64_LOAD: $ => seq(repeat($._space), field("$text", "i64.load")),
    I64_LOAD8_S: $ => seq(repeat($._space), field("$text", "i64.load8_s")),
    I64_LOAD8_U: $ => seq(repeat($._space), field("$text", "i64.load8_u")),
    I64_LOAD16_S: $ => seq(repeat($._space), field("$text", "i64.load16_s")),
    I64_LOAD16_U: $ => seq(repeat($._space), field("$text", "i64.load16_u")),
    I64_LOAD32_S: $ => seq(repeat($._space), field("$text", "i64.load32_s")),
    I64_LOAD32_U: $ => seq(repeat($._space), field("$text", "i64.load32_u")),
    I64_LT_S: $ => seq(repeat($._space), field("$text", "i64.lt_s")),
    I64_LT_U: $ => seq(repeat($._space), field("$text", "i64.lt_u")),
    I64_MUL: $ => seq(repeat($._space), field("$text", "i64.mul")),
    I64_NE: $ => seq(repeat($._space), field("$text", "i64.ne")),
    I64_OR: $ => seq(repeat($._space), field("$text", "i64.or")),
    I64_POPCNT: $ => seq(repeat($._space), field("$text", "i64.popcnt")),
    I64_REINTERPRET_F32: $ => seq(repeat($._space), field("$text", "i64.reinterpret_f32")),
    I64_REINTERPRET_F64: $ => seq(repeat($._space), field("$text", "i64.reinterpret_f64")),
    I64_REM_S: $ => seq(repeat($._space), field("$text", "i64.rem_s")),
    I64_REM_U: $ => seq(repeat($._space), field("$text", "i64.rem_u")),
    I64_ROTL: $ => seq(repeat($._space), field("$text", "i64.rotl")),
    I64_ROTR: $ => seq(repeat($._space), field("$text", "i64.rotr")),
    I64_SHL: $ => seq(repeat($._space), field("$text", "i64.shl")),
    I64_SHR_S: $ => seq(repeat($._space), field("$text", "i64.shr_s")),
    I64_SHR_U: $ => seq(repeat($._space), field("$text", "i64.shr_u")),
    I64_STORE: $ => seq(repeat($._space), field("$text", "i64.store")),
    I64_STORE8: $ => seq(repeat($._space), field("$text", "i64.store8")),
    I64_STORE16: $ => seq(repeat($._space), field("$text", "i64.store16")),
    I64_STORE32: $ => seq(repeat($._space), field("$text", "i64.store32")),
    I64_SUB: $ => seq(repeat($._space), field("$text", "i64.sub")),
    I64_TRUNC_F32_S: $ => seq(repeat($._space), field("$text", "i64.trunc_f32_s")),
    I64_TRUNC_F32_U: $ => seq(repeat($._space), field("$text", "i64.trunc_f32_u")),
    I64_TRUNC_F64_S: $ => seq(repeat($._space), field("$text", "i64.trunc_f64_s")),
    I64_TRUNC_F64_U: $ => seq(repeat($._space), field("$text", "i64.trunc_f64_u")),
    I64_XOR: $ => seq(repeat($._space), field("$text", "i64.xor")),
    IF: $ => seq(repeat($._space), field("$text", "if")),
    LOCAL_GET: $ => seq(repeat($._space), field("$text", "local.get")),
    LOCAL_SET: $ => seq(repeat($._space), field("$text", "local.set")),
    LOCAL_TEE: $ => seq(repeat($._space), field("$text", "local.tee")),
    LOOP: $ => seq(repeat($._space), field("$text", "loop")),
    MEMORY_GROW: $ => seq(repeat($._space), field("$text", "memory.grow")),
    MEMORY_SIZE: $ => seq(repeat($._space), field("$text", "memory.size")),
    NOP: $ => seq(repeat($._space), field("$text", "nop")),
    OFFSET_EQ: $ => seq(repeat($._space), field("$text", "offset=")),
    RETURN: $ => seq(repeat($._space), field("$text", "return")),
    SELECT: $ => seq(repeat($._space), field("$text", "select")),
    THEN: $ => seq(repeat($._space), field("$text", "then")),
    UNREACHABLE: $ => seq(repeat($._space), field("$text", "unreachable")),

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

    uN_text: $ => /(?:[0-9]|[0-9]+(?:_?[0-9]+)*)|(?:0x[0-9A-Fa-f]|[0-9A-Fa-f]+(?:_?[0-9A-Fa-f]+)*)/,

    _sN: $ => /(?:[+-]?[0-9]|[0-9]+(?:_?[0-9]+)*)|(?:[+-]?0x[0-9A-Fa-f]|[0-9A-Fa-f]+(?:_?[0-9A-Fa-f]+)*)/,

    iN_text: $ => choice($.uN_text, $._sN),

    iN: $ => seq(repeat($._space), field("$text", $.iN_text)),

    uN: $ => seq(repeat($._space), field("$text", $.uN_text)),

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

    _fNmag: $ => choice($._float, $._hexfloat, "inf", "nan", seq("nan:0x", $._hexnum)),

    fN_text: $ => seq(optional($._sign), $._fNmag),

    fN: $ => seq(repeat($._space), field("$text", $.fN_text)),

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

    name_text: $ => $._string,

    name: $ => seq(repeat($._space), field("$text", $.name_text)),

    /***************
     * Identifiers *
     ***************/

    id_text: $ => /\$[0-9A-Za-z!#$%&'*+-./:<=>?@\\^_'|~]+/,

    id: $ => seq(repeat($._space), field("$text", $.id_text)),

    // ====================================================== //
    // ======================== Types ======================= //
    // ====================================================== //

    valtype_text: $ => choice("i32", "i64", "f32", "f64"),

    valtype: $ => seq(repeat($._space), field("$text", $.valtype_text)),

    /****************
     * Result Types *
     ****************/

    resulttype: $ => $.result,

    /******************
     * Function Types *
     ******************/

    functype: $ =>
      seq(
        $._LEFT_PARENTHESIS,
        $._FUNC,
        field("param", repeat($.param)),
        field("result", repeat($.result)),
        $._RIGHT_PARENTHESIS,
      ),

    param: $ =>
      choice(
        // NOTE: re-factored to avoid conflict with abbreviation
        seq(
          $._LEFT_PARENTHESIS,
          $._PARAM,
          optional(seq(field("id", $.id), field("valtype", $.valtype))),
          $._RIGHT_PARENTHESIS,
        ),
        // abbreviation
        seq($._LEFT_PARENTHESIS, $._PARAM, field("valtype", repeat1($.valtype)), $._RIGHT_PARENTHESIS),
      ),

    result: $ => seq($._LEFT_PARENTHESIS, $._RESULT, field("valtype", repeat($.valtype)), $._RIGHT_PARENTHESIS),

    /**********
     * Limits *
     **********/

    limits: $ => seq(field("min", $.uN), field("max", optional(seq($._space, $.uN_text)))),

    /****************
     * Memory Types *
     ****************/

    memtype: $ => $.limits,

    /***************
     * Table Types *
     ***************/

    tabletype: $ => seq(field("limits", $.limits), field("elemtype", $.elemtype)),

    elemtype: $ => alias($._FUNCREF, "funcref"),

    /****************
     * Global Types *
     ****************/

    globaltype: $ =>
      choice(
        field("valtype", $.valtype),
        seq($._LEFT_PARENTHESIS, $._MUT, field("valtype", $.valtype), $._RIGHT_PARENTHESIS),
      ),

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
        seq(
          field("instr", $.BLOCK),
          field("label", alias(optional($.id), "label")),
          field("resulttype", $.resulttype),
          field("instr", repeat($.instr)),
          $._END,
          field("id", optional($.id)),
        ),
        seq(
          field("instr", $.LOOP),
          field("label", alias(optional($.id), "label")),
          field("resulttype", $.resulttype),
          field("instr", repeat($.instr)),
          $._END,
          field("id", optional($.id)),
        ),
        seq(
          field("instr", $.IF),
          field("label", alias(optional($.id), "label")),
          field("resulttype", $.resulttype),
          field("instr0", repeat($.instr)),
          choice(
            seq(
              $.ELSE,
              field("id0", optional($.id)),
              field("instr1", repeat($.instr)),
              $._END,
              field("id1", optional($.id)),
            ),
            // abbreviation
            $._END,
            field("id0", optional($.id)),
          ),
        ),
      ),

    plaininstr: $ =>
      choice(
        field("instr", $.UNREACHABLE),
        field("instr", $.NOP),
        seq(field("instr", $.BR), field("labelidx", $.labelidx)),
        seq(field("instr", $.BR_IF), field("labelidx", $.labelidx)),
        seq(field("instr", $.BR_TABLE), field("labelidx0", repeat($.labelidx)), field("labelidx1", $.labelidx)),
        field("instr", $.RETURN),
        seq(field("instr", $.CALL), $.funcidx),
        seq(
          field("instr", $.CALL_INDIRECT),
          field(
            "typeuse",
            alias(
              seq(
                optional(seq($._LEFT_PARENTHESIS, $._TYPE, field("typeidx", $.typeidx), $._RIGHT_PARENTHESIS)),
                field("param", repeat($.param)),
                field("param", repeat($.result)),
              ),
              "typeuse",
            ),
          ),
        ),

        /***************************
         * Parametric Instructions *
         ***************************/

        field("instr", $.DROP),
        field("instr", $.SELECT),

        /*************************
         * Variable Instructions *
         *************************/

        seq(field("instr", $.LOCAL_GET), field("localidx", $.localidx)),
        seq(field("instr", $.LOCAL_SET), field("localidx", $.localidx)),
        seq(field("instr", $.LOCAL_TEE), field("localidx", $.localidx)),
        seq(field("instr", $.GLOBAL_GET), field("globalidx", $.globalidx)),
        seq(field("instr", $.GLOBAL_SET), field("globalidx", $.globalidx)),

        /***********************
         * Memory Instructions *
         ***********************/

        seq(
          field("instr", $.F32_LOAD),
          alias(
            seq(
              field("offset", optional(seq($.OFFSET_EQ, field("$text", $.uN_text)))),
              field("align", optional(seq($.ALIGN_EQ, field("$text", $.uN_text)))),
            ),
            "memarg",
          ),
        ),
        seq(
          field("instr", $.F64_LOAD),
          alias(
            seq(
              field("offset", optional(seq($.OFFSET_EQ, field("$text", $.uN_text)))),
              field("align", optional(seq($.ALIGN_EQ, field("$text", $.uN_text)))),
            ),
            "memarg",
          ),
        ),
        seq(
          field("instr", $.I32_LOAD),
          alias(
            seq(
              field("offset", optional(seq($.OFFSET_EQ, field("$text", $.uN_text)))),
              field("align", optional(seq($.ALIGN_EQ, field("$text", $.uN_text)))),
            ),
            "memarg",
          ),
        ),
        seq(
          field("instr", $.I32_LOAD8_S),
          alias(
            seq(
              field("offset", optional(seq($.OFFSET_EQ, field("$text", $.uN_text)))),
              field("align", optional(seq($.ALIGN_EQ, field("$text", $.uN_text)))),
            ),
            "memarg",
          ),
        ),
        seq(
          field("instr", $.I32_LOAD8_U),
          alias(
            seq(
              field("offset", optional(seq($.OFFSET_EQ, field("$text", $.uN_text)))),
              field("align", optional(seq($.ALIGN_EQ, field("$text", $.uN_text)))),
            ),
            "memarg",
          ),
        ),
        seq(
          field("instr", $.I32_LOAD16_S),
          alias(
            seq(
              field("offset", optional(seq($.OFFSET_EQ, field("$text", $.uN_text)))),
              field("align", optional(seq($.ALIGN_EQ, field("$text", $.uN_text)))),
            ),
            "memarg",
          ),
        ),
        seq(
          field("instr", $.I32_LOAD16_U),
          alias(
            seq(
              field("offset", optional(seq($.OFFSET_EQ, field("$text", $.uN_text)))),
              field("align", optional(seq($.ALIGN_EQ, field("$text", $.uN_text)))),
            ),
            "memarg",
          ),
        ),
        seq(
          field("instr", $.I32_STORE),
          alias(
            seq(
              field("offset", optional(seq($.OFFSET_EQ, field("$text", $.uN_text)))),
              field("align", optional(seq($.ALIGN_EQ, field("$text", $.uN_text)))),
            ),
            "memarg",
          ),
        ),
        seq(
          field("instr", $.I32_STORE8),
          alias(
            seq(
              field("offset", optional(seq($.OFFSET_EQ, field("$text", $.uN_text)))),
              field("align", optional(seq($.ALIGN_EQ, field("$text", $.uN_text)))),
            ),
            "memarg",
          ),
        ),
        seq(
          field("instr", $.I32_STORE16),
          alias(
            seq(
              field("offset", optional(seq($.OFFSET_EQ, field("$text", $.uN_text)))),
              field("align", optional(seq($.ALIGN_EQ, field("$text", $.uN_text)))),
            ),
            "memarg",
          ),
        ),
        seq(
          field("instr", $.I64_LOAD),
          alias(
            seq(
              field("offset", optional(seq($.OFFSET_EQ, field("$text", $.uN_text)))),
              field("align", optional(seq($.ALIGN_EQ, field("$text", $.uN_text)))),
            ),
            "memarg",
          ),
        ),
        seq(
          field("instr", $.I64_LOAD8_S),
          alias(
            seq(
              field("offset", optional(seq($.OFFSET_EQ, field("$text", $.uN_text)))),
              field("align", optional(seq($.ALIGN_EQ, field("$text", $.uN_text)))),
            ),
            "memarg",
          ),
        ),
        seq(
          field("instr", $.I64_LOAD8_U),
          alias(
            seq(
              field("offset", optional(seq($.OFFSET_EQ, field("$text", $.uN_text)))),
              field("align", optional(seq($.ALIGN_EQ, field("$text", $.uN_text)))),
            ),
            "memarg",
          ),
        ),
        seq(
          field("instr", $.I64_LOAD16_S),
          alias(
            seq(
              field("offset", optional(seq($.OFFSET_EQ, field("$text", $.uN_text)))),
              field("align", optional(seq($.ALIGN_EQ, field("$text", $.uN_text)))),
            ),
            "memarg",
          ),
        ),
        seq(
          field("instr", $.I64_LOAD16_U),
          alias(
            seq(
              field("offset", optional(seq($.OFFSET_EQ, field("$text", $.uN_text)))),
              field("align", optional(seq($.ALIGN_EQ, field("$text", $.uN_text)))),
            ),
            "memarg",
          ),
        ),
        seq(
          field("instr", $.I64_LOAD32_S),
          alias(
            seq(
              field("offset", optional(seq($.OFFSET_EQ, field("$text", $.uN_text)))),
              field("align", optional(seq($.ALIGN_EQ, field("$text", $.uN_text)))),
            ),
            "memarg",
          ),
        ),
        seq(
          field("instr", $.I64_LOAD32_U),
          alias(
            seq(
              field("offset", optional(seq($.OFFSET_EQ, field("$text", $.uN_text)))),
              field("align", optional(seq($.ALIGN_EQ, field("$text", $.uN_text)))),
            ),
            "memarg",
          ),
        ),
        seq(
          field("instr", $.I64_STORE),
          alias(
            seq(
              field("offset", optional(seq($.OFFSET_EQ, field("$text", $.uN_text)))),
              field("align", optional(seq($.ALIGN_EQ, field("$text", $.uN_text)))),
            ),
            "memarg",
          ),
        ),
        seq(
          field("instr", $.I64_STORE8),
          alias(
            seq(
              field("offset", optional(seq($.OFFSET_EQ, field("$text", $.uN_text)))),
              field("align", optional(seq($.ALIGN_EQ, field("$text", $.uN_text)))),
            ),
            "memarg",
          ),
        ),
        seq(
          field("instr", $.I64_STORE16),
          alias(
            seq(
              field("offset", optional(seq($.OFFSET_EQ, field("$text", $.uN_text)))),
              field("align", optional(seq($.ALIGN_EQ, field("$text", $.uN_text)))),
            ),
            "memarg",
          ),
        ),
        seq(
          field("instr", $.I64_STORE32),
          alias(
            seq(
              field("offset", optional(seq($.OFFSET_EQ, field("$text", $.uN_text)))),
              field("align", optional(seq($.ALIGN_EQ, field("$text", $.uN_text)))),
            ),
            "memarg",
          ),
        ),
        field("instr", $.MEMORY_SIZE),
        field("instr", $.MEMORY_GROW),

        /************************
         * Numeric Instructions *
         ************************/

        seq(field("instr", $.I32_CONST), field("value", $.iN)),
        seq(field("instr", $.I64_CONST), field("value", $.iN)),
        seq(field("instr", $.F32_CONST), field("value", $.fN)),
        seq(field("instr", $.F64_CONST), field("value", $.fN)),

        field("instr", $.F32_ABS),
        field("instr", $.F32_ADD),
        field("instr", $.F32_CEIL),
        field("instr", $.F32_CONVERT_I32_S),
        field("instr", $.F32_CONVERT_I32_U),
        field("instr", $.F32_CONVERT_I64_S),
        field("instr", $.F32_CONVERT_I64_U),
        field("instr", $.F32_COPYSIGN),
        field("instr", $.F32_DEMOTE_F64),
        field("instr", $.F32_DIV),
        field("instr", $.F32_EQ),
        field("instr", $.F32_FLOOR),
        field("instr", $.F32_GE),
        field("instr", $.F32_GT),
        field("instr", $.F32_LE),
        field("instr", $.F32_LT),
        field("instr", $.F32_MAX),
        field("instr", $.F32_MIN),
        field("instr", $.F32_MUL),
        field("instr", $.F32_NE),
        field("instr", $.F32_NEAREST),
        field("instr", $.F32_NEG),
        field("instr", $.F32_REINTERPRET_I32),
        field("instr", $.F32_REINTERPRET_I64),
        field("instr", $.F32_SQRT),
        field("instr", $.F32_SUB),
        field("instr", $.F32_TRUNC),
        field("instr", $.F64_ABS),
        field("instr", $.F64_ADD),
        field("instr", $.F64_CEIL),
        field("instr", $.F64_CONVERT_I32_S),
        field("instr", $.F64_CONVERT_I32_U),
        field("instr", $.F64_CONVERT_I64_S),
        field("instr", $.F64_CONVERT_I64_U),
        field("instr", $.F64_COPYSIGN),
        field("instr", $.F64_DIV),
        field("instr", $.F64_EQ),
        field("instr", $.F64_FLOOR),
        field("instr", $.F64_GE),
        field("instr", $.F64_GT),
        field("instr", $.F64_LE),
        field("instr", $.F64_LT),
        field("instr", $.F64_MAX),
        field("instr", $.F64_MIN),
        field("instr", $.F64_MUL),
        field("instr", $.F64_PROMOTE_F32),
        field("instr", $.F64_NE),
        field("instr", $.F64_NEAREST),
        field("instr", $.F64_NEG),
        field("instr", $.F64_REINTERPRET_I32),
        field("instr", $.F64_REINTERPRET_I64),
        field("instr", $.F64_SQRT),
        field("instr", $.F64_SUB),
        field("instr", $.F64_TRUNC),
        field("instr", $.I32_ADD),
        field("instr", $.I32_AND),
        field("instr", $.I32_CLZ),
        field("instr", $.I32_CTZ),
        field("instr", $.I32_DIV_S),
        field("instr", $.I32_DIV_U),
        field("instr", $.I32_EQ),
        field("instr", $.I32_EQZ),
        field("instr", $.I32_GE_S),
        field("instr", $.I32_GE_U),
        field("instr", $.I32_GT_S),
        field("instr", $.I32_GT_U),
        field("instr", $.I32_LE_S),
        field("instr", $.I32_LE_U),
        field("instr", $.I32_LT_S),
        field("instr", $.I32_LT_U),
        field("instr", $.I32_MUL),
        field("instr", $.I32_NE),
        field("instr", $.I32_OR),
        field("instr", $.I32_POPCNT),
        field("instr", $.I32_REINTERPRET_F32),
        field("instr", $.I32_REINTERPRET_F64),
        field("instr", $.I32_REM_S),
        field("instr", $.I32_REM_U),
        field("instr", $.I32_ROTL),
        field("instr", $.I32_ROTR),
        field("instr", $.I32_SHL),
        field("instr", $.I32_SHR_S),
        field("instr", $.I32_SHR_U),
        field("instr", $.I32_SUB),
        field("instr", $.I32_TRUNC_F32_S),
        field("instr", $.I32_TRUNC_F32_U),
        field("instr", $.I32_TRUNC_F64_S),
        field("instr", $.I32_TRUNC_F64_U),
        field("instr", $.I32_WRAP_I64),
        field("instr", $.I32_XOR),
        field("instr", $.I64_ADD),
        field("instr", $.I64_AND),
        field("instr", $.I64_CLZ),
        field("instr", $.I64_CTZ),
        field("instr", $.I64_DIV_S),
        field("instr", $.I64_DIV_U),
        field("instr", $.I64_EQ),
        field("instr", $.I64_EQZ),
        field("instr", $.I64_EXTEND_I32_S),
        field("instr", $.I64_EXTEND_I32_U),
        field("instr", $.I64_GE_S),
        field("instr", $.I64_GE_U),
        field("instr", $.I64_GT_S),
        field("instr", $.I64_GT_U),
        field("instr", $.I64_LE_S),
        field("instr", $.I64_LE_U),
        field("instr", $.I64_LT_S),
        field("instr", $.I64_LT_U),
        field("instr", $.I64_MUL),
        field("instr", $.I64_NE),
        field("instr", $.I64_OR),
        field("instr", $.I64_POPCNT),
        field("instr", $.I64_REINTERPRET_F32),
        field("instr", $.I64_REINTERPRET_F64),
        field("instr", $.I64_REM_S),
        field("instr", $.I64_REM_U),
        field("instr", $.I64_ROTL),
        field("instr", $.I64_ROTR),
        field("instr", $.I64_SHL),
        field("instr", $.I64_SHR_S),
        field("instr", $.I64_SHR_U),
        field("instr", $.I64_SUB),
        field("instr", $.I64_TRUNC_F32_S),
        field("instr", $.I64_TRUNC_F32_U),
        field("instr", $.I64_TRUNC_F64_S),
        field("instr", $.I64_TRUNC_F64_U),
        field("instr", $.I64_XOR),
      ),

    // NOTE: we inline this because it matches the empty string
    // memarg: $ => seq(optional(seq("offset=", $.uN_text)), optional(seq("align=", $.uN_text))),

    /***********************
     * Folded Instructions *
     ***********************/

    foldedinstr: $ =>
      choice(
        seq(
          $._LEFT_PARENTHESIS,
          field("plain", $.plaininstr),
          field("folded", repeat($.foldedinstr)),
          $._RIGHT_PARENTHESIS,
        ),
        seq(
          $._LEFT_PARENTHESIS,
          field("block", $.BLOCK),
          field("label", alias(optional($.id), "label")),
          field("resulttype", $.resulttype),
          field("instr", repeat($.instr)),
          $._RIGHT_PARENTHESIS,
        ),
        seq(
          $._LEFT_PARENTHESIS,
          field("loop", $.LOOP),
          field("label", alias(optional($.id), "label")),
          field("resulttype", $.resulttype),
          field("instr", repeat($.instr)),
          $._RIGHT_PARENTHESIS,
        ),
        seq(
          $._LEFT_PARENTHESIS,
          field("if", $.IF),
          field("label", alias(optional($.id), "label")),
          field("resulttype", $.resulttype),
          field("foldedinstr", repeat($.foldedinstr)),
          field("then", seq($._LEFT_PARENTHESIS, $.THEN, field("instr", repeat($.instr)), $._RIGHT_PARENTHESIS)),
          field(
            "else",
            optional(seq($._LEFT_PARENTHESIS, $.ELSE, field("instr", repeat($.instr)), $._RIGHT_PARENTHESIS)),
          ),
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

    type: $ =>
      seq(
        $._LEFT_PARENTHESIS,
        $._TYPE,
        field("id", optional($.id)),
        field("functype", $.functype),
        $._RIGHT_PARENTHESIS,
      ),

    /*************
     * Type Uses *
     *************/

    // NOTE: we inline this because it matches the empty string
    // typeuse: $ =>
    //   alias(
    //     seq(
    //       optional(seq($._LEFT_PARENTHESIS, $._TYPE, field("typeidx", $.typeidx), $._RIGHT_PARENTHESIS)),
    //       field("param", repeat($.param)),
    //       field("param", repeat($.result)),
    //     ),
    //     "typeuse",
    //   ),

    /***********
     * Imports *
     ***********/

    import: $ =>
      seq(
        $._LEFT_PARENTHESIS,
        $._IMPORT,
        field("module", $.name),
        field("item", $.name),
        field("importdesc", $.importdesc),
        $._RIGHT_PARENTHESIS,
      ),

    importdesc: $ =>
      choice(
        field("func", $.importdesc_func),
        field("table", $.importdesc_table),
        field("memory", $.importdesc_memory),
        field("global", $.importdesc_global),
      ),

    importdesc_func: $ =>
      seq(
        $._LEFT_PARENTHESIS,
        $._FUNC,
        field("id", optional($.id)),
        // NOTE: see typeuse
        alias(
          seq(
            optional(seq($._LEFT_PARENTHESIS, $._TYPE, field("typeidx", $.typeidx), $._RIGHT_PARENTHESIS)),
            field("param", repeat($.param)),
            field("param", repeat($.result)),
          ),
          "typeuse",
        ),
        $._RIGHT_PARENTHESIS,
      ),

    importdesc_table: $ =>
      seq(
        $._LEFT_PARENTHESIS,
        $._TABLE,
        field("id", optional($.id)),
        field("tabletype", $.tabletype),
        $._RIGHT_PARENTHESIS,
      ),

    importdesc_memory: $ =>
      seq(
        $._LEFT_PARENTHESIS,
        $._MEMORY,
        field("id", optional($.id)),
        field("memtype", $.memtype),
        $._RIGHT_PARENTHESIS,
      ),

    importdesc_global: $ =>
      seq(
        $._LEFT_PARENTHESIS,
        $._GLOBAL,
        field("id", optional($.id)),
        field("globaltype", $.globaltype),
        $._RIGHT_PARENTHESIS,
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
          field("exports_imports", optional(seq($.inlineExport, repeat(choice($.inlineImport, $.inlineExport))))),
          alias(
            seq(
              optional(seq($._LEFT_PARENTHESIS, $._TYPE, field("typeidx", $.typeidx), $._RIGHT_PARENTHESIS)),
              field("param", repeat($.param)),
              field("param", repeat($.result)),
            ),
            "typeuse",
          ),
          field("local", repeat($.local)),
          field("instr", repeat($.instr)),
          $._RIGHT_PARENTHESIS,
        ),
        // abbreviation
        seq(
          $._LEFT_PARENTHESIS,
          $._FUNC,
          field("id", optional($.id)),
          field("import", $.inlineImport),
          alias(
            seq(
              optional(seq($._LEFT_PARENTHESIS, $._TYPE, field("typeidx", $.typeidx), $._RIGHT_PARENTHESIS)),
              field("param", repeat($.param)),
              field("param", repeat($.result)),
            ),
            "typeuse",
          ),
          $._RIGHT_PARENTHESIS,
        ),
      ),

    local: $ =>
      choice(
        // NOTE: re-factored to avoid conflict with abbreviation
        seq(
          $._LEFT_PARENTHESIS,
          $._LOCAL,
          optional(seq(field("id", $.id), field("valtype", $.valtype))),
          $._RIGHT_PARENTHESIS,
        ),
        // abbreviation
        seq($._LEFT_PARENTHESIS, $._LOCAL, field("valtype", repeat1($.valtype)), $._RIGHT_PARENTHESIS),
      ),

    inlineImport: $ =>
      seq($._LEFT_PARENTHESIS, $._IMPORT, field("module", $.name), field("item", $.name), $._RIGHT_PARENTHESIS),

    inlineExport: $ => seq($._LEFT_PARENTHESIS, $._EXPORT, field("item", $.name), $._RIGHT_PARENTHESIS),

    /**********
     * Tables *
     **********/

    table: $ =>
      choice(
        seq(
          $._LEFT_PARENTHESIS,
          $._TABLE,
          field("id", optional($.id)),
          // abbreviation
          field("exports_imports", optional(seq($.inlineExport, repeat(choice($.inlineImport, $.inlineExport))))),
          choice(
            field("tabletype", $.tabletype),
            // abbreviation
            // NOTE: are inline element segments allowed after inline imports?
            field(
              "elem",
              seq($.elemtype, $._LEFT_PARENTHESIS, $._ELEM, field("funcidx", repeat($.funcidx)), $._RIGHT_PARENTHESIS),
            ),
          ),
          $._RIGHT_PARENTHESIS,
        ),
        seq(
          $._LEFT_PARENTHESIS,
          $._TABLE,
          field("id", optional($.id)),
          // abbreviation
          field("import", $.inlineImport),
          choice(
            field("tabletype", $.tabletype),
            // abbreviation
            // NOTE: are inline element segments allowed after inline imports?
            field(
              "elem",
              seq($.elemtype, $._LEFT_PARENTHESIS, $._ELEM, field("funcidx", repeat($.funcidx)), $._RIGHT_PARENTHESIS),
            ),
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
          field("id", optional($.id)),
          // abbreviation
          field("exports_import", optional(seq($.inlineExport, repeat(choice($.inlineImport, $.inlineExport))))),
          choice(
            field("memtype", $.memtype),
            // abbreviation
            field(
              "data",
              seq(
                $._LEFT_PARENTHESIS,
                $._DATA,
                field("datastring", alias(repeat($._string), "datastring")),
                $._RIGHT_PARENTHESIS,
              ),
            ),
          ),
          $._RIGHT_PARENTHESIS,
        ),
        seq(
          $._LEFT_PARENTHESIS,
          field("id", optional($.id)),
          // abbreviation
          field("import", $.inlineImport),
          choice(
            field("memtype", $.memtype),
            // abbreviation
            field(
              "data",
              seq(
                $._LEFT_PARENTHESIS,
                $._DATA,
                field("datastring", alias(repeat($._string), "datastring")),
                $._RIGHT_PARENTHESIS,
              ),
            ),
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
          field("id", optional($.id)),
          // abbreviation
          field("exports_imports", optional(seq($.inlineExport, repeat(choice($.inlineImport, $.inlineExport))))),
          field("globaltype", $.globaltype),
          field("expr", alias(repeat($.instr), "expr")),
          $._RIGHT_PARENTHESIS,
        ),
        seq(
          $._LEFT_PARENTHESIS,
          $._GLOBAL,
          field("id", optional($.id)),
          // abbreviation
          field("import", $.inlineImport),
          field("globaltype", $.globaltype),
          $._RIGHT_PARENTHESIS,
        ),
      ),

    /***********
     * Exports *
     ***********/

    export: $ =>
      seq(
        $._LEFT_PARENTHESIS,
        $._EXPORT,
        field("item", $.name),
        field("exportdesc", $.exportdesc),
        $._RIGHT_PARENTHESIS,
      ),

    exportdesc: $ =>
      choice(
        seq($._LEFT_PARENTHESIS, $._FUNC, field("funcidx", $.funcidx), $._RIGHT_PARENTHESIS),
        seq($._LEFT_PARENTHESIS, $._TABLE, field("tableidx", $.tableidx), $._RIGHT_PARENTHESIS),
        seq($._LEFT_PARENTHESIS, $._MEMORY, field("memidx", $.memidx), $._RIGHT_PARENTHESIS),
        seq($._LEFT_PARENTHESIS, $._GLOBAL, field("globalidx", $.globalidx), $._RIGHT_PARENTHESIS),
      ),

    /******************
     * Start Function *
     ******************/

    start: $ => seq($._LEFT_PARENTHESIS, $._START, field("funcidx", $.funcidx), $._RIGHT_PARENTHESIS),

    /********************
     * Element Segments *
     ********************/

    elem: $ =>
      seq(
        $._LEFT_PARENTHESIS,
        $._ELEM,
        field("tableidx", optional($.tableidx)),
        choice(
          // abbreviation
          field("instr", $.instr),
          seq($._LEFT_PARENTHESIS, field("expr", alias(repeat($.instr), "expr")), $._RIGHT_PARENTHESIS),
        ),
        field("funcidx", repeat($.funcidx)),
        $._RIGHT_PARENTHESIS,
      ),

    /*****************
     * Data Segments *
     *****************/

    data: $ =>
      seq(
        $._LEFT_PARENTHESIS,
        $._DATA,
        field("memidx", optional($.memidx)),
        choice(
          // abbreviation
          field("instr", $.instr),
          seq($._LEFT_PARENTHESIS, $._OFFSET, field("expr", alias(repeat($.instr), "expr")), $._RIGHT_PARENTHESIS),
        ),
        field("datastring", alias(repeat($._string), "datastring")),
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
        field("field", repeat($._modulefield)),
        $._RIGHT_PARENTHESIS,
      ),

    _modulefield: $ => choice($.type, $.import, $.func, $.table, $.mem, $.global, $.export, $.start, $.elem, $.data),
  },
});
