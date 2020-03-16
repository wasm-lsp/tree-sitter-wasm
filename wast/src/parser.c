#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 11
#define STATE_COUNT 124
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 87
#define ALIAS_COUNT 0
#define TOKEN_COUNT 51
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
  sym__hexdigit = 20,
  anon_sym__ = 21,
  anon_sym_i = 22,
  sym__letter = 23,
  anon_sym_8 = 24,
  anon_sym_DOLLAR = 25,
  anon_sym_POUND = 26,
  anon_sym_PLUS = 27,
  anon_sym_DASH = 28,
  anon_sym_s = 29,
  anon_sym_u = 30,
  anon_sym_DQUOTE = 31,
  sym__symbol = 32,
  sym__utf8cont = 33,
  aux_sym__utf8enc_token1 = 34,
  aux_sym__utf8enc_token2 = 35,
  aux_sym__utf8enc_token3 = 36,
  aux_sym__utf8enc_token4 = 37,
  aux_sym__utf8enc_token5 = 38,
  aux_sym__utf8enc_token6 = 39,
  aux_sym__utf8enc_token7 = 40,
  aux_sym__utf8enc_token8 = 41,
  aux_sym__utf8enc_token9 = 42,
  aux_sym__utf8enc_token10 = 43,
  aux_sym__utf8enc_token11 = 44,
  sym_CONST = 45,
  sym__FUNC = 46,
  sym__LPAR = 47,
  sym__MODULE = 48,
  sym__RPAR = 49,
  sym__TYPE = 50,
  sym_file = 51,
  sym__bindVar = 52,
  sym_expr = 53,
  sym_expr1 = 54,
  sym_func = 55,
  sym_funcBody = 56,
  sym_funcField = 57,
  sym_funcFieldBody = 58,
  sym_funcResultBody = 59,
  sym_instr = 60,
  sym_instrPlain = 61,
  sym_literal = 62,
  sym_module = 63,
  sym_moduleField = 64,
  sym__moduleVar = 65,
  sym_typeUse = 66,
  sym__float = 67,
  sym__frac = 68,
  sym__hexfrac = 69,
  sym__hexnum = 70,
  sym__int = 71,
  sym__name = 72,
  sym__nat = 73,
  sym__num = 74,
  sym__sign = 75,
  sym__var = 76,
  sym_FLOAT = 77,
  sym_INT = 78,
  sym_NAT = 79,
  sym_VAR = 80,
  aux_sym_expr1_repeat1 = 81,
  aux_sym_funcBody_repeat1 = 82,
  aux_sym_module_repeat1 = 83,
  aux_sym__hexnum_repeat1 = 84,
  aux_sym__name_repeat1 = 85,
  aux_sym__num_repeat1 = 86,
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
  [sym_CONST] = "CONST",
  [sym__FUNC] = "_FUNC",
  [sym__LPAR] = "_LPAR",
  [sym__MODULE] = "_MODULE",
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
  [sym__hexfrac] = "_hexfrac",
  [sym__hexnum] = "_hexnum",
  [sym__int] = "_int",
  [sym__name] = "_name",
  [sym__nat] = "_nat",
  [sym__num] = "_num",
  [sym__sign] = "_sign",
  [sym__var] = "_var",
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
  [sym_CONST] = sym_CONST,
  [sym__FUNC] = sym__FUNC,
  [sym__LPAR] = sym__LPAR,
  [sym__MODULE] = sym__MODULE,
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
  [sym__hexfrac] = sym__hexfrac,
  [sym__hexnum] = sym__hexnum,
  [sym__int] = sym__int,
  [sym__name] = sym__name,
  [sym__nat] = sym__nat,
  [sym__num] = sym__num,
  [sym__sign] = sym__sign,
  [sym__var] = sym__var,
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
  [sym_CONST] = {
    .visible = true,
    .named = true,
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
  [sym__name] = {
    .visible = false,
    .named = true,
  },
  [sym__nat] = {
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
      if (eof) ADVANCE(67);
      if (lookahead == '"') ADVANCE(102);
      if (lookahead == '#') ADVANCE(97);
      if (lookahead == '$') ADVANCE(96);
      if (lookahead == '\'') ADVANCE(77);
      if (lookahead == '(') ADVANCE(114);
      if (lookahead == ')') ADVANCE(116);
      if (lookahead == '+') ADVANCE(98);
      if (lookahead == '-') ADVANCE(99);
      if (lookahead == '.') ADVANCE(78);
      if (lookahead == '8') ADVANCE(95);
      if (lookahead == 'E') ADVANCE(80);
      if (lookahead == 'P') ADVANCE(83);
      if (lookahead == '\\') ADVANCE(73);
      if (lookahead == '_') ADVANCE(90);
      if (lookahead == 'c') ADVANCE(89);
      if (lookahead == 'e') ADVANCE(79);
      if (lookahead == 'f') ADVANCE(87);
      if (lookahead == 'i') ADVANCE(91);
      if (lookahead == 'p') ADVANCE(82);
      if (lookahead == 's') ADVANCE(100);
      if (lookahead == 'u') ADVANCE(101);
      if (lookahead == '}') ADVANCE(74);
      if (lookahead == 224) ADVANCE(106);
      if (lookahead == 237) ADVANCE(107);
      if (lookahead == 240) ADVANCE(109);
      if (lookahead == 244) ADVANCE(110);
      if (lookahead == 'n' ||
          ('r' <= lookahead && lookahead <= 't')) ADVANCE(77);
      if ((241 <= lookahead && lookahead <= 243)) ADVANCE(111);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'd')) ADVANCE(88);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(75);
      if ((225 <= lookahead && lookahead <= 239)) ADVANCE(108);
      if (('!' <= lookahead && lookahead <= '*') ||
          ('/' <= lookahead && lookahead <= ':') ||
          ('<' <= lookahead && lookahead <= '@') ||
          ('^' <= lookahead && lookahead <= '`') ||
          ('|' <= lookahead && lookahead <= '~')) ADVANCE(103);
      if ((128 <= lookahead && lookahead <= 143)) ADVANCE(104);
      if ((144 <= lookahead && lookahead <= 159)) ADVANCE(104);
      if ((194 <= lookahead && lookahead <= 223)) ADVANCE(105);
      if (('G' <= lookahead && lookahead <= 'Z') ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(92);
      if ((160 <= lookahead && lookahead <= 191)) ADVANCE(104);
      END_STATE();
    case 1:
      if (lookahead == '$') ADVANCE(96);
      if (lookahead == '(') ADVANCE(114);
      if (lookahead == ')') ADVANCE(116);
      if (lookahead == '+') ADVANCE(98);
      if (lookahead == '-') ADVANCE(99);
      if (lookahead == '.') ADVANCE(78);
      if (lookahead == '0') ADVANCE(76);
      if (lookahead == 'E') ADVANCE(80);
      if (lookahead == 'P') ADVANCE(83);
      if (lookahead == 'c') ADVANCE(41);
      if (lookahead == 'e') ADVANCE(79);
      if (lookahead == 'f') ADVANCE(62);
      if (lookahead == 'i') ADVANCE(36);
      if (lookahead == 'm') ADVANCE(43);
      if (lookahead == 'n') ADVANCE(12);
      if (lookahead == 'p') ADVANCE(82);
      if (lookahead == 't') ADVANCE(66);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(75);
      END_STATE();
    case 2:
      if (lookahead == '(') ADVANCE(114);
      if (lookahead == ')') ADVANCE(116);
      if (lookahead == '+') ADVANCE(98);
      if (lookahead == '-') ADVANCE(99);
      if (lookahead == '.') ADVANCE(78);
      if (lookahead == 'E') ADVANCE(80);
      if (lookahead == '_') ADVANCE(90);
      if (lookahead == 'c') ADVANCE(41);
      if (lookahead == 'e') ADVANCE(79);
      if (lookahead == 'f') ADVANCE(64);
      if (lookahead == 'i') ADVANCE(40);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(2)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(75);
      END_STATE();
    case 3:
      if (lookahead == '(') ADVANCE(114);
      if (lookahead == ')') ADVANCE(116);
      if (lookahead == '.') ADVANCE(78);
      if (lookahead == 'P') ADVANCE(83);
      if (lookahead == '_') ADVANCE(90);
      if (lookahead == 'c') ADVANCE(89);
      if (lookahead == 'i') ADVANCE(40);
      if (lookahead == 'p') ADVANCE(82);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(3)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(88);
      END_STATE();
    case 4:
      if (lookahead == '(') ADVANCE(114);
      if (lookahead == ')') ADVANCE(116);
      if (lookahead == '.') ADVANCE(78);
      if (lookahead == 'P') ADVANCE(83);
      if (lookahead == '_') ADVANCE(90);
      if (lookahead == 'p') ADVANCE(82);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(4)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(88);
      END_STATE();
    case 5:
      if (lookahead == '(') ADVANCE(114);
      if (lookahead == ')') ADVANCE(116);
      if (lookahead == '_') ADVANCE(90);
      if (lookahead == 'c') ADVANCE(94);
      if (lookahead == 'i') ADVANCE(93);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(5)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(75);
      if (lookahead == '!' ||
          ('#' <= lookahead && lookahead <= '+') ||
          ('-' <= lookahead && lookahead <= ':') ||
          ('<' <= lookahead && lookahead <= '@') ||
          lookahead == '\\' ||
          ('^' <= lookahead && lookahead <= '`') ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(103);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(92);
      END_STATE();
    case 6:
      if (lookahead == '(') ADVANCE(114);
      if (lookahead == ')') ADVANCE(116);
      if (lookahead == '_') ADVANCE(90);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(6)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(75);
      if (lookahead == '!' ||
          ('#' <= lookahead && lookahead <= '+') ||
          ('-' <= lookahead && lookahead <= ':') ||
          ('<' <= lookahead && lookahead <= '@') ||
          lookahead == '\\' ||
          ('^' <= lookahead && lookahead <= '`') ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(103);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(92);
      END_STATE();
    case 7:
      if (lookahead == 'B') ADVANCE(27);
      if (lookahead == 'C') ADVANCE(11);
      END_STATE();
    case 8:
      if (lookahead == 'E') ADVANCE(65);
      if (lookahead == 'I') ADVANCE(32);
      END_STATE();
    case 9:
      if (lookahead == 'F') ADVANCE(24);
      END_STATE();
    case 10:
      if (lookahead == 'I') ADVANCE(33);
      END_STATE();
    case 11:
      if (lookahead == 'a') ADVANCE(31);
      END_STATE();
    case 12:
      if (lookahead == 'a') ADVANCE(37);
      END_STATE();
    case 13:
      if (lookahead == 'c') ADVANCE(25);
      END_STATE();
    case 14:
      if (lookahead == 'c') ADVANCE(9);
      END_STATE();
    case 15:
      if (lookahead == 'c') ADVANCE(113);
      END_STATE();
    case 16:
      if (lookahead == 'd') ADVANCE(10);
      END_STATE();
    case 17:
      if (lookahead == 'd') ADVANCE(63);
      END_STATE();
    case 18:
      if (lookahead == 'e') ADVANCE(8);
      END_STATE();
    case 19:
      if (lookahead == 'e') ADVANCE(117);
      END_STATE();
    case 20:
      if (lookahead == 'e') ADVANCE(115);
      END_STATE();
    case 21:
      if (lookahead == 'e') ADVANCE(29);
      END_STATE();
    case 22:
      if (lookahead == 'f') ADVANCE(84);
      if (lookahead == 'l') ADVANCE(23);
      if (lookahead == 's') ADVANCE(57);
      END_STATE();
    case 23:
      if (lookahead == 'i') ADVANCE(35);
      END_STATE();
    case 24:
      if (lookahead == 'i') ADVANCE(21);
      END_STATE();
    case 25:
      if (lookahead == 'k') ADVANCE(72);
      END_STATE();
    case 26:
      if (lookahead == 'l') ADVANCE(23);
      if (lookahead == 's') ADVANCE(57);
      END_STATE();
    case 27:
      if (lookahead == 'l') ADVANCE(42);
      END_STATE();
    case 28:
      if (lookahead == 'l') ADVANCE(71);
      END_STATE();
    case 29:
      if (lookahead == 'l') ADVANCE(16);
      END_STATE();
    case 30:
      if (lookahead == 'l') ADVANCE(20);
      END_STATE();
    case 31:
      if (lookahead == 'l') ADVANCE(28);
      END_STATE();
    case 32:
      if (lookahead == 'm') ADVANCE(49);
      END_STATE();
    case 33:
      if (lookahead == 'm') ADVANCE(50);
      END_STATE();
    case 34:
      if (lookahead == 'n') ADVANCE(56);
      END_STATE();
    case 35:
      if (lookahead == 'n') ADVANCE(18);
      END_STATE();
    case 36:
      if (lookahead == 'n') ADVANCE(22);
      END_STATE();
    case 37:
      if (lookahead == 'n') ADVANCE(85);
      END_STATE();
    case 38:
      if (lookahead == 'n') ADVANCE(14);
      END_STATE();
    case 39:
      if (lookahead == 'n') ADVANCE(15);
      END_STATE();
    case 40:
      if (lookahead == 'n') ADVANCE(55);
      END_STATE();
    case 41:
      if (lookahead == 'o') ADVANCE(34);
      END_STATE();
    case 42:
      if (lookahead == 'o') ADVANCE(13);
      END_STATE();
    case 43:
      if (lookahead == 'o') ADVANCE(17);
      END_STATE();
    case 44:
      if (lookahead == 'o') ADVANCE(52);
      END_STATE();
    case 45:
      if (lookahead == 'o') ADVANCE(53);
      END_STATE();
    case 46:
      if (lookahead == 'o') ADVANCE(54);
      END_STATE();
    case 47:
      if (lookahead == 'p') ADVANCE(19);
      END_STATE();
    case 48:
      if (lookahead == 'p') ADVANCE(44);
      END_STATE();
    case 49:
      if (lookahead == 'p') ADVANCE(45);
      END_STATE();
    case 50:
      if (lookahead == 'p') ADVANCE(46);
      END_STATE();
    case 51:
      if (lookahead == 'r') ADVANCE(7);
      END_STATE();
    case 52:
      if (lookahead == 'r') ADVANCE(59);
      END_STATE();
    case 53:
      if (lookahead == 'r') ADVANCE(60);
      END_STATE();
    case 54:
      if (lookahead == 'r') ADVANCE(61);
      END_STATE();
    case 55:
      if (lookahead == 's') ADVANCE(57);
      END_STATE();
    case 56:
      if (lookahead == 's') ADVANCE(58);
      END_STATE();
    case 57:
      if (lookahead == 't') ADVANCE(51);
      END_STATE();
    case 58:
      if (lookahead == 't') ADVANCE(112);
      END_STATE();
    case 59:
      if (lookahead == 't') ADVANCE(69);
      END_STATE();
    case 60:
      if (lookahead == 't') ADVANCE(70);
      END_STATE();
    case 61:
      if (lookahead == 't') ADVANCE(68);
      END_STATE();
    case 62:
      if (lookahead == 'u') ADVANCE(38);
      END_STATE();
    case 63:
      if (lookahead == 'u') ADVANCE(30);
      END_STATE();
    case 64:
      if (lookahead == 'u') ADVANCE(39);
      END_STATE();
    case 65:
      if (lookahead == 'x') ADVANCE(48);
      END_STATE();
    case 66:
      if (lookahead == 'y') ADVANCE(47);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(sym_funcFieldImport);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym_inlineExport);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_inlineImport);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym_instrCall);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym_instrBlock);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_BSLASH);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(sym__digit);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(sym__digit);
      if (lookahead == 'x') ADVANCE(81);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(sym__escape);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(anon_sym_e);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(anon_sym_E);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(anon_sym_0x);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(anon_sym_p);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(anon_sym_P);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(anon_sym_inf);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(anon_sym_nan);
      if (lookahead == ':') ADVANCE(86);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(anon_sym_nan_COLON);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(anon_sym_f);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(sym__hexdigit);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(sym__hexdigit);
      if (lookahead == 'o') ADVANCE(34);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(anon_sym__);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(anon_sym_i);
      if (lookahead == 'n') ADVANCE(26);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(sym__letter);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(sym__letter);
      if (lookahead == 'n') ADVANCE(26);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(sym__letter);
      if (lookahead == 'o') ADVANCE(34);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(anon_sym_8);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(anon_sym_DOLLAR);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(anon_sym_POUND);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(anon_sym_s);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(anon_sym_u);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(sym__symbol);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(sym__utf8cont);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(aux_sym__utf8enc_token1);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(aux_sym__utf8enc_token2);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(aux_sym__utf8enc_token4);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(aux_sym__utf8enc_token6);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(aux_sym__utf8enc_token7);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(aux_sym__utf8enc_token9);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(aux_sym__utf8enc_token11);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(sym_CONST);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(sym__FUNC);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(sym__LPAR);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(sym__MODULE);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(sym__RPAR);
      END_STATE();
    case 117:
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
  [3] = {.lex_state = 1},
  [4] = {.lex_state = 1},
  [5] = {.lex_state = 1},
  [6] = {.lex_state = 1},
  [7] = {.lex_state = 1},
  [8] = {.lex_state = 5},
  [9] = {.lex_state = 5},
  [10] = {.lex_state = 3},
  [11] = {.lex_state = 3},
  [12] = {.lex_state = 2},
  [13] = {.lex_state = 2},
  [14] = {.lex_state = 3},
  [15] = {.lex_state = 2},
  [16] = {.lex_state = 3},
  [17] = {.lex_state = 2},
  [18] = {.lex_state = 2},
  [19] = {.lex_state = 2},
  [20] = {.lex_state = 3},
  [21] = {.lex_state = 3},
  [22] = {.lex_state = 1},
  [23] = {.lex_state = 1},
  [24] = {.lex_state = 1},
  [25] = {.lex_state = 1},
  [26] = {.lex_state = 4},
  [27] = {.lex_state = 1},
  [28] = {.lex_state = 1},
  [29] = {.lex_state = 1},
  [30] = {.lex_state = 1},
  [31] = {.lex_state = 4},
  [32] = {.lex_state = 4},
  [33] = {.lex_state = 1},
  [34] = {.lex_state = 1},
  [35] = {.lex_state = 1},
  [36] = {.lex_state = 4},
  [37] = {.lex_state = 4},
  [38] = {.lex_state = 4},
  [39] = {.lex_state = 1},
  [40] = {.lex_state = 1},
  [41] = {.lex_state = 1},
  [42] = {.lex_state = 6},
  [43] = {.lex_state = 1},
  [44] = {.lex_state = 6},
  [45] = {.lex_state = 1},
  [46] = {.lex_state = 1},
  [47] = {.lex_state = 1},
  [48] = {.lex_state = 1},
  [49] = {.lex_state = 1},
  [50] = {.lex_state = 1},
  [51] = {.lex_state = 1},
  [52] = {.lex_state = 1},
  [53] = {.lex_state = 1},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 1},
  [56] = {.lex_state = 6},
  [57] = {.lex_state = 1},
  [58] = {.lex_state = 6},
  [59] = {.lex_state = 1},
  [60] = {.lex_state = 2},
  [61] = {.lex_state = 2},
  [62] = {.lex_state = 2},
  [63] = {.lex_state = 0},
  [64] = {.lex_state = 1},
  [65] = {.lex_state = 1},
  [66] = {.lex_state = 2},
  [67] = {.lex_state = 1},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 1},
  [70] = {.lex_state = 0},
  [71] = {.lex_state = 1},
  [72] = {.lex_state = 1},
  [73] = {.lex_state = 2},
  [74] = {.lex_state = 0},
  [75] = {.lex_state = 1},
  [76] = {.lex_state = 0},
  [77] = {.lex_state = 0},
  [78] = {.lex_state = 1},
  [79] = {.lex_state = 0},
  [80] = {.lex_state = 4},
  [81] = {.lex_state = 4},
  [82] = {.lex_state = 5},
  [83] = {.lex_state = 4},
  [84] = {.lex_state = 0},
  [85] = {.lex_state = 4},
  [86] = {.lex_state = 4},
  [87] = {.lex_state = 4},
  [88] = {.lex_state = 4},
  [89] = {.lex_state = 0},
  [90] = {.lex_state = 4},
  [91] = {.lex_state = 5},
  [92] = {.lex_state = 5},
  [93] = {.lex_state = 0},
  [94] = {.lex_state = 0},
  [95] = {.lex_state = 5},
  [96] = {.lex_state = 4},
  [97] = {.lex_state = 5},
  [98] = {.lex_state = 0},
  [99] = {.lex_state = 0},
  [100] = {.lex_state = 1},
  [101] = {.lex_state = 0},
  [102] = {.lex_state = 0},
  [103] = {.lex_state = 4},
  [104] = {.lex_state = 1},
  [105] = {.lex_state = 0},
  [106] = {.lex_state = 2},
  [107] = {.lex_state = 0},
  [108] = {.lex_state = 1},
  [109] = {.lex_state = 5},
  [110] = {.lex_state = 1},
  [111] = {.lex_state = 0},
  [112] = {.lex_state = 0},
  [113] = {.lex_state = 0},
  [114] = {.lex_state = 1},
  [115] = {.lex_state = 0},
  [116] = {.lex_state = 0},
  [117] = {.lex_state = 1},
  [118] = {.lex_state = 0},
  [119] = {.lex_state = 0},
  [120] = {.lex_state = 1},
  [121] = {.lex_state = 4},
  [122] = {.lex_state = 0},
  [123] = {.lex_state = 0},
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
    [sym_CONST] = ACTIONS(1),
    [sym__LPAR] = ACTIONS(1),
    [sym__RPAR] = ACTIONS(1),
  },
  [1] = {
    [sym_file] = STATE(112),
    [sym_module] = STATE(113),
    [sym__LPAR] = ACTIONS(3),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 16,
    ACTIONS(5), 1,
      sym_inlineExport,
    ACTIONS(7), 1,
      sym_inlineImport,
    ACTIONS(11), 1,
      anon_sym_DOLLAR,
    ACTIONS(13), 1,
      sym_CONST,
    ACTIONS(15), 1,
      sym__LPAR,
    ACTIONS(17), 1,
      sym__RPAR,
    STATE(7), 1,
      sym_typeUse,
    STATE(40), 1,
      sym__name,
    STATE(98), 1,
      sym_funcResultBody,
    STATE(99), 1,
      sym_funcField,
    STATE(118), 1,
      sym_funcBody,
    STATE(123), 1,
      sym_funcFieldBody,
    ACTIONS(9), 2,
      sym_instrCall,
      sym_instrBlock,
    STATE(4), 2,
      sym__bindVar,
      sym_VAR,
    STATE(24), 2,
      sym_instr,
      aux_sym_funcBody_repeat1,
    STATE(72), 2,
      sym_expr,
      sym_instrPlain,
  [53] = 13,
    ACTIONS(19), 1,
      sym__digit,
    ACTIONS(21), 1,
      anon_sym_0x,
    ACTIONS(23), 1,
      anon_sym_inf,
    ACTIONS(25), 1,
      anon_sym_nan,
    ACTIONS(27), 1,
      anon_sym_nan_COLON,
    STATE(30), 1,
      sym__num,
    STATE(35), 1,
      sym__sign,
    STATE(48), 1,
      sym_literal,
    STATE(49), 1,
      sym__float,
    STATE(50), 1,
      sym__int,
    STATE(51), 1,
      sym__nat,
    ACTIONS(29), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    STATE(52), 3,
      sym_FLOAT,
      sym_INT,
      sym_NAT,
  [96] = 13,
    ACTIONS(5), 1,
      sym_inlineExport,
    ACTIONS(7), 1,
      sym_inlineImport,
    ACTIONS(13), 1,
      sym_CONST,
    ACTIONS(15), 1,
      sym__LPAR,
    ACTIONS(31), 1,
      sym__RPAR,
    STATE(7), 1,
      sym_typeUse,
    STATE(98), 1,
      sym_funcResultBody,
    STATE(118), 1,
      sym_funcBody,
    STATE(119), 1,
      sym_funcField,
    STATE(123), 1,
      sym_funcFieldBody,
    ACTIONS(9), 2,
      sym_instrCall,
      sym_instrBlock,
    STATE(24), 2,
      sym_instr,
      aux_sym_funcBody_repeat1,
    STATE(72), 2,
      sym_expr,
      sym_instrPlain,
  [139] = 13,
    ACTIONS(19), 1,
      sym__digit,
    ACTIONS(23), 1,
      anon_sym_inf,
    ACTIONS(25), 1,
      anon_sym_nan,
    ACTIONS(33), 1,
      anon_sym_0x,
    ACTIONS(35), 1,
      anon_sym_nan_COLON,
    STATE(30), 1,
      sym__num,
    STATE(34), 1,
      sym__sign,
    STATE(48), 1,
      sym_literal,
    STATE(49), 1,
      sym__float,
    STATE(50), 1,
      sym__int,
    STATE(51), 1,
      sym__nat,
    ACTIONS(37), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    STATE(52), 3,
      sym_FLOAT,
      sym_INT,
      sym_NAT,
  [182] = 12,
    ACTIONS(5), 1,
      sym_inlineExport,
    ACTIONS(7), 1,
      sym_inlineImport,
    ACTIONS(13), 1,
      sym_CONST,
    ACTIONS(15), 1,
      sym__LPAR,
    STATE(7), 1,
      sym_typeUse,
    STATE(98), 1,
      sym_funcResultBody,
    STATE(102), 1,
      sym_funcField,
    STATE(118), 1,
      sym_funcBody,
    STATE(123), 1,
      sym_funcFieldBody,
    ACTIONS(9), 2,
      sym_instrCall,
      sym_instrBlock,
    STATE(24), 2,
      sym_instr,
      aux_sym_funcBody_repeat1,
    STATE(72), 2,
      sym_expr,
      sym_instrPlain,
  [222] = 9,
    ACTIONS(13), 1,
      sym_CONST,
    ACTIONS(39), 1,
      sym__LPAR,
    ACTIONS(41), 1,
      sym__RPAR,
    STATE(98), 1,
      sym_funcResultBody,
    STATE(102), 1,
      sym_funcFieldBody,
    STATE(118), 1,
      sym_funcBody,
    ACTIONS(9), 2,
      sym_instrCall,
      sym_instrBlock,
    STATE(24), 2,
      sym_instr,
      aux_sym_funcBody_repeat1,
    STATE(72), 2,
      sym_expr,
      sym_instrPlain,
  [253] = 4,
    ACTIONS(48), 1,
      sym__letter,
    STATE(8), 1,
      aux_sym__name_repeat1,
    ACTIONS(45), 3,
      sym__digit,
      anon_sym__,
      sym__symbol,
    ACTIONS(43), 7,
      sym_inlineExport,
      sym_inlineImport,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__LPAR,
      sym__RPAR,
  [274] = 4,
    ACTIONS(55), 1,
      sym__letter,
    STATE(8), 1,
      aux_sym__name_repeat1,
    ACTIONS(53), 3,
      sym__digit,
      anon_sym__,
      sym__symbol,
    ACTIONS(51), 7,
      sym_inlineExport,
      sym_inlineImport,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__LPAR,
      sym__RPAR,
  [295] = 4,
    ACTIONS(59), 1,
      sym__hexdigit,
    ACTIONS(61), 1,
      anon_sym__,
    STATE(14), 1,
      aux_sym__hexnum_repeat1,
    ACTIONS(57), 8,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_DOT,
      anon_sym_p,
      anon_sym_P,
      sym_CONST,
      sym__LPAR,
      sym__RPAR,
  [315] = 4,
    ACTIONS(61), 1,
      anon_sym__,
    ACTIONS(65), 1,
      sym__hexdigit,
    STATE(10), 1,
      aux_sym__hexnum_repeat1,
    ACTIONS(63), 8,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_DOT,
      anon_sym_p,
      anon_sym_P,
      sym_CONST,
      sym__LPAR,
      sym__RPAR,
  [335] = 4,
    ACTIONS(69), 1,
      sym__digit,
    ACTIONS(71), 1,
      anon_sym__,
    STATE(15), 1,
      aux_sym__num_repeat1,
    ACTIONS(67), 8,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_DOT,
      anon_sym_e,
      anon_sym_E,
      sym_CONST,
      sym__LPAR,
      sym__RPAR,
  [355] = 4,
    ACTIONS(71), 1,
      anon_sym__,
    ACTIONS(75), 1,
      sym__digit,
    STATE(12), 1,
      aux_sym__num_repeat1,
    ACTIONS(73), 8,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_DOT,
      anon_sym_e,
      anon_sym_E,
      sym_CONST,
      sym__LPAR,
      sym__RPAR,
  [375] = 4,
    ACTIONS(79), 1,
      sym__hexdigit,
    ACTIONS(82), 1,
      anon_sym__,
    STATE(14), 1,
      aux_sym__hexnum_repeat1,
    ACTIONS(77), 8,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_DOT,
      anon_sym_p,
      anon_sym_P,
      sym_CONST,
      sym__LPAR,
      sym__RPAR,
  [395] = 4,
    ACTIONS(87), 1,
      sym__digit,
    ACTIONS(90), 1,
      anon_sym__,
    STATE(15), 1,
      aux_sym__num_repeat1,
    ACTIONS(85), 8,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_DOT,
      anon_sym_e,
      anon_sym_E,
      sym_CONST,
      sym__LPAR,
      sym__RPAR,
  [415] = 4,
    ACTIONS(97), 1,
      sym__hexdigit,
    ACTIONS(95), 2,
      anon_sym_p,
      anon_sym_P,
    STATE(41), 2,
      sym__hexfrac,
      sym__hexnum,
    ACTIONS(93), 5,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__LPAR,
      sym__RPAR,
  [434] = 1,
    ACTIONS(85), 10,
      sym_instrCall,
      sym_instrBlock,
      sym__digit,
      anon_sym_DOT,
      anon_sym_e,
      anon_sym_E,
      anon_sym__,
      sym_CONST,
      sym__LPAR,
      sym__RPAR,
  [447] = 4,
    ACTIONS(99), 1,
      sym__digit,
    ACTIONS(95), 2,
      anon_sym_e,
      anon_sym_E,
    STATE(33), 2,
      sym__frac,
      sym__num,
    ACTIONS(93), 5,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__LPAR,
      sym__RPAR,
  [466] = 4,
    ACTIONS(99), 1,
      sym__digit,
    ACTIONS(103), 2,
      anon_sym_e,
      anon_sym_E,
    STATE(43), 2,
      sym__frac,
      sym__num,
    ACTIONS(101), 5,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__LPAR,
      sym__RPAR,
  [485] = 2,
    ACTIONS(105), 1,
      sym__hexdigit,
    ACTIONS(77), 9,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_DOT,
      anon_sym_p,
      anon_sym_P,
      anon_sym__,
      sym_CONST,
      sym__LPAR,
      sym__RPAR,
  [500] = 4,
    ACTIONS(97), 1,
      sym__hexdigit,
    ACTIONS(109), 2,
      anon_sym_p,
      anon_sym_P,
    STATE(39), 2,
      sym__hexfrac,
      sym__hexnum,
    ACTIONS(107), 5,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__LPAR,
      sym__RPAR,
  [519] = 7,
    ACTIONS(111), 1,
      anon_sym_DOLLAR,
    ACTIONS(113), 1,
      sym__LPAR,
    ACTIONS(115), 1,
      sym__RPAR,
    STATE(40), 1,
      sym__name,
    STATE(89), 1,
      sym_func,
    STATE(54), 2,
      sym_moduleField,
      aux_sym_module_repeat1,
    STATE(68), 2,
      sym__moduleVar,
      sym_VAR,
  [543] = 6,
    ACTIONS(19), 1,
      sym__digit,
    ACTIONS(111), 1,
      anon_sym_DOLLAR,
    ACTIONS(117), 1,
      anon_sym_0x,
    STATE(40), 1,
      sym__name,
    STATE(51), 2,
      sym__nat,
      sym__num,
    STATE(101), 3,
      sym__var,
      sym_NAT,
      sym_VAR,
  [565] = 6,
    ACTIONS(13), 1,
      sym_CONST,
    ACTIONS(39), 1,
      sym__LPAR,
    ACTIONS(119), 1,
      sym__RPAR,
    ACTIONS(9), 2,
      sym_instrCall,
      sym_instrBlock,
    STATE(25), 2,
      sym_instr,
      aux_sym_funcBody_repeat1,
    STATE(72), 2,
      sym_expr,
      sym_instrPlain,
  [587] = 6,
    ACTIONS(124), 1,
      sym_CONST,
    ACTIONS(127), 1,
      sym__LPAR,
    ACTIONS(130), 1,
      sym__RPAR,
    ACTIONS(121), 2,
      sym_instrCall,
      sym_instrBlock,
    STATE(25), 2,
      sym_instr,
      aux_sym_funcBody_repeat1,
    STATE(72), 2,
      sym_expr,
      sym_instrPlain,
  [609] = 4,
    ACTIONS(132), 1,
      sym__hexdigit,
    ACTIONS(135), 1,
      anon_sym__,
    STATE(26), 1,
      aux_sym__hexnum_repeat1,
    ACTIONS(77), 5,
      anon_sym_DOT,
      anon_sym_p,
      anon_sym_P,
      sym__LPAR,
      sym__RPAR,
  [626] = 3,
    ACTIONS(140), 1,
      anon_sym_DOT,
    ACTIONS(103), 2,
      anon_sym_p,
      anon_sym_P,
    ACTIONS(138), 5,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__LPAR,
      sym__RPAR,
  [641] = 3,
    ACTIONS(142), 1,
      anon_sym_DOT,
    ACTIONS(95), 2,
      anon_sym_p,
      anon_sym_P,
    ACTIONS(138), 5,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__LPAR,
      sym__RPAR,
  [656] = 3,
    ACTIONS(146), 1,
      anon_sym_DOT,
    ACTIONS(103), 2,
      anon_sym_e,
      anon_sym_E,
    ACTIONS(144), 5,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__LPAR,
      sym__RPAR,
  [671] = 3,
    ACTIONS(148), 1,
      anon_sym_DOT,
    ACTIONS(150), 2,
      anon_sym_e,
      anon_sym_E,
    ACTIONS(144), 5,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__LPAR,
      sym__RPAR,
  [686] = 4,
    ACTIONS(152), 1,
      sym__hexdigit,
    ACTIONS(154), 1,
      anon_sym__,
    STATE(32), 1,
      aux_sym__hexnum_repeat1,
    ACTIONS(63), 5,
      anon_sym_DOT,
      anon_sym_p,
      anon_sym_P,
      sym__LPAR,
      sym__RPAR,
  [703] = 4,
    ACTIONS(154), 1,
      anon_sym__,
    ACTIONS(156), 1,
      sym__hexdigit,
    STATE(26), 1,
      aux_sym__hexnum_repeat1,
    ACTIONS(57), 5,
      anon_sym_DOT,
      anon_sym_p,
      anon_sym_P,
      sym__LPAR,
      sym__RPAR,
  [720] = 2,
    ACTIONS(109), 2,
      anon_sym_e,
      anon_sym_E,
    ACTIONS(107), 5,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__LPAR,
      sym__RPAR,
  [732] = 7,
    ACTIONS(19), 1,
      sym__digit,
    ACTIONS(158), 1,
      anon_sym_0x,
    ACTIONS(160), 1,
      anon_sym_inf,
    ACTIONS(162), 1,
      anon_sym_nan,
    ACTIONS(164), 1,
      anon_sym_nan_COLON,
    STATE(29), 1,
      sym__num,
    STATE(65), 1,
      sym__nat,
  [754] = 7,
    ACTIONS(19), 1,
      sym__digit,
    ACTIONS(160), 1,
      anon_sym_inf,
    ACTIONS(162), 1,
      anon_sym_nan,
    ACTIONS(166), 1,
      anon_sym_0x,
    ACTIONS(168), 1,
      anon_sym_nan_COLON,
    STATE(29), 1,
      sym__num,
    STATE(65), 1,
      sym__nat,
  [776] = 4,
    ACTIONS(170), 1,
      sym__hexdigit,
    ACTIONS(107), 2,
      sym__LPAR,
      sym__RPAR,
    ACTIONS(109), 2,
      anon_sym_p,
      anon_sym_P,
    STATE(39), 2,
      sym__hexfrac,
      sym__hexnum,
  [792] = 1,
    ACTIONS(77), 7,
      anon_sym_DOT,
      anon_sym_p,
      anon_sym_P,
      sym__hexdigit,
      anon_sym__,
      sym__LPAR,
      sym__RPAR,
  [802] = 4,
    ACTIONS(170), 1,
      sym__hexdigit,
    ACTIONS(93), 2,
      sym__LPAR,
      sym__RPAR,
    ACTIONS(95), 2,
      anon_sym_p,
      anon_sym_P,
    STATE(41), 2,
      sym__hexfrac,
      sym__hexnum,
  [818] = 2,
    ACTIONS(174), 2,
      anon_sym_p,
      anon_sym_P,
    ACTIONS(172), 5,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__LPAR,
      sym__RPAR,
  [830] = 1,
    ACTIONS(176), 7,
      sym_inlineExport,
      sym_inlineImport,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__LPAR,
      sym__RPAR,
  [840] = 2,
    ACTIONS(109), 2,
      anon_sym_p,
      anon_sym_P,
    ACTIONS(107), 5,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__LPAR,
      sym__RPAR,
  [852] = 3,
    STATE(44), 1,
      aux_sym__name_repeat1,
    ACTIONS(51), 2,
      sym__LPAR,
      sym__RPAR,
    ACTIONS(178), 4,
      sym__digit,
      anon_sym__,
      sym__letter,
      sym__symbol,
  [866] = 2,
    ACTIONS(95), 2,
      anon_sym_e,
      anon_sym_E,
    ACTIONS(93), 5,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__LPAR,
      sym__RPAR,
  [878] = 3,
    STATE(44), 1,
      aux_sym__name_repeat1,
    ACTIONS(43), 2,
      sym__LPAR,
      sym__RPAR,
    ACTIONS(180), 4,
      sym__digit,
      anon_sym__,
      sym__letter,
      sym__symbol,
  [892] = 1,
    ACTIONS(183), 6,
      sym_funcFieldImport,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__LPAR,
      sym__RPAR,
  [901] = 1,
    ACTIONS(185), 5,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__LPAR,
      sym__RPAR,
  [909] = 1,
    ACTIONS(101), 5,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__LPAR,
      sym__RPAR,
  [917] = 1,
    ACTIONS(187), 5,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__LPAR,
      sym__RPAR,
  [925] = 1,
    ACTIONS(189), 5,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__LPAR,
      sym__RPAR,
  [933] = 1,
    ACTIONS(191), 5,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__LPAR,
      sym__RPAR,
  [941] = 1,
    ACTIONS(193), 5,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__LPAR,
      sym__RPAR,
  [949] = 1,
    ACTIONS(195), 5,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__LPAR,
      sym__RPAR,
  [957] = 3,
    ACTIONS(197), 1,
      anon_sym_DOT,
    ACTIONS(95), 2,
      anon_sym_p,
      anon_sym_P,
    ACTIONS(138), 2,
      sym__LPAR,
      sym__RPAR,
  [969] = 4,
    ACTIONS(113), 1,
      sym__LPAR,
    ACTIONS(199), 1,
      sym__RPAR,
    STATE(89), 1,
      sym_func,
    STATE(70), 2,
      sym_moduleField,
      aux_sym_module_repeat1,
  [983] = 3,
    ACTIONS(201), 1,
      anon_sym_DOT,
    ACTIONS(103), 2,
      anon_sym_p,
      anon_sym_P,
    ACTIONS(138), 2,
      sym__LPAR,
      sym__RPAR,
  [995] = 2,
    STATE(9), 1,
      aux_sym__name_repeat1,
    ACTIONS(203), 4,
      sym__digit,
      anon_sym__,
      sym__letter,
      sym__symbol,
  [1005] = 1,
    ACTIONS(93), 5,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__LPAR,
      sym__RPAR,
  [1013] = 2,
    STATE(42), 1,
      aux_sym__name_repeat1,
    ACTIONS(205), 4,
      sym__digit,
      anon_sym__,
      sym__letter,
      sym__symbol,
  [1023] = 1,
    ACTIONS(207), 5,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__LPAR,
      sym__RPAR,
  [1031] = 4,
    ACTIONS(99), 1,
      sym__digit,
    STATE(71), 1,
      sym__num,
    STATE(91), 1,
      sym__sign,
    ACTIONS(209), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
  [1045] = 4,
    ACTIONS(99), 1,
      sym__digit,
    STATE(57), 1,
      sym__num,
    STATE(82), 1,
      sym__sign,
    ACTIONS(211), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
  [1059] = 4,
    ACTIONS(99), 1,
      sym__digit,
    STATE(46), 1,
      sym__num,
    STATE(92), 1,
      sym__sign,
    ACTIONS(213), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
  [1073] = 4,
    ACTIONS(113), 1,
      sym__LPAR,
    ACTIONS(215), 1,
      sym__RPAR,
    STATE(89), 1,
      sym_func,
    STATE(70), 2,
      sym_moduleField,
      aux_sym_module_repeat1,
  [1087] = 1,
    ACTIONS(217), 5,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__LPAR,
      sym__RPAR,
  [1095] = 1,
    ACTIONS(219), 5,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__LPAR,
      sym__RPAR,
  [1103] = 4,
    ACTIONS(99), 1,
      sym__digit,
    STATE(64), 1,
      sym__num,
    STATE(97), 1,
      sym__sign,
    ACTIONS(221), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
  [1117] = 1,
    ACTIONS(172), 5,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__LPAR,
      sym__RPAR,
  [1125] = 4,
    ACTIONS(113), 1,
      sym__LPAR,
    ACTIONS(199), 1,
      sym__RPAR,
    STATE(89), 1,
      sym_func,
    STATE(63), 2,
      sym_moduleField,
      aux_sym_module_repeat1,
  [1139] = 1,
    ACTIONS(223), 5,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__LPAR,
      sym__RPAR,
  [1147] = 4,
    ACTIONS(225), 1,
      sym__LPAR,
    ACTIONS(228), 1,
      sym__RPAR,
    STATE(89), 1,
      sym_func,
    STATE(70), 2,
      sym_moduleField,
      aux_sym_module_repeat1,
  [1161] = 1,
    ACTIONS(107), 5,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__LPAR,
      sym__RPAR,
  [1169] = 1,
    ACTIONS(230), 5,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__LPAR,
      sym__RPAR,
  [1177] = 4,
    ACTIONS(99), 1,
      sym__digit,
    STATE(67), 1,
      sym__num,
    STATE(95), 1,
      sym__sign,
    ACTIONS(232), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
  [1191] = 3,
    ACTIONS(39), 1,
      sym__LPAR,
    ACTIONS(234), 1,
      sym__RPAR,
    STATE(76), 2,
      sym_expr,
      aux_sym_expr1_repeat1,
  [1202] = 4,
    ACTIONS(236), 1,
      sym_CONST,
    ACTIONS(238), 1,
      sym__TYPE,
    STATE(77), 1,
      sym_instrPlain,
    STATE(107), 1,
      sym_expr1,
  [1215] = 3,
    ACTIONS(240), 1,
      sym__LPAR,
    ACTIONS(243), 1,
      sym__RPAR,
    STATE(76), 2,
      sym_expr,
      aux_sym_expr1_repeat1,
  [1226] = 3,
    ACTIONS(39), 1,
      sym__LPAR,
    ACTIONS(245), 1,
      sym__RPAR,
    STATE(74), 2,
      sym_expr,
      aux_sym_expr1_repeat1,
  [1237] = 3,
    ACTIONS(247), 1,
      sym_funcFieldImport,
    ACTIONS(249), 1,
      sym__LPAR,
    STATE(108), 1,
      sym_typeUse,
  [1247] = 3,
    ACTIONS(236), 1,
      sym_CONST,
    STATE(77), 1,
      sym_instrPlain,
    STATE(107), 1,
      sym_expr1,
  [1257] = 2,
    ACTIONS(251), 1,
      sym__hexdigit,
    STATE(27), 1,
      sym__hexnum,
  [1264] = 2,
    ACTIONS(251), 1,
      sym__hexdigit,
    STATE(28), 1,
      sym__hexnum,
  [1271] = 2,
    ACTIONS(99), 1,
      sym__digit,
    STATE(71), 1,
      sym__num,
  [1278] = 2,
    ACTIONS(251), 1,
      sym__hexdigit,
    STATE(71), 1,
      sym__hexnum,
  [1285] = 1,
    ACTIONS(253), 2,
      sym__LPAR,
      sym__RPAR,
  [1290] = 2,
    ACTIONS(170), 1,
      sym__hexdigit,
    STATE(55), 1,
      sym__hexnum,
  [1297] = 2,
    ACTIONS(170), 1,
      sym__hexdigit,
    STATE(71), 1,
      sym__hexnum,
  [1304] = 2,
    ACTIONS(170), 1,
      sym__hexdigit,
    STATE(53), 1,
      sym__hexnum,
  [1311] = 2,
    ACTIONS(170), 1,
      sym__hexdigit,
    STATE(57), 1,
      sym__hexnum,
  [1318] = 1,
    ACTIONS(255), 2,
      sym__LPAR,
      sym__RPAR,
  [1323] = 2,
    ACTIONS(251), 1,
      sym__hexdigit,
    STATE(57), 1,
      sym__hexnum,
  [1330] = 2,
    ACTIONS(99), 1,
      sym__digit,
    STATE(67), 1,
      sym__num,
  [1337] = 2,
    ACTIONS(99), 1,
      sym__digit,
    STATE(59), 1,
      sym__num,
  [1344] = 1,
    ACTIONS(257), 2,
      sym__LPAR,
      sym__RPAR,
  [1349] = 1,
    ACTIONS(259), 2,
      sym__LPAR,
      sym__RPAR,
  [1354] = 2,
    ACTIONS(99), 1,
      sym__digit,
    STATE(64), 1,
      sym__num,
  [1361] = 2,
    ACTIONS(170), 1,
      sym__hexdigit,
    STATE(116), 1,
      sym__hexnum,
  [1368] = 2,
    ACTIONS(99), 1,
      sym__digit,
    STATE(46), 1,
      sym__num,
  [1375] = 1,
    ACTIONS(261), 1,
      sym__RPAR,
  [1379] = 1,
    ACTIONS(31), 1,
      sym__RPAR,
  [1383] = 1,
    ACTIONS(263), 1,
      sym__MODULE,
  [1387] = 1,
    ACTIONS(265), 1,
      sym__RPAR,
  [1391] = 1,
    ACTIONS(267), 1,
      sym__RPAR,
  [1395] = 1,
    ACTIONS(269), 1,
      sym__hexdigit,
  [1399] = 1,
    ACTIONS(238), 1,
      sym__TYPE,
  [1403] = 1,
    ACTIONS(271), 1,
      ts_builtin_sym_end,
  [1407] = 1,
    ACTIONS(273), 1,
      sym__FUNC,
  [1411] = 1,
    ACTIONS(275), 1,
      sym__RPAR,
  [1415] = 1,
    ACTIONS(277), 1,
      sym_funcFieldImport,
  [1419] = 1,
    ACTIONS(279), 1,
      sym__digit,
  [1423] = 1,
    ACTIONS(281), 1,
      anon_sym_0x,
  [1427] = 1,
    ACTIONS(283), 1,
      ts_builtin_sym_end,
  [1431] = 1,
    ACTIONS(285), 1,
      ts_builtin_sym_end,
  [1435] = 1,
    ACTIONS(287), 1,
      ts_builtin_sym_end,
  [1439] = 1,
    ACTIONS(289), 1,
      anon_sym_0x,
  [1443] = 1,
    ACTIONS(291), 1,
      sym__RPAR,
  [1447] = 1,
    ACTIONS(138), 1,
      sym__RPAR,
  [1451] = 1,
    ACTIONS(293), 1,
      anon_sym_0x,
  [1455] = 1,
    ACTIONS(295), 1,
      sym__RPAR,
  [1459] = 1,
    ACTIONS(297), 1,
      sym__RPAR,
  [1463] = 1,
    ACTIONS(299), 1,
      anon_sym_0x,
  [1467] = 1,
    ACTIONS(301), 1,
      sym__hexdigit,
  [1471] = 1,
    ACTIONS(303), 1,
      ts_builtin_sym_end,
  [1475] = 1,
    ACTIONS(41), 1,
      sym__RPAR,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 53,
  [SMALL_STATE(4)] = 96,
  [SMALL_STATE(5)] = 139,
  [SMALL_STATE(6)] = 182,
  [SMALL_STATE(7)] = 222,
  [SMALL_STATE(8)] = 253,
  [SMALL_STATE(9)] = 274,
  [SMALL_STATE(10)] = 295,
  [SMALL_STATE(11)] = 315,
  [SMALL_STATE(12)] = 335,
  [SMALL_STATE(13)] = 355,
  [SMALL_STATE(14)] = 375,
  [SMALL_STATE(15)] = 395,
  [SMALL_STATE(16)] = 415,
  [SMALL_STATE(17)] = 434,
  [SMALL_STATE(18)] = 447,
  [SMALL_STATE(19)] = 466,
  [SMALL_STATE(20)] = 485,
  [SMALL_STATE(21)] = 500,
  [SMALL_STATE(22)] = 519,
  [SMALL_STATE(23)] = 543,
  [SMALL_STATE(24)] = 565,
  [SMALL_STATE(25)] = 587,
  [SMALL_STATE(26)] = 609,
  [SMALL_STATE(27)] = 626,
  [SMALL_STATE(28)] = 641,
  [SMALL_STATE(29)] = 656,
  [SMALL_STATE(30)] = 671,
  [SMALL_STATE(31)] = 686,
  [SMALL_STATE(32)] = 703,
  [SMALL_STATE(33)] = 720,
  [SMALL_STATE(34)] = 732,
  [SMALL_STATE(35)] = 754,
  [SMALL_STATE(36)] = 776,
  [SMALL_STATE(37)] = 792,
  [SMALL_STATE(38)] = 802,
  [SMALL_STATE(39)] = 818,
  [SMALL_STATE(40)] = 830,
  [SMALL_STATE(41)] = 840,
  [SMALL_STATE(42)] = 852,
  [SMALL_STATE(43)] = 866,
  [SMALL_STATE(44)] = 878,
  [SMALL_STATE(45)] = 892,
  [SMALL_STATE(46)] = 901,
  [SMALL_STATE(47)] = 909,
  [SMALL_STATE(48)] = 917,
  [SMALL_STATE(49)] = 925,
  [SMALL_STATE(50)] = 933,
  [SMALL_STATE(51)] = 941,
  [SMALL_STATE(52)] = 949,
  [SMALL_STATE(53)] = 957,
  [SMALL_STATE(54)] = 969,
  [SMALL_STATE(55)] = 983,
  [SMALL_STATE(56)] = 995,
  [SMALL_STATE(57)] = 1005,
  [SMALL_STATE(58)] = 1013,
  [SMALL_STATE(59)] = 1023,
  [SMALL_STATE(60)] = 1031,
  [SMALL_STATE(61)] = 1045,
  [SMALL_STATE(62)] = 1059,
  [SMALL_STATE(63)] = 1073,
  [SMALL_STATE(64)] = 1087,
  [SMALL_STATE(65)] = 1095,
  [SMALL_STATE(66)] = 1103,
  [SMALL_STATE(67)] = 1117,
  [SMALL_STATE(68)] = 1125,
  [SMALL_STATE(69)] = 1139,
  [SMALL_STATE(70)] = 1147,
  [SMALL_STATE(71)] = 1161,
  [SMALL_STATE(72)] = 1169,
  [SMALL_STATE(73)] = 1177,
  [SMALL_STATE(74)] = 1191,
  [SMALL_STATE(75)] = 1202,
  [SMALL_STATE(76)] = 1215,
  [SMALL_STATE(77)] = 1226,
  [SMALL_STATE(78)] = 1237,
  [SMALL_STATE(79)] = 1247,
  [SMALL_STATE(80)] = 1257,
  [SMALL_STATE(81)] = 1264,
  [SMALL_STATE(82)] = 1271,
  [SMALL_STATE(83)] = 1278,
  [SMALL_STATE(84)] = 1285,
  [SMALL_STATE(85)] = 1290,
  [SMALL_STATE(86)] = 1297,
  [SMALL_STATE(87)] = 1304,
  [SMALL_STATE(88)] = 1311,
  [SMALL_STATE(89)] = 1318,
  [SMALL_STATE(90)] = 1323,
  [SMALL_STATE(91)] = 1330,
  [SMALL_STATE(92)] = 1337,
  [SMALL_STATE(93)] = 1344,
  [SMALL_STATE(94)] = 1349,
  [SMALL_STATE(95)] = 1354,
  [SMALL_STATE(96)] = 1361,
  [SMALL_STATE(97)] = 1368,
  [SMALL_STATE(98)] = 1375,
  [SMALL_STATE(99)] = 1379,
  [SMALL_STATE(100)] = 1383,
  [SMALL_STATE(101)] = 1387,
  [SMALL_STATE(102)] = 1391,
  [SMALL_STATE(103)] = 1395,
  [SMALL_STATE(104)] = 1399,
  [SMALL_STATE(105)] = 1403,
  [SMALL_STATE(106)] = 1407,
  [SMALL_STATE(107)] = 1411,
  [SMALL_STATE(108)] = 1415,
  [SMALL_STATE(109)] = 1419,
  [SMALL_STATE(110)] = 1423,
  [SMALL_STATE(111)] = 1427,
  [SMALL_STATE(112)] = 1431,
  [SMALL_STATE(113)] = 1435,
  [SMALL_STATE(114)] = 1439,
  [SMALL_STATE(115)] = 1443,
  [SMALL_STATE(116)] = 1447,
  [SMALL_STATE(117)] = 1451,
  [SMALL_STATE(118)] = 1455,
  [SMALL_STATE(119)] = 1459,
  [SMALL_STATE(120)] = 1463,
  [SMALL_STATE(121)] = 1467,
  [SMALL_STATE(122)] = 1471,
  [SMALL_STATE(123)] = 1475,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.count = 0, .reusable = false},
  [1] = {.count = 1, .reusable = false}, RECOVER(),
  [3] = {.count = 1, .reusable = true}, SHIFT(100),
  [5] = {.count = 1, .reusable = true}, SHIFT(6),
  [7] = {.count = 1, .reusable = true}, SHIFT(78),
  [9] = {.count = 1, .reusable = true}, SHIFT(72),
  [11] = {.count = 1, .reusable = true}, SHIFT(56),
  [13] = {.count = 1, .reusable = true}, SHIFT(5),
  [15] = {.count = 1, .reusable = true}, SHIFT(75),
  [17] = {.count = 1, .reusable = true}, SHIFT(94),
  [19] = {.count = 1, .reusable = false}, SHIFT(13),
  [21] = {.count = 1, .reusable = true}, SHIFT(85),
  [23] = {.count = 1, .reusable = true}, SHIFT(49),
  [25] = {.count = 1, .reusable = false}, SHIFT(49),
  [27] = {.count = 1, .reusable = true}, SHIFT(117),
  [29] = {.count = 1, .reusable = true}, SHIFT(35),
  [31] = {.count = 1, .reusable = true}, SHIFT(84),
  [33] = {.count = 1, .reusable = true}, SHIFT(80),
  [35] = {.count = 1, .reusable = true}, SHIFT(114),
  [37] = {.count = 1, .reusable = true}, SHIFT(34),
  [39] = {.count = 1, .reusable = true}, SHIFT(79),
  [41] = {.count = 1, .reusable = true}, REDUCE(sym_funcField, 1),
  [43] = {.count = 1, .reusable = true}, REDUCE(aux_sym__name_repeat1, 2),
  [45] = {.count = 2, .reusable = true}, REDUCE(aux_sym__name_repeat1, 2), SHIFT_REPEAT(8),
  [48] = {.count = 2, .reusable = false}, REDUCE(aux_sym__name_repeat1, 2), SHIFT_REPEAT(8),
  [51] = {.count = 1, .reusable = true}, REDUCE(sym__name, 2),
  [53] = {.count = 1, .reusable = true}, SHIFT(8),
  [55] = {.count = 1, .reusable = false}, SHIFT(8),
  [57] = {.count = 1, .reusable = true}, REDUCE(sym__hexnum, 2),
  [59] = {.count = 1, .reusable = false}, SHIFT(14),
  [61] = {.count = 1, .reusable = true}, SHIFT(103),
  [63] = {.count = 1, .reusable = true}, REDUCE(sym__hexnum, 1),
  [65] = {.count = 1, .reusable = false}, SHIFT(10),
  [67] = {.count = 1, .reusable = true}, REDUCE(sym__num, 2),
  [69] = {.count = 1, .reusable = true}, SHIFT(15),
  [71] = {.count = 1, .reusable = true}, SHIFT(109),
  [73] = {.count = 1, .reusable = true}, REDUCE(sym__num, 1),
  [75] = {.count = 1, .reusable = true}, SHIFT(12),
  [77] = {.count = 1, .reusable = true}, REDUCE(aux_sym__hexnum_repeat1, 2),
  [79] = {.count = 2, .reusable = false}, REDUCE(aux_sym__hexnum_repeat1, 2), SHIFT_REPEAT(14),
  [82] = {.count = 2, .reusable = true}, REDUCE(aux_sym__hexnum_repeat1, 2), SHIFT_REPEAT(103),
  [85] = {.count = 1, .reusable = true}, REDUCE(aux_sym__num_repeat1, 2),
  [87] = {.count = 2, .reusable = true}, REDUCE(aux_sym__num_repeat1, 2), SHIFT_REPEAT(15),
  [90] = {.count = 2, .reusable = true}, REDUCE(aux_sym__num_repeat1, 2), SHIFT_REPEAT(109),
  [93] = {.count = 1, .reusable = true}, REDUCE(sym__float, 3),
  [95] = {.count = 1, .reusable = true}, SHIFT(73),
  [97] = {.count = 1, .reusable = false}, SHIFT(11),
  [99] = {.count = 1, .reusable = true}, SHIFT(13),
  [101] = {.count = 1, .reusable = true}, REDUCE(sym__float, 2),
  [103] = {.count = 1, .reusable = true}, SHIFT(60),
  [105] = {.count = 1, .reusable = false}, REDUCE(aux_sym__hexnum_repeat1, 2),
  [107] = {.count = 1, .reusable = true}, REDUCE(sym__float, 4),
  [109] = {.count = 1, .reusable = true}, SHIFT(66),
  [111] = {.count = 1, .reusable = true}, SHIFT(58),
  [113] = {.count = 1, .reusable = true}, SHIFT(106),
  [115] = {.count = 1, .reusable = true}, SHIFT(105),
  [117] = {.count = 1, .reusable = true}, SHIFT(96),
  [119] = {.count = 1, .reusable = true}, REDUCE(sym_funcBody, 1),
  [121] = {.count = 2, .reusable = true}, REDUCE(aux_sym_funcBody_repeat1, 2), SHIFT_REPEAT(72),
  [124] = {.count = 2, .reusable = true}, REDUCE(aux_sym_funcBody_repeat1, 2), SHIFT_REPEAT(5),
  [127] = {.count = 2, .reusable = true}, REDUCE(aux_sym_funcBody_repeat1, 2), SHIFT_REPEAT(79),
  [130] = {.count = 1, .reusable = true}, REDUCE(aux_sym_funcBody_repeat1, 2),
  [132] = {.count = 2, .reusable = true}, REDUCE(aux_sym__hexnum_repeat1, 2), SHIFT_REPEAT(26),
  [135] = {.count = 2, .reusable = true}, REDUCE(aux_sym__hexnum_repeat1, 2), SHIFT_REPEAT(121),
  [138] = {.count = 1, .reusable = true}, REDUCE(sym__nat, 2),
  [140] = {.count = 1, .reusable = true}, SHIFT(16),
  [142] = {.count = 1, .reusable = true}, SHIFT(21),
  [144] = {.count = 1, .reusable = true}, REDUCE(sym__nat, 1),
  [146] = {.count = 1, .reusable = true}, SHIFT(18),
  [148] = {.count = 1, .reusable = true}, SHIFT(19),
  [150] = {.count = 1, .reusable = true}, SHIFT(61),
  [152] = {.count = 1, .reusable = true}, SHIFT(32),
  [154] = {.count = 1, .reusable = true}, SHIFT(121),
  [156] = {.count = 1, .reusable = true}, SHIFT(26),
  [158] = {.count = 1, .reusable = true}, SHIFT(81),
  [160] = {.count = 1, .reusable = true}, SHIFT(47),
  [162] = {.count = 1, .reusable = false}, SHIFT(47),
  [164] = {.count = 1, .reusable = true}, SHIFT(110),
  [166] = {.count = 1, .reusable = true}, SHIFT(87),
  [168] = {.count = 1, .reusable = true}, SHIFT(120),
  [170] = {.count = 1, .reusable = true}, SHIFT(31),
  [172] = {.count = 1, .reusable = true}, REDUCE(sym__float, 5),
  [174] = {.count = 1, .reusable = true}, SHIFT(62),
  [176] = {.count = 1, .reusable = true}, REDUCE(sym_VAR, 1),
  [178] = {.count = 1, .reusable = true}, SHIFT(44),
  [180] = {.count = 2, .reusable = true}, REDUCE(aux_sym__name_repeat1, 2), SHIFT_REPEAT(44),
  [183] = {.count = 1, .reusable = true}, REDUCE(sym_typeUse, 4),
  [185] = {.count = 1, .reusable = true}, REDUCE(sym__float, 7),
  [187] = {.count = 1, .reusable = true}, REDUCE(sym_instrPlain, 2),
  [189] = {.count = 1, .reusable = true}, REDUCE(sym_FLOAT, 1),
  [191] = {.count = 1, .reusable = true}, REDUCE(sym_INT, 1),
  [193] = {.count = 1, .reusable = true}, REDUCE(sym_NAT, 1),
  [195] = {.count = 1, .reusable = true}, REDUCE(sym_literal, 1),
  [197] = {.count = 1, .reusable = true}, SHIFT(36),
  [199] = {.count = 1, .reusable = true}, SHIFT(122),
  [201] = {.count = 1, .reusable = true}, SHIFT(38),
  [203] = {.count = 1, .reusable = true}, SHIFT(9),
  [205] = {.count = 1, .reusable = true}, SHIFT(42),
  [207] = {.count = 1, .reusable = true}, REDUCE(sym__float, 8),
  [209] = {.count = 1, .reusable = true}, SHIFT(91),
  [211] = {.count = 1, .reusable = true}, SHIFT(82),
  [213] = {.count = 1, .reusable = true}, SHIFT(92),
  [215] = {.count = 1, .reusable = true}, SHIFT(111),
  [217] = {.count = 1, .reusable = true}, REDUCE(sym__float, 6),
  [219] = {.count = 1, .reusable = true}, REDUCE(sym__int, 2),
  [221] = {.count = 1, .reusable = true}, SHIFT(97),
  [223] = {.count = 1, .reusable = true}, REDUCE(sym_expr, 3),
  [225] = {.count = 2, .reusable = true}, REDUCE(aux_sym_module_repeat1, 2), SHIFT_REPEAT(106),
  [228] = {.count = 1, .reusable = true}, REDUCE(aux_sym_module_repeat1, 2),
  [230] = {.count = 1, .reusable = true}, REDUCE(sym_instr, 1),
  [232] = {.count = 1, .reusable = true}, SHIFT(95),
  [234] = {.count = 1, .reusable = true}, REDUCE(sym_expr1, 2),
  [236] = {.count = 1, .reusable = true}, SHIFT(3),
  [238] = {.count = 1, .reusable = true}, SHIFT(23),
  [240] = {.count = 2, .reusable = true}, REDUCE(aux_sym_expr1_repeat1, 2), SHIFT_REPEAT(79),
  [243] = {.count = 1, .reusable = true}, REDUCE(aux_sym_expr1_repeat1, 2),
  [245] = {.count = 1, .reusable = true}, REDUCE(sym_expr1, 1),
  [247] = {.count = 1, .reusable = true}, SHIFT(102),
  [249] = {.count = 1, .reusable = true}, SHIFT(104),
  [251] = {.count = 1, .reusable = true}, SHIFT(11),
  [253] = {.count = 1, .reusable = true}, REDUCE(sym_func, 4),
  [255] = {.count = 1, .reusable = true}, REDUCE(sym_moduleField, 1),
  [257] = {.count = 1, .reusable = true}, REDUCE(sym_func, 5),
  [259] = {.count = 1, .reusable = true}, REDUCE(sym_func, 3),
  [261] = {.count = 1, .reusable = true}, REDUCE(sym_funcFieldBody, 1),
  [263] = {.count = 1, .reusable = true}, SHIFT(22),
  [265] = {.count = 1, .reusable = true}, SHIFT(45),
  [267] = {.count = 1, .reusable = true}, REDUCE(sym_funcField, 2),
  [269] = {.count = 1, .reusable = true}, SHIFT(20),
  [271] = {.count = 1, .reusable = true}, REDUCE(sym_module, 3),
  [273] = {.count = 1, .reusable = true}, SHIFT(2),
  [275] = {.count = 1, .reusable = true}, SHIFT(69),
  [277] = {.count = 1, .reusable = true}, SHIFT(115),
  [279] = {.count = 1, .reusable = true}, SHIFT(17),
  [281] = {.count = 1, .reusable = true}, SHIFT(83),
  [283] = {.count = 1, .reusable = true}, REDUCE(sym_module, 5),
  [285] = {.count = 1, .reusable = true},  ACCEPT_INPUT(),
  [287] = {.count = 1, .reusable = true}, REDUCE(sym_file, 1),
  [289] = {.count = 1, .reusable = true}, SHIFT(90),
  [291] = {.count = 1, .reusable = true}, REDUCE(sym_funcField, 3),
  [293] = {.count = 1, .reusable = true}, SHIFT(88),
  [295] = {.count = 1, .reusable = true}, REDUCE(sym_funcResultBody, 1),
  [297] = {.count = 1, .reusable = true}, SHIFT(93),
  [299] = {.count = 1, .reusable = true}, SHIFT(86),
  [301] = {.count = 1, .reusable = true}, SHIFT(37),
  [303] = {.count = 1, .reusable = true}, REDUCE(sym_module, 4),
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
