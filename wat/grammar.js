module.exports = grammar({
  name: "wat",

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

    ALIGN_EQ_NAT: $ => seq("align=", $._nat),

    ASSERT_EXHAUSTION: $ => "assert_exhaustion",

    ASSERT_INVALID: $ => "assert_invalid",

    ASSERT_MALFORMED: $ => "assert_malformed",

    ASSERT_RETURN: $ => "assert_return",

    ASSERT_TRAP: $ => "assert_trap",

    ASSERT_UNLINKABLE: $ => "assert_unlinkable",

    BIN: $ => "binary",

    BINARY: $ =>
      choice(
        seq(
          $._ixx,
          ".",
          choice(
            "add",
            "sub",
            "mul",
            "div_s",
            "div_u",
            "rem_s",
            "rem_u",
            "and",
            "or",
            "xor",
            "shl",
            "shr_s",
            "shr_u",
            "rotl",
            "rotr",
          ),
        ),
        seq($._fxx, ".", choice("add", "sub", "mul", "div", "min", "max", "copysign")),
      ),

    BLOCK: $ => "block",

    BR: $ => "br",

    BR_IF: $ => "br_if",

    BR_TABLE: $ => "br_table",

    CALL: $ => "call",

    CALL_INDIRECT: $ => "call_indirect",

    COMPARE: $ =>
      choice(
        seq($._ixx, ".", choice("eq", "ne", "lt_s", "lt_u", "le_s", "le_u", "gt_s", "gt_u", "ge_s", "ge_u")),
        seq($._fxx, ".", choice("eq", "ne", "lt", "le", "gt", "ge")),
      ),

    CONST: $ => seq($._nxx, ".const"),

    CONVERT: $ =>
      choice(
        seq("i32", ".", "wrap_i64"),
        seq("i64", ".", "extend_i32_s"),
        seq("i64", ".", "extend_i32_u"),
        seq("f32", ".", "demote_f64"),
        seq("f64", ".", "promote_f32"),
        seq($._ixx, ".", choice("trunc_f32_s", "trunc_f32_u", "trunc_f64_s", "trunc_f64_u")),
        seq($._fxx, ".", choice("convert_i32_s", "convert_i32_u", "convert_i64_s", "convert_i64_u")),
        seq("f32", ".", "reinterpret_i32"),
        seq("f64", ".", "reinterpret_i64"),
        seq("i32", ".", "reinterpret_f32"),
        seq("i64", ".", "reinterpret_f64"),
      ),

    DROP: $ => "drop",

    ELEM: $ => "elem",

    ELSE: $ => "else",

    END: $ => "end",

    EXPORT: $ => "export",

    DATA: $ => "data",

    FLOAT: $ => $._float,

    _FUNC: $ => "func",

    FUNCREF: $ => "funcref",

    GET: $ => "get",

    GLOBAL: $ => "global",

    GLOBAL_GET: $ => seq("global", ".", "get"),

    GLOBAL_SET: $ => seq("global", ".", "set"),

    IF: $ => "if",

    IMPORT: $ => "import",

    INPUT: $ => "input",

    INVOKE: $ => "invoke",

    INT: $ => $._int,

    LOAD: $ => seq($._nxx, ".load"),

    LOCAL: $ => "local",

    LOCAL_GET: $ => seq("local", ".", "get"),

    LOCAL_SET: $ => seq("local", ".", "set"),

    LOCAL_TEE: $ => seq("local", ".", "tee"),

    LOOP: $ => "loop",

    _LPAR: $ => "(",

    MEMORY: $ => "memory",

    MEMORY_GROW: $ => seq("memory", ".", "grow"),

    MEMORY_SIZE: $ => seq("memory", ".", "size"),

    _MODULE: $ => "module",

    MUT: $ => "mut",

    NAN: $ => seq("nan", ":", choice("arithmetic", "canonical")),

    NAT: $ => $._nat,

    NOP: $ => "nop",

    OFFSET: $ => "offset",

    OFFSET_EQ_NAT: $ => seq("offset=", $._nat),

    OUTPUT: $ => "output",

    PARAM: $ => "param",

    QUOTE: $ => "quote",

    _RPAR: $ => ")",

    REGISTER: $ => "register",

    RESULT: $ => "result",

    RETURN: $ => "return",

    SCRIPT: $ => "script",

    SELECT: $ => "select",

    START: $ => "start",

    STORE: $ => seq($._nxx, ".", "store"),

    _STRING: $ => $._string,

    TABLE: $ => "table",

    TEST: $ => seq($._ixx, ".", "eqz"),

    THEN: $ => "then",

    _TYPE: $ => "type",

    UNARY: $ =>
      choice(
        seq($._ixx, ".", choice("clz", "ctz", "popcnt")),
        seq($._fxx, ".", choice("neg", "abs", "sqrt", "ceil", "floor", "trunc", "nearest")),
      ),

    UNREACHABLE: $ => "unreachable",

    VALUE_TYPE: $ => $._nxx,

    VAR: $ => $._name,
  },
});
