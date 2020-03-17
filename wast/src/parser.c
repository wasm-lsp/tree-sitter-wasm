#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 11
#define STATE_COUNT 130
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 94
#define ALIAS_COUNT 0
#define TOKEN_COUNT 54
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 8

enum {
  sym_funcFieldImport = 1,
  sym_inlineExport = 2,
  sym_inlineImport = 3,
  sym_instrCall = 4,
  sym_instrBlock = 5,
  anon_sym_BSLASH = 6,
  anon_sym_RBRACE = 7,
  sym__digit = 8,
  sym__escape = 9,
  anon_sym_DOT = 10,
  anon_sym_e = 11,
  anon_sym_E = 12,
  anon_sym_0x = 13,
  anon_sym_p = 14,
  anon_sym_P = 15,
  anon_sym_inf = 16,
  anon_sym_nan = 17,
  anon_sym_nan_COLON = 18,
  anon_sym_f = 19,
  anon_sym_32 = 20,
  anon_sym_64 = 21,
  sym__hexdigit = 22,
  anon_sym__ = 23,
  anon_sym_i = 24,
  sym__letter = 25,
  anon_sym_8 = 26,
  anon_sym_DOLLAR = 27,
  anon_sym_POUND = 28,
  anon_sym_PLUS = 29,
  anon_sym_DASH = 30,
  anon_sym_s = 31,
  anon_sym_u = 32,
  anon_sym_DQUOTE = 33,
  sym__symbol = 34,
  sym__utf8cont = 35,
  aux_sym__utf8enc_token1 = 36,
  aux_sym__utf8enc_token2 = 37,
  aux_sym__utf8enc_token3 = 38,
  aux_sym__utf8enc_token4 = 39,
  aux_sym__utf8enc_token5 = 40,
  aux_sym__utf8enc_token6 = 41,
  aux_sym__utf8enc_token7 = 42,
  aux_sym__utf8enc_token8 = 43,
  aux_sym__utf8enc_token9 = 44,
  aux_sym__utf8enc_token10 = 45,
  aux_sym__utf8enc_token11 = 46,
  anon_sym_DOTconst = 47,
  sym__FUNC = 48,
  sym__LPAR = 49,
  sym__MODULE = 50,
  anon_sym_COLON = 51,
  sym__RPAR = 52,
  sym__TYPE = 53,
  sym_file = 54,
  sym__bindVar = 55,
  sym_expr = 56,
  sym_expr1 = 57,
  sym_func = 58,
  sym_funcBody = 59,
  sym_funcField = 60,
  sym_funcFieldBody = 61,
  sym_funcResultBody = 62,
  sym_instr = 63,
  sym_instrPlain = 64,
  sym_literal = 65,
  sym_module = 66,
  sym_moduleField = 67,
  sym__moduleVar = 68,
  sym_typeUse = 69,
  sym__float = 70,
  sym__frac = 71,
  sym__fxx = 72,
  sym__hexfrac = 73,
  sym__hexnum = 74,
  sym__int = 75,
  sym__ixx = 76,
  sym__name = 77,
  sym__nat = 78,
  sym__nxx = 79,
  sym__num = 80,
  sym__sign = 81,
  sym__var = 82,
  sym_CONST = 83,
  sym_FLOAT = 84,
  sym_INT = 85,
  sym_NAT = 86,
  sym_VAR = 87,
  aux_sym_expr1_repeat1 = 88,
  aux_sym_funcBody_repeat1 = 89,
  aux_sym_module_repeat1 = 90,
  aux_sym__hexnum_repeat1 = 91,
  aux_sym__name_repeat1 = 92,
  aux_sym__num_repeat1 = 93,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_funcFieldImport] = "funcFieldImport",
  [sym_inlineExport] = "inlineExport",
  [sym_inlineImport] = "inlineImport",
  [sym_instrCall] = "instrCall",
  [sym_instrBlock] = "instrBlock",
  [anon_sym_BSLASH] = "\\",
  [anon_sym_RBRACE] = "}",
  [sym__digit] = "_digit",
  [sym__escape] = "_escape",
  [anon_sym_DOT] = ".",
  [anon_sym_e] = "e",
  [anon_sym_E] = "E",
  [anon_sym_0x] = "0x",
  [anon_sym_p] = "p",
  [anon_sym_P] = "P",
  [anon_sym_inf] = "inf",
  [anon_sym_nan] = "nan",
  [anon_sym_nan_COLON] = "nan:",
  [anon_sym_f] = "f",
  [anon_sym_32] = "32",
  [anon_sym_64] = "64",
  [sym__hexdigit] = "_hexdigit",
  [anon_sym__] = "_",
  [anon_sym_i] = "i",
  [sym__letter] = "_letter",
  [anon_sym_8] = "8",
  [anon_sym_DOLLAR] = "$",
  [anon_sym_POUND] = "#",
  [anon_sym_PLUS] = "+",
  [anon_sym_DASH] = "-",
  [anon_sym_s] = "s",
  [anon_sym_u] = "u",
  [anon_sym_DQUOTE] = "\"",
  [sym__symbol] = "_symbol",
  [sym__utf8cont] = "_utf8cont",
  [aux_sym__utf8enc_token1] = "_utf8enc_token1",
  [aux_sym__utf8enc_token2] = "_utf8enc_token2",
  [aux_sym__utf8enc_token3] = "_utf8enc_token3",
  [aux_sym__utf8enc_token4] = "_utf8enc_token4",
  [aux_sym__utf8enc_token5] = "_utf8enc_token5",
  [aux_sym__utf8enc_token6] = "_utf8enc_token6",
  [aux_sym__utf8enc_token7] = "_utf8enc_token7",
  [aux_sym__utf8enc_token8] = "_utf8enc_token8",
  [aux_sym__utf8enc_token9] = "_utf8enc_token9",
  [aux_sym__utf8enc_token10] = "_utf8enc_token10",
  [aux_sym__utf8enc_token11] = "_utf8enc_token11",
  [anon_sym_DOTconst] = ".const",
  [sym__FUNC] = "_FUNC",
  [sym__LPAR] = "_LPAR",
  [sym__MODULE] = "_MODULE",
  [anon_sym_COLON] = ":",
  [sym__RPAR] = "_RPAR",
  [sym__TYPE] = "_TYPE",
  [sym_file] = "file",
  [sym__bindVar] = "_bindVar",
  [sym_expr] = "expr",
  [sym_expr1] = "expr1",
  [sym_func] = "func",
  [sym_funcBody] = "funcBody",
  [sym_funcField] = "funcField",
  [sym_funcFieldBody] = "funcFieldBody",
  [sym_funcResultBody] = "funcResultBody",
  [sym_instr] = "instr",
  [sym_instrPlain] = "instrPlain",
  [sym_literal] = "literal",
  [sym_module] = "module",
  [sym_moduleField] = "moduleField",
  [sym__moduleVar] = "_moduleVar",
  [sym_typeUse] = "typeUse",
  [sym__float] = "_float",
  [sym__frac] = "_frac",
  [sym__fxx] = "_fxx",
  [sym__hexfrac] = "_hexfrac",
  [sym__hexnum] = "_hexnum",
  [sym__int] = "_int",
  [sym__ixx] = "_ixx",
  [sym__name] = "_name",
  [sym__nat] = "_nat",
  [sym__nxx] = "_nxx",
  [sym__num] = "_num",
  [sym__sign] = "_sign",
  [sym__var] = "_var",
  [sym_CONST] = "CONST",
  [sym_FLOAT] = "FLOAT",
  [sym_INT] = "INT",
  [sym_NAT] = "NAT",
  [sym_VAR] = "VAR",
  [aux_sym_expr1_repeat1] = "expr1_repeat1",
  [aux_sym_funcBody_repeat1] = "funcBody_repeat1",
  [aux_sym_module_repeat1] = "module_repeat1",
  [aux_sym__hexnum_repeat1] = "_hexnum_repeat1",
  [aux_sym__name_repeat1] = "_name_repeat1",
  [aux_sym__num_repeat1] = "_num_repeat1",
};

static TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_funcFieldImport] = sym_funcFieldImport,
  [sym_inlineExport] = sym_inlineExport,
  [sym_inlineImport] = sym_inlineImport,
  [sym_instrCall] = sym_instrCall,
  [sym_instrBlock] = sym_instrBlock,
  [anon_sym_BSLASH] = anon_sym_BSLASH,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [sym__digit] = sym__digit,
  [sym__escape] = sym__escape,
  [anon_sym_DOT] = anon_sym_DOT,
  [anon_sym_e] = anon_sym_e,
  [anon_sym_E] = anon_sym_E,
  [anon_sym_0x] = anon_sym_0x,
  [anon_sym_p] = anon_sym_p,
  [anon_sym_P] = anon_sym_P,
  [anon_sym_inf] = anon_sym_inf,
  [anon_sym_nan] = anon_sym_nan,
  [anon_sym_nan_COLON] = anon_sym_nan_COLON,
  [anon_sym_f] = anon_sym_f,
  [anon_sym_32] = anon_sym_32,
  [anon_sym_64] = anon_sym_64,
  [sym__hexdigit] = sym__hexdigit,
  [anon_sym__] = anon_sym__,
  [anon_sym_i] = anon_sym_i,
  [sym__letter] = sym__letter,
  [anon_sym_8] = anon_sym_8,
  [anon_sym_DOLLAR] = anon_sym_DOLLAR,
  [anon_sym_POUND] = anon_sym_POUND,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_s] = anon_sym_s,
  [anon_sym_u] = anon_sym_u,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [sym__symbol] = sym__symbol,
  [sym__utf8cont] = sym__utf8cont,
  [aux_sym__utf8enc_token1] = aux_sym__utf8enc_token1,
  [aux_sym__utf8enc_token2] = aux_sym__utf8enc_token2,
  [aux_sym__utf8enc_token3] = aux_sym__utf8enc_token3,
  [aux_sym__utf8enc_token4] = aux_sym__utf8enc_token4,
  [aux_sym__utf8enc_token5] = aux_sym__utf8enc_token5,
  [aux_sym__utf8enc_token6] = aux_sym__utf8enc_token6,
  [aux_sym__utf8enc_token7] = aux_sym__utf8enc_token7,
  [aux_sym__utf8enc_token8] = aux_sym__utf8enc_token8,
  [aux_sym__utf8enc_token9] = aux_sym__utf8enc_token9,
  [aux_sym__utf8enc_token10] = aux_sym__utf8enc_token10,
  [aux_sym__utf8enc_token11] = aux_sym__utf8enc_token11,
  [anon_sym_DOTconst] = anon_sym_DOTconst,
  [sym__FUNC] = sym__FUNC,
  [sym__LPAR] = sym__LPAR,
  [sym__MODULE] = sym__MODULE,
  [anon_sym_COLON] = anon_sym_COLON,
  [sym__RPAR] = sym__RPAR,
  [sym__TYPE] = sym__TYPE,
  [sym_file] = sym_file,
  [sym__bindVar] = sym__bindVar,
  [sym_expr] = sym_expr,
  [sym_expr1] = sym_expr1,
  [sym_func] = sym_func,
  [sym_funcBody] = sym_funcBody,
  [sym_funcField] = sym_funcField,
  [sym_funcFieldBody] = sym_funcFieldBody,
  [sym_funcResultBody] = sym_funcResultBody,
  [sym_instr] = sym_instr,
  [sym_instrPlain] = sym_instrPlain,
  [sym_literal] = sym_literal,
  [sym_module] = sym_module,
  [sym_moduleField] = sym_moduleField,
  [sym__moduleVar] = sym__moduleVar,
  [sym_typeUse] = sym_typeUse,
  [sym__float] = sym__float,
  [sym__frac] = sym__frac,
  [sym__fxx] = sym__fxx,
  [sym__hexfrac] = sym__hexfrac,
  [sym__hexnum] = sym__hexnum,
  [sym__int] = sym__int,
  [sym__ixx] = sym__ixx,
  [sym__name] = sym__name,
  [sym__nat] = sym__nat,
  [sym__nxx] = sym__nxx,
  [sym__num] = sym__num,
  [sym__sign] = sym__sign,
  [sym__var] = sym__var,
  [sym_CONST] = sym_CONST,
  [sym_FLOAT] = sym_FLOAT,
  [sym_INT] = sym_INT,
  [sym_NAT] = sym_NAT,
  [sym_VAR] = sym_VAR,
  [aux_sym_expr1_repeat1] = aux_sym_expr1_repeat1,
  [aux_sym_funcBody_repeat1] = aux_sym_funcBody_repeat1,
  [aux_sym_module_repeat1] = aux_sym_module_repeat1,
  [aux_sym__hexnum_repeat1] = aux_sym__hexnum_repeat1,
  [aux_sym__name_repeat1] = aux_sym__name_repeat1,
  [aux_sym__num_repeat1] = aux_sym__num_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_funcFieldImport] = {
    .visible = true,
    .named = true,
  },
  [sym_inlineExport] = {
    .visible = true,
    .named = true,
  },
  [sym_inlineImport] = {
    .visible = true,
    .named = true,
  },
  [sym_instrCall] = {
    .visible = true,
    .named = true,
  },
  [sym_instrBlock] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_BSLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [sym__digit] = {
    .visible = false,
    .named = true,
  },
  [sym__escape] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_DOT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_e] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_E] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_0x] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_p] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_P] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_inf] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_nan] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_nan_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_f] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_32] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_64] = {
    .visible = true,
    .named = false,
  },
  [sym__hexdigit] = {
    .visible = false,
    .named = true,
  },
  [anon_sym__] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_i] = {
    .visible = true,
    .named = false,
  },
  [sym__letter] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_8] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOLLAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_POUND] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_s] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_u] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [sym__symbol] = {
    .visible = false,
    .named = true,
  },
  [sym__utf8cont] = {
    .visible = false,
    .named = true,
  },
  [aux_sym__utf8enc_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__utf8enc_token2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__utf8enc_token3] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__utf8enc_token4] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__utf8enc_token5] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__utf8enc_token6] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__utf8enc_token7] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__utf8enc_token8] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__utf8enc_token9] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__utf8enc_token10] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__utf8enc_token11] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_DOTconst] = {
    .visible = true,
    .named = false,
  },
  [sym__FUNC] = {
    .visible = false,
    .named = true,
  },
  [sym__LPAR] = {
    .visible = false,
    .named = true,
  },
  [sym__MODULE] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [sym__RPAR] = {
    .visible = false,
    .named = true,
  },
  [sym__TYPE] = {
    .visible = false,
    .named = true,
  },
  [sym_file] = {
    .visible = true,
    .named = true,
  },
  [sym__bindVar] = {
    .visible = false,
    .named = true,
  },
  [sym_expr] = {
    .visible = true,
    .named = true,
  },
  [sym_expr1] = {
    .visible = true,
    .named = true,
  },
  [sym_func] = {
    .visible = true,
    .named = true,
  },
  [sym_funcBody] = {
    .visible = true,
    .named = true,
  },
  [sym_funcField] = {
    .visible = true,
    .named = true,
  },
  [sym_funcFieldBody] = {
    .visible = true,
    .named = true,
  },
  [sym_funcResultBody] = {
    .visible = true,
    .named = true,
  },
  [sym_instr] = {
    .visible = true,
    .named = true,
  },
  [sym_instrPlain] = {
    .visible = true,
    .named = true,
  },
  [sym_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_module] = {
    .visible = true,
    .named = true,
  },
  [sym_moduleField] = {
    .visible = true,
    .named = true,
  },
  [sym__moduleVar] = {
    .visible = false,
    .named = true,
  },
  [sym_typeUse] = {
    .visible = true,
    .named = true,
  },
  [sym__float] = {
    .visible = false,
    .named = true,
  },
  [sym__frac] = {
    .visible = false,
    .named = true,
  },
  [sym__fxx] = {
    .visible = false,
    .named = true,
  },
  [sym__hexfrac] = {
    .visible = false,
    .named = true,
  },
  [sym__hexnum] = {
    .visible = false,
    .named = true,
  },
  [sym__int] = {
    .visible = false,
    .named = true,
  },
  [sym__ixx] = {
    .visible = false,
    .named = true,
  },
  [sym__name] = {
    .visible = false,
    .named = true,
  },
  [sym__nat] = {
    .visible = false,
    .named = true,
  },
  [sym__nxx] = {
    .visible = false,
    .named = true,
  },
  [sym__num] = {
    .visible = false,
    .named = true,
  },
  [sym__sign] = {
    .visible = false,
    .named = true,
  },
  [sym__var] = {
    .visible = false,
    .named = true,
  },
  [sym_CONST] = {
    .visible = true,
    .named = true,
  },
  [sym_FLOAT] = {
    .visible = true,
    .named = true,
  },
  [sym_INT] = {
    .visible = true,
    .named = true,
  },
  [sym_NAT] = {
    .visible = true,
    .named = true,
  },
  [sym_VAR] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_expr1_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_funcBody_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_module_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__hexnum_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__name_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__num_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static TSSymbol ts_alias_sequences[1][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(71);
      if (lookahead == '"') ADVANCE(107);
      if (lookahead == '#') ADVANCE(102);
      if (lookahead == '$') ADVANCE(101);
      if (lookahead == '\'') ADVANCE(81);
      if (lookahead == '(') ADVANCE(119);
      if (lookahead == ')') ADVANCE(122);
      if (lookahead == '+') ADVANCE(103);
      if (lookahead == '-') ADVANCE(104);
      if (lookahead == '.') ADVANCE(82);
      if (lookahead == '8') ADVANCE(100);
      if (lookahead == ':') ADVANCE(121);
      if (lookahead == 'E') ADVANCE(84);
      if (lookahead == 'P') ADVANCE(87);
      if (lookahead == '\\') ADVANCE(77);
      if (lookahead == '_') ADVANCE(96);
      if (lookahead == 'e') ADVANCE(83);
      if (lookahead == 'f') ADVANCE(91);
      if (lookahead == 'i') ADVANCE(97);
      if (lookahead == 'p') ADVANCE(86);
      if (lookahead == 's') ADVANCE(105);
      if (lookahead == 'u') ADVANCE(106);
      if (lookahead == '}') ADVANCE(78);
      if (lookahead == 224) ADVANCE(111);
      if (lookahead == 237) ADVANCE(112);
      if (lookahead == 240) ADVANCE(114);
      if (lookahead == 244) ADVANCE(115);
      if (lookahead == 'n' ||
          ('r' <= lookahead && lookahead <= 't')) ADVANCE(81);
      if ((241 <= lookahead && lookahead <= 243)) ADVANCE(116);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(79);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'd')) ADVANCE(95);
      if (('!' <= lookahead && lookahead <= '*') ||
          lookahead == '/' ||
          ('<' <= lookahead && lookahead <= '@') ||
          ('^' <= lookahead && lookahead <= '`') ||
          ('|' <= lookahead && lookahead <= '~')) ADVANCE(108);
      if ((225 <= lookahead && lookahead <= 239)) ADVANCE(113);
      if ((128 <= lookahead && lookahead <= 143)) ADVANCE(109);
      if ((144 <= lookahead && lookahead <= 159)) ADVANCE(109);
      if ((194 <= lookahead && lookahead <= 223)) ADVANCE(110);
      if (('G' <= lookahead && lookahead <= 'Z') ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      if ((160 <= lookahead && lookahead <= 191)) ADVANCE(109);
      END_STATE();
    case 1:
      if (lookahead == '$') ADVANCE(101);
      if (lookahead == '(') ADVANCE(119);
      if (lookahead == ')') ADVANCE(122);
      if (lookahead == '+') ADVANCE(103);
      if (lookahead == '-') ADVANCE(104);
      if (lookahead == '.') ADVANCE(82);
      if (lookahead == 'E') ADVANCE(84);
      if (lookahead == 'P') ADVANCE(87);
      if (lookahead == '_') ADVANCE(96);
      if (lookahead == 'e') ADVANCE(83);
      if (lookahead == 'f') ADVANCE(91);
      if (lookahead == 'i') ADVANCE(97);
      if (lookahead == 'm') ADVANCE(46);
      if (lookahead == 'p') ADVANCE(86);
      if (lookahead == 't') ADVANCE(70);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(79);
      END_STATE();
    case 2:
      if (lookahead == '$') ADVANCE(101);
      if (lookahead == '(') ADVANCE(119);
      if (lookahead == '+') ADVANCE(103);
      if (lookahead == '-') ADVANCE(104);
      if (lookahead == '.') ADVANCE(19);
      if (lookahead == '0') ADVANCE(80);
      if (lookahead == 'f') ADVANCE(66);
      if (lookahead == 'i') ADVANCE(40);
      if (lookahead == 'n') ADVANCE(15);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(2)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(79);
      END_STATE();
    case 3:
      if (lookahead == '(') ADVANCE(119);
      if (lookahead == ')') ADVANCE(122);
      if (lookahead == '.') ADVANCE(82);
      if (lookahead == 'P') ADVANCE(87);
      if (lookahead == '_') ADVANCE(96);
      if (lookahead == 'f') ADVANCE(91);
      if (lookahead == 'i') ADVANCE(98);
      if (lookahead == 'p') ADVANCE(86);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(3)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'e')) ADVANCE(95);
      END_STATE();
    case 4:
      if (lookahead == '(') ADVANCE(119);
      if (lookahead == ')') ADVANCE(122);
      if (lookahead == '.') ADVANCE(82);
      if (lookahead == 'P') ADVANCE(87);
      if (lookahead == '_') ADVANCE(96);
      if (lookahead == 'p') ADVANCE(86);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(4)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(95);
      END_STATE();
    case 5:
      if (lookahead == '(') ADVANCE(119);
      if (lookahead == ')') ADVANCE(122);
      if (lookahead == '3') ADVANCE(8);
      if (lookahead == '6') ADVANCE(9);
      if (lookahead == 'f') ADVANCE(92);
      if (lookahead == 'i') ADVANCE(98);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(5)
      END_STATE();
    case 6:
      if (lookahead == '(') ADVANCE(119);
      if (lookahead == ')') ADVANCE(122);
      if (lookahead == '_') ADVANCE(96);
      if (lookahead == 'f') ADVANCE(91);
      if (lookahead == 'i') ADVANCE(97);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(6)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(79);
      if (lookahead == '!' ||
          ('#' <= lookahead && lookahead <= '+') ||
          ('-' <= lookahead && lookahead <= ':') ||
          ('<' <= lookahead && lookahead <= '@') ||
          lookahead == '\\' ||
          ('^' <= lookahead && lookahead <= '`') ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(108);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 7:
      if (lookahead == '(') ADVANCE(119);
      if (lookahead == ')') ADVANCE(122);
      if (lookahead == '_') ADVANCE(96);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(7)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(79);
      if (lookahead == '!' ||
          ('#' <= lookahead && lookahead <= '+') ||
          ('-' <= lookahead && lookahead <= ':') ||
          ('<' <= lookahead && lookahead <= '@') ||
          lookahead == '\\' ||
          ('^' <= lookahead && lookahead <= '`') ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(108);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 8:
      if (lookahead == '2') ADVANCE(93);
      END_STATE();
    case 9:
      if (lookahead == '4') ADVANCE(94);
      END_STATE();
    case 10:
      if (lookahead == 'B') ADVANCE(32);
      if (lookahead == 'C') ADVANCE(14);
      END_STATE();
    case 11:
      if (lookahead == 'E') ADVANCE(69);
      if (lookahead == 'I') ADVANCE(37);
      END_STATE();
    case 12:
      if (lookahead == 'F') ADVANCE(29);
      END_STATE();
    case 13:
      if (lookahead == 'I') ADVANCE(38);
      END_STATE();
    case 14:
      if (lookahead == 'a') ADVANCE(36);
      END_STATE();
    case 15:
      if (lookahead == 'a') ADVANCE(41);
      END_STATE();
    case 16:
      if (lookahead == 'c') ADVANCE(30);
      END_STATE();
    case 17:
      if (lookahead == 'c') ADVANCE(12);
      END_STATE();
    case 18:
      if (lookahead == 'c') ADVANCE(118);
      END_STATE();
    case 19:
      if (lookahead == 'c') ADVANCE(50);
      END_STATE();
    case 20:
      if (lookahead == 'd') ADVANCE(67);
      END_STATE();
    case 21:
      if (lookahead == 'd') ADVANCE(13);
      END_STATE();
    case 22:
      if (lookahead == 'e') ADVANCE(11);
      END_STATE();
    case 23:
      if (lookahead == 'e') ADVANCE(123);
      END_STATE();
    case 24:
      if (lookahead == 'e') ADVANCE(120);
      END_STATE();
    case 25:
      if (lookahead == 'e') ADVANCE(34);
      END_STATE();
    case 26:
      if (lookahead == 'f') ADVANCE(88);
      END_STATE();
    case 27:
      if (lookahead == 'f') ADVANCE(68);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(27)
      END_STATE();
    case 28:
      if (lookahead == 'i') ADVANCE(39);
      END_STATE();
    case 29:
      if (lookahead == 'i') ADVANCE(25);
      END_STATE();
    case 30:
      if (lookahead == 'k') ADVANCE(76);
      END_STATE();
    case 31:
      if (lookahead == 'l') ADVANCE(28);
      if (lookahead == 's') ADVANCE(61);
      END_STATE();
    case 32:
      if (lookahead == 'l') ADVANCE(45);
      END_STATE();
    case 33:
      if (lookahead == 'l') ADVANCE(75);
      END_STATE();
    case 34:
      if (lookahead == 'l') ADVANCE(21);
      END_STATE();
    case 35:
      if (lookahead == 'l') ADVANCE(24);
      END_STATE();
    case 36:
      if (lookahead == 'l') ADVANCE(33);
      END_STATE();
    case 37:
      if (lookahead == 'm') ADVANCE(53);
      END_STATE();
    case 38:
      if (lookahead == 'm') ADVANCE(54);
      END_STATE();
    case 39:
      if (lookahead == 'n') ADVANCE(22);
      END_STATE();
    case 40:
      if (lookahead == 'n') ADVANCE(26);
      END_STATE();
    case 41:
      if (lookahead == 'n') ADVANCE(89);
      END_STATE();
    case 42:
      if (lookahead == 'n') ADVANCE(60);
      END_STATE();
    case 43:
      if (lookahead == 'n') ADVANCE(17);
      END_STATE();
    case 44:
      if (lookahead == 'n') ADVANCE(18);
      END_STATE();
    case 45:
      if (lookahead == 'o') ADVANCE(16);
      END_STATE();
    case 46:
      if (lookahead == 'o') ADVANCE(20);
      END_STATE();
    case 47:
      if (lookahead == 'o') ADVANCE(56);
      END_STATE();
    case 48:
      if (lookahead == 'o') ADVANCE(57);
      END_STATE();
    case 49:
      if (lookahead == 'o') ADVANCE(58);
      END_STATE();
    case 50:
      if (lookahead == 'o') ADVANCE(42);
      END_STATE();
    case 51:
      if (lookahead == 'p') ADVANCE(23);
      END_STATE();
    case 52:
      if (lookahead == 'p') ADVANCE(47);
      END_STATE();
    case 53:
      if (lookahead == 'p') ADVANCE(48);
      END_STATE();
    case 54:
      if (lookahead == 'p') ADVANCE(49);
      END_STATE();
    case 55:
      if (lookahead == 'r') ADVANCE(10);
      END_STATE();
    case 56:
      if (lookahead == 'r') ADVANCE(62);
      END_STATE();
    case 57:
      if (lookahead == 'r') ADVANCE(63);
      END_STATE();
    case 58:
      if (lookahead == 'r') ADVANCE(65);
      END_STATE();
    case 59:
      if (lookahead == 's') ADVANCE(61);
      END_STATE();
    case 60:
      if (lookahead == 's') ADVANCE(64);
      END_STATE();
    case 61:
      if (lookahead == 't') ADVANCE(55);
      END_STATE();
    case 62:
      if (lookahead == 't') ADVANCE(73);
      END_STATE();
    case 63:
      if (lookahead == 't') ADVANCE(74);
      END_STATE();
    case 64:
      if (lookahead == 't') ADVANCE(117);
      END_STATE();
    case 65:
      if (lookahead == 't') ADVANCE(72);
      END_STATE();
    case 66:
      if (lookahead == 'u') ADVANCE(43);
      END_STATE();
    case 67:
      if (lookahead == 'u') ADVANCE(35);
      END_STATE();
    case 68:
      if (lookahead == 'u') ADVANCE(44);
      END_STATE();
    case 69:
      if (lookahead == 'x') ADVANCE(52);
      END_STATE();
    case 70:
      if (lookahead == 'y') ADVANCE(51);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym_funcFieldImport);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(sym_inlineExport);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(sym_inlineImport);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(sym_instrCall);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(sym_instrBlock);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(anon_sym_BSLASH);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(sym__digit);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(sym__digit);
      if (lookahead == 'x') ADVANCE(85);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(sym__escape);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(anon_sym_e);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(anon_sym_E);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(anon_sym_0x);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(anon_sym_p);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(anon_sym_P);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(anon_sym_inf);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(anon_sym_nan);
      if (lookahead == ':') ADVANCE(90);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(anon_sym_nan_COLON);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(anon_sym_f);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(anon_sym_f);
      if (lookahead == 'u') ADVANCE(43);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(anon_sym_32);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(anon_sym_64);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(sym__hexdigit);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(anon_sym__);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(anon_sym_i);
      if (lookahead == 'n') ADVANCE(31);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(anon_sym_i);
      if (lookahead == 'n') ADVANCE(59);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(sym__letter);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(anon_sym_8);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(anon_sym_DOLLAR);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(anon_sym_POUND);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(anon_sym_s);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(anon_sym_u);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(sym__symbol);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(sym__utf8cont);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(aux_sym__utf8enc_token1);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(aux_sym__utf8enc_token2);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(aux_sym__utf8enc_token4);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(aux_sym__utf8enc_token6);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(aux_sym__utf8enc_token7);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(aux_sym__utf8enc_token9);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(aux_sym__utf8enc_token11);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(anon_sym_DOTconst);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(sym__FUNC);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(sym__LPAR);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(sym__MODULE);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(sym__RPAR);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(sym__TYPE);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 1},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 2},
  [7] = {.lex_state = 2},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 6},
  [11] = {.lex_state = 6},
  [12] = {.lex_state = 1},
  [13] = {.lex_state = 1},
  [14] = {.lex_state = 3},
  [15] = {.lex_state = 1},
  [16] = {.lex_state = 3},
  [17] = {.lex_state = 3},
  [18] = {.lex_state = 1},
  [19] = {.lex_state = 3},
  [20] = {.lex_state = 3},
  [21] = {.lex_state = 1},
  [22] = {.lex_state = 1},
  [23] = {.lex_state = 3},
  [24] = {.lex_state = 1},
  [25] = {.lex_state = 1},
  [26] = {.lex_state = 2},
  [27] = {.lex_state = 1},
  [28] = {.lex_state = 1},
  [29] = {.lex_state = 1},
  [30] = {.lex_state = 1},
  [31] = {.lex_state = 4},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 1},
  [34] = {.lex_state = 4},
  [35] = {.lex_state = 1},
  [36] = {.lex_state = 1},
  [37] = {.lex_state = 1},
  [38] = {.lex_state = 4},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 4},
  [41] = {.lex_state = 5},
  [42] = {.lex_state = 7},
  [43] = {.lex_state = 2},
  [44] = {.lex_state = 4},
  [45] = {.lex_state = 2},
  [46] = {.lex_state = 7},
  [47] = {.lex_state = 2},
  [48] = {.lex_state = 4},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 0},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 0},
  [61] = {.lex_state = 0},
  [62] = {.lex_state = 0},
  [63] = {.lex_state = 0},
  [64] = {.lex_state = 0},
  [65] = {.lex_state = 1},
  [66] = {.lex_state = 1},
  [67] = {.lex_state = 1},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 1},
  [70] = {.lex_state = 1},
  [71] = {.lex_state = 0},
  [72] = {.lex_state = 0},
  [73] = {.lex_state = 7},
  [74] = {.lex_state = 7},
  [75] = {.lex_state = 1},
  [76] = {.lex_state = 1},
  [77] = {.lex_state = 0},
  [78] = {.lex_state = 0},
  [79] = {.lex_state = 0},
  [80] = {.lex_state = 2},
  [81] = {.lex_state = 4},
  [82] = {.lex_state = 1},
  [83] = {.lex_state = 4},
  [84] = {.lex_state = 4},
  [85] = {.lex_state = 4},
  [86] = {.lex_state = 4},
  [87] = {.lex_state = 0},
  [88] = {.lex_state = 1},
  [89] = {.lex_state = 4},
  [90] = {.lex_state = 4},
  [91] = {.lex_state = 4},
  [92] = {.lex_state = 0},
  [93] = {.lex_state = 0},
  [94] = {.lex_state = 1},
  [95] = {.lex_state = 5},
  [96] = {.lex_state = 5},
  [97] = {.lex_state = 1},
  [98] = {.lex_state = 0},
  [99] = {.lex_state = 1},
  [100] = {.lex_state = 4},
  [101] = {.lex_state = 0},
  [102] = {.lex_state = 0},
  [103] = {.lex_state = 2},
  [104] = {.lex_state = 2},
  [105] = {.lex_state = 2},
  [106] = {.lex_state = 0},
  [107] = {.lex_state = 0},
  [108] = {.lex_state = 2},
  [109] = {.lex_state = 1},
  [110] = {.lex_state = 1},
  [111] = {.lex_state = 0},
  [112] = {.lex_state = 1},
  [113] = {.lex_state = 0},
  [114] = {.lex_state = 0},
  [115] = {.lex_state = 0},
  [116] = {.lex_state = 0},
  [117] = {.lex_state = 0},
  [118] = {.lex_state = 0},
  [119] = {.lex_state = 27},
  [120] = {.lex_state = 2},
  [121] = {.lex_state = 0},
  [122] = {.lex_state = 0},
  [123] = {.lex_state = 2},
  [124] = {.lex_state = 0},
  [125] = {.lex_state = 2},
  [126] = {.lex_state = 2},
  [127] = {.lex_state = 4},
  [128] = {.lex_state = 4},
  [129] = {.lex_state = 0},
};

static uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_inlineExport] = ACTIONS(1),
    [sym_inlineImport] = ACTIONS(1),
    [sym_instrCall] = ACTIONS(1),
    [sym_instrBlock] = ACTIONS(1),
    [anon_sym_BSLASH] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [sym__digit] = ACTIONS(1),
    [sym__escape] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [anon_sym_e] = ACTIONS(1),
    [anon_sym_E] = ACTIONS(1),
    [anon_sym_p] = ACTIONS(1),
    [anon_sym_P] = ACTIONS(1),
    [anon_sym_f] = ACTIONS(1),
    [sym__hexdigit] = ACTIONS(1),
    [anon_sym__] = ACTIONS(1),
    [anon_sym_i] = ACTIONS(1),
    [sym__letter] = ACTIONS(1),
    [anon_sym_8] = ACTIONS(1),
    [anon_sym_DOLLAR] = ACTIONS(1),
    [anon_sym_POUND] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_s] = ACTIONS(1),
    [anon_sym_u] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [sym__symbol] = ACTIONS(1),
    [sym__utf8cont] = ACTIONS(1),
    [aux_sym__utf8enc_token1] = ACTIONS(1),
    [aux_sym__utf8enc_token2] = ACTIONS(1),
    [aux_sym__utf8enc_token3] = ACTIONS(1),
    [aux_sym__utf8enc_token4] = ACTIONS(1),
    [aux_sym__utf8enc_token5] = ACTIONS(1),
    [aux_sym__utf8enc_token6] = ACTIONS(1),
    [aux_sym__utf8enc_token7] = ACTIONS(1),
    [aux_sym__utf8enc_token8] = ACTIONS(1),
    [aux_sym__utf8enc_token9] = ACTIONS(1),
    [aux_sym__utf8enc_token10] = ACTIONS(1),
    [aux_sym__utf8enc_token11] = ACTIONS(1),
    [sym__LPAR] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [sym__RPAR] = ACTIONS(1),
  },
  [1] = {
    [sym_file] = STATE(129),
    [sym_module] = STATE(124),
    [sym__LPAR] = ACTIONS(3),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 19,
    ACTIONS(5), 1,
      sym_inlineExport,
    ACTIONS(7), 1,
      sym_inlineImport,
    ACTIONS(11), 1,
      anon_sym_f,
    ACTIONS(13), 1,
      anon_sym_i,
    ACTIONS(15), 1,
      anon_sym_DOLLAR,
    ACTIONS(17), 1,
      sym__LPAR,
    ACTIONS(19), 1,
      sym__RPAR,
    STATE(5), 1,
      sym_typeUse,
    STATE(7), 1,
      sym_CONST,
    STATE(32), 1,
      sym__name,
    STATE(102), 1,
      sym_funcFieldBody,
    STATE(113), 1,
      sym_funcBody,
    STATE(114), 1,
      sym_funcField,
    STATE(117), 1,
      sym_funcResultBody,
    ACTIONS(9), 2,
      sym_instrCall,
      sym_instrBlock,
    STATE(3), 2,
      sym__bindVar,
      sym_VAR,
    STATE(9), 2,
      sym_instr,
      aux_sym_funcBody_repeat1,
    STATE(52), 2,
      sym_expr,
      sym_instrPlain,
    STATE(120), 3,
      sym__fxx,
      sym__ixx,
      sym__nxx,
  [64] = 16,
    ACTIONS(5), 1,
      sym_inlineExport,
    ACTIONS(7), 1,
      sym_inlineImport,
    ACTIONS(11), 1,
      anon_sym_f,
    ACTIONS(13), 1,
      anon_sym_i,
    ACTIONS(17), 1,
      sym__LPAR,
    ACTIONS(21), 1,
      sym__RPAR,
    STATE(5), 1,
      sym_typeUse,
    STATE(7), 1,
      sym_CONST,
    STATE(101), 1,
      sym_funcField,
    STATE(102), 1,
      sym_funcFieldBody,
    STATE(113), 1,
      sym_funcBody,
    STATE(117), 1,
      sym_funcResultBody,
    ACTIONS(9), 2,
      sym_instrCall,
      sym_instrBlock,
    STATE(9), 2,
      sym_instr,
      aux_sym_funcBody_repeat1,
    STATE(52), 2,
      sym_expr,
      sym_instrPlain,
    STATE(120), 3,
      sym__fxx,
      sym__ixx,
      sym__nxx,
  [118] = 15,
    ACTIONS(5), 1,
      sym_inlineExport,
    ACTIONS(7), 1,
      sym_inlineImport,
    ACTIONS(11), 1,
      anon_sym_f,
    ACTIONS(13), 1,
      anon_sym_i,
    ACTIONS(17), 1,
      sym__LPAR,
    STATE(5), 1,
      sym_typeUse,
    STATE(7), 1,
      sym_CONST,
    STATE(102), 1,
      sym_funcFieldBody,
    STATE(106), 1,
      sym_funcField,
    STATE(113), 1,
      sym_funcBody,
    STATE(117), 1,
      sym_funcResultBody,
    ACTIONS(9), 2,
      sym_instrCall,
      sym_instrBlock,
    STATE(9), 2,
      sym_instr,
      aux_sym_funcBody_repeat1,
    STATE(52), 2,
      sym_expr,
      sym_instrPlain,
    STATE(120), 3,
      sym__fxx,
      sym__ixx,
      sym__nxx,
  [169] = 12,
    ACTIONS(11), 1,
      anon_sym_f,
    ACTIONS(13), 1,
      anon_sym_i,
    ACTIONS(23), 1,
      sym__LPAR,
    ACTIONS(25), 1,
      sym__RPAR,
    STATE(7), 1,
      sym_CONST,
    STATE(106), 1,
      sym_funcFieldBody,
    STATE(113), 1,
      sym_funcBody,
    STATE(117), 1,
      sym_funcResultBody,
    ACTIONS(9), 2,
      sym_instrCall,
      sym_instrBlock,
    STATE(9), 2,
      sym_instr,
      aux_sym_funcBody_repeat1,
    STATE(52), 2,
      sym_expr,
      sym_instrPlain,
    STATE(120), 3,
      sym__fxx,
      sym__ixx,
      sym__nxx,
  [211] = 13,
    ACTIONS(27), 1,
      sym__digit,
    ACTIONS(29), 1,
      anon_sym_0x,
    ACTIONS(31), 1,
      anon_sym_inf,
    ACTIONS(33), 1,
      anon_sym_nan,
    ACTIONS(35), 1,
      anon_sym_nan_COLON,
    STATE(24), 1,
      sym__num,
    STATE(43), 1,
      sym__sign,
    STATE(54), 1,
      sym_literal,
    STATE(55), 1,
      sym__float,
    STATE(56), 1,
      sym__int,
    STATE(57), 1,
      sym__nat,
    ACTIONS(37), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    STATE(58), 3,
      sym_FLOAT,
      sym_INT,
      sym_NAT,
  [254] = 13,
    ACTIONS(27), 1,
      sym__digit,
    ACTIONS(31), 1,
      anon_sym_inf,
    ACTIONS(33), 1,
      anon_sym_nan,
    ACTIONS(39), 1,
      anon_sym_0x,
    ACTIONS(41), 1,
      anon_sym_nan_COLON,
    STATE(24), 1,
      sym__num,
    STATE(45), 1,
      sym__sign,
    STATE(54), 1,
      sym_literal,
    STATE(55), 1,
      sym__float,
    STATE(56), 1,
      sym__int,
    STATE(57), 1,
      sym__nat,
    ACTIONS(43), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    STATE(58), 3,
      sym_FLOAT,
      sym_INT,
      sym_NAT,
  [297] = 9,
    ACTIONS(48), 1,
      anon_sym_f,
    ACTIONS(51), 1,
      anon_sym_i,
    ACTIONS(54), 1,
      sym__LPAR,
    ACTIONS(57), 1,
      sym__RPAR,
    STATE(7), 1,
      sym_CONST,
    ACTIONS(45), 2,
      sym_instrCall,
      sym_instrBlock,
    STATE(8), 2,
      sym_instr,
      aux_sym_funcBody_repeat1,
    STATE(52), 2,
      sym_expr,
      sym_instrPlain,
    STATE(120), 3,
      sym__fxx,
      sym__ixx,
      sym__nxx,
  [330] = 9,
    ACTIONS(11), 1,
      anon_sym_f,
    ACTIONS(13), 1,
      anon_sym_i,
    ACTIONS(23), 1,
      sym__LPAR,
    ACTIONS(59), 1,
      sym__RPAR,
    STATE(7), 1,
      sym_CONST,
    ACTIONS(9), 2,
      sym_instrCall,
      sym_instrBlock,
    STATE(8), 2,
      sym_instr,
      aux_sym_funcBody_repeat1,
    STATE(52), 2,
      sym_expr,
      sym_instrPlain,
    STATE(120), 3,
      sym__fxx,
      sym__ixx,
      sym__nxx,
  [363] = 5,
    ACTIONS(66), 1,
      anon_sym_i,
    ACTIONS(68), 1,
      sym__letter,
    STATE(10), 1,
      aux_sym__name_repeat1,
    ACTIONS(63), 3,
      sym__digit,
      anon_sym__,
      sym__symbol,
    ACTIONS(61), 7,
      sym_inlineExport,
      sym_inlineImport,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_f,
      sym__LPAR,
      sym__RPAR,
  [387] = 5,
    ACTIONS(75), 1,
      anon_sym_i,
    ACTIONS(77), 1,
      sym__letter,
    STATE(10), 1,
      aux_sym__name_repeat1,
    ACTIONS(73), 3,
      sym__digit,
      anon_sym__,
      sym__symbol,
    ACTIONS(71), 7,
      sym_inlineExport,
      sym_inlineImport,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_f,
      sym__LPAR,
      sym__RPAR,
  [411] = 5,
    ACTIONS(81), 1,
      sym__digit,
    ACTIONS(83), 1,
      anon_sym__,
    ACTIONS(85), 1,
      anon_sym_i,
    STATE(13), 1,
      aux_sym__num_repeat1,
    ACTIONS(79), 8,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_DOT,
      anon_sym_e,
      anon_sym_E,
      anon_sym_f,
      sym__LPAR,
      sym__RPAR,
  [434] = 5,
    ACTIONS(83), 1,
      anon_sym__,
    ACTIONS(89), 1,
      sym__digit,
    ACTIONS(91), 1,
      anon_sym_i,
    STATE(15), 1,
      aux_sym__num_repeat1,
    ACTIONS(87), 8,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_DOT,
      anon_sym_e,
      anon_sym_E,
      anon_sym_f,
      sym__LPAR,
      sym__RPAR,
  [457] = 5,
    ACTIONS(95), 1,
      sym__hexdigit,
    ACTIONS(97), 1,
      anon_sym__,
    ACTIONS(99), 1,
      anon_sym_i,
    STATE(16), 1,
      aux_sym__hexnum_repeat1,
    ACTIONS(93), 8,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_DOT,
      anon_sym_p,
      anon_sym_P,
      anon_sym_f,
      sym__LPAR,
      sym__RPAR,
  [480] = 5,
    ACTIONS(103), 1,
      sym__digit,
    ACTIONS(106), 1,
      anon_sym__,
    ACTIONS(109), 1,
      anon_sym_i,
    STATE(15), 1,
      aux_sym__num_repeat1,
    ACTIONS(101), 8,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_DOT,
      anon_sym_e,
      anon_sym_E,
      anon_sym_f,
      sym__LPAR,
      sym__RPAR,
  [503] = 5,
    ACTIONS(97), 1,
      anon_sym__,
    ACTIONS(113), 1,
      sym__hexdigit,
    ACTIONS(115), 1,
      anon_sym_i,
    STATE(17), 1,
      aux_sym__hexnum_repeat1,
    ACTIONS(111), 8,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_DOT,
      anon_sym_p,
      anon_sym_P,
      anon_sym_f,
      sym__LPAR,
      sym__RPAR,
  [526] = 5,
    ACTIONS(119), 1,
      sym__hexdigit,
    ACTIONS(122), 1,
      anon_sym__,
    ACTIONS(125), 1,
      anon_sym_i,
    STATE(17), 1,
      aux_sym__hexnum_repeat1,
    ACTIONS(117), 8,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_DOT,
      anon_sym_p,
      anon_sym_P,
      anon_sym_f,
      sym__LPAR,
      sym__RPAR,
  [549] = 2,
    ACTIONS(109), 1,
      anon_sym_i,
    ACTIONS(101), 10,
      sym_instrCall,
      sym_instrBlock,
      sym__digit,
      anon_sym_DOT,
      anon_sym_e,
      anon_sym_E,
      anon_sym_f,
      anon_sym__,
      sym__LPAR,
      sym__RPAR,
  [565] = 5,
    ACTIONS(131), 1,
      sym__hexdigit,
    ACTIONS(133), 1,
      anon_sym_i,
    ACTIONS(129), 2,
      anon_sym_p,
      anon_sym_P,
    STATE(33), 2,
      sym__hexfrac,
      sym__hexnum,
    ACTIONS(127), 5,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_f,
      sym__LPAR,
      sym__RPAR,
  [587] = 2,
    ACTIONS(125), 2,
      sym__hexdigit,
      anon_sym_i,
    ACTIONS(117), 9,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_DOT,
      anon_sym_p,
      anon_sym_P,
      anon_sym_f,
      anon_sym__,
      sym__LPAR,
      sym__RPAR,
  [603] = 5,
    ACTIONS(137), 1,
      sym__digit,
    ACTIONS(141), 1,
      anon_sym_i,
    ACTIONS(139), 2,
      anon_sym_e,
      anon_sym_E,
    STATE(36), 2,
      sym__frac,
      sym__num,
    ACTIONS(135), 5,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_f,
      sym__LPAR,
      sym__RPAR,
  [625] = 5,
    ACTIONS(137), 1,
      sym__digit,
    ACTIONS(147), 1,
      anon_sym_i,
    ACTIONS(145), 2,
      anon_sym_e,
      anon_sym_E,
    STATE(35), 2,
      sym__frac,
      sym__num,
    ACTIONS(143), 5,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_f,
      sym__LPAR,
      sym__RPAR,
  [647] = 5,
    ACTIONS(131), 1,
      sym__hexdigit,
    ACTIONS(147), 1,
      anon_sym_i,
    ACTIONS(145), 2,
      anon_sym_p,
      anon_sym_P,
    STATE(37), 2,
      sym__hexfrac,
      sym__hexnum,
    ACTIONS(143), 5,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_f,
      sym__LPAR,
      sym__RPAR,
  [669] = 4,
    ACTIONS(151), 1,
      anon_sym_DOT,
    ACTIONS(155), 1,
      anon_sym_i,
    ACTIONS(153), 2,
      anon_sym_e,
      anon_sym_E,
    ACTIONS(149), 5,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_f,
      sym__LPAR,
      sym__RPAR,
  [687] = 7,
    ACTIONS(157), 1,
      anon_sym_DOLLAR,
    ACTIONS(159), 1,
      sym__LPAR,
    ACTIONS(161), 1,
      sym__RPAR,
    STATE(32), 1,
      sym__name,
    STATE(87), 1,
      sym_func,
    STATE(71), 2,
      sym_moduleField,
      aux_sym_module_repeat1,
    STATE(72), 2,
      sym__moduleVar,
      sym_VAR,
  [711] = 6,
    ACTIONS(27), 1,
      sym__digit,
    ACTIONS(157), 1,
      anon_sym_DOLLAR,
    ACTIONS(163), 1,
      anon_sym_0x,
    STATE(32), 1,
      sym__name,
    STATE(57), 2,
      sym__nat,
      sym__num,
    STATE(115), 3,
      sym__var,
      sym_NAT,
      sym_VAR,
  [733] = 4,
    ACTIONS(167), 1,
      anon_sym_DOT,
    ACTIONS(169), 1,
      anon_sym_i,
    ACTIONS(139), 2,
      anon_sym_p,
      anon_sym_P,
    ACTIONS(165), 5,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_f,
      sym__LPAR,
      sym__RPAR,
  [751] = 7,
    ACTIONS(11), 1,
      anon_sym_f,
    ACTIONS(171), 1,
      anon_sym_i,
    ACTIONS(173), 1,
      sym__TYPE,
    STATE(6), 1,
      sym_CONST,
    STATE(77), 1,
      sym_instrPlain,
    STATE(107), 1,
      sym_expr1,
    STATE(120), 3,
      sym__fxx,
      sym__ixx,
      sym__nxx,
  [775] = 4,
    ACTIONS(169), 1,
      anon_sym_i,
    ACTIONS(175), 1,
      anon_sym_DOT,
    ACTIONS(145), 2,
      anon_sym_p,
      anon_sym_P,
    ACTIONS(165), 5,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_f,
      sym__LPAR,
      sym__RPAR,
  [793] = 4,
    ACTIONS(155), 1,
      anon_sym_i,
    ACTIONS(177), 1,
      anon_sym_DOT,
    ACTIONS(139), 2,
      anon_sym_e,
      anon_sym_E,
    ACTIONS(149), 5,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_f,
      sym__LPAR,
      sym__RPAR,
  [811] = 4,
    ACTIONS(179), 1,
      sym__hexdigit,
    ACTIONS(181), 1,
      anon_sym__,
    STATE(34), 1,
      aux_sym__hexnum_repeat1,
    ACTIONS(93), 5,
      anon_sym_DOT,
      anon_sym_p,
      anon_sym_P,
      sym__LPAR,
      sym__RPAR,
  [828] = 2,
    ACTIONS(185), 1,
      anon_sym_i,
    ACTIONS(183), 7,
      sym_inlineExport,
      sym_inlineImport,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_f,
      sym__LPAR,
      sym__RPAR,
  [841] = 3,
    ACTIONS(191), 1,
      anon_sym_i,
    ACTIONS(189), 2,
      anon_sym_p,
      anon_sym_P,
    ACTIONS(187), 5,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_f,
      sym__LPAR,
      sym__RPAR,
  [856] = 4,
    ACTIONS(181), 1,
      anon_sym__,
    ACTIONS(193), 1,
      sym__hexdigit,
    STATE(38), 1,
      aux_sym__hexnum_repeat1,
    ACTIONS(111), 5,
      anon_sym_DOT,
      anon_sym_p,
      anon_sym_P,
      sym__LPAR,
      sym__RPAR,
  [873] = 3,
    ACTIONS(133), 1,
      anon_sym_i,
    ACTIONS(129), 2,
      anon_sym_e,
      anon_sym_E,
    ACTIONS(127), 5,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_f,
      sym__LPAR,
      sym__RPAR,
  [888] = 3,
    ACTIONS(147), 1,
      anon_sym_i,
    ACTIONS(145), 2,
      anon_sym_e,
      anon_sym_E,
    ACTIONS(143), 5,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_f,
      sym__LPAR,
      sym__RPAR,
  [903] = 3,
    ACTIONS(133), 1,
      anon_sym_i,
    ACTIONS(129), 2,
      anon_sym_p,
      anon_sym_P,
    ACTIONS(127), 5,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_f,
      sym__LPAR,
      sym__RPAR,
  [918] = 4,
    ACTIONS(195), 1,
      sym__hexdigit,
    ACTIONS(198), 1,
      anon_sym__,
    STATE(38), 1,
      aux_sym__hexnum_repeat1,
    ACTIONS(117), 5,
      anon_sym_DOT,
      anon_sym_p,
      anon_sym_P,
      sym__LPAR,
      sym__RPAR,
  [935] = 6,
    ACTIONS(11), 1,
      anon_sym_f,
    ACTIONS(171), 1,
      anon_sym_i,
    STATE(6), 1,
      sym_CONST,
    STATE(77), 1,
      sym_instrPlain,
    STATE(107), 1,
      sym_expr1,
    STATE(120), 3,
      sym__fxx,
      sym__ixx,
      sym__nxx,
  [956] = 4,
    ACTIONS(201), 1,
      sym__hexdigit,
    ACTIONS(143), 2,
      sym__LPAR,
      sym__RPAR,
    ACTIONS(145), 2,
      anon_sym_p,
      anon_sym_P,
    STATE(37), 2,
      sym__hexfrac,
      sym__hexnum,
  [972] = 2,
    ACTIONS(205), 2,
      anon_sym_f,
      anon_sym_i,
    ACTIONS(203), 5,
      sym_funcFieldImport,
      sym_instrCall,
      sym_instrBlock,
      sym__LPAR,
      sym__RPAR,
  [984] = 3,
    STATE(46), 1,
      aux_sym__name_repeat1,
    ACTIONS(71), 2,
      sym__LPAR,
      sym__RPAR,
    ACTIONS(207), 4,
      sym__digit,
      anon_sym__,
      sym__letter,
      sym__symbol,
  [998] = 7,
    ACTIONS(27), 1,
      sym__digit,
    ACTIONS(209), 1,
      anon_sym_0x,
    ACTIONS(211), 1,
      anon_sym_inf,
    ACTIONS(213), 1,
      anon_sym_nan,
    ACTIONS(215), 1,
      anon_sym_nan_COLON,
    STATE(30), 1,
      sym__num,
    STATE(53), 1,
      sym__nat,
  [1020] = 1,
    ACTIONS(117), 7,
      anon_sym_DOT,
      anon_sym_p,
      anon_sym_P,
      sym__hexdigit,
      anon_sym__,
      sym__LPAR,
      sym__RPAR,
  [1030] = 7,
    ACTIONS(27), 1,
      sym__digit,
    ACTIONS(211), 1,
      anon_sym_inf,
    ACTIONS(213), 1,
      anon_sym_nan,
    ACTIONS(217), 1,
      anon_sym_0x,
    ACTIONS(219), 1,
      anon_sym_nan_COLON,
    STATE(30), 1,
      sym__num,
    STATE(53), 1,
      sym__nat,
  [1052] = 3,
    STATE(46), 1,
      aux_sym__name_repeat1,
    ACTIONS(61), 2,
      sym__LPAR,
      sym__RPAR,
    ACTIONS(221), 4,
      sym__digit,
      anon_sym__,
      sym__letter,
      sym__symbol,
  [1066] = 2,
    ACTIONS(224), 2,
      sym__digit,
      anon_sym_nan,
    ACTIONS(226), 5,
      anon_sym_0x,
      anon_sym_inf,
      anon_sym_nan_COLON,
      anon_sym_PLUS,
      anon_sym_DASH,
  [1078] = 4,
    ACTIONS(201), 1,
      sym__hexdigit,
    ACTIONS(127), 2,
      sym__LPAR,
      sym__RPAR,
    ACTIONS(129), 2,
      anon_sym_p,
      anon_sym_P,
    STATE(33), 2,
      sym__hexfrac,
      sym__hexnum,
  [1094] = 2,
    ACTIONS(133), 1,
      anon_sym_i,
    ACTIONS(127), 5,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_f,
      sym__LPAR,
      sym__RPAR,
  [1105] = 2,
    ACTIONS(230), 1,
      anon_sym_i,
    ACTIONS(228), 5,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_f,
      sym__LPAR,
      sym__RPAR,
  [1116] = 2,
    ACTIONS(147), 1,
      anon_sym_i,
    ACTIONS(143), 5,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_f,
      sym__LPAR,
      sym__RPAR,
  [1127] = 2,
    ACTIONS(234), 1,
      anon_sym_i,
    ACTIONS(232), 5,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_f,
      sym__LPAR,
      sym__RPAR,
  [1138] = 2,
    ACTIONS(238), 1,
      anon_sym_i,
    ACTIONS(236), 5,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_f,
      sym__LPAR,
      sym__RPAR,
  [1149] = 2,
    ACTIONS(242), 1,
      anon_sym_i,
    ACTIONS(240), 5,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_f,
      sym__LPAR,
      sym__RPAR,
  [1160] = 2,
    ACTIONS(246), 1,
      anon_sym_i,
    ACTIONS(244), 5,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_f,
      sym__LPAR,
      sym__RPAR,
  [1171] = 2,
    ACTIONS(250), 1,
      anon_sym_i,
    ACTIONS(248), 5,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_f,
      sym__LPAR,
      sym__RPAR,
  [1182] = 2,
    ACTIONS(254), 1,
      anon_sym_i,
    ACTIONS(252), 5,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_f,
      sym__LPAR,
      sym__RPAR,
  [1193] = 2,
    ACTIONS(258), 1,
      anon_sym_i,
    ACTIONS(256), 5,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_f,
      sym__LPAR,
      sym__RPAR,
  [1204] = 2,
    ACTIONS(191), 1,
      anon_sym_i,
    ACTIONS(187), 5,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_f,
      sym__LPAR,
      sym__RPAR,
  [1215] = 2,
    ACTIONS(141), 1,
      anon_sym_i,
    ACTIONS(135), 5,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_f,
      sym__LPAR,
      sym__RPAR,
  [1226] = 2,
    ACTIONS(262), 1,
      anon_sym_i,
    ACTIONS(260), 5,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_f,
      sym__LPAR,
      sym__RPAR,
  [1237] = 2,
    ACTIONS(266), 1,
      anon_sym_i,
    ACTIONS(264), 5,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_f,
      sym__LPAR,
      sym__RPAR,
  [1248] = 2,
    ACTIONS(270), 1,
      anon_sym_i,
    ACTIONS(268), 5,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_f,
      sym__LPAR,
      sym__RPAR,
  [1259] = 4,
    ACTIONS(159), 1,
      sym__LPAR,
    ACTIONS(272), 1,
      sym__RPAR,
    STATE(87), 1,
      sym_func,
    STATE(68), 2,
      sym_moduleField,
      aux_sym_module_repeat1,
  [1273] = 4,
    ACTIONS(137), 1,
      sym__digit,
    STATE(49), 1,
      sym__num,
    STATE(97), 1,
      sym__sign,
    ACTIONS(274), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
  [1287] = 3,
    ACTIONS(276), 1,
      anon_sym_DOT,
    ACTIONS(145), 2,
      anon_sym_p,
      anon_sym_P,
    ACTIONS(165), 2,
      sym__LPAR,
      sym__RPAR,
  [1299] = 4,
    ACTIONS(137), 1,
      sym__digit,
    STATE(63), 1,
      sym__num,
    STATE(94), 1,
      sym__sign,
    ACTIONS(278), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
  [1313] = 4,
    ACTIONS(280), 1,
      sym__LPAR,
    ACTIONS(283), 1,
      sym__RPAR,
    STATE(87), 1,
      sym_func,
    STATE(68), 2,
      sym_moduleField,
      aux_sym_module_repeat1,
  [1327] = 4,
    ACTIONS(137), 1,
      sym__digit,
    STATE(51), 1,
      sym__num,
    STATE(88), 1,
      sym__sign,
    ACTIONS(285), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
  [1341] = 4,
    ACTIONS(137), 1,
      sym__digit,
    STATE(61), 1,
      sym__num,
    STATE(99), 1,
      sym__sign,
    ACTIONS(287), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
  [1355] = 4,
    ACTIONS(159), 1,
      sym__LPAR,
    ACTIONS(289), 1,
      sym__RPAR,
    STATE(87), 1,
      sym_func,
    STATE(68), 2,
      sym_moduleField,
      aux_sym_module_repeat1,
  [1369] = 4,
    ACTIONS(159), 1,
      sym__LPAR,
    ACTIONS(289), 1,
      sym__RPAR,
    STATE(87), 1,
      sym_func,
    STATE(64), 2,
      sym_moduleField,
      aux_sym_module_repeat1,
  [1383] = 2,
    STATE(42), 1,
      aux_sym__name_repeat1,
    ACTIONS(291), 4,
      sym__digit,
      anon_sym__,
      sym__letter,
      sym__symbol,
  [1393] = 2,
    STATE(11), 1,
      aux_sym__name_repeat1,
    ACTIONS(293), 4,
      sym__digit,
      anon_sym__,
      sym__letter,
      sym__symbol,
  [1403] = 4,
    ACTIONS(137), 1,
      sym__digit,
    STATE(59), 1,
      sym__num,
    STATE(82), 1,
      sym__sign,
    ACTIONS(295), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
  [1417] = 3,
    ACTIONS(297), 1,
      anon_sym_DOT,
    ACTIONS(139), 2,
      anon_sym_p,
      anon_sym_P,
    ACTIONS(165), 2,
      sym__LPAR,
      sym__RPAR,
  [1429] = 3,
    ACTIONS(23), 1,
      sym__LPAR,
    ACTIONS(299), 1,
      sym__RPAR,
    STATE(78), 2,
      sym_expr,
      aux_sym_expr1_repeat1,
  [1440] = 3,
    ACTIONS(23), 1,
      sym__LPAR,
    ACTIONS(301), 1,
      sym__RPAR,
    STATE(79), 2,
      sym_expr,
      aux_sym_expr1_repeat1,
  [1451] = 3,
    ACTIONS(303), 1,
      sym__LPAR,
    ACTIONS(306), 1,
      sym__RPAR,
    STATE(79), 2,
      sym_expr,
      aux_sym_expr1_repeat1,
  [1462] = 3,
    ACTIONS(308), 1,
      sym_funcFieldImport,
    ACTIONS(310), 1,
      sym__LPAR,
    STATE(108), 1,
      sym_typeUse,
  [1472] = 2,
    ACTIONS(312), 1,
      sym__hexdigit,
    STATE(51), 1,
      sym__hexnum,
  [1479] = 2,
    ACTIONS(137), 1,
      sym__digit,
    STATE(61), 1,
      sym__num,
  [1486] = 2,
    ACTIONS(312), 1,
      sym__hexdigit,
    STATE(27), 1,
      sym__hexnum,
  [1493] = 2,
    ACTIONS(201), 1,
      sym__hexdigit,
    STATE(76), 1,
      sym__hexnum,
  [1500] = 2,
    ACTIONS(201), 1,
      sym__hexdigit,
    STATE(116), 1,
      sym__hexnum,
  [1507] = 2,
    ACTIONS(201), 1,
      sym__hexdigit,
    STATE(49), 1,
      sym__hexnum,
  [1514] = 1,
    ACTIONS(314), 2,
      sym__LPAR,
      sym__RPAR,
  [1519] = 2,
    ACTIONS(137), 1,
      sym__digit,
    STATE(49), 1,
      sym__num,
  [1526] = 2,
    ACTIONS(201), 1,
      sym__hexdigit,
    STATE(66), 1,
      sym__hexnum,
  [1533] = 2,
    ACTIONS(312), 1,
      sym__hexdigit,
    STATE(49), 1,
      sym__hexnum,
  [1540] = 2,
    ACTIONS(201), 1,
      sym__hexdigit,
    STATE(51), 1,
      sym__hexnum,
  [1547] = 1,
    ACTIONS(316), 2,
      sym__LPAR,
      sym__RPAR,
  [1552] = 1,
    ACTIONS(318), 2,
      sym__LPAR,
      sym__RPAR,
  [1557] = 2,
    ACTIONS(137), 1,
      sym__digit,
    STATE(50), 1,
      sym__num,
  [1564] = 1,
    ACTIONS(320), 2,
      anon_sym_32,
      anon_sym_64,
  [1569] = 1,
    ACTIONS(322), 2,
      anon_sym_32,
      anon_sym_64,
  [1574] = 2,
    ACTIONS(137), 1,
      sym__digit,
    STATE(59), 1,
      sym__num,
  [1581] = 1,
    ACTIONS(324), 2,
      sym__LPAR,
      sym__RPAR,
  [1586] = 2,
    ACTIONS(137), 1,
      sym__digit,
    STATE(63), 1,
      sym__num,
  [1593] = 2,
    ACTIONS(312), 1,
      sym__hexdigit,
    STATE(29), 1,
      sym__hexnum,
  [1600] = 1,
    ACTIONS(326), 1,
      sym__RPAR,
  [1604] = 1,
    ACTIONS(25), 1,
      sym__RPAR,
  [1608] = 1,
    ACTIONS(328), 1,
      anon_sym_DOTconst,
  [1612] = 1,
    ACTIONS(330), 1,
      anon_sym_0x,
  [1616] = 1,
    ACTIONS(332), 1,
      anon_sym_DOTconst,
  [1620] = 1,
    ACTIONS(334), 1,
      sym__RPAR,
  [1624] = 1,
    ACTIONS(336), 1,
      sym__RPAR,
  [1628] = 1,
    ACTIONS(338), 1,
      sym_funcFieldImport,
  [1632] = 1,
    ACTIONS(340), 1,
      sym__MODULE,
  [1636] = 1,
    ACTIONS(342), 1,
      sym__digit,
  [1640] = 1,
    ACTIONS(344), 1,
      ts_builtin_sym_end,
  [1644] = 1,
    ACTIONS(173), 1,
      sym__TYPE,
  [1648] = 1,
    ACTIONS(346), 1,
      sym__RPAR,
  [1652] = 1,
    ACTIONS(21), 1,
      sym__RPAR,
  [1656] = 1,
    ACTIONS(348), 1,
      sym__RPAR,
  [1660] = 1,
    ACTIONS(165), 1,
      sym__RPAR,
  [1664] = 1,
    ACTIONS(350), 1,
      sym__RPAR,
  [1668] = 1,
    ACTIONS(352), 1,
      ts_builtin_sym_end,
  [1672] = 1,
    ACTIONS(354), 1,
      sym__FUNC,
  [1676] = 1,
    ACTIONS(356), 1,
      anon_sym_DOTconst,
  [1680] = 1,
    ACTIONS(358), 1,
      sym__RPAR,
  [1684] = 1,
    ACTIONS(360), 1,
      ts_builtin_sym_end,
  [1688] = 1,
    ACTIONS(362), 1,
      anon_sym_0x,
  [1692] = 1,
    ACTIONS(364), 1,
      ts_builtin_sym_end,
  [1696] = 1,
    ACTIONS(366), 1,
      anon_sym_0x,
  [1700] = 1,
    ACTIONS(368), 1,
      anon_sym_0x,
  [1704] = 1,
    ACTIONS(370), 1,
      sym__hexdigit,
  [1708] = 1,
    ACTIONS(372), 1,
      sym__hexdigit,
  [1712] = 1,
    ACTIONS(374), 1,
      ts_builtin_sym_end,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 64,
  [SMALL_STATE(4)] = 118,
  [SMALL_STATE(5)] = 169,
  [SMALL_STATE(6)] = 211,
  [SMALL_STATE(7)] = 254,
  [SMALL_STATE(8)] = 297,
  [SMALL_STATE(9)] = 330,
  [SMALL_STATE(10)] = 363,
  [SMALL_STATE(11)] = 387,
  [SMALL_STATE(12)] = 411,
  [SMALL_STATE(13)] = 434,
  [SMALL_STATE(14)] = 457,
  [SMALL_STATE(15)] = 480,
  [SMALL_STATE(16)] = 503,
  [SMALL_STATE(17)] = 526,
  [SMALL_STATE(18)] = 549,
  [SMALL_STATE(19)] = 565,
  [SMALL_STATE(20)] = 587,
  [SMALL_STATE(21)] = 603,
  [SMALL_STATE(22)] = 625,
  [SMALL_STATE(23)] = 647,
  [SMALL_STATE(24)] = 669,
  [SMALL_STATE(25)] = 687,
  [SMALL_STATE(26)] = 711,
  [SMALL_STATE(27)] = 733,
  [SMALL_STATE(28)] = 751,
  [SMALL_STATE(29)] = 775,
  [SMALL_STATE(30)] = 793,
  [SMALL_STATE(31)] = 811,
  [SMALL_STATE(32)] = 828,
  [SMALL_STATE(33)] = 841,
  [SMALL_STATE(34)] = 856,
  [SMALL_STATE(35)] = 873,
  [SMALL_STATE(36)] = 888,
  [SMALL_STATE(37)] = 903,
  [SMALL_STATE(38)] = 918,
  [SMALL_STATE(39)] = 935,
  [SMALL_STATE(40)] = 956,
  [SMALL_STATE(41)] = 972,
  [SMALL_STATE(42)] = 984,
  [SMALL_STATE(43)] = 998,
  [SMALL_STATE(44)] = 1020,
  [SMALL_STATE(45)] = 1030,
  [SMALL_STATE(46)] = 1052,
  [SMALL_STATE(47)] = 1066,
  [SMALL_STATE(48)] = 1078,
  [SMALL_STATE(49)] = 1094,
  [SMALL_STATE(50)] = 1105,
  [SMALL_STATE(51)] = 1116,
  [SMALL_STATE(52)] = 1127,
  [SMALL_STATE(53)] = 1138,
  [SMALL_STATE(54)] = 1149,
  [SMALL_STATE(55)] = 1160,
  [SMALL_STATE(56)] = 1171,
  [SMALL_STATE(57)] = 1182,
  [SMALL_STATE(58)] = 1193,
  [SMALL_STATE(59)] = 1204,
  [SMALL_STATE(60)] = 1215,
  [SMALL_STATE(61)] = 1226,
  [SMALL_STATE(62)] = 1237,
  [SMALL_STATE(63)] = 1248,
  [SMALL_STATE(64)] = 1259,
  [SMALL_STATE(65)] = 1273,
  [SMALL_STATE(66)] = 1287,
  [SMALL_STATE(67)] = 1299,
  [SMALL_STATE(68)] = 1313,
  [SMALL_STATE(69)] = 1327,
  [SMALL_STATE(70)] = 1341,
  [SMALL_STATE(71)] = 1355,
  [SMALL_STATE(72)] = 1369,
  [SMALL_STATE(73)] = 1383,
  [SMALL_STATE(74)] = 1393,
  [SMALL_STATE(75)] = 1403,
  [SMALL_STATE(76)] = 1417,
  [SMALL_STATE(77)] = 1429,
  [SMALL_STATE(78)] = 1440,
  [SMALL_STATE(79)] = 1451,
  [SMALL_STATE(80)] = 1462,
  [SMALL_STATE(81)] = 1472,
  [SMALL_STATE(82)] = 1479,
  [SMALL_STATE(83)] = 1486,
  [SMALL_STATE(84)] = 1493,
  [SMALL_STATE(85)] = 1500,
  [SMALL_STATE(86)] = 1507,
  [SMALL_STATE(87)] = 1514,
  [SMALL_STATE(88)] = 1519,
  [SMALL_STATE(89)] = 1526,
  [SMALL_STATE(90)] = 1533,
  [SMALL_STATE(91)] = 1540,
  [SMALL_STATE(92)] = 1547,
  [SMALL_STATE(93)] = 1552,
  [SMALL_STATE(94)] = 1557,
  [SMALL_STATE(95)] = 1564,
  [SMALL_STATE(96)] = 1569,
  [SMALL_STATE(97)] = 1574,
  [SMALL_STATE(98)] = 1581,
  [SMALL_STATE(99)] = 1586,
  [SMALL_STATE(100)] = 1593,
  [SMALL_STATE(101)] = 1600,
  [SMALL_STATE(102)] = 1604,
  [SMALL_STATE(103)] = 1608,
  [SMALL_STATE(104)] = 1612,
  [SMALL_STATE(105)] = 1616,
  [SMALL_STATE(106)] = 1620,
  [SMALL_STATE(107)] = 1624,
  [SMALL_STATE(108)] = 1628,
  [SMALL_STATE(109)] = 1632,
  [SMALL_STATE(110)] = 1636,
  [SMALL_STATE(111)] = 1640,
  [SMALL_STATE(112)] = 1644,
  [SMALL_STATE(113)] = 1648,
  [SMALL_STATE(114)] = 1652,
  [SMALL_STATE(115)] = 1656,
  [SMALL_STATE(116)] = 1660,
  [SMALL_STATE(117)] = 1664,
  [SMALL_STATE(118)] = 1668,
  [SMALL_STATE(119)] = 1672,
  [SMALL_STATE(120)] = 1676,
  [SMALL_STATE(121)] = 1680,
  [SMALL_STATE(122)] = 1684,
  [SMALL_STATE(123)] = 1688,
  [SMALL_STATE(124)] = 1692,
  [SMALL_STATE(125)] = 1696,
  [SMALL_STATE(126)] = 1700,
  [SMALL_STATE(127)] = 1704,
  [SMALL_STATE(128)] = 1708,
  [SMALL_STATE(129)] = 1712,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.count = 0, .reusable = false},
  [1] = {.count = 1, .reusable = false}, RECOVER(),
  [3] = {.count = 1, .reusable = true}, SHIFT(109),
  [5] = {.count = 1, .reusable = true}, SHIFT(4),
  [7] = {.count = 1, .reusable = true}, SHIFT(80),
  [9] = {.count = 1, .reusable = true}, SHIFT(52),
  [11] = {.count = 1, .reusable = true}, SHIFT(96),
  [13] = {.count = 1, .reusable = false}, SHIFT(95),
  [15] = {.count = 1, .reusable = true}, SHIFT(74),
  [17] = {.count = 1, .reusable = true}, SHIFT(28),
  [19] = {.count = 1, .reusable = true}, SHIFT(93),
  [21] = {.count = 1, .reusable = true}, SHIFT(98),
  [23] = {.count = 1, .reusable = true}, SHIFT(39),
  [25] = {.count = 1, .reusable = true}, REDUCE(sym_funcField, 1),
  [27] = {.count = 1, .reusable = false}, SHIFT(12),
  [29] = {.count = 1, .reusable = true}, SHIFT(84),
  [31] = {.count = 1, .reusable = true}, SHIFT(55),
  [33] = {.count = 1, .reusable = false}, SHIFT(55),
  [35] = {.count = 1, .reusable = true}, SHIFT(123),
  [37] = {.count = 1, .reusable = true}, SHIFT(43),
  [39] = {.count = 1, .reusable = true}, SHIFT(83),
  [41] = {.count = 1, .reusable = true}, SHIFT(125),
  [43] = {.count = 1, .reusable = true}, SHIFT(45),
  [45] = {.count = 2, .reusable = true}, REDUCE(aux_sym_funcBody_repeat1, 2), SHIFT_REPEAT(52),
  [48] = {.count = 2, .reusable = true}, REDUCE(aux_sym_funcBody_repeat1, 2), SHIFT_REPEAT(96),
  [51] = {.count = 2, .reusable = false}, REDUCE(aux_sym_funcBody_repeat1, 2), SHIFT_REPEAT(95),
  [54] = {.count = 2, .reusable = true}, REDUCE(aux_sym_funcBody_repeat1, 2), SHIFT_REPEAT(39),
  [57] = {.count = 1, .reusable = true}, REDUCE(aux_sym_funcBody_repeat1, 2),
  [59] = {.count = 1, .reusable = true}, REDUCE(sym_funcBody, 1),
  [61] = {.count = 1, .reusable = true}, REDUCE(aux_sym__name_repeat1, 2),
  [63] = {.count = 2, .reusable = true}, REDUCE(aux_sym__name_repeat1, 2), SHIFT_REPEAT(10),
  [66] = {.count = 1, .reusable = false}, REDUCE(aux_sym__name_repeat1, 2),
  [68] = {.count = 2, .reusable = false}, REDUCE(aux_sym__name_repeat1, 2), SHIFT_REPEAT(10),
  [71] = {.count = 1, .reusable = true}, REDUCE(sym__name, 2),
  [73] = {.count = 1, .reusable = true}, SHIFT(10),
  [75] = {.count = 1, .reusable = false}, REDUCE(sym__name, 2),
  [77] = {.count = 1, .reusable = false}, SHIFT(10),
  [79] = {.count = 1, .reusable = true}, REDUCE(sym__num, 1),
  [81] = {.count = 1, .reusable = true}, SHIFT(13),
  [83] = {.count = 1, .reusable = true}, SHIFT(110),
  [85] = {.count = 1, .reusable = false}, REDUCE(sym__num, 1),
  [87] = {.count = 1, .reusable = true}, REDUCE(sym__num, 2),
  [89] = {.count = 1, .reusable = true}, SHIFT(15),
  [91] = {.count = 1, .reusable = false}, REDUCE(sym__num, 2),
  [93] = {.count = 1, .reusable = true}, REDUCE(sym__hexnum, 1),
  [95] = {.count = 1, .reusable = false}, SHIFT(16),
  [97] = {.count = 1, .reusable = true}, SHIFT(128),
  [99] = {.count = 1, .reusable = false}, REDUCE(sym__hexnum, 1),
  [101] = {.count = 1, .reusable = true}, REDUCE(aux_sym__num_repeat1, 2),
  [103] = {.count = 2, .reusable = true}, REDUCE(aux_sym__num_repeat1, 2), SHIFT_REPEAT(15),
  [106] = {.count = 2, .reusable = true}, REDUCE(aux_sym__num_repeat1, 2), SHIFT_REPEAT(110),
  [109] = {.count = 1, .reusable = false}, REDUCE(aux_sym__num_repeat1, 2),
  [111] = {.count = 1, .reusable = true}, REDUCE(sym__hexnum, 2),
  [113] = {.count = 1, .reusable = false}, SHIFT(17),
  [115] = {.count = 1, .reusable = false}, REDUCE(sym__hexnum, 2),
  [117] = {.count = 1, .reusable = true}, REDUCE(aux_sym__hexnum_repeat1, 2),
  [119] = {.count = 2, .reusable = false}, REDUCE(aux_sym__hexnum_repeat1, 2), SHIFT_REPEAT(17),
  [122] = {.count = 2, .reusable = true}, REDUCE(aux_sym__hexnum_repeat1, 2), SHIFT_REPEAT(128),
  [125] = {.count = 1, .reusable = false}, REDUCE(aux_sym__hexnum_repeat1, 2),
  [127] = {.count = 1, .reusable = true}, REDUCE(sym__float, 4),
  [129] = {.count = 1, .reusable = true}, SHIFT(70),
  [131] = {.count = 1, .reusable = false}, SHIFT(14),
  [133] = {.count = 1, .reusable = false}, REDUCE(sym__float, 4),
  [135] = {.count = 1, .reusable = true}, REDUCE(sym__float, 2),
  [137] = {.count = 1, .reusable = true}, SHIFT(12),
  [139] = {.count = 1, .reusable = true}, SHIFT(65),
  [141] = {.count = 1, .reusable = false}, REDUCE(sym__float, 2),
  [143] = {.count = 1, .reusable = true}, REDUCE(sym__float, 3),
  [145] = {.count = 1, .reusable = true}, SHIFT(75),
  [147] = {.count = 1, .reusable = false}, REDUCE(sym__float, 3),
  [149] = {.count = 1, .reusable = true}, REDUCE(sym__nat, 1),
  [151] = {.count = 1, .reusable = true}, SHIFT(21),
  [153] = {.count = 1, .reusable = true}, SHIFT(69),
  [155] = {.count = 1, .reusable = false}, REDUCE(sym__nat, 1),
  [157] = {.count = 1, .reusable = true}, SHIFT(73),
  [159] = {.count = 1, .reusable = true}, SHIFT(119),
  [161] = {.count = 1, .reusable = true}, SHIFT(118),
  [163] = {.count = 1, .reusable = true}, SHIFT(85),
  [165] = {.count = 1, .reusable = true}, REDUCE(sym__nat, 2),
  [167] = {.count = 1, .reusable = true}, SHIFT(23),
  [169] = {.count = 1, .reusable = false}, REDUCE(sym__nat, 2),
  [171] = {.count = 1, .reusable = true}, SHIFT(95),
  [173] = {.count = 1, .reusable = true}, SHIFT(26),
  [175] = {.count = 1, .reusable = true}, SHIFT(19),
  [177] = {.count = 1, .reusable = true}, SHIFT(22),
  [179] = {.count = 1, .reusable = true}, SHIFT(34),
  [181] = {.count = 1, .reusable = true}, SHIFT(127),
  [183] = {.count = 1, .reusable = true}, REDUCE(sym_VAR, 1),
  [185] = {.count = 1, .reusable = false}, REDUCE(sym_VAR, 1),
  [187] = {.count = 1, .reusable = true}, REDUCE(sym__float, 5),
  [189] = {.count = 1, .reusable = true}, SHIFT(67),
  [191] = {.count = 1, .reusable = false}, REDUCE(sym__float, 5),
  [193] = {.count = 1, .reusable = true}, SHIFT(38),
  [195] = {.count = 2, .reusable = true}, REDUCE(aux_sym__hexnum_repeat1, 2), SHIFT_REPEAT(38),
  [198] = {.count = 2, .reusable = true}, REDUCE(aux_sym__hexnum_repeat1, 2), SHIFT_REPEAT(127),
  [201] = {.count = 1, .reusable = true}, SHIFT(31),
  [203] = {.count = 1, .reusable = true}, REDUCE(sym_typeUse, 4),
  [205] = {.count = 1, .reusable = false}, REDUCE(sym_typeUse, 4),
  [207] = {.count = 1, .reusable = true}, SHIFT(46),
  [209] = {.count = 1, .reusable = true}, SHIFT(89),
  [211] = {.count = 1, .reusable = true}, SHIFT(60),
  [213] = {.count = 1, .reusable = false}, SHIFT(60),
  [215] = {.count = 1, .reusable = true}, SHIFT(126),
  [217] = {.count = 1, .reusable = true}, SHIFT(100),
  [219] = {.count = 1, .reusable = true}, SHIFT(104),
  [221] = {.count = 2, .reusable = true}, REDUCE(aux_sym__name_repeat1, 2), SHIFT_REPEAT(46),
  [224] = {.count = 1, .reusable = false}, REDUCE(sym_CONST, 2),
  [226] = {.count = 1, .reusable = true}, REDUCE(sym_CONST, 2),
  [228] = {.count = 1, .reusable = true}, REDUCE(sym__float, 8),
  [230] = {.count = 1, .reusable = false}, REDUCE(sym__float, 8),
  [232] = {.count = 1, .reusable = true}, REDUCE(sym_instr, 1),
  [234] = {.count = 1, .reusable = false}, REDUCE(sym_instr, 1),
  [236] = {.count = 1, .reusable = true}, REDUCE(sym__int, 2),
  [238] = {.count = 1, .reusable = false}, REDUCE(sym__int, 2),
  [240] = {.count = 1, .reusable = true}, REDUCE(sym_instrPlain, 2),
  [242] = {.count = 1, .reusable = false}, REDUCE(sym_instrPlain, 2),
  [244] = {.count = 1, .reusable = true}, REDUCE(sym_FLOAT, 1),
  [246] = {.count = 1, .reusable = false}, REDUCE(sym_FLOAT, 1),
  [248] = {.count = 1, .reusable = true}, REDUCE(sym_INT, 1),
  [250] = {.count = 1, .reusable = false}, REDUCE(sym_INT, 1),
  [252] = {.count = 1, .reusable = true}, REDUCE(sym_NAT, 1),
  [254] = {.count = 1, .reusable = false}, REDUCE(sym_NAT, 1),
  [256] = {.count = 1, .reusable = true}, REDUCE(sym_literal, 1),
  [258] = {.count = 1, .reusable = false}, REDUCE(sym_literal, 1),
  [260] = {.count = 1, .reusable = true}, REDUCE(sym__float, 6),
  [262] = {.count = 1, .reusable = false}, REDUCE(sym__float, 6),
  [264] = {.count = 1, .reusable = true}, REDUCE(sym_expr, 3),
  [266] = {.count = 1, .reusable = false}, REDUCE(sym_expr, 3),
  [268] = {.count = 1, .reusable = true}, REDUCE(sym__float, 7),
  [270] = {.count = 1, .reusable = false}, REDUCE(sym__float, 7),
  [272] = {.count = 1, .reusable = true}, SHIFT(122),
  [274] = {.count = 1, .reusable = true}, SHIFT(97),
  [276] = {.count = 1, .reusable = true}, SHIFT(48),
  [278] = {.count = 1, .reusable = true}, SHIFT(94),
  [280] = {.count = 2, .reusable = true}, REDUCE(aux_sym_module_repeat1, 2), SHIFT_REPEAT(119),
  [283] = {.count = 1, .reusable = true}, REDUCE(aux_sym_module_repeat1, 2),
  [285] = {.count = 1, .reusable = true}, SHIFT(88),
  [287] = {.count = 1, .reusable = true}, SHIFT(99),
  [289] = {.count = 1, .reusable = true}, SHIFT(111),
  [291] = {.count = 1, .reusable = true}, SHIFT(42),
  [293] = {.count = 1, .reusable = true}, SHIFT(11),
  [295] = {.count = 1, .reusable = true}, SHIFT(82),
  [297] = {.count = 1, .reusable = true}, SHIFT(40),
  [299] = {.count = 1, .reusable = true}, REDUCE(sym_expr1, 1),
  [301] = {.count = 1, .reusable = true}, REDUCE(sym_expr1, 2),
  [303] = {.count = 2, .reusable = true}, REDUCE(aux_sym_expr1_repeat1, 2), SHIFT_REPEAT(39),
  [306] = {.count = 1, .reusable = true}, REDUCE(aux_sym_expr1_repeat1, 2),
  [308] = {.count = 1, .reusable = true}, SHIFT(106),
  [310] = {.count = 1, .reusable = true}, SHIFT(112),
  [312] = {.count = 1, .reusable = true}, SHIFT(14),
  [314] = {.count = 1, .reusable = true}, REDUCE(sym_moduleField, 1),
  [316] = {.count = 1, .reusable = true}, REDUCE(sym_func, 5),
  [318] = {.count = 1, .reusable = true}, REDUCE(sym_func, 3),
  [320] = {.count = 1, .reusable = true}, SHIFT(105),
  [322] = {.count = 1, .reusable = true}, SHIFT(103),
  [324] = {.count = 1, .reusable = true}, REDUCE(sym_func, 4),
  [326] = {.count = 1, .reusable = true}, SHIFT(92),
  [328] = {.count = 1, .reusable = true}, REDUCE(sym__fxx, 2),
  [330] = {.count = 1, .reusable = true}, SHIFT(90),
  [332] = {.count = 1, .reusable = true}, REDUCE(sym__ixx, 2),
  [334] = {.count = 1, .reusable = true}, REDUCE(sym_funcField, 2),
  [336] = {.count = 1, .reusable = true}, SHIFT(62),
  [338] = {.count = 1, .reusable = true}, SHIFT(121),
  [340] = {.count = 1, .reusable = true}, SHIFT(25),
  [342] = {.count = 1, .reusable = true}, SHIFT(18),
  [344] = {.count = 1, .reusable = true}, REDUCE(sym_module, 4),
  [346] = {.count = 1, .reusable = true}, REDUCE(sym_funcResultBody, 1),
  [348] = {.count = 1, .reusable = true}, SHIFT(41),
  [350] = {.count = 1, .reusable = true}, REDUCE(sym_funcFieldBody, 1),
  [352] = {.count = 1, .reusable = true}, REDUCE(sym_module, 3),
  [354] = {.count = 1, .reusable = true}, SHIFT(2),
  [356] = {.count = 1, .reusable = true}, SHIFT(47),
  [358] = {.count = 1, .reusable = true}, REDUCE(sym_funcField, 3),
  [360] = {.count = 1, .reusable = true}, REDUCE(sym_module, 5),
  [362] = {.count = 1, .reusable = true}, SHIFT(91),
  [364] = {.count = 1, .reusable = true}, REDUCE(sym_file, 1),
  [366] = {.count = 1, .reusable = true}, SHIFT(81),
  [368] = {.count = 1, .reusable = true}, SHIFT(86),
  [370] = {.count = 1, .reusable = true}, SHIFT(44),
  [372] = {.count = 1, .reusable = true}, SHIFT(20),
  [374] = {.count = 1, .reusable = true},  ACCEPT_INPUT(),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_wast(void) {
  static TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .symbol_metadata = ts_symbol_metadata,
    .parse_table = (const unsigned short *)ts_parse_table,
    .small_parse_table = (const uint16_t *)ts_small_parse_table,
    .small_parse_table_map = (const uint32_t *)ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .lex_modes = ts_lex_modes,
    .symbol_names = ts_symbol_names,
    .public_symbol_map = ts_symbol_map,
    .alias_sequences = (const TSSymbol *)ts_alias_sequences,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .lex_fn = ts_lex,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
