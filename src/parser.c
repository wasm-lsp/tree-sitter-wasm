#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 11
#define STATE_COUNT 100
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 64
#define ALIAS_COUNT 0
#define TOKEN_COUNT 30
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 8

enum {
  sym_expr = 1,
  sym_funcFieldImport = 2,
  sym_inlineExport = 3,
  sym_inlineImport = 4,
  sym_instrCall = 5,
  sym_instrBlock = 6,
  aux_sym__digit_token1 = 7,
  anon_sym_DOT = 8,
  anon_sym_e = 9,
  anon_sym_E = 10,
  anon_sym_0x = 11,
  anon_sym_p = 12,
  anon_sym_P = 13,
  anon_sym_inf = 14,
  anon_sym_nan = 15,
  anon_sym_nan_COLON = 16,
  sym__hexdigit = 17,
  anon_sym__ = 18,
  anon_sym_DOLLAR = 19,
  aux_sym__name_token1 = 20,
  aux_sym__name_token2 = 21,
  anon_sym_PLUS = 22,
  anon_sym_DASH = 23,
  sym_CONST = 24,
  sym__FUNC = 25,
  sym__LPAR = 26,
  sym__MODULE = 27,
  sym__RPAR = 28,
  sym__TYPE = 29,
  sym_file = 30,
  sym__bindVar = 31,
  sym_func = 32,
  sym_funcBody = 33,
  sym_funcField = 34,
  sym_funcFieldBody = 35,
  sym_funcResultBody = 36,
  sym_instr = 37,
  sym_instrPlain = 38,
  sym_literal = 39,
  sym_module = 40,
  sym_moduleField = 41,
  sym__moduleVar = 42,
  sym_typeUse = 43,
  sym__digit = 44,
  sym__float = 45,
  sym__frac = 46,
  sym__hexfrac = 47,
  sym__hexnum = 48,
  sym__int = 49,
  sym__name = 50,
  sym__nat = 51,
  sym__num = 52,
  sym__sign = 53,
  sym__var = 54,
  sym_FLOAT = 55,
  sym_INT = 56,
  sym_NAT = 57,
  sym_VAR = 58,
  aux_sym_funcBody_repeat1 = 59,
  aux_sym_module_repeat1 = 60,
  aux_sym__hexnum_repeat1 = 61,
  aux_sym__name_repeat1 = 62,
  aux_sym__num_repeat1 = 63,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_expr] = "expr",
  [sym_funcFieldImport] = "funcFieldImport",
  [sym_inlineExport] = "inlineExport",
  [sym_inlineImport] = "inlineImport",
  [sym_instrCall] = "instrCall",
  [sym_instrBlock] = "instrBlock",
  [aux_sym__digit_token1] = "_digit_token1",
  [anon_sym_DOT] = ".",
  [anon_sym_e] = "e",
  [anon_sym_E] = "E",
  [anon_sym_0x] = "0x",
  [anon_sym_p] = "p",
  [anon_sym_P] = "P",
  [anon_sym_inf] = "inf",
  [anon_sym_nan] = "nan",
  [anon_sym_nan_COLON] = "nan:",
  [sym__hexdigit] = "_hexdigit",
  [anon_sym__] = "_",
  [anon_sym_DOLLAR] = "$",
  [aux_sym__name_token1] = "_name_token1",
  [aux_sym__name_token2] = "_name_token2",
  [anon_sym_PLUS] = "+",
  [anon_sym_DASH] = "-",
  [sym_CONST] = "CONST",
  [sym__FUNC] = "_FUNC",
  [sym__LPAR] = "_LPAR",
  [sym__MODULE] = "_MODULE",
  [sym__RPAR] = "_RPAR",
  [sym__TYPE] = "_TYPE",
  [sym_file] = "file",
  [sym__bindVar] = "_bindVar",
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
  [sym__digit] = "_digit",
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
  [aux_sym_funcBody_repeat1] = "funcBody_repeat1",
  [aux_sym_module_repeat1] = "module_repeat1",
  [aux_sym__hexnum_repeat1] = "_hexnum_repeat1",
  [aux_sym__name_repeat1] = "_name_repeat1",
  [aux_sym__num_repeat1] = "_num_repeat1",
};

static TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_expr] = sym_expr,
  [sym_funcFieldImport] = sym_funcFieldImport,
  [sym_inlineExport] = sym_inlineExport,
  [sym_inlineImport] = sym_inlineImport,
  [sym_instrCall] = sym_instrCall,
  [sym_instrBlock] = sym_instrBlock,
  [aux_sym__digit_token1] = aux_sym__digit_token1,
  [anon_sym_DOT] = anon_sym_DOT,
  [anon_sym_e] = anon_sym_e,
  [anon_sym_E] = anon_sym_E,
  [anon_sym_0x] = anon_sym_0x,
  [anon_sym_p] = anon_sym_p,
  [anon_sym_P] = anon_sym_P,
  [anon_sym_inf] = anon_sym_inf,
  [anon_sym_nan] = anon_sym_nan,
  [anon_sym_nan_COLON] = anon_sym_nan_COLON,
  [sym__hexdigit] = sym__hexdigit,
  [anon_sym__] = anon_sym__,
  [anon_sym_DOLLAR] = anon_sym_DOLLAR,
  [aux_sym__name_token1] = aux_sym__name_token1,
  [aux_sym__name_token2] = aux_sym__name_token2,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_DASH] = anon_sym_DASH,
  [sym_CONST] = sym_CONST,
  [sym__FUNC] = sym__FUNC,
  [sym__LPAR] = sym__LPAR,
  [sym__MODULE] = sym__MODULE,
  [sym__RPAR] = sym__RPAR,
  [sym__TYPE] = sym__TYPE,
  [sym_file] = sym_file,
  [sym__bindVar] = sym__bindVar,
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
  [sym__digit] = sym__digit,
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
  [sym_expr] = {
    .visible = true,
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
  [aux_sym__digit_token1] = {
    .visible = false,
    .named = false,
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
  [sym__hexdigit] = {
    .visible = false,
    .named = true,
  },
  [anon_sym__] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOLLAR] = {
    .visible = true,
    .named = false,
  },
  [aux_sym__name_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__name_token2] = {
    .visible = false,
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
  [sym__digit] = {
    .visible = false,
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
      if (eof) ADVANCE(68);
      if (lookahead == '$') ADVANCE(90);
      if (lookahead == '(') ADVANCE(100);
      if (lookahead == ')') ADVANCE(102);
      if (lookahead == '+') ADVANCE(96);
      if (lookahead == '-') ADVANCE(97);
      if (lookahead == '.') ADVANCE(77);
      if (lookahead == '0') ADVANCE(76);
      if (lookahead == 'E') ADVANCE(79);
      if (lookahead == 'P') ADVANCE(82);
      if (lookahead == '_') ADVANCE(89);
      if (lookahead == 'c') ADVANCE(87);
      if (lookahead == 'e') ADVANCE(78);
      if (lookahead == 'i') ADVANCE(92);
      if (lookahead == 'p') ADVANCE(81);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(75);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(86);
      if (lookahead == '!' ||
          ('#' <= lookahead && lookahead <= '*') ||
          ('/' <= lookahead && lookahead <= ':') ||
          ('<' <= lookahead && lookahead <= '@') ||
          lookahead == '\\' ||
          ('^' <= lookahead && lookahead <= '`') ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(95);
      if (('G' <= lookahead && lookahead <= 'Z') ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(91);
      END_STATE();
    case 1:
      if (lookahead == '$') ADVANCE(90);
      if (lookahead == '(') ADVANCE(100);
      if (lookahead == ')') ADVANCE(102);
      if (lookahead == '+') ADVANCE(96);
      if (lookahead == '-') ADVANCE(97);
      if (lookahead == '.') ADVANCE(77);
      if (lookahead == '0') ADVANCE(76);
      if (lookahead == 'E') ADVANCE(79);
      if (lookahead == 'P') ADVANCE(82);
      if (lookahead == 'c') ADVANCE(40);
      if (lookahead == 'e') ADVANCE(78);
      if (lookahead == 'f') ADVANCE(63);
      if (lookahead == 'i') ADVANCE(35);
      if (lookahead == 'm') ADVANCE(42);
      if (lookahead == 'n') ADVANCE(11);
      if (lookahead == 'p') ADVANCE(81);
      if (lookahead == 't') ADVANCE(67);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(75);
      END_STATE();
    case 2:
      if (lookahead == '(') ADVANCE(100);
      if (lookahead == ')') ADVANCE(102);
      if (lookahead == '_') ADVANCE(89);
      if (lookahead == 'c') ADVANCE(93);
      if (lookahead == 'e') ADVANCE(94);
      if (lookahead == 'i') ADVANCE(92);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(2)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(75);
      if (lookahead == '!' ||
          ('#' <= lookahead && lookahead <= '+') ||
          ('-' <= lookahead && lookahead <= ':') ||
          ('<' <= lookahead && lookahead <= '@') ||
          lookahead == '\\' ||
          ('^' <= lookahead && lookahead <= '`') ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(95);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(91);
      END_STATE();
    case 3:
      if (lookahead == '(') ADVANCE(100);
      if (lookahead == ')') ADVANCE(102);
      if (lookahead == '_') ADVANCE(89);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(3)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(75);
      if (lookahead == '!' ||
          ('#' <= lookahead && lookahead <= '+') ||
          ('-' <= lookahead && lookahead <= ':') ||
          ('<' <= lookahead && lookahead <= '@') ||
          lookahead == '\\' ||
          ('^' <= lookahead && lookahead <= '`') ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(95);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(91);
      END_STATE();
    case 4:
      if (lookahead == ')') ADVANCE(102);
      if (lookahead == '+') ADVANCE(96);
      if (lookahead == '-') ADVANCE(97);
      if (lookahead == '.') ADVANCE(77);
      if (lookahead == 'E') ADVANCE(79);
      if (lookahead == '_') ADVANCE(89);
      if (lookahead == 'c') ADVANCE(40);
      if (lookahead == 'e') ADVANCE(78);
      if (lookahead == 'f') ADVANCE(65);
      if (lookahead == 'i') ADVANCE(39);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(4)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(75);
      END_STATE();
    case 5:
      if (lookahead == ')') ADVANCE(102);
      if (lookahead == '.') ADVANCE(77);
      if (lookahead == 'P') ADVANCE(82);
      if (lookahead == '_') ADVANCE(89);
      if (lookahead == 'c') ADVANCE(87);
      if (lookahead == 'e') ADVANCE(88);
      if (lookahead == 'i') ADVANCE(39);
      if (lookahead == 'p') ADVANCE(81);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(5)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(86);
      END_STATE();
    case 6:
      if (lookahead == 'B') ADVANCE(26);
      if (lookahead == 'C') ADVANCE(10);
      END_STATE();
    case 7:
      if (lookahead == 'E') ADVANCE(66);
      if (lookahead == 'I') ADVANCE(31);
      END_STATE();
    case 8:
      if (lookahead == 'F') ADVANCE(23);
      END_STATE();
    case 9:
      if (lookahead == 'I') ADVANCE(32);
      END_STATE();
    case 10:
      if (lookahead == 'a') ADVANCE(30);
      END_STATE();
    case 11:
      if (lookahead == 'a') ADVANCE(36);
      END_STATE();
    case 12:
      if (lookahead == 'c') ADVANCE(24);
      END_STATE();
    case 13:
      if (lookahead == 'c') ADVANCE(8);
      END_STATE();
    case 14:
      if (lookahead == 'c') ADVANCE(99);
      END_STATE();
    case 15:
      if (lookahead == 'd') ADVANCE(9);
      END_STATE();
    case 16:
      if (lookahead == 'd') ADVANCE(64);
      END_STATE();
    case 17:
      if (lookahead == 'e') ADVANCE(7);
      END_STATE();
    case 18:
      if (lookahead == 'e') ADVANCE(103);
      END_STATE();
    case 19:
      if (lookahead == 'e') ADVANCE(101);
      END_STATE();
    case 20:
      if (lookahead == 'e') ADVANCE(28);
      END_STATE();
    case 21:
      if (lookahead == 'f') ADVANCE(83);
      if (lookahead == 'l') ADVANCE(22);
      if (lookahead == 's') ADVANCE(62);
      END_STATE();
    case 22:
      if (lookahead == 'i') ADVANCE(34);
      END_STATE();
    case 23:
      if (lookahead == 'i') ADVANCE(20);
      END_STATE();
    case 24:
      if (lookahead == 'k') ADVANCE(74);
      END_STATE();
    case 25:
      if (lookahead == 'l') ADVANCE(22);
      if (lookahead == 's') ADVANCE(62);
      END_STATE();
    case 26:
      if (lookahead == 'l') ADVANCE(41);
      END_STATE();
    case 27:
      if (lookahead == 'l') ADVANCE(73);
      END_STATE();
    case 28:
      if (lookahead == 'l') ADVANCE(15);
      END_STATE();
    case 29:
      if (lookahead == 'l') ADVANCE(19);
      END_STATE();
    case 30:
      if (lookahead == 'l') ADVANCE(27);
      END_STATE();
    case 31:
      if (lookahead == 'm') ADVANCE(49);
      END_STATE();
    case 32:
      if (lookahead == 'm') ADVANCE(50);
      END_STATE();
    case 33:
      if (lookahead == 'n') ADVANCE(57);
      END_STATE();
    case 34:
      if (lookahead == 'n') ADVANCE(17);
      END_STATE();
    case 35:
      if (lookahead == 'n') ADVANCE(21);
      END_STATE();
    case 36:
      if (lookahead == 'n') ADVANCE(84);
      END_STATE();
    case 37:
      if (lookahead == 'n') ADVANCE(13);
      END_STATE();
    case 38:
      if (lookahead == 'n') ADVANCE(14);
      END_STATE();
    case 39:
      if (lookahead == 'n') ADVANCE(56);
      END_STATE();
    case 40:
      if (lookahead == 'o') ADVANCE(33);
      END_STATE();
    case 41:
      if (lookahead == 'o') ADVANCE(12);
      END_STATE();
    case 42:
      if (lookahead == 'o') ADVANCE(16);
      END_STATE();
    case 43:
      if (lookahead == 'o') ADVANCE(53);
      END_STATE();
    case 44:
      if (lookahead == 'o') ADVANCE(54);
      END_STATE();
    case 45:
      if (lookahead == 'o') ADVANCE(55);
      END_STATE();
    case 46:
      if (lookahead == 'p') ADVANCE(51);
      END_STATE();
    case 47:
      if (lookahead == 'p') ADVANCE(18);
      END_STATE();
    case 48:
      if (lookahead == 'p') ADVANCE(43);
      END_STATE();
    case 49:
      if (lookahead == 'p') ADVANCE(44);
      END_STATE();
    case 50:
      if (lookahead == 'p') ADVANCE(45);
      END_STATE();
    case 51:
      if (lookahead == 'r') ADVANCE(69);
      END_STATE();
    case 52:
      if (lookahead == 'r') ADVANCE(6);
      END_STATE();
    case 53:
      if (lookahead == 'r') ADVANCE(59);
      END_STATE();
    case 54:
      if (lookahead == 'r') ADVANCE(60);
      END_STATE();
    case 55:
      if (lookahead == 'r') ADVANCE(61);
      END_STATE();
    case 56:
      if (lookahead == 's') ADVANCE(62);
      END_STATE();
    case 57:
      if (lookahead == 's') ADVANCE(58);
      END_STATE();
    case 58:
      if (lookahead == 't') ADVANCE(98);
      END_STATE();
    case 59:
      if (lookahead == 't') ADVANCE(71);
      END_STATE();
    case 60:
      if (lookahead == 't') ADVANCE(72);
      END_STATE();
    case 61:
      if (lookahead == 't') ADVANCE(70);
      END_STATE();
    case 62:
      if (lookahead == 't') ADVANCE(52);
      END_STATE();
    case 63:
      if (lookahead == 'u') ADVANCE(37);
      END_STATE();
    case 64:
      if (lookahead == 'u') ADVANCE(29);
      END_STATE();
    case 65:
      if (lookahead == 'u') ADVANCE(38);
      END_STATE();
    case 66:
      if (lookahead == 'x') ADVANCE(48);
      END_STATE();
    case 67:
      if (lookahead == 'y') ADVANCE(47);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym_expr);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_funcFieldImport);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym_inlineExport);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym_inlineImport);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(sym_instrCall);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(sym_instrBlock);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(aux_sym__digit_token1);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(aux_sym__digit_token1);
      if (lookahead == 'x') ADVANCE(80);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(anon_sym_e);
      if (lookahead == 'x') ADVANCE(46);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(anon_sym_E);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(anon_sym_0x);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(anon_sym_p);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(anon_sym_P);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(anon_sym_inf);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(anon_sym_nan);
      if (lookahead == ':') ADVANCE(85);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(anon_sym_nan_COLON);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(sym__hexdigit);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(sym__hexdigit);
      if (lookahead == 'o') ADVANCE(33);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(sym__hexdigit);
      if (lookahead == 'x') ADVANCE(46);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(anon_sym__);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(anon_sym_DOLLAR);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(aux_sym__name_token1);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(aux_sym__name_token1);
      if (lookahead == 'n') ADVANCE(25);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(aux_sym__name_token1);
      if (lookahead == 'o') ADVANCE(33);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(aux_sym__name_token1);
      if (lookahead == 'x') ADVANCE(46);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(aux_sym__name_token2);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(sym_CONST);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(sym__FUNC);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(sym__LPAR);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(sym__MODULE);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(sym__RPAR);
      END_STATE();
    case 103:
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
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 2},
  [7] = {.lex_state = 2},
  [8] = {.lex_state = 4},
  [9] = {.lex_state = 4},
  [10] = {.lex_state = 4},
  [11] = {.lex_state = 4},
  [12] = {.lex_state = 5},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 5},
  [15] = {.lex_state = 4},
  [16] = {.lex_state = 5},
  [17] = {.lex_state = 5},
  [18] = {.lex_state = 5},
  [19] = {.lex_state = 4},
  [20] = {.lex_state = 1},
  [21] = {.lex_state = 5},
  [22] = {.lex_state = 1},
  [23] = {.lex_state = 1},
  [24] = {.lex_state = 1},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 1},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 1},
  [30] = {.lex_state = 1},
  [31] = {.lex_state = 1},
  [32] = {.lex_state = 1},
  [33] = {.lex_state = 1},
  [34] = {.lex_state = 3},
  [35] = {.lex_state = 1},
  [36] = {.lex_state = 3},
  [37] = {.lex_state = 4},
  [38] = {.lex_state = 4},
  [39] = {.lex_state = 4},
  [40] = {.lex_state = 1},
  [41] = {.lex_state = 4},
  [42] = {.lex_state = 4},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 3},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 3},
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
  [63] = {.lex_state = 2},
  [64] = {.lex_state = 2},
  [65] = {.lex_state = 2},
  [66] = {.lex_state = 2},
  [67] = {.lex_state = 1},
  [68] = {.lex_state = 2},
  [69] = {.lex_state = 0},
  [70] = {.lex_state = 2},
  [71] = {.lex_state = 5},
  [72] = {.lex_state = 5},
  [73] = {.lex_state = 0},
  [74] = {.lex_state = 0},
  [75] = {.lex_state = 5},
  [76] = {.lex_state = 0},
  [77] = {.lex_state = 5},
  [78] = {.lex_state = 5},
  [79] = {.lex_state = 0},
  [80] = {.lex_state = 0},
  [81] = {.lex_state = 4},
  [82] = {.lex_state = 0},
  [83] = {.lex_state = 0},
  [84] = {.lex_state = 0},
  [85] = {.lex_state = 0},
  [86] = {.lex_state = 1},
  [87] = {.lex_state = 1},
  [88] = {.lex_state = 0},
  [89] = {.lex_state = 0},
  [90] = {.lex_state = 0},
  [91] = {.lex_state = 0},
  [92] = {.lex_state = 0},
  [93] = {.lex_state = 1},
  [94] = {.lex_state = 1},
  [95] = {.lex_state = 5},
  [96] = {.lex_state = 0},
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 0},
  [99] = {.lex_state = 1},
};

static uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_expr] = ACTIONS(1),
    [sym_inlineExport] = ACTIONS(1),
    [sym_inlineImport] = ACTIONS(1),
    [sym_instrCall] = ACTIONS(1),
    [sym_instrBlock] = ACTIONS(1),
    [aux_sym__digit_token1] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [anon_sym_e] = ACTIONS(1),
    [anon_sym_E] = ACTIONS(1),
    [anon_sym_0x] = ACTIONS(1),
    [anon_sym_p] = ACTIONS(1),
    [anon_sym_P] = ACTIONS(1),
    [sym__hexdigit] = ACTIONS(1),
    [anon_sym__] = ACTIONS(1),
    [anon_sym_DOLLAR] = ACTIONS(1),
    [aux_sym__name_token1] = ACTIONS(1),
    [aux_sym__name_token2] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [sym_CONST] = ACTIONS(1),
    [sym__LPAR] = ACTIONS(1),
    [sym__RPAR] = ACTIONS(1),
  },
  [1] = {
    [sym_file] = STATE(98),
    [sym_module] = STATE(97),
    [sym__LPAR] = ACTIONS(3),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 16,
    ACTIONS(7), 1,
      sym_inlineExport,
    ACTIONS(9), 1,
      sym_inlineImport,
    ACTIONS(11), 1,
      anon_sym_DOLLAR,
    ACTIONS(13), 1,
      sym_CONST,
    ACTIONS(15), 1,
      sym__LPAR,
    ACTIONS(17), 1,
      sym__RPAR,
    STATE(13), 1,
      sym_typeUse,
    STATE(25), 1,
      sym__name,
    STATE(61), 1,
      sym_instrPlain,
    STATE(82), 1,
      sym_funcBody,
    STATE(85), 1,
      sym_funcFieldBody,
    STATE(90), 1,
      sym_funcResultBody,
    STATE(96), 1,
      sym_funcField,
    STATE(4), 2,
      sym__bindVar,
      sym_VAR,
    STATE(27), 2,
      sym_instr,
      aux_sym_funcBody_repeat1,
    ACTIONS(5), 3,
      sym_expr,
      sym_instrCall,
      sym_instrBlock,
  [53] = 14,
    ACTIONS(19), 1,
      aux_sym__digit_token1,
    ACTIONS(21), 1,
      anon_sym_0x,
    ACTIONS(23), 1,
      anon_sym_inf,
    ACTIONS(25), 1,
      anon_sym_nan,
    ACTIONS(27), 1,
      anon_sym_nan_COLON,
    STATE(8), 1,
      sym__digit,
    STATE(29), 1,
      sym__num,
    STATE(30), 1,
      sym__sign,
    STATE(43), 1,
      sym__float,
    STATE(44), 1,
      sym_literal,
    STATE(45), 1,
      sym__int,
    STATE(46), 1,
      sym__nat,
    ACTIONS(29), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    STATE(47), 3,
      sym_FLOAT,
      sym_INT,
      sym_NAT,
  [99] = 13,
    ACTIONS(7), 1,
      sym_inlineExport,
    ACTIONS(9), 1,
      sym_inlineImport,
    ACTIONS(13), 1,
      sym_CONST,
    ACTIONS(15), 1,
      sym__LPAR,
    ACTIONS(31), 1,
      sym__RPAR,
    STATE(13), 1,
      sym_typeUse,
    STATE(61), 1,
      sym_instrPlain,
    STATE(82), 1,
      sym_funcBody,
    STATE(85), 1,
      sym_funcFieldBody,
    STATE(90), 1,
      sym_funcResultBody,
    STATE(91), 1,
      sym_funcField,
    STATE(27), 2,
      sym_instr,
      aux_sym_funcBody_repeat1,
    ACTIONS(5), 3,
      sym_expr,
      sym_instrCall,
      sym_instrBlock,
  [142] = 12,
    ACTIONS(7), 1,
      sym_inlineExport,
    ACTIONS(9), 1,
      sym_inlineImport,
    ACTIONS(13), 1,
      sym_CONST,
    ACTIONS(15), 1,
      sym__LPAR,
    STATE(13), 1,
      sym_typeUse,
    STATE(61), 1,
      sym_instrPlain,
    STATE(82), 1,
      sym_funcBody,
    STATE(84), 1,
      sym_funcField,
    STATE(85), 1,
      sym_funcFieldBody,
    STATE(90), 1,
      sym_funcResultBody,
    STATE(27), 2,
      sym_instr,
      aux_sym_funcBody_repeat1,
    ACTIONS(5), 3,
      sym_expr,
      sym_instrCall,
      sym_instrBlock,
  [182] = 4,
    ACTIONS(38), 1,
      aux_sym__name_token1,
    STATE(6), 1,
      aux_sym__name_repeat1,
    ACTIONS(35), 3,
      aux_sym__digit_token1,
      anon_sym__,
      aux_sym__name_token2,
    ACTIONS(33), 8,
      sym_expr,
      sym_inlineExport,
      sym_inlineImport,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__LPAR,
      sym__RPAR,
  [204] = 4,
    ACTIONS(45), 1,
      aux_sym__name_token1,
    STATE(6), 1,
      aux_sym__name_repeat1,
    ACTIONS(43), 3,
      aux_sym__digit_token1,
      anon_sym__,
      aux_sym__name_token2,
    ACTIONS(41), 8,
      sym_expr,
      sym_inlineExport,
      sym_inlineImport,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__LPAR,
      sym__RPAR,
  [226] = 5,
    ACTIONS(49), 1,
      aux_sym__digit_token1,
    ACTIONS(51), 1,
      anon_sym_e,
    ACTIONS(53), 1,
      anon_sym__,
    STATE(9), 2,
      sym__digit,
      aux_sym__num_repeat1,
    ACTIONS(47), 7,
      sym_expr,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_DOT,
      anon_sym_E,
      sym_CONST,
      sym__RPAR,
  [249] = 5,
    ACTIONS(53), 1,
      anon_sym__,
    ACTIONS(57), 1,
      aux_sym__digit_token1,
    ACTIONS(59), 1,
      anon_sym_e,
    STATE(10), 2,
      sym__digit,
      aux_sym__num_repeat1,
    ACTIONS(55), 7,
      sym_expr,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_DOT,
      anon_sym_E,
      sym_CONST,
      sym__RPAR,
  [272] = 5,
    ACTIONS(63), 1,
      aux_sym__digit_token1,
    ACTIONS(66), 1,
      anon_sym_e,
    ACTIONS(68), 1,
      anon_sym__,
    STATE(10), 2,
      sym__digit,
      aux_sym__num_repeat1,
    ACTIONS(61), 7,
      sym_expr,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_DOT,
      anon_sym_E,
      sym_CONST,
      sym__RPAR,
  [295] = 6,
    ACTIONS(73), 1,
      aux_sym__digit_token1,
    ACTIONS(75), 1,
      anon_sym_e,
    ACTIONS(77), 1,
      anon_sym_E,
    STATE(8), 1,
      sym__digit,
    STATE(35), 2,
      sym__frac,
      sym__num,
    ACTIONS(71), 5,
      sym_expr,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__RPAR,
  [319] = 4,
    ACTIONS(81), 1,
      sym__hexdigit,
    ACTIONS(83), 1,
      anon_sym__,
    STATE(16), 1,
      aux_sym__hexnum_repeat1,
    ACTIONS(79), 8,
      sym_expr,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_DOT,
      anon_sym_p,
      anon_sym_P,
      sym_CONST,
      sym__RPAR,
  [339] = 8,
    ACTIONS(13), 1,
      sym_CONST,
    ACTIONS(85), 1,
      sym__RPAR,
    STATE(61), 1,
      sym_instrPlain,
    STATE(82), 1,
      sym_funcBody,
    STATE(84), 1,
      sym_funcFieldBody,
    STATE(90), 1,
      sym_funcResultBody,
    STATE(27), 2,
      sym_instr,
      aux_sym_funcBody_repeat1,
    ACTIONS(5), 3,
      sym_expr,
      sym_instrCall,
      sym_instrBlock,
  [367] = 4,
    ACTIONS(83), 1,
      anon_sym__,
    ACTIONS(89), 1,
      sym__hexdigit,
    STATE(12), 1,
      aux_sym__hexnum_repeat1,
    ACTIONS(87), 8,
      sym_expr,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_DOT,
      anon_sym_p,
      anon_sym_P,
      sym_CONST,
      sym__RPAR,
  [387] = 6,
    ACTIONS(73), 1,
      aux_sym__digit_token1,
    ACTIONS(93), 1,
      anon_sym_e,
    ACTIONS(95), 1,
      anon_sym_E,
    STATE(8), 1,
      sym__digit,
    STATE(32), 2,
      sym__frac,
      sym__num,
    ACTIONS(91), 5,
      sym_expr,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__RPAR,
  [411] = 4,
    ACTIONS(99), 1,
      sym__hexdigit,
    ACTIONS(102), 1,
      anon_sym__,
    STATE(16), 1,
      aux_sym__hexnum_repeat1,
    ACTIONS(97), 8,
      sym_expr,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_DOT,
      anon_sym_p,
      anon_sym_P,
      sym_CONST,
      sym__RPAR,
  [431] = 4,
    ACTIONS(105), 1,
      sym__hexdigit,
    ACTIONS(95), 2,
      anon_sym_p,
      anon_sym_P,
    STATE(33), 2,
      sym__hexfrac,
      sym__hexnum,
    ACTIONS(91), 5,
      sym_expr,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__RPAR,
  [450] = 4,
    ACTIONS(105), 1,
      sym__hexdigit,
    ACTIONS(109), 2,
      anon_sym_p,
      anon_sym_P,
    STATE(31), 2,
      sym__hexfrac,
      sym__hexnum,
    ACTIONS(107), 5,
      sym_expr,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__RPAR,
  [469] = 2,
    ACTIONS(66), 1,
      anon_sym_e,
    ACTIONS(61), 9,
      sym_expr,
      sym_instrCall,
      sym_instrBlock,
      aux_sym__digit_token1,
      anon_sym_DOT,
      anon_sym_E,
      anon_sym__,
      sym_CONST,
      sym__RPAR,
  [484] = 7,
    ACTIONS(19), 1,
      aux_sym__digit_token1,
    ACTIONS(111), 1,
      anon_sym_0x,
    ACTIONS(113), 1,
      anon_sym_DOLLAR,
    STATE(8), 1,
      sym__digit,
    STATE(25), 1,
      sym__name,
    STATE(46), 2,
      sym__nat,
      sym__num,
    STATE(83), 3,
      sym__var,
      sym_NAT,
      sym_VAR,
  [509] = 2,
    ACTIONS(115), 1,
      sym__hexdigit,
    ACTIONS(97), 9,
      sym_expr,
      sym_instrCall,
      sym_instrBlock,
      anon_sym_DOT,
      anon_sym_p,
      anon_sym_P,
      anon_sym__,
      sym_CONST,
      sym__RPAR,
  [524] = 7,
    ACTIONS(113), 1,
      anon_sym_DOLLAR,
    ACTIONS(117), 1,
      sym__LPAR,
    ACTIONS(119), 1,
      sym__RPAR,
    STATE(25), 1,
      sym__name,
    STATE(76), 1,
      sym_func,
    STATE(57), 2,
      sym__moduleVar,
      sym_VAR,
    STATE(59), 2,
      sym_moduleField,
      aux_sym_module_repeat1,
  [548] = 3,
    ACTIONS(123), 1,
      anon_sym_DOT,
    ACTIONS(95), 2,
      anon_sym_p,
      anon_sym_P,
    ACTIONS(121), 5,
      sym_expr,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__RPAR,
  [563] = 3,
    ACTIONS(125), 1,
      anon_sym_DOT,
    ACTIONS(77), 2,
      anon_sym_p,
      anon_sym_P,
    ACTIONS(121), 5,
      sym_expr,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__RPAR,
  [578] = 1,
    ACTIONS(127), 8,
      sym_expr,
      sym_inlineExport,
      sym_inlineImport,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__LPAR,
      sym__RPAR,
  [589] = 4,
    ACTIONS(75), 1,
      anon_sym_e,
    ACTIONS(77), 1,
      anon_sym_E,
    ACTIONS(131), 1,
      anon_sym_DOT,
    ACTIONS(129), 5,
      sym_expr,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__RPAR,
  [606] = 5,
    ACTIONS(13), 1,
      sym_CONST,
    ACTIONS(133), 1,
      sym__RPAR,
    STATE(61), 1,
      sym_instrPlain,
    STATE(28), 2,
      sym_instr,
      aux_sym_funcBody_repeat1,
    ACTIONS(5), 3,
      sym_expr,
      sym_instrCall,
      sym_instrBlock,
  [625] = 5,
    ACTIONS(138), 1,
      sym_CONST,
    ACTIONS(141), 1,
      sym__RPAR,
    STATE(61), 1,
      sym_instrPlain,
    STATE(28), 2,
      sym_instr,
      aux_sym_funcBody_repeat1,
    ACTIONS(135), 3,
      sym_expr,
      sym_instrCall,
      sym_instrBlock,
  [644] = 4,
    ACTIONS(143), 1,
      anon_sym_DOT,
    ACTIONS(145), 1,
      anon_sym_e,
    ACTIONS(147), 1,
      anon_sym_E,
    ACTIONS(129), 5,
      sym_expr,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__RPAR,
  [661] = 8,
    ACTIONS(19), 1,
      aux_sym__digit_token1,
    ACTIONS(149), 1,
      anon_sym_0x,
    ACTIONS(151), 1,
      anon_sym_inf,
    ACTIONS(153), 1,
      anon_sym_nan,
    ACTIONS(155), 1,
      anon_sym_nan_COLON,
    STATE(8), 1,
      sym__digit,
    STATE(26), 1,
      sym__num,
    STATE(60), 1,
      sym__nat,
  [686] = 2,
    ACTIONS(159), 2,
      anon_sym_p,
      anon_sym_P,
    ACTIONS(157), 5,
      sym_expr,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__RPAR,
  [698] = 3,
    ACTIONS(109), 1,
      anon_sym_E,
    ACTIONS(161), 1,
      anon_sym_e,
    ACTIONS(107), 5,
      sym_expr,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__RPAR,
  [712] = 2,
    ACTIONS(109), 2,
      anon_sym_p,
      anon_sym_P,
    ACTIONS(107), 5,
      sym_expr,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__RPAR,
  [724] = 3,
    STATE(34), 1,
      aux_sym__name_repeat1,
    ACTIONS(33), 2,
      sym__LPAR,
      sym__RPAR,
    ACTIONS(163), 4,
      aux_sym__digit_token1,
      anon_sym__,
      aux_sym__name_token1,
      aux_sym__name_token2,
  [738] = 3,
    ACTIONS(93), 1,
      anon_sym_e,
    ACTIONS(95), 1,
      anon_sym_E,
    ACTIONS(91), 5,
      sym_expr,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__RPAR,
  [752] = 3,
    STATE(34), 1,
      aux_sym__name_repeat1,
    ACTIONS(41), 2,
      sym__LPAR,
      sym__RPAR,
    ACTIONS(166), 4,
      aux_sym__digit_token1,
      anon_sym__,
      aux_sym__name_token1,
      aux_sym__name_token2,
  [766] = 5,
    ACTIONS(73), 1,
      aux_sym__digit_token1,
    STATE(8), 1,
      sym__digit,
    STATE(50), 1,
      sym__num,
    STATE(68), 1,
      sym__sign,
    ACTIONS(168), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
  [783] = 5,
    ACTIONS(73), 1,
      aux_sym__digit_token1,
    STATE(8), 1,
      sym__digit,
    STATE(52), 1,
      sym__num,
    STATE(63), 1,
      sym__sign,
    ACTIONS(170), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
  [800] = 5,
    ACTIONS(73), 1,
      aux_sym__digit_token1,
    STATE(8), 1,
      sym__digit,
    STATE(62), 1,
      sym__num,
    STATE(64), 1,
      sym__sign,
    ACTIONS(172), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
  [817] = 1,
    ACTIONS(174), 6,
      sym_expr,
      sym_funcFieldImport,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__RPAR,
  [826] = 5,
    ACTIONS(73), 1,
      aux_sym__digit_token1,
    STATE(8), 1,
      sym__digit,
    STATE(48), 1,
      sym__num,
    STATE(66), 1,
      sym__sign,
    ACTIONS(176), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
  [843] = 5,
    ACTIONS(73), 1,
      aux_sym__digit_token1,
    STATE(8), 1,
      sym__digit,
    STATE(53), 1,
      sym__num,
    STATE(65), 1,
      sym__sign,
    ACTIONS(178), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
  [860] = 1,
    ACTIONS(180), 5,
      sym_expr,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__RPAR,
  [868] = 1,
    ACTIONS(182), 5,
      sym_expr,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__RPAR,
  [876] = 1,
    ACTIONS(184), 5,
      sym_expr,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__RPAR,
  [884] = 1,
    ACTIONS(186), 5,
      sym_expr,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__RPAR,
  [892] = 1,
    ACTIONS(188), 5,
      sym_expr,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__RPAR,
  [900] = 1,
    ACTIONS(190), 5,
      sym_expr,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__RPAR,
  [908] = 2,
    STATE(7), 1,
      aux_sym__name_repeat1,
    ACTIONS(192), 4,
      aux_sym__digit_token1,
      anon_sym__,
      aux_sym__name_token1,
      aux_sym__name_token2,
  [918] = 1,
    ACTIONS(157), 5,
      sym_expr,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__RPAR,
  [926] = 2,
    STATE(36), 1,
      aux_sym__name_repeat1,
    ACTIONS(194), 4,
      aux_sym__digit_token1,
      anon_sym__,
      aux_sym__name_token1,
      aux_sym__name_token2,
  [936] = 1,
    ACTIONS(107), 5,
      sym_expr,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__RPAR,
  [944] = 1,
    ACTIONS(196), 5,
      sym_expr,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__RPAR,
  [952] = 4,
    ACTIONS(198), 1,
      sym__LPAR,
    ACTIONS(201), 1,
      sym__RPAR,
    STATE(76), 1,
      sym_func,
    STATE(54), 2,
      sym_moduleField,
      aux_sym_module_repeat1,
  [966] = 4,
    ACTIONS(117), 1,
      sym__LPAR,
    ACTIONS(203), 1,
      sym__RPAR,
    STATE(76), 1,
      sym_func,
    STATE(54), 2,
      sym_moduleField,
      aux_sym_module_repeat1,
  [980] = 1,
    ACTIONS(205), 5,
      sym_expr,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__RPAR,
  [988] = 4,
    ACTIONS(117), 1,
      sym__LPAR,
    ACTIONS(207), 1,
      sym__RPAR,
    STATE(76), 1,
      sym_func,
    STATE(55), 2,
      sym_moduleField,
      aux_sym_module_repeat1,
  [1002] = 1,
    ACTIONS(71), 5,
      sym_expr,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__RPAR,
  [1010] = 4,
    ACTIONS(117), 1,
      sym__LPAR,
    ACTIONS(207), 1,
      sym__RPAR,
    STATE(76), 1,
      sym_func,
    STATE(54), 2,
      sym_moduleField,
      aux_sym_module_repeat1,
  [1024] = 1,
    ACTIONS(209), 5,
      sym_expr,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__RPAR,
  [1032] = 1,
    ACTIONS(211), 5,
      sym_expr,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__RPAR,
  [1040] = 1,
    ACTIONS(91), 5,
      sym_expr,
      sym_instrCall,
      sym_instrBlock,
      sym_CONST,
      sym__RPAR,
  [1048] = 3,
    ACTIONS(73), 1,
      aux_sym__digit_token1,
    STATE(8), 1,
      sym__digit,
    STATE(50), 1,
      sym__num,
  [1058] = 3,
    ACTIONS(73), 1,
      aux_sym__digit_token1,
    STATE(8), 1,
      sym__digit,
    STATE(52), 1,
      sym__num,
  [1068] = 3,
    ACTIONS(73), 1,
      aux_sym__digit_token1,
    STATE(8), 1,
      sym__digit,
    STATE(56), 1,
      sym__num,
  [1078] = 3,
    ACTIONS(73), 1,
      aux_sym__digit_token1,
    STATE(8), 1,
      sym__digit,
    STATE(53), 1,
      sym__num,
  [1088] = 3,
    ACTIONS(15), 1,
      sym__LPAR,
    ACTIONS(213), 1,
      sym_funcFieldImport,
    STATE(99), 1,
      sym_typeUse,
  [1098] = 3,
    ACTIONS(73), 1,
      aux_sym__digit_token1,
    STATE(8), 1,
      sym__digit,
    STATE(48), 1,
      sym__num,
  [1108] = 1,
    ACTIONS(215), 2,
      sym__LPAR,
      sym__RPAR,
  [1113] = 2,
    ACTIONS(217), 1,
      aux_sym__digit_token1,
    STATE(19), 1,
      sym__digit,
  [1120] = 2,
    ACTIONS(219), 1,
      sym__hexdigit,
    STATE(88), 1,
      sym__hexnum,
  [1127] = 2,
    ACTIONS(219), 1,
      sym__hexdigit,
    STATE(24), 1,
      sym__hexnum,
  [1134] = 1,
    ACTIONS(221), 2,
      sym__LPAR,
      sym__RPAR,
  [1139] = 1,
    ACTIONS(223), 2,
      sym__LPAR,
      sym__RPAR,
  [1144] = 2,
    ACTIONS(219), 1,
      sym__hexdigit,
    STATE(52), 1,
      sym__hexnum,
  [1151] = 1,
    ACTIONS(225), 2,
      sym__LPAR,
      sym__RPAR,
  [1156] = 2,
    ACTIONS(219), 1,
      sym__hexdigit,
    STATE(62), 1,
      sym__hexnum,
  [1163] = 2,
    ACTIONS(219), 1,
      sym__hexdigit,
    STATE(23), 1,
      sym__hexnum,
  [1170] = 1,
    ACTIONS(227), 1,
      ts_builtin_sym_end,
  [1174] = 1,
    ACTIONS(229), 1,
      ts_builtin_sym_end,
  [1178] = 1,
    ACTIONS(231), 1,
      sym__FUNC,
  [1182] = 1,
    ACTIONS(233), 1,
      sym__RPAR,
  [1186] = 1,
    ACTIONS(235), 1,
      sym__RPAR,
  [1190] = 1,
    ACTIONS(237), 1,
      sym__RPAR,
  [1194] = 1,
    ACTIONS(85), 1,
      sym__RPAR,
  [1198] = 1,
    ACTIONS(239), 1,
      sym__TYPE,
  [1202] = 1,
    ACTIONS(241), 1,
      sym__MODULE,
  [1206] = 1,
    ACTIONS(121), 1,
      sym__RPAR,
  [1210] = 1,
    ACTIONS(243), 1,
      sym__RPAR,
  [1214] = 1,
    ACTIONS(245), 1,
      sym__RPAR,
  [1218] = 1,
    ACTIONS(247), 1,
      sym__RPAR,
  [1222] = 1,
    ACTIONS(249), 1,
      ts_builtin_sym_end,
  [1226] = 1,
    ACTIONS(251), 1,
      anon_sym_0x,
  [1230] = 1,
    ACTIONS(253), 1,
      anon_sym_0x,
  [1234] = 1,
    ACTIONS(255), 1,
      sym__hexdigit,
  [1238] = 1,
    ACTIONS(31), 1,
      sym__RPAR,
  [1242] = 1,
    ACTIONS(257), 1,
      ts_builtin_sym_end,
  [1246] = 1,
    ACTIONS(259), 1,
      ts_builtin_sym_end,
  [1250] = 1,
    ACTIONS(261), 1,
      sym_funcFieldImport,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 53,
  [SMALL_STATE(4)] = 99,
  [SMALL_STATE(5)] = 142,
  [SMALL_STATE(6)] = 182,
  [SMALL_STATE(7)] = 204,
  [SMALL_STATE(8)] = 226,
  [SMALL_STATE(9)] = 249,
  [SMALL_STATE(10)] = 272,
  [SMALL_STATE(11)] = 295,
  [SMALL_STATE(12)] = 319,
  [SMALL_STATE(13)] = 339,
  [SMALL_STATE(14)] = 367,
  [SMALL_STATE(15)] = 387,
  [SMALL_STATE(16)] = 411,
  [SMALL_STATE(17)] = 431,
  [SMALL_STATE(18)] = 450,
  [SMALL_STATE(19)] = 469,
  [SMALL_STATE(20)] = 484,
  [SMALL_STATE(21)] = 509,
  [SMALL_STATE(22)] = 524,
  [SMALL_STATE(23)] = 548,
  [SMALL_STATE(24)] = 563,
  [SMALL_STATE(25)] = 578,
  [SMALL_STATE(26)] = 589,
  [SMALL_STATE(27)] = 606,
  [SMALL_STATE(28)] = 625,
  [SMALL_STATE(29)] = 644,
  [SMALL_STATE(30)] = 661,
  [SMALL_STATE(31)] = 686,
  [SMALL_STATE(32)] = 698,
  [SMALL_STATE(33)] = 712,
  [SMALL_STATE(34)] = 724,
  [SMALL_STATE(35)] = 738,
  [SMALL_STATE(36)] = 752,
  [SMALL_STATE(37)] = 766,
  [SMALL_STATE(38)] = 783,
  [SMALL_STATE(39)] = 800,
  [SMALL_STATE(40)] = 817,
  [SMALL_STATE(41)] = 826,
  [SMALL_STATE(42)] = 843,
  [SMALL_STATE(43)] = 860,
  [SMALL_STATE(44)] = 868,
  [SMALL_STATE(45)] = 876,
  [SMALL_STATE(46)] = 884,
  [SMALL_STATE(47)] = 892,
  [SMALL_STATE(48)] = 900,
  [SMALL_STATE(49)] = 908,
  [SMALL_STATE(50)] = 918,
  [SMALL_STATE(51)] = 926,
  [SMALL_STATE(52)] = 936,
  [SMALL_STATE(53)] = 944,
  [SMALL_STATE(54)] = 952,
  [SMALL_STATE(55)] = 966,
  [SMALL_STATE(56)] = 980,
  [SMALL_STATE(57)] = 988,
  [SMALL_STATE(58)] = 1002,
  [SMALL_STATE(59)] = 1010,
  [SMALL_STATE(60)] = 1024,
  [SMALL_STATE(61)] = 1032,
  [SMALL_STATE(62)] = 1040,
  [SMALL_STATE(63)] = 1048,
  [SMALL_STATE(64)] = 1058,
  [SMALL_STATE(65)] = 1068,
  [SMALL_STATE(66)] = 1078,
  [SMALL_STATE(67)] = 1088,
  [SMALL_STATE(68)] = 1098,
  [SMALL_STATE(69)] = 1108,
  [SMALL_STATE(70)] = 1113,
  [SMALL_STATE(71)] = 1120,
  [SMALL_STATE(72)] = 1127,
  [SMALL_STATE(73)] = 1134,
  [SMALL_STATE(74)] = 1139,
  [SMALL_STATE(75)] = 1144,
  [SMALL_STATE(76)] = 1151,
  [SMALL_STATE(77)] = 1156,
  [SMALL_STATE(78)] = 1163,
  [SMALL_STATE(79)] = 1170,
  [SMALL_STATE(80)] = 1174,
  [SMALL_STATE(81)] = 1178,
  [SMALL_STATE(82)] = 1182,
  [SMALL_STATE(83)] = 1186,
  [SMALL_STATE(84)] = 1190,
  [SMALL_STATE(85)] = 1194,
  [SMALL_STATE(86)] = 1198,
  [SMALL_STATE(87)] = 1202,
  [SMALL_STATE(88)] = 1206,
  [SMALL_STATE(89)] = 1210,
  [SMALL_STATE(90)] = 1214,
  [SMALL_STATE(91)] = 1218,
  [SMALL_STATE(92)] = 1222,
  [SMALL_STATE(93)] = 1226,
  [SMALL_STATE(94)] = 1230,
  [SMALL_STATE(95)] = 1234,
  [SMALL_STATE(96)] = 1238,
  [SMALL_STATE(97)] = 1242,
  [SMALL_STATE(98)] = 1246,
  [SMALL_STATE(99)] = 1250,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.count = 0, .reusable = false},
  [1] = {.count = 1, .reusable = false}, RECOVER(),
  [3] = {.count = 1, .reusable = true}, SHIFT(87),
  [5] = {.count = 1, .reusable = true}, SHIFT(61),
  [7] = {.count = 1, .reusable = true}, SHIFT(5),
  [9] = {.count = 1, .reusable = true}, SHIFT(67),
  [11] = {.count = 1, .reusable = true}, SHIFT(49),
  [13] = {.count = 1, .reusable = true}, SHIFT(3),
  [15] = {.count = 1, .reusable = true}, SHIFT(86),
  [17] = {.count = 1, .reusable = true}, SHIFT(69),
  [19] = {.count = 1, .reusable = false}, SHIFT(8),
  [21] = {.count = 1, .reusable = true}, SHIFT(72),
  [23] = {.count = 1, .reusable = true}, SHIFT(43),
  [25] = {.count = 1, .reusable = false}, SHIFT(43),
  [27] = {.count = 1, .reusable = true}, SHIFT(94),
  [29] = {.count = 1, .reusable = true}, SHIFT(30),
  [31] = {.count = 1, .reusable = true}, SHIFT(73),
  [33] = {.count = 1, .reusable = true}, REDUCE(aux_sym__name_repeat1, 2),
  [35] = {.count = 2, .reusable = true}, REDUCE(aux_sym__name_repeat1, 2), SHIFT_REPEAT(6),
  [38] = {.count = 2, .reusable = false}, REDUCE(aux_sym__name_repeat1, 2), SHIFT_REPEAT(6),
  [41] = {.count = 1, .reusable = true}, REDUCE(sym__name, 2),
  [43] = {.count = 1, .reusable = true}, SHIFT(6),
  [45] = {.count = 1, .reusable = false}, SHIFT(6),
  [47] = {.count = 1, .reusable = true}, REDUCE(sym__num, 1),
  [49] = {.count = 1, .reusable = true}, SHIFT(9),
  [51] = {.count = 1, .reusable = false}, REDUCE(sym__num, 1),
  [53] = {.count = 1, .reusable = true}, SHIFT(70),
  [55] = {.count = 1, .reusable = true}, REDUCE(sym__num, 2),
  [57] = {.count = 1, .reusable = true}, SHIFT(10),
  [59] = {.count = 1, .reusable = false}, REDUCE(sym__num, 2),
  [61] = {.count = 1, .reusable = true}, REDUCE(aux_sym__num_repeat1, 2),
  [63] = {.count = 2, .reusable = true}, REDUCE(aux_sym__num_repeat1, 2), SHIFT_REPEAT(10),
  [66] = {.count = 1, .reusable = false}, REDUCE(aux_sym__num_repeat1, 2),
  [68] = {.count = 2, .reusable = true}, REDUCE(aux_sym__num_repeat1, 2), SHIFT_REPEAT(70),
  [71] = {.count = 1, .reusable = true}, REDUCE(sym__float, 2),
  [73] = {.count = 1, .reusable = true}, SHIFT(8),
  [75] = {.count = 1, .reusable = false}, SHIFT(38),
  [77] = {.count = 1, .reusable = true}, SHIFT(38),
  [79] = {.count = 1, .reusable = true}, REDUCE(sym__hexnum, 2),
  [81] = {.count = 1, .reusable = false}, SHIFT(16),
  [83] = {.count = 1, .reusable = true}, SHIFT(95),
  [85] = {.count = 1, .reusable = true}, REDUCE(sym_funcField, 1),
  [87] = {.count = 1, .reusable = true}, REDUCE(sym__hexnum, 1),
  [89] = {.count = 1, .reusable = false}, SHIFT(12),
  [91] = {.count = 1, .reusable = true}, REDUCE(sym__float, 3),
  [93] = {.count = 1, .reusable = false}, SHIFT(37),
  [95] = {.count = 1, .reusable = true}, SHIFT(37),
  [97] = {.count = 1, .reusable = true}, REDUCE(aux_sym__hexnum_repeat1, 2),
  [99] = {.count = 2, .reusable = false}, REDUCE(aux_sym__hexnum_repeat1, 2), SHIFT_REPEAT(16),
  [102] = {.count = 2, .reusable = true}, REDUCE(aux_sym__hexnum_repeat1, 2), SHIFT_REPEAT(95),
  [105] = {.count = 1, .reusable = false}, SHIFT(14),
  [107] = {.count = 1, .reusable = true}, REDUCE(sym__float, 4),
  [109] = {.count = 1, .reusable = true}, SHIFT(41),
  [111] = {.count = 1, .reusable = true}, SHIFT(71),
  [113] = {.count = 1, .reusable = true}, SHIFT(51),
  [115] = {.count = 1, .reusable = false}, REDUCE(aux_sym__hexnum_repeat1, 2),
  [117] = {.count = 1, .reusable = true}, SHIFT(81),
  [119] = {.count = 1, .reusable = true}, SHIFT(80),
  [121] = {.count = 1, .reusable = true}, REDUCE(sym__nat, 2),
  [123] = {.count = 1, .reusable = true}, SHIFT(18),
  [125] = {.count = 1, .reusable = true}, SHIFT(17),
  [127] = {.count = 1, .reusable = true}, REDUCE(sym_VAR, 1),
  [129] = {.count = 1, .reusable = true}, REDUCE(sym__nat, 1),
  [131] = {.count = 1, .reusable = true}, SHIFT(15),
  [133] = {.count = 1, .reusable = true}, REDUCE(sym_funcBody, 1),
  [135] = {.count = 2, .reusable = true}, REDUCE(aux_sym_funcBody_repeat1, 2), SHIFT_REPEAT(61),
  [138] = {.count = 2, .reusable = true}, REDUCE(aux_sym_funcBody_repeat1, 2), SHIFT_REPEAT(3),
  [141] = {.count = 1, .reusable = true}, REDUCE(aux_sym_funcBody_repeat1, 2),
  [143] = {.count = 1, .reusable = true}, SHIFT(11),
  [145] = {.count = 1, .reusable = false}, SHIFT(39),
  [147] = {.count = 1, .reusable = true}, SHIFT(39),
  [149] = {.count = 1, .reusable = true}, SHIFT(78),
  [151] = {.count = 1, .reusable = true}, SHIFT(58),
  [153] = {.count = 1, .reusable = false}, SHIFT(58),
  [155] = {.count = 1, .reusable = true}, SHIFT(93),
  [157] = {.count = 1, .reusable = true}, REDUCE(sym__float, 5),
  [159] = {.count = 1, .reusable = true}, SHIFT(42),
  [161] = {.count = 1, .reusable = false}, SHIFT(41),
  [163] = {.count = 2, .reusable = true}, REDUCE(aux_sym__name_repeat1, 2), SHIFT_REPEAT(34),
  [166] = {.count = 1, .reusable = true}, SHIFT(34),
  [168] = {.count = 1, .reusable = true}, SHIFT(68),
  [170] = {.count = 1, .reusable = true}, SHIFT(63),
  [172] = {.count = 1, .reusable = true}, SHIFT(64),
  [174] = {.count = 1, .reusable = true}, REDUCE(sym_typeUse, 4),
  [176] = {.count = 1, .reusable = true}, SHIFT(66),
  [178] = {.count = 1, .reusable = true}, SHIFT(65),
  [180] = {.count = 1, .reusable = true}, REDUCE(sym_FLOAT, 1),
  [182] = {.count = 1, .reusable = true}, REDUCE(sym_instrPlain, 2),
  [184] = {.count = 1, .reusable = true}, REDUCE(sym_INT, 1),
  [186] = {.count = 1, .reusable = true}, REDUCE(sym_NAT, 1),
  [188] = {.count = 1, .reusable = true}, REDUCE(sym_literal, 1),
  [190] = {.count = 1, .reusable = true}, REDUCE(sym__float, 6),
  [192] = {.count = 1, .reusable = true}, SHIFT(7),
  [194] = {.count = 1, .reusable = true}, SHIFT(36),
  [196] = {.count = 1, .reusable = true}, REDUCE(sym__float, 7),
  [198] = {.count = 2, .reusable = true}, REDUCE(aux_sym_module_repeat1, 2), SHIFT_REPEAT(81),
  [201] = {.count = 1, .reusable = true}, REDUCE(aux_sym_module_repeat1, 2),
  [203] = {.count = 1, .reusable = true}, SHIFT(79),
  [205] = {.count = 1, .reusable = true}, REDUCE(sym__float, 8),
  [207] = {.count = 1, .reusable = true}, SHIFT(92),
  [209] = {.count = 1, .reusable = true}, REDUCE(sym__int, 2),
  [211] = {.count = 1, .reusable = true}, REDUCE(sym_instr, 1),
  [213] = {.count = 1, .reusable = true}, SHIFT(84),
  [215] = {.count = 1, .reusable = true}, REDUCE(sym_func, 3),
  [217] = {.count = 1, .reusable = true}, SHIFT(19),
  [219] = {.count = 1, .reusable = true}, SHIFT(14),
  [221] = {.count = 1, .reusable = true}, REDUCE(sym_func, 4),
  [223] = {.count = 1, .reusable = true}, REDUCE(sym_func, 5),
  [225] = {.count = 1, .reusable = true}, REDUCE(sym_moduleField, 1),
  [227] = {.count = 1, .reusable = true}, REDUCE(sym_module, 5),
  [229] = {.count = 1, .reusable = true}, REDUCE(sym_module, 3),
  [231] = {.count = 1, .reusable = true}, SHIFT(2),
  [233] = {.count = 1, .reusable = true}, REDUCE(sym_funcResultBody, 1),
  [235] = {.count = 1, .reusable = true}, SHIFT(40),
  [237] = {.count = 1, .reusable = true}, REDUCE(sym_funcField, 2),
  [239] = {.count = 1, .reusable = true}, SHIFT(20),
  [241] = {.count = 1, .reusable = true}, SHIFT(22),
  [243] = {.count = 1, .reusable = true}, REDUCE(sym_funcField, 3),
  [245] = {.count = 1, .reusable = true}, REDUCE(sym_funcFieldBody, 1),
  [247] = {.count = 1, .reusable = true}, SHIFT(74),
  [249] = {.count = 1, .reusable = true}, REDUCE(sym_module, 4),
  [251] = {.count = 1, .reusable = true}, SHIFT(75),
  [253] = {.count = 1, .reusable = true}, SHIFT(77),
  [255] = {.count = 1, .reusable = true}, SHIFT(21),
  [257] = {.count = 1, .reusable = true}, REDUCE(sym_file, 1),
  [259] = {.count = 1, .reusable = true},  ACCEPT_INPUT(),
  [261] = {.count = 1, .reusable = true}, SHIFT(89),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_webassembly(void) {
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
