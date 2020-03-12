module.exports = grammar({
  name: "webassembly",

  inline: $ => [
    $.bindVar,
    $.moduleVar,
    $.var,
    $.VAR,
  ],

  rules: {
    module1: $ => choice(
      $.module,
    ),

    bindVar: $ => $.VAR,

    expr: $ => "expr",

    func: $ => seq(
      "(",
      "func",
      optional($.bindVar),
      optional($.funcFields),
      ")",
    ),

    funcBody: $ => choice(
      repeat1($.instr),
      //
      //
    ),

    funcFields: $ => choice(
      seq($.typeUse, optional($.funcFieldsBody)),
      seq($.inlineImport, $.typeUse, $.funcFieldsImport),
      seq($.inlineImport, $.funcFieldsImport),
      seq($.inlineExport, $.funcFields),
    ),

    funcFieldsBody: $ => choice(
      $.funcResultBody,
      //
      //
    ),

    funcFieldsImport: $ => "funcFieldsImport",

    funcResultBody: $ => choice(
      $.funcBody,
      //
      //
    ),

    inlineExport: $ => "inlineExport",

    inlineImport: $ => "inlineImport",

    instr: $ => choice(
      $.instrCall,
      $.instrPlain,
      $.instrBlock,
      $.expr,
    ),

    instrCall: $ => "instrCall",

    instrPlain: $ => "instrPlain",

    instrBlock: $ => "instrBlock",

    module: $ => choice(
      seq(
        "(",
        "module",
        optional($.moduleVar),
        repeat($.moduleField),
        ")",
      ),
    ),

    moduleField: $ => choice(
      $.func,
    ),

    moduleVar: $ => $.VAR,

    typeUse: $ => seq(
      "(",
      "type",
      $.var,
      ")",
    ),

    digit: $ => /[0-9]/,

    hexdigit: $ => /[0-9a-fA-F]/,

    hexnum: $ => seq(
      $.hexdigit,
      repeat(seq(optional("_"), $.hexdigit)),
    ),

    nat: $ => choice(
      $.num,
      seq("0x", $.hexnum),
    ),

    num: $ => seq(
      $.digit,
      repeat(seq(optional("_"), $.digit)),
    ),

    var: $ => choice(
      $.NAT,
      $.VAR,
    ),

    NAME: $ => {
      const digit  = /[0-9]/;
      const letter = /[a-zA-Z]/;
      const symbol = /[-+*/\\^~=<>!?@#$%&|:`.']/;
      return seq("$", repeat1(choice(letter, digit, "_", symbol)));
    },

    NAT: $ => {
      const numeric = /[0-9]+/;
      return token(numeric);
    },

    VAR: $ => $.NAME,
  },
})
