// FIXME:
// 1. hide keyword rules
// 2. field must go inside repeat

module.exports = grammar({
  name: "wat",

  extras: $ => [$.comment, /[\s\uFEFF\u2060\u200B\u00A0]/],

  conflicts: $ => [
    [$._plaininstr],
    [$.blockinstr_block],
    [$.blockinstr_loop],
    [$.blockinstr_if],
    [$.blockinstr_if, $.foldedinstr_if],
    [$._instr, $.foldedinstr_if],
    [$._instr, $.foldedinstr_plain],
  ],

  rules: {
    ENTRYPOINT: $ => $.module,

    // ====================================================== //
    // =================== Lexical Format =================== //
    // ====================================================== //

    /**************
     * Whitespace *
     **************/

    // _space: $ => choice(" ", $._format, $.comment),

    // _format: $ => /[\t\n\r]/,

    /************
     * Comments *
     ************/

    comment: $ => token(prec(1, choice(seq(";;", /.*/), seq("(;", /[^;]*;+([^);][^;]*;+)*/, ")")))),

    // comment: $ => choice($.linecomment, $.blockcomment),

    // linecomment: $ => seq(";;", repeat($._linechar), "\n"),

    // _linechar: $ => $._utf8line,

    // blockcomment: $ => seq("(;", repeat($._blockchar), ";)"),

    // _blockchar: $ => choice(/[^;(]/, /;[^)]/, /\([^;]/, $.blockcomment),

    // ====================================================== //
    // ======================= Tokens ======================= //
    // ====================================================== //

    ALIGN_EQ: $ => "align=",
    BLOCK: $ => "block",
    BR_IF: $ => "br_if",
    BR_TABLE: $ => "br_table",
    BR: $ => "br",
    CALL_INDIRECT: $ => "call_indirect",
    CALL: $ => "call",
    DATA: $ => "data",
    DROP: $ => "drop",
    ELEM: $ => "elem",
    ELSE: $ => "else",
    END: $ => "end",
    EXPORT: $ => "export",
    FUNC: $ => "func",
    FUNCREF: $ => "funcref",
    GLOBAL_GET: $ => "global.get",
    GLOBAL_SET: $ => "global.set",
    GLOBAL: $ => "global",
    IF: $ => "if",
    IMPORT: $ => "import",
    LOCAL_GET: $ => "local.get",
    LOCAL_SET: $ => "local.set",
    LOCAL_TEE: $ => "local.tee",
    LOCAL: $ => "local",
    LOOP: $ => "loop",
    MEMORY_GROW: $ => "memory.grow",
    MEMORY_SIZE: $ => "memory.size",
    MEMORY: $ => "memory",
    MODULE: $ => "module",
    MUT: $ => "mut",
    NOP: $ => "nop",
    OFFSET_EQ: $ => "offset=",
    OFFSET: $ => "offset",
    PARAM: $ => "param",
    RESULT: $ => "result",
    RETURN: $ => "return",
    SELECT: $ => "select",
    START: $ => "start",
    TABLE: $ => "table",
    THEN: $ => "then",
    TYPE: $ => "type",
    UNREACHABLE: $ => "unreachable",

    F32_ABS: $ => "f32.abs",
    F32_ADD: $ => "f32.add",
    F32_CEIL: $ => "f32.ceil",
    F32_CONVERT_I32_S: $ => "f32.convert_i32_s",
    F32_CONVERT_I32_U: $ => "f32.convert_i32_u",
    F32_CONVERT_I64_S: $ => "f32.convert_i64_s",
    F32_CONVERT_I64_U: $ => "f32.convert_i64_u",
    F32_CONST: $ => "f32.const",
    F32_COPYSIGN: $ => "f32.copysign",
    F32_DEMOTE_F64: $ => "f32.demote_f64",
    F32_DIV: $ => "f32.div",
    F32_EQ: $ => "f32.eq",
    F32_FLOOR: $ => "f32.floor",
    F32_GE: $ => "f32.ge",
    F32_GT: $ => "f32.gt",
    F32_LE: $ => "f32.le",
    F32_LOAD: $ => "f32.load",
    F32_LT: $ => "f32.lt",
    F32_MAX: $ => "f32.max",
    F32_MIN: $ => "f32.min",
    F32_MUL: $ => "f32.mul",
    F32_NE: $ => "f32.ne",
    F32_NEAREST: $ => "f32.nearest",
    F32_NEG: $ => "f32.neg",
    F32_REINTERPRET_I32: $ => "f32.reinterpret_i32",
    F32_REINTERPRET_I64: $ => "f32.reinterpret_i64",
    F32_SQRT: $ => "f32.sqrt",
    F32_STORE: $ => "f32.store",
    F32_SUB: $ => "f32.sub",
    F32_TRUNC: $ => "f32.trunc",

    F64_ABS: $ => "f64.abs",
    F64_ADD: $ => "f64.add",
    F64_CEIL: $ => "f64.ceil",
    F64_CONST: $ => "f64.const",
    F64_CONVERT_I32_S: $ => "f64.convert_i32_s",
    F64_CONVERT_I32_U: $ => "f64.convert_i32_u",
    F64_CONVERT_I64_S: $ => "f64.convert_i64_s",
    F64_CONVERT_I64_U: $ => "f64.convert_i64_u",
    F64_COPYSIGN: $ => "f64.copysign",
    F64_DIV: $ => "f64.div",
    F64_EQ: $ => "f64.eq",
    F64_FLOOR: $ => "f64.floor",
    F64_GE: $ => "f64.ge",
    F64_GT: $ => "f64.gt",
    F64_LE: $ => "f64.le",
    F64_LOAD: $ => "f64.load",
    F64_LT: $ => "f64.lt",
    F64_MAX: $ => "f64.max",
    F64_MIN: $ => "f64.min",
    F64_MUL: $ => "f64.mul",
    F64_NE: $ => "f64.ne",
    F64_NEAREST: $ => "f64.nearest",
    F64_NEG: $ => "f64.neg",
    F64_PROMOTE_F32: $ => "f64.promote_f32",
    F64_REINTERPRET_I32: $ => "f64.reinterpret_i32",
    F64_REINTERPRET_I64: $ => "f64.reinterpret_i64",
    F64_SQRT: $ => "f64.sqrt",
    F64_STORE: $ => "f64.store",
    F64_SUB: $ => "f64.sub",
    F64_TRUNC: $ => "f64.trunc",

    I32_ADD: $ => "i32.add",
    I32_AND: $ => "i32.and",
    I32_CLZ: $ => "i32.clz",
    I32_CONST: $ => "i32.const",
    I32_CTZ: $ => "i32.ctz",
    I32_DIV_S: $ => "i32.div_s",
    I32_DIV_U: $ => "i32.div_u",
    I32_EQ: $ => "i32.eq",
    I32_EQZ: $ => "i32.eqz",
    I32_GE_S: $ => "i32.ge_s",
    I32_GE_U: $ => "i32.ge_u",
    I32_GT_S: $ => "i32.gt_s",
    I32_GT_U: $ => "i32.gt_u",
    I32_LE_S: $ => "i32.le_s",
    I32_LE_U: $ => "i32.le_u",
    I32_LOAD: $ => "i32.load",
    I32_LOAD8_S: $ => "i32.load8_s",
    I32_LOAD8_U: $ => "i32.load8_u",
    I32_LOAD16_S: $ => "i32.load16_s",
    I32_LOAD16_U: $ => "i32.load16_u",
    I32_LT_S: $ => "i32.lt_s",
    I32_LT_U: $ => "i32.lt_u",
    I32_MUL: $ => "i32.mul",
    I32_NE: $ => "i32.ne",
    I32_OR: $ => "i32.or",
    I32_POPCNT: $ => "i32.popcnt",
    I32_REINTERPRET_F32: $ => "i32.reinterpret_f32",
    I32_REINTERPRET_F64: $ => "i32.reinterpret_f64",
    I32_REM_S: $ => "i32.rem_s",
    I32_REM_U: $ => "i32.rem_u",
    I32_ROTL: $ => "i32.rotl",
    I32_ROTR: $ => "i32.rotr",
    I32_SHL: $ => "i32.shl",
    I32_SHR_S: $ => "i32.shr_s",
    I32_SHR_U: $ => "i32.shr_u",
    I32_STORE: $ => "i32.store",
    I32_STORE8: $ => "i32.store8",
    I32_STORE16: $ => "i32.store16",
    I32_SUB: $ => "i32.sub",
    I32_TRUNC_F32_S: $ => "i32.trunc_f32_s",
    I32_TRUNC_F32_U: $ => "i32.trunc_f32_u",
    I32_TRUNC_F64_S: $ => "i32.trunc_f64_s",
    I32_TRUNC_F64_U: $ => "i32.trunc_f64_u",
    I32_WRAP_I64: $ => "i32.wrap_i64",
    I32_XOR: $ => "i32.xor",

    I64_ADD: $ => "i64.add",
    I64_AND: $ => "i64.and",
    I64_CLZ: $ => "i64.clz",
    I64_CONST: $ => "i644.const",
    I64_CTZ: $ => "i64.ctz",
    I64_DIV_S: $ => "i64.div_s",
    I64_DIV_U: $ => "i64.div_u",
    I64_EXTEND_I32_S: $ => "i64.extend_i32_s",
    I64_EXTEND_I32_U: $ => "i64.extend_i32_u",
    I64_EQ: $ => "i64.eq",
    I64_EQZ: $ => "i64.eqz",
    I64_GE_S: $ => "i64.ge_s",
    I64_GE_U: $ => "i64.ge_u",
    I64_GT_S: $ => "i64.gt_s",
    I64_GT_U: $ => "i64.gt_u",
    I64_LE_S: $ => "i64.le_s",
    I64_LE_U: $ => "i64.le_u",
    I64_LOAD: $ => "i64.load",
    I64_LOAD8_S: $ => "i64.load8_s",
    I64_LOAD8_U: $ => "i64.load8_u",
    I64_LOAD16_S: $ => "i64.load16_s",
    I64_LOAD16_U: $ => "i64.load16_u",
    I64_LOAD32_S: $ => "i64.load32_s",
    I64_LOAD32_U: $ => "i64.load32_u",
    I64_LT_S: $ => "i64.lt_s",
    I64_LT_U: $ => "i64.lt_u",
    I64_MUL: $ => "i64.mul",
    I64_NE: $ => "i64.ne",
    I64_OR: $ => "i64.or",
    I64_POPCNT: $ => "i64.popcnt",
    I64_REINTERPRET_F32: $ => "i64.reinterpret_f32",
    I64_REINTERPRET_F64: $ => "i64.reinterpret_f64",
    I64_REM_S: $ => "i64.rem_s",
    I64_REM_U: $ => "i64.rem_u",
    I64_ROTL: $ => "i64.rotl",
    I64_ROTR: $ => "i64.rotr",
    I64_SHL: $ => "i64.shl",
    I64_SHR_S: $ => "i64.shr_s",
    I64_SHR_U: $ => "i64.shr_u",
    I64_STORE: $ => "i64.store",
    I64_STORE8: $ => "i64.store8",
    I64_STORE16: $ => "i64.store16",
    I64_STORE32: $ => "i64.store32",
    I64_SUB: $ => "i64.sub",
    I64_TRUNC_F32_S: $ => "i64.trunc_f32_s",
    I64_TRUNC_F32_U: $ => "i64.trunc_f32_u",
    I64_TRUNC_F64_S: $ => "i64.trunc_f64_s",
    I64_TRUNC_F64_U: $ => "i64.trunc_f64_u",
    I64_XOR: $ => "i64.xor",

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

    uN: $ => /(?:[0-9]|[0-9]+(?:_?[0-9]+)*)|(?:0x[0-9A-Fa-f]|[0-9A-Fa-f]+(?:_?[0-9A-Fa-f]+)*)/,

    _sN: $ => /(?:[+-]?[0-9]|[0-9]+(?:_?[0-9]+)*)|(?:[+-]?0x[0-9A-Fa-f]|[0-9A-Fa-f]+(?:_?[0-9A-Fa-f]+)*)/,

    iN: $ => choice($.uN, $._sN),

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

    fN: $ => seq(optional($._sign), $._fNmag),

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

    name: $ => $._string,

    /***************
     * Identifiers *
     ***************/

    id: $ => /\$[0-9A-Za-z!#$%&'*+-./:<=>?@\\^_'|~]+/,

    // ====================================================== //
    // ======================== Types ======================= //
    // ====================================================== //

    valtype: $ => choice("i32", "i64", "f32", "f64"),

    /****************
     * Result Types *
     ****************/

    resulttype: $ => $.result,

    /******************
     * Function Types *
     ******************/

    functype: $ => seq("(", $.FUNC, repeat(field("param", $.param)), repeat(field("result", $.result)), ")"),

    param: $ =>
      choice(
        // NOTE: re-factored to avoid conflict with abbreviation
        seq("(", $.PARAM, optional(seq(field("id", $.id), field("valtype", $.valtype))), ")"),
        // abbreviation
        seq("(", $.PARAM, repeat1(field("valtype", $.valtype)), ")"),
      ),

    result: $ => seq("(", $.RESULT, repeat(field("valtype", $.valtype)), ")"),

    /**********
     * Limits *
     **********/

    limits: $ => seq(field("min", $.uN), optional(field("max", $.uN))),

    /****************
     * Memory Types *
     ****************/

    memtype: $ => $.limits,

    /***************
     * Table Types *
     ***************/

    tabletype: $ => seq(field("limits", $.limits), field("elemtype", $.elemtype)),

    elemtype: $ => $.FUNCREF,

    /****************
     * Global Types *
     ****************/

    globaltype: $ => choice(field("valtype", $.valtype), seq("(", $.MUT, field("valtype", $.valtype), ")")),

    // ====================================================== //
    // ==================== Instructions ==================== //
    // ====================================================== //

    _instr: $ => choice($._plaininstr, $._blockinstr, $._foldedinstr),

    /**********
     * Labels *
     **********/

    // NOTE: we inline this because it matches the empty string
    // label: $ => optional($.id),

    /************************
     * Control Instructions *
     ************************/

    _blockinstr: $ => choice($.blockinstr_block, $.blockinstr_loop, $.blockinstr_if),

    blockinstr_block: $ =>
      seq(
        $.BLOCK,
        alias(optional(field("label", $.id)), "label"),
        field("resulttype", $.resulttype),
        repeat(field("instr", $._instr)),
        $.END,
        optional(field("id", $.id)),
      ),

    blockinstr_loop: $ =>
      seq(
        $.LOOP,
        alias(optional(field("label", $.id)), "label"),
        field("resulttype", $.resulttype),
        repeat(field("instr", $._instr)),
        $.END,
        optional(field("id", $.id)),
      ),

    blockinstr_if: $ =>
      seq(
        $.IF,
        alias(optional(field("label", $.id)), "label"),
        field("resulttype", $.resulttype),
        repeat(field("instr0", $._instr)),
        choice(
          seq(
            $.ELSE,
            optional(field("id0", $.id)),
            repeat(field("instr1", $._instr)),
            $.END,
            optional(field("id1", $.id)),
          ),
          // abbreviation
          $.END,
          optional(field("id0", $.id)),
        ),
      ),

    _plaininstr: $ =>
      choice(
        field("plain", $.UNREACHABLE),
        field("plain", $.NOP),
        seq(field("plain", $.BR), field("labelidx", $.labelidx)),
        seq(field("plain", $.BR_IF), field("labelidx", $.labelidx)),
        seq(field("plain", $.BR_TABLE), repeat(field("labelidx0", $.labelidx)), field("labelidx1", $.labelidx)),
        field("plain", $.RETURN),
        seq(field("plain", $.CALL), $.funcidx),
        seq(
          field("plain", $.CALL_INDIRECT),
          field(
            "typeuse",
            alias(
              seq(
                optional(seq("(", "type", field("typeidx", $.typeidx), ")")),
                repeat(field("param", $.param)),
                repeat(field("param", $.result)),
              ),
              "typeuse",
            ),
          ),
        ),

        /***************************
         * Parametric Instructions *
         ***************************/

        field("plain", $.DROP),
        field("plain", $.SELECT),

        /*************************
         * Variable Instructions *
         *************************/

        seq(field("plain", $.LOCAL_GET), field("localidx", $.localidx)),
        seq(field("plain", $.LOCAL_SET), field("localidx", $.localidx)),
        seq(field("plain", $.LOCAL_TEE), field("localidx", $.localidx)),
        seq(field("plain", $.GLOBAL_GET), field("globalidx", $.globalidx)),
        seq(field("plain", $.GLOBAL_SET), field("globalidx", $.globalidx)),

        /***********************
         * Memory Instructions *
         ***********************/

        seq(
          field("plain", $.F32_LOAD),
          alias(
            seq(optional(field("offset", seq($.OFFSET_EQ, $.uN))), optional(field("align", seq($.ALIGN_EQ, $.uN)))),
            "memarg",
          ),
        ),
        seq(
          field("plain", $.F64_LOAD),
          alias(
            seq(optional(field("offset", seq($.OFFSET_EQ, $.uN))), optional(field("align", seq($.ALIGN_EQ, $.uN)))),
            "memarg",
          ),
        ),
        seq(
          field("plain", $.I32_LOAD),
          alias(
            seq(optional(field("offset", seq($.OFFSET_EQ, $.uN))), optional(field("align", seq($.ALIGN_EQ, $.uN)))),
            "memarg",
          ),
        ),
        seq(
          field("plain", $.I32_LOAD8_S),
          alias(
            seq(optional(field("offset", seq($.OFFSET_EQ, $.uN))), optional(field("align", seq($.ALIGN_EQ, $.uN)))),
            "memarg",
          ),
        ),
        seq(
          field("plain", $.I32_LOAD8_U),
          alias(
            seq(optional(field("offset", seq($.OFFSET_EQ, $.uN))), optional(field("align", seq($.ALIGN_EQ, $.uN)))),
            "memarg",
          ),
        ),
        seq(
          field("plain", $.I32_LOAD16_S),
          alias(
            seq(optional(field("offset", seq($.OFFSET_EQ, $.uN))), optional(field("align", seq($.ALIGN_EQ, $.uN)))),
            "memarg",
          ),
        ),
        seq(
          field("plain", $.I32_LOAD16_U),
          alias(
            seq(optional(field("offset", seq($.OFFSET_EQ, $.uN))), optional(field("align", seq($.ALIGN_EQ, $.uN)))),
            "memarg",
          ),
        ),
        seq(
          field("plain", $.I32_STORE),
          alias(
            seq(optional(field("offset", seq($.OFFSET_EQ, $.uN))), optional(field("align", seq($.ALIGN_EQ, $.uN)))),
            "memarg",
          ),
        ),
        seq(
          field("plain", $.I32_STORE8),
          alias(
            seq(optional(field("offset", seq($.OFFSET_EQ, $.uN))), optional(field("align", seq($.ALIGN_EQ, $.uN)))),
            "memarg",
          ),
        ),
        seq(
          field("plain", $.I32_STORE16),
          alias(
            seq(optional(field("offset", seq($.OFFSET_EQ, $.uN))), optional(field("align", seq($.ALIGN_EQ, $.uN)))),
            "memarg",
          ),
        ),
        seq(
          field("plain", $.I64_LOAD),
          alias(
            seq(optional(field("offset", seq($.OFFSET_EQ, $.uN))), optional(field("align", seq($.ALIGN_EQ, $.uN)))),
            "memarg",
          ),
        ),
        seq(
          field("plain", $.I64_LOAD8_S),
          alias(
            seq(optional(field("offset", seq($.OFFSET_EQ, $.uN))), optional(field("align", seq($.ALIGN_EQ, $.uN)))),
            "memarg",
          ),
        ),
        seq(
          field("plain", $.I64_LOAD8_U),
          alias(
            seq(optional(field("offset", seq($.OFFSET_EQ, $.uN))), optional(field("align", seq($.ALIGN_EQ, $.uN)))),
            "memarg",
          ),
        ),
        seq(
          field("plain", $.I64_LOAD16_S),
          alias(
            seq(optional(field("offset", seq($.OFFSET_EQ, $.uN))), optional(field("align", seq($.ALIGN_EQ, $.uN)))),
            "memarg",
          ),
        ),
        seq(
          field("plain", $.I64_LOAD16_U),
          alias(
            seq(optional(field("offset", seq($.OFFSET_EQ, $.uN))), optional(field("align", seq($.ALIGN_EQ, $.uN)))),
            "memarg",
          ),
        ),
        seq(
          field("plain", $.I64_LOAD32_S),
          alias(
            seq(optional(field("offset", seq($.OFFSET_EQ, $.uN))), optional(field("align", seq($.ALIGN_EQ, $.uN)))),
            "memarg",
          ),
        ),
        seq(
          field("plain", $.I64_LOAD32_U),
          alias(
            seq(optional(field("offset", seq($.OFFSET_EQ, $.uN))), optional(field("align", seq($.ALIGN_EQ, $.uN)))),
            "memarg",
          ),
        ),
        seq(
          field("plain", $.I64_STORE),
          alias(
            seq(optional(field("offset", seq($.OFFSET_EQ, $.uN))), optional(field("align", seq($.ALIGN_EQ, $.uN)))),
            "memarg",
          ),
        ),
        seq(
          field("plain", $.I64_STORE8),
          alias(
            seq(optional(field("offset", seq($.OFFSET_EQ, $.uN))), optional(field("align", seq($.ALIGN_EQ, $.uN)))),
            "memarg",
          ),
        ),
        seq(
          field("plain", $.I64_STORE16),
          alias(
            seq(optional(field("offset", seq($.OFFSET_EQ, $.uN))), optional(field("align", seq($.ALIGN_EQ, $.uN)))),
            "memarg",
          ),
        ),
        seq(
          field("plain", $.I64_STORE32),
          alias(
            seq(optional(field("offset", seq($.OFFSET_EQ, $.uN))), optional(field("align", seq($.ALIGN_EQ, $.uN)))),
            "memarg",
          ),
        ),
        field("plain", $.MEMORY_SIZE),
        field("plain", $.MEMORY_GROW),

        /************************
         * Numeric Instructions *
         ************************/

        seq(field("plain", $.I32_CONST), field("value", $.iN)),
        seq(field("plain", $.I64_CONST), field("value", $.iN)),
        seq(field("plain", $.F32_CONST), field("value", $.fN)),
        seq(field("plain", $.F64_CONST), field("value", $.fN)),

        field("plain", $.F32_ABS),
        field("plain", $.F32_ADD),
        field("plain", $.F32_CEIL),
        field("plain", $.F32_CONVERT_I32_S),
        field("plain", $.F32_CONVERT_I32_U),
        field("plain", $.F32_CONVERT_I64_S),
        field("plain", $.F32_CONVERT_I64_U),
        field("plain", $.F32_COPYSIGN),
        field("plain", $.F32_DEMOTE_F64),
        field("plain", $.F32_DIV),
        field("plain", $.F32_EQ),
        field("plain", $.F32_FLOOR),
        field("plain", $.F32_GE),
        field("plain", $.F32_GT),
        field("plain", $.F32_LE),
        field("plain", $.F32_LT),
        field("plain", $.F32_MAX),
        field("plain", $.F32_MIN),
        field("plain", $.F32_MUL),
        field("plain", $.F32_NE),
        field("plain", $.F32_NEAREST),
        field("plain", $.F32_NEG),
        field("plain", $.F32_REINTERPRET_I32),
        field("plain", $.F32_REINTERPRET_I64),
        field("plain", $.F32_SQRT),
        field("plain", $.F32_SUB),
        field("plain", $.F32_TRUNC),

        field("plain", $.F64_ABS),
        field("plain", $.F64_ADD),
        field("plain", $.F64_CEIL),
        field("plain", $.F64_CONVERT_I32_S),
        field("plain", $.F64_CONVERT_I32_U),
        field("plain", $.F64_CONVERT_I64_S),
        field("plain", $.F64_CONVERT_I64_U),
        field("plain", $.F64_COPYSIGN),
        field("plain", $.F64_DIV),
        field("plain", $.F64_EQ),
        field("plain", $.F64_FLOOR),
        field("plain", $.F64_GE),
        field("plain", $.F64_GT),
        field("plain", $.F64_LE),
        field("plain", $.F64_LT),
        field("plain", $.F64_MAX),
        field("plain", $.F64_MIN),
        field("plain", $.F64_MUL),
        field("plain", $.F64_NE),
        field("plain", $.F64_NEAREST),
        field("plain", $.F64_NEG),
        field("plain", $.F64_PROMOTE_F32),
        field("plain", $.F64_REINTERPRET_I32),
        field("plain", $.F64_REINTERPRET_I64),
        field("plain", $.F64_SQRT),
        field("plain", $.F64_SUB),
        field("plain", $.F64_TRUNC),

        field("plain", $.I32_ADD),
        field("plain", $.I32_AND),
        field("plain", $.I32_CLZ),
        field("plain", $.I32_CTZ),
        field("plain", $.I32_DIV_S),
        field("plain", $.I32_DIV_U),
        field("plain", $.I32_EQ),
        field("plain", $.I32_EQZ),
        field("plain", $.I32_GE_S),
        field("plain", $.I32_GE_U),
        field("plain", $.I32_GT_S),
        field("plain", $.I32_GT_U),
        field("plain", $.I32_LE_S),
        field("plain", $.I32_LE_U),
        field("plain", $.I32_LT_S),
        field("plain", $.I32_LT_U),
        field("plain", $.I32_MUL),
        field("plain", $.I32_NE),
        field("plain", $.I32_OR),
        field("plain", $.I32_POPCNT),
        field("plain", $.I32_REINTERPRET_F32),
        field("plain", $.I32_REINTERPRET_F64),
        field("plain", $.I32_REM_S),
        field("plain", $.I32_REM_U),
        field("plain", $.I32_ROTL),
        field("plain", $.I32_ROTR),
        field("plain", $.I32_SHL),
        field("plain", $.I32_SHR_S),
        field("plain", $.I32_SHR_U),
        field("plain", $.I32_SUB),
        field("plain", $.I32_TRUNC_F32_S),
        field("plain", $.I32_TRUNC_F32_U),
        field("plain", $.I32_TRUNC_F64_S),
        field("plain", $.I32_TRUNC_F64_U),
        field("plain", $.I32_XOR),

        field("plain", $.I64_ADD),
        field("plain", $.I64_AND),
        field("plain", $.I64_CLZ),
        field("plain", $.I64_CTZ),
        field("plain", $.I64_DIV_S),
        field("plain", $.I64_DIV_U),
        field("plain", $.I64_EQ),
        field("plain", $.I64_EQZ),
        field("plain", $.I64_EXTEND_I32_S),
        field("plain", $.I64_EXTEND_I32_U),
        field("plain", $.I64_GE_S),
        field("plain", $.I64_GE_U),
        field("plain", $.I64_GT_S),
        field("plain", $.I64_GT_U),
        field("plain", $.I64_LE_S),
        field("plain", $.I64_LE_U),
        field("plain", $.I64_LT_S),
        field("plain", $.I64_LT_U),
        field("plain", $.I64_MUL),
        field("plain", $.I64_NE),
        field("plain", $.I64_OR),
        field("plain", $.I64_POPCNT),
        field("plain", $.I64_REINTERPRET_F32),
        field("plain", $.I64_REINTERPRET_F64),
        field("plain", $.I64_REM_S),
        field("plain", $.I64_REM_U),
        field("plain", $.I64_ROTL),
        field("plain", $.I64_ROTR),
        field("plain", $.I64_SHL),
        field("plain", $.I64_SHR_S),
        field("plain", $.I64_SHR_U),
        field("plain", $.I64_SUB),
        field("plain", $.I64_TRUNC_F32_S),
        field("plain", $.I64_TRUNC_F32_U),
        field("plain", $.I64_TRUNC_F64_S),
        field("plain", $.I64_TRUNC_F64_U),
        field("plain", $.I64_XOR),
      ),

    // NOTE: we inline this because it matches the empty string
    // memarg: $ => seq(optional(seq($.OFFSET_EQ, $.uN)), optional(seq($.ALIGN_EQ, $.uN))),

    /***********************
     * Folded Instructions *
     ***********************/

    _foldedinstr: $ => choice($.foldedinstr_plain, $.foldedinstr_block, $.foldedinstr_loop, $.foldedinstr_if),

    foldedinstr_plain: $ => seq("(", $._plaininstr, repeat(field("folded", $._foldedinstr)), ")"),

    foldedinstr_block: $ =>
      seq(
        "(",
        $.BLOCK,
        alias(optional(field("label", $.id)), "label"),
        field("resulttype", $.resulttype),
        repeat(field("instr", $._instr)),
        ")",
      ),

    foldedinstr_loop: $ =>
      seq(
        "(",
        $.LOOP,
        alias(optional(field("label", $.id)), "label"),
        field("resulttype", $.resulttype),
        repeat(field("instr", $._instr)),
        ")",
      ),

    foldedinstr_if: $ =>
      seq(
        "(",
        $.IF,
        alias(optional(field("label", $.id)), "label"),
        field("resulttype", $.resulttype),
        repeat(field("foldedinstr", $._foldedinstr)),
        field("then", seq("(", $.THEN, repeat(field("instr", $._instr)), ")")),
        optional(field("else", seq("(", $.ELSE, repeat(field("instr", $._instr)), ")"))),
        ")",
      ),

    /***************
     * Expressions *
     ***************/

    // NOTE: we inline this because it matches the empty string
    // expr: $ => repeat($._instr),

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

    type: $ => seq("(", $.TYPE, optional(field("id", $.id)), field("functype", $.functype), ")"),

    /*************
     * Type Uses *
     *************/

    // NOTE: we inline this because it matches the empty string
    // typeuse: $ =>
    //   alias(
    //     seq(
    //       optional(seq("(", $.TYPE, field("typeidx", $.typeidx), ")")),
    //       field("param", repeat($.param)),
    //       field("param", repeat($.result)),
    //     ),
    //     "typeuse",
    //   ),

    /***********
     * Imports *
     ***********/

    import: $ =>
      seq("(", $.IMPORT, field("module", $.name), field("item", $.name), field("importdesc", $._importdesc), ")"),

    _importdesc: $ => choice($.importdesc_func, $.importdesc_table, $.importdesc_memory, $.importdesc_global),

    importdesc_func: $ =>
      seq(
        "(",
        $.FUNC,
        optional(field("id", $.id)),
        // NOTE: see typeuse
        alias(
          seq(
            optional(seq("(", $.TYPE, field("typeidx", $.typeidx), ")")),
            repeat(field("param", $.param)),
            repeat(field("result", $.result)),
          ),
          "typeuse",
        ),
        ")",
      ),

    importdesc_table: $ => seq("(", $.TABLE, optional(field("id", $.id)), field("tabletype", $.tabletype), ")"),

    importdesc_memory: $ => seq("(", $.MEMORY, optional(field("id", $.id)), field("memtype", $.memtype), ")"),

    importdesc_global: $ => seq("(", $.GLOBAL, optional(field("id", $.id)), field("globaltype", $.globaltype), ")"),

    /*************
     * Functions *
     *************/

    func: $ =>
      choice(
        seq(
          "(",
          $.FUNC,
          optional(field("id", $.id)),
          // abbreviation
          optional(field("exports_imports", seq($.inlineExport, repeat(choice($.inlineImport, $.inlineExport))))),
          alias(
            seq(
              optional(seq("(", $.TYPE, field("typeidx", $.typeidx), ")")),
              repeat(field("param", $.param)),
              repeat(field("result", $.result)),
            ),
            "typeuse",
          ),
          repeat(field("local", $.local)),
          repeat(field("instr", $._instr)),
          ")",
        ),
        // abbreviation
        seq(
          "(",
          $.FUNC,
          optional(field("id", $.id)),
          field("import", $.inlineImport),
          alias(
            seq(
              optional(seq("(", $.TYPE, field("typeidx", $.typeidx), ")")),
              repeat(field("param", $.param)),
              repeat(field("result", $.result)),
            ),
            "typeuse",
          ),
          ")",
        ),
      ),

    local: $ =>
      choice(
        // NOTE: re-factored to avoid conflict with abbreviation
        seq("(", $.LOCAL, optional(seq(field("id", $.id), field("valtype", $.valtype))), ")"),
        // abbreviation
        seq("(", $.LOCAL, repeat1(field("valtype", $.valtype)), ")"),
      ),

    inlineImport: $ => seq("(", $.IMPORT, field("module", $.name), field("item", $.name), ")"),

    inlineExport: $ => seq("(", $.EXPORT, field("item", $.name), ")"),

    /**********
     * Tables *
     **********/

    table: $ =>
      choice(
        seq(
          "(",
          $.TABLE,
          optional(field("id", $.id)),
          // abbreviation
          optional(field("exports_imports", seq($.inlineExport, repeat(choice($.inlineImport, $.inlineExport))))),
          choice(
            field("tabletype", $.tabletype),
            // abbreviation
            // NOTE: are inline element segments allowed after inline imports?
            field("elem", seq($.elemtype, "(", $.ELEM, repeat(field("funcidx", $.funcidx)), ")")),
          ),
          ")",
        ),
        seq(
          "(",
          $.TABLE,
          optional(field("id", $.id)),
          // abbreviation
          field("import", $.inlineImport),
          choice(
            field("tabletype", $.tabletype),
            // abbreviation
            // NOTE: are inline element segments allowed after inline imports?
            field("elem", seq($.elemtype, "(", $.ELEM, repeat(field("funcidx", $.funcidx)), ")")),
          ),
          ")",
        ),
      ),

    /************
     * Memories *
     ************/

    mem: $ =>
      choice(
        seq(
          "(",
          $.MEMORY,
          optional(field("id", $.id)),
          // abbreviation
          optional(field("exports_import", seq($.inlineExport, repeat(choice($.inlineImport, $.inlineExport))))),
          choice(
            field("memtype", $.memtype),
            // abbreviation
            field("data", seq("(", $.DATA, alias(repeat(field("datastring", $._string)), "datastring"), ")")),
          ),
          ")",
        ),
        seq(
          "(",
          $.MEMORY,
          optional(field("id", $.id)),
          // abbreviation
          field("import", $.inlineImport),
          choice(
            field("memtype", $.memtype),
            // abbreviation
            field("data", seq("(", $.DATA, alias(repeat(field("datastring", $._string)), "datastring"), ")")),
          ),
          ")",
        ),
      ),

    /***********
     * Globals *
     ***********/

    global: $ =>
      choice(
        seq(
          "(",
          $.GLOBAL,
          optional(field("id", $.id)),
          // abbreviation
          optional(field("exports_imports", seq($.inlineExport, repeat(choice($.inlineImport, $.inlineExport))))),
          field("globaltype", $.globaltype),
          alias(repeat(field("expr", $._instr)), "expr"),
          ")",
        ),
        seq(
          "(",
          $.GLOBAL,
          optional(field("id", $.id)),
          // abbreviation
          field("import", $.inlineImport),
          field("globaltype", $.globaltype),
          ")",
        ),
      ),

    /***********
     * Exports *
     ***********/

    export: $ => seq("(", $.EXPORT, field("item", $.name), field("exportdesc", $._exportdesc), ")"),

    _exportdesc: $ => choice($.exportdesc_func, $.exportdesc_table, $.exportdesc_memory, $.exportdesc_global),

    exportdesc_func: $ => seq("(", $.FUNC, field("funcidx", $.funcidx), ")"),

    exportdesc_table: $ => seq("(", $.TABLE, field("tableidx", $.tableidx), ")"),

    exportdesc_memory: $ => seq("(", $.MEMORY, field("memidx", $.memidx), ")"),

    exportdesc_global: $ => seq("(", $.GLOBAL, field("globalidx", $.globalidx), ")"),

    /******************
     * Start Function *
     ******************/

    start: $ => seq("(", $.START, field("funcidx", $.funcidx), ")"),

    /********************
     * Element Segments *
     ********************/

    elem: $ =>
      seq(
        "(",
        $.ELEM,
        optional(field("tableidx", $.tableidx)),
        choice(
          // abbreviation
          field("instr", $._instr),
          seq("(", alias(repeat(field("expr", $._instr)), "expr"), ")"),
        ),
        repeat(field("funcidx", $.funcidx)),
        ")",
      ),

    /*****************
     * Data Segments *
     *****************/

    data: $ =>
      seq(
        "(",
        $.DATA,
        optional(field("memidx", $.memidx)),
        choice(
          // abbreviation
          field("instr", $._instr),
          seq("(", $.OFFSET, alias(repeat(field("expr", $._instr)), "expr"), ")"),
        ),
        alias(repeat(field("datastring", $._string)), "datastring"),
        ")",
      ),

    // NOTE: we inline this because it matches the empty string
    // datastring: $ => repeat($._string),

    /***********
     * Modules *
     ***********/

    module: $ => seq("(", $.MODULE, optional(field("id", $.id)), repeat(field("field", $._modulefield)), ")"),

    _modulefield: $ => choice($.type, $.import, $.func, $.table, $.mem, $.global, $.export, $.start, $.elem, $.data),
  },
});
