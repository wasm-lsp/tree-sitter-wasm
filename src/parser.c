#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 11
#define STATE_COUNT 43
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 34
#define ALIAS_COUNT 0
#define TOKEN_COUNT 20
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 5

enum {
  sym_expr = 1,
  anon_sym_LPAREN = 2,
  anon_sym_func = 3,
  anon_sym_RPAREN = 4,
  sym_funcFieldsImport = 5,
  sym_inlineExport = 6,
  sym_inlineImport = 7,
  sym_instrCall = 8,
  sym_instrPlain = 9,
  sym_instrBlock = 10,
  anon_sym_module = 11,
  anon_sym_type = 12,
  aux_sym_digit_token1 = 13,
  sym_hexdigit = 14,
  anon_sym__ = 15,
  anon_sym_DOLLAR = 16,
  aux_sym_NAME_token1 = 17,
  aux_sym_NAME_token2 = 18,
  sym_NAT = 19,
  sym_module1 = 20,
  sym_func = 21,
  sym_funcBody = 22,
  sym_funcFields = 23,
  sym_funcFieldsBody = 24,
  sym_funcResultBody = 25,
  sym_instr = 26,
  sym_module = 27,
  sym_moduleField = 28,
  sym_typeUse = 29,
  sym_NAME = 30,
  aux_sym_funcBody_repeat1 = 31,
  aux_sym_module_repeat1 = 32,
  aux_sym_NAME_repeat1 = 33,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_expr] = "expr",
  [anon_sym_LPAREN] = "(",
  [anon_sym_func] = "func",
  [anon_sym_RPAREN] = ")",
  [sym_funcFieldsImport] = "funcFieldsImport",
  [sym_inlineExport] = "inlineExport",
  [sym_inlineImport] = "inlineImport",
  [sym_instrCall] = "instrCall",
  [sym_instrPlain] = "instrPlain",
  [sym_instrBlock] = "instrBlock",
  [anon_sym_module] = "module",
  [anon_sym_type] = "type",
  [aux_sym_digit_token1] = "digit_token1",
  [sym_hexdigit] = "hexdigit",
  [anon_sym__] = "_",
  [anon_sym_DOLLAR] = "$",
  [aux_sym_NAME_token1] = "NAME_token1",
  [aux_sym_NAME_token2] = "NAME_token2",
  [sym_NAT] = "NAT",
  [sym_module1] = "module1",
  [sym_func] = "func",
  [sym_funcBody] = "funcBody",
  [sym_funcFields] = "funcFields",
  [sym_funcFieldsBody] = "funcFieldsBody",
  [sym_funcResultBody] = "funcResultBody",
  [sym_instr] = "instr",
  [sym_module] = "module",
  [sym_moduleField] = "moduleField",
  [sym_typeUse] = "typeUse",
  [sym_NAME] = "NAME",
  [aux_sym_funcBody_repeat1] = "funcBody_repeat1",
  [aux_sym_module_repeat1] = "module_repeat1",
  [aux_sym_NAME_repeat1] = "NAME_repeat1",
};

static TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_expr] = sym_expr,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_func] = anon_sym_func,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [sym_funcFieldsImport] = sym_funcFieldsImport,
  [sym_inlineExport] = sym_inlineExport,
  [sym_inlineImport] = sym_inlineImport,
  [sym_instrCall] = sym_instrCall,
  [sym_instrPlain] = sym_instrPlain,
  [sym_instrBlock] = sym_instrBlock,
  [anon_sym_module] = anon_sym_module,
  [anon_sym_type] = anon_sym_type,
  [aux_sym_digit_token1] = aux_sym_digit_token1,
  [sym_hexdigit] = sym_hexdigit,
  [anon_sym__] = anon_sym__,
  [anon_sym_DOLLAR] = anon_sym_DOLLAR,
  [aux_sym_NAME_token1] = aux_sym_NAME_token1,
  [aux_sym_NAME_token2] = aux_sym_NAME_token2,
  [sym_NAT] = sym_NAT,
  [sym_module1] = sym_module1,
  [sym_func] = sym_func,
  [sym_funcBody] = sym_funcBody,
  [sym_funcFields] = sym_funcFields,
  [sym_funcFieldsBody] = sym_funcFieldsBody,
  [sym_funcResultBody] = sym_funcResultBody,
  [sym_instr] = sym_instr,
  [sym_module] = sym_module,
  [sym_moduleField] = sym_moduleField,
  [sym_typeUse] = sym_typeUse,
  [sym_NAME] = sym_NAME,
  [aux_sym_funcBody_repeat1] = aux_sym_funcBody_repeat1,
  [aux_sym_module_repeat1] = aux_sym_module_repeat1,
  [aux_sym_NAME_repeat1] = aux_sym_NAME_repeat1,
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
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_func] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [sym_funcFieldsImport] = {
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
  [sym_instrPlain] = {
    .visible = true,
    .named = true,
  },
  [sym_instrBlock] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_module] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_type] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_digit_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_hexdigit] = {
    .visible = true,
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
  [aux_sym_NAME_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_NAME_token2] = {
    .visible = false,
    .named = false,
  },
  [sym_NAT] = {
    .visible = true,
    .named = true,
  },
  [sym_module1] = {
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
  [sym_funcFields] = {
    .visible = true,
    .named = true,
  },
  [sym_funcFieldsBody] = {
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
  [sym_module] = {
    .visible = true,
    .named = true,
  },
  [sym_moduleField] = {
    .visible = true,
    .named = true,
  },
  [sym_typeUse] = {
    .visible = true,
    .named = true,
  },
  [sym_NAME] = {
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
  [aux_sym_NAME_repeat1] = {
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
      if (eof) ADVANCE(65);
      if (lookahead == '$') ADVANCE(81);
      if (lookahead == '(') ADVANCE(67);
      if (lookahead == ')') ADVANCE(69);
      if (lookahead == '_') ADVANCE(80);
      if (lookahead == 'i') ADVANCE(83);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(78);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(79);
      if (lookahead == '!' ||
          ('#' <= lookahead && lookahead <= '+') ||
          ('-' <= lookahead && lookahead <= ':') ||
          ('<' <= lookahead && lookahead <= '@') ||
          lookahead == '\\' ||
          ('^' <= lookahead && lookahead <= '`') ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(84);
      if (('G' <= lookahead && lookahead <= 'Z') ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(82);
      END_STATE();
    case 1:
      if (lookahead == '$') ADVANCE(81);
      if (lookahead == '(') ADVANCE(67);
      if (lookahead == ')') ADVANCE(69);
      if (lookahead == 'e') ADVANCE(63);
      if (lookahead == 'f') ADVANCE(60);
      if (lookahead == 'i') ADVANCE(35);
      if (lookahead == 'm') ADVANCE(40);
      if (lookahead == 't') ADVANCE(64);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(85);
      END_STATE();
    case 2:
      if (lookahead == '(') ADVANCE(67);
      if (lookahead == ')') ADVANCE(69);
      if (lookahead == '_') ADVANCE(80);
      if (lookahead == 'i') ADVANCE(83);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(2)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(78);
      if (lookahead == '!' ||
          ('#' <= lookahead && lookahead <= '+') ||
          ('-' <= lookahead && lookahead <= ':') ||
          ('<' <= lookahead && lookahead <= '@') ||
          lookahead == '\\' ||
          ('^' <= lookahead && lookahead <= '`') ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(84);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(82);
      END_STATE();
    case 3:
      if (lookahead == '(') ADVANCE(67);
      if (lookahead == ')') ADVANCE(69);
      if (lookahead == '_') ADVANCE(80);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(3)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(78);
      if (lookahead == '!' ||
          ('#' <= lookahead && lookahead <= '+') ||
          ('-' <= lookahead && lookahead <= ':') ||
          ('<' <= lookahead && lookahead <= '@') ||
          lookahead == '\\' ||
          ('^' <= lookahead && lookahead <= '`') ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(84);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(82);
      END_STATE();
    case 4:
      if (lookahead == 'B') ADVANCE(30);
      if (lookahead == 'C') ADVANCE(8);
      if (lookahead == 'P') ADVANCE(28);
      END_STATE();
    case 5:
      if (lookahead == 'E') ADVANCE(62);
      if (lookahead == 'I') ADVANCE(32);
      END_STATE();
    case 6:
      if (lookahead == 'F') ADVANCE(22);
      END_STATE();
    case 7:
      if (lookahead == 'I') ADVANCE(33);
      END_STATE();
    case 8:
      if (lookahead == 'a') ADVANCE(31);
      END_STATE();
    case 9:
      if (lookahead == 'a') ADVANCE(21);
      END_STATE();
    case 10:
      if (lookahead == 'c') ADVANCE(6);
      END_STATE();
    case 11:
      if (lookahead == 'c') ADVANCE(23);
      END_STATE();
    case 12:
      if (lookahead == 'c') ADVANCE(68);
      END_STATE();
    case 13:
      if (lookahead == 'd') ADVANCE(54);
      END_STATE();
    case 14:
      if (lookahead == 'd') ADVANCE(59);
      END_STATE();
    case 15:
      if (lookahead == 'e') ADVANCE(5);
      END_STATE();
    case 16:
      if (lookahead == 'e') ADVANCE(77);
      END_STATE();
    case 17:
      if (lookahead == 'e') ADVANCE(76);
      END_STATE();
    case 18:
      if (lookahead == 'e') ADVANCE(27);
      END_STATE();
    case 19:
      if (lookahead == 'f') ADVANCE(61);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(19)
      END_STATE();
    case 20:
      if (lookahead == 'i') ADVANCE(34);
      END_STATE();
    case 21:
      if (lookahead == 'i') ADVANCE(37);
      END_STATE();
    case 22:
      if (lookahead == 'i') ADVANCE(18);
      END_STATE();
    case 23:
      if (lookahead == 'k') ADVANCE(75);
      END_STATE();
    case 24:
      if (lookahead == 'l') ADVANCE(20);
      END_STATE();
    case 25:
      if (lookahead == 'l') ADVANCE(20);
      if (lookahead == 's') ADVANCE(58);
      END_STATE();
    case 26:
      if (lookahead == 'l') ADVANCE(73);
      END_STATE();
    case 27:
      if (lookahead == 'l') ADVANCE(13);
      END_STATE();
    case 28:
      if (lookahead == 'l') ADVANCE(9);
      END_STATE();
    case 29:
      if (lookahead == 'l') ADVANCE(17);
      END_STATE();
    case 30:
      if (lookahead == 'l') ADVANCE(41);
      END_STATE();
    case 31:
      if (lookahead == 'l') ADVANCE(26);
      END_STATE();
    case 32:
      if (lookahead == 'm') ADVANCE(47);
      END_STATE();
    case 33:
      if (lookahead == 'm') ADVANCE(48);
      END_STATE();
    case 34:
      if (lookahead == 'n') ADVANCE(15);
      END_STATE();
    case 35:
      if (lookahead == 'n') ADVANCE(25);
      END_STATE();
    case 36:
      if (lookahead == 'n') ADVANCE(10);
      END_STATE();
    case 37:
      if (lookahead == 'n') ADVANCE(74);
      END_STATE();
    case 38:
      if (lookahead == 'n') ADVANCE(12);
      END_STATE();
    case 39:
      if (lookahead == 'o') ADVANCE(49);
      END_STATE();
    case 40:
      if (lookahead == 'o') ADVANCE(14);
      END_STATE();
    case 41:
      if (lookahead == 'o') ADVANCE(11);
      END_STATE();
    case 42:
      if (lookahead == 'o') ADVANCE(52);
      END_STATE();
    case 43:
      if (lookahead == 'o') ADVANCE(53);
      END_STATE();
    case 44:
      if (lookahead == 'p') ADVANCE(39);
      END_STATE();
    case 45:
      if (lookahead == 'p') ADVANCE(16);
      END_STATE();
    case 46:
      if (lookahead == 'p') ADVANCE(50);
      END_STATE();
    case 47:
      if (lookahead == 'p') ADVANCE(42);
      END_STATE();
    case 48:
      if (lookahead == 'p') ADVANCE(43);
      END_STATE();
    case 49:
      if (lookahead == 'r') ADVANCE(55);
      END_STATE();
    case 50:
      if (lookahead == 'r') ADVANCE(66);
      END_STATE();
    case 51:
      if (lookahead == 'r') ADVANCE(4);
      END_STATE();
    case 52:
      if (lookahead == 'r') ADVANCE(56);
      END_STATE();
    case 53:
      if (lookahead == 'r') ADVANCE(57);
      END_STATE();
    case 54:
      if (lookahead == 's') ADVANCE(7);
      END_STATE();
    case 55:
      if (lookahead == 't') ADVANCE(71);
      END_STATE();
    case 56:
      if (lookahead == 't') ADVANCE(72);
      END_STATE();
    case 57:
      if (lookahead == 't') ADVANCE(70);
      END_STATE();
    case 58:
      if (lookahead == 't') ADVANCE(51);
      END_STATE();
    case 59:
      if (lookahead == 'u') ADVANCE(29);
      END_STATE();
    case 60:
      if (lookahead == 'u') ADVANCE(36);
      END_STATE();
    case 61:
      if (lookahead == 'u') ADVANCE(38);
      END_STATE();
    case 62:
      if (lookahead == 'x') ADVANCE(44);
      END_STATE();
    case 63:
      if (lookahead == 'x') ADVANCE(46);
      END_STATE();
    case 64:
      if (lookahead == 'y') ADVANCE(45);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym_expr);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(anon_sym_func);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_funcFieldsImport);
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
      ACCEPT_TOKEN(sym_instrPlain);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(sym_instrBlock);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(anon_sym_module);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(anon_sym_type);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(aux_sym_digit_token1);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(sym_hexdigit);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(anon_sym__);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(anon_sym_DOLLAR);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(aux_sym_NAME_token1);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(aux_sym_NAME_token1);
      if (lookahead == 'n') ADVANCE(24);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(aux_sym_NAME_token2);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(sym_NAT);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(85);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 1},
  [3] = {.lex_state = 2},
  [4] = {.lex_state = 2},
  [5] = {.lex_state = 1},
  [6] = {.lex_state = 3},
  [7] = {.lex_state = 1},
  [8] = {.lex_state = 1},
  [9] = {.lex_state = 1},
  [10] = {.lex_state = 3},
  [11] = {.lex_state = 1},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 1},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 3},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 3},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 1},
  [22] = {.lex_state = 1},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 1},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 1},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 1},
  [39] = {.lex_state = 19},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 0},
};

static uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [sym_inlineExport] = ACTIONS(1),
    [sym_inlineImport] = ACTIONS(1),
    [aux_sym_digit_token1] = ACTIONS(1),
    [sym_hexdigit] = ACTIONS(1),
    [anon_sym__] = ACTIONS(1),
    [anon_sym_DOLLAR] = ACTIONS(1),
    [aux_sym_NAME_token1] = ACTIONS(1),
    [aux_sym_NAME_token2] = ACTIONS(1),
  },
  [1] = {
    [sym_module1] = STATE(41),
    [sym_module] = STATE(40),
    [anon_sym_LPAREN] = ACTIONS(3),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 6,
    ACTIONS(7), 1,
      anon_sym_RPAREN,
    STATE(28), 1,
      sym_funcFieldsBody,
    STATE(31), 1,
      sym_funcBody,
    STATE(32), 1,
      sym_funcResultBody,
    STATE(9), 2,
      sym_instr,
      aux_sym_funcBody_repeat1,
    ACTIONS(5), 4,
      sym_expr,
      sym_instrCall,
      sym_instrPlain,
      sym_instrBlock,
  [23] = 4,
    ACTIONS(14), 1,
      aux_sym_NAME_token1,
    STATE(3), 1,
      aux_sym_NAME_repeat1,
    ACTIONS(11), 3,
      aux_sym_digit_token1,
      anon_sym__,
      aux_sym_NAME_token2,
    ACTIONS(9), 4,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      sym_inlineExport,
      sym_inlineImport,
  [41] = 4,
    ACTIONS(21), 1,
      aux_sym_NAME_token1,
    STATE(3), 1,
      aux_sym_NAME_repeat1,
    ACTIONS(19), 3,
      aux_sym_digit_token1,
      anon_sym__,
      aux_sym_NAME_token2,
    ACTIONS(17), 4,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      sym_inlineExport,
      sym_inlineImport,
  [59] = 8,
    ACTIONS(23), 1,
      anon_sym_LPAREN,
    ACTIONS(25), 1,
      anon_sym_RPAREN,
    ACTIONS(27), 1,
      sym_inlineExport,
    ACTIONS(29), 1,
      sym_inlineImport,
    ACTIONS(31), 1,
      anon_sym_DOLLAR,
    STATE(2), 1,
      sym_typeUse,
    STATE(12), 1,
      sym_NAME,
    STATE(42), 1,
      sym_funcFields,
  [84] = 3,
    STATE(10), 1,
      aux_sym_NAME_repeat1,
    ACTIONS(17), 2,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
    ACTIONS(33), 4,
      aux_sym_digit_token1,
      anon_sym__,
      aux_sym_NAME_token1,
      aux_sym_NAME_token2,
  [98] = 6,
    ACTIONS(35), 1,
      anon_sym_LPAREN,
    ACTIONS(37), 1,
      anon_sym_RPAREN,
    ACTIONS(39), 1,
      anon_sym_DOLLAR,
    STATE(20), 1,
      sym_NAME,
    STATE(26), 1,
      sym_func,
    STATE(19), 2,
      sym_moduleField,
      aux_sym_module_repeat1,
  [118] = 3,
    ACTIONS(44), 1,
      anon_sym_RPAREN,
    STATE(8), 2,
      sym_instr,
      aux_sym_funcBody_repeat1,
    ACTIONS(41), 4,
      sym_expr,
      sym_instrCall,
      sym_instrPlain,
      sym_instrBlock,
  [132] = 3,
    ACTIONS(46), 1,
      anon_sym_RPAREN,
    STATE(8), 2,
      sym_instr,
      aux_sym_funcBody_repeat1,
    ACTIONS(5), 4,
      sym_expr,
      sym_instrCall,
      sym_instrPlain,
      sym_instrBlock,
  [146] = 3,
    STATE(10), 1,
      aux_sym_NAME_repeat1,
    ACTIONS(9), 2,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
    ACTIONS(48), 4,
      aux_sym_digit_token1,
      anon_sym__,
      aux_sym_NAME_token1,
      aux_sym_NAME_token2,
  [160] = 1,
    ACTIONS(51), 6,
      sym_expr,
      anon_sym_RPAREN,
      sym_funcFieldsImport,
      sym_instrCall,
      sym_instrPlain,
      sym_instrBlock,
  [169] = 6,
    ACTIONS(23), 1,
      anon_sym_LPAREN,
    ACTIONS(27), 1,
      sym_inlineExport,
    ACTIONS(29), 1,
      sym_inlineImport,
    ACTIONS(53), 1,
      anon_sym_RPAREN,
    STATE(2), 1,
      sym_typeUse,
    STATE(34), 1,
      sym_funcFields,
  [188] = 1,
    ACTIONS(55), 5,
      sym_expr,
      anon_sym_RPAREN,
      sym_instrCall,
      sym_instrPlain,
      sym_instrBlock,
  [196] = 4,
    ACTIONS(35), 1,
      anon_sym_LPAREN,
    ACTIONS(57), 1,
      anon_sym_RPAREN,
    STATE(26), 1,
      sym_func,
    STATE(15), 2,
      sym_moduleField,
      aux_sym_module_repeat1,
  [210] = 4,
    ACTIONS(59), 1,
      anon_sym_LPAREN,
    ACTIONS(62), 1,
      anon_sym_RPAREN,
    STATE(26), 1,
      sym_func,
    STATE(15), 2,
      sym_moduleField,
      aux_sym_module_repeat1,
  [224] = 2,
    STATE(4), 1,
      aux_sym_NAME_repeat1,
    ACTIONS(64), 4,
      aux_sym_digit_token1,
      anon_sym__,
      aux_sym_NAME_token1,
      aux_sym_NAME_token2,
  [234] = 5,
    ACTIONS(23), 1,
      anon_sym_LPAREN,
    ACTIONS(27), 1,
      sym_inlineExport,
    ACTIONS(29), 1,
      sym_inlineImport,
    STATE(2), 1,
      sym_typeUse,
    STATE(28), 1,
      sym_funcFields,
  [250] = 2,
    STATE(6), 1,
      aux_sym_NAME_repeat1,
    ACTIONS(66), 4,
      aux_sym_digit_token1,
      anon_sym__,
      aux_sym_NAME_token1,
      aux_sym_NAME_token2,
  [260] = 4,
    ACTIONS(35), 1,
      anon_sym_LPAREN,
    ACTIONS(68), 1,
      anon_sym_RPAREN,
    STATE(26), 1,
      sym_func,
    STATE(15), 2,
      sym_moduleField,
      aux_sym_module_repeat1,
  [274] = 4,
    ACTIONS(35), 1,
      anon_sym_LPAREN,
    ACTIONS(68), 1,
      anon_sym_RPAREN,
    STATE(26), 1,
      sym_func,
    STATE(14), 2,
      sym_moduleField,
      aux_sym_module_repeat1,
  [288] = 3,
    ACTIONS(23), 1,
      anon_sym_LPAREN,
    ACTIONS(70), 1,
      sym_funcFieldsImport,
    STATE(27), 1,
      sym_typeUse,
  [298] = 3,
    ACTIONS(39), 1,
      anon_sym_DOLLAR,
    ACTIONS(72), 1,
      sym_NAT,
    STATE(35), 1,
      sym_NAME,
  [308] = 1,
    ACTIONS(74), 2,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [313] = 1,
    ACTIONS(76), 2,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [318] = 1,
    ACTIONS(78), 2,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [323] = 1,
    ACTIONS(80), 2,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [328] = 1,
    ACTIONS(82), 1,
      sym_funcFieldsImport,
  [332] = 1,
    ACTIONS(84), 1,
      anon_sym_RPAREN,
  [336] = 1,
    ACTIONS(86), 1,
      ts_builtin_sym_end,
  [340] = 1,
    ACTIONS(88), 1,
      anon_sym_type,
  [344] = 1,
    ACTIONS(90), 1,
      anon_sym_RPAREN,
  [348] = 1,
    ACTIONS(92), 1,
      anon_sym_RPAREN,
  [352] = 1,
    ACTIONS(94), 1,
      ts_builtin_sym_end,
  [356] = 1,
    ACTIONS(96), 1,
      anon_sym_RPAREN,
  [360] = 1,
    ACTIONS(98), 1,
      anon_sym_RPAREN,
  [364] = 1,
    ACTIONS(100), 1,
      anon_sym_RPAREN,
  [368] = 1,
    ACTIONS(102), 1,
      ts_builtin_sym_end,
  [372] = 1,
    ACTIONS(104), 1,
      anon_sym_module,
  [376] = 1,
    ACTIONS(106), 1,
      anon_sym_func,
  [380] = 1,
    ACTIONS(108), 1,
      ts_builtin_sym_end,
  [384] = 1,
    ACTIONS(110), 1,
      ts_builtin_sym_end,
  [388] = 1,
    ACTIONS(53), 1,
      anon_sym_RPAREN,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 23,
  [SMALL_STATE(4)] = 41,
  [SMALL_STATE(5)] = 59,
  [SMALL_STATE(6)] = 84,
  [SMALL_STATE(7)] = 98,
  [SMALL_STATE(8)] = 118,
  [SMALL_STATE(9)] = 132,
  [SMALL_STATE(10)] = 146,
  [SMALL_STATE(11)] = 160,
  [SMALL_STATE(12)] = 169,
  [SMALL_STATE(13)] = 188,
  [SMALL_STATE(14)] = 196,
  [SMALL_STATE(15)] = 210,
  [SMALL_STATE(16)] = 224,
  [SMALL_STATE(17)] = 234,
  [SMALL_STATE(18)] = 250,
  [SMALL_STATE(19)] = 260,
  [SMALL_STATE(20)] = 274,
  [SMALL_STATE(21)] = 288,
  [SMALL_STATE(22)] = 298,
  [SMALL_STATE(23)] = 308,
  [SMALL_STATE(24)] = 313,
  [SMALL_STATE(25)] = 318,
  [SMALL_STATE(26)] = 323,
  [SMALL_STATE(27)] = 328,
  [SMALL_STATE(28)] = 332,
  [SMALL_STATE(29)] = 336,
  [SMALL_STATE(30)] = 340,
  [SMALL_STATE(31)] = 344,
  [SMALL_STATE(32)] = 348,
  [SMALL_STATE(33)] = 352,
  [SMALL_STATE(34)] = 356,
  [SMALL_STATE(35)] = 360,
  [SMALL_STATE(36)] = 364,
  [SMALL_STATE(37)] = 368,
  [SMALL_STATE(38)] = 372,
  [SMALL_STATE(39)] = 376,
  [SMALL_STATE(40)] = 380,
  [SMALL_STATE(41)] = 384,
  [SMALL_STATE(42)] = 388,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.count = 0, .reusable = false},
  [1] = {.count = 1, .reusable = false}, RECOVER(),
  [3] = {.count = 1, .reusable = true}, SHIFT(38),
  [5] = {.count = 1, .reusable = true}, SHIFT(13),
  [7] = {.count = 1, .reusable = true}, REDUCE(sym_funcFields, 1),
  [9] = {.count = 1, .reusable = true}, REDUCE(aux_sym_NAME_repeat1, 2),
  [11] = {.count = 2, .reusable = true}, REDUCE(aux_sym_NAME_repeat1, 2), SHIFT_REPEAT(3),
  [14] = {.count = 2, .reusable = false}, REDUCE(aux_sym_NAME_repeat1, 2), SHIFT_REPEAT(3),
  [17] = {.count = 1, .reusable = true}, REDUCE(sym_NAME, 2),
  [19] = {.count = 1, .reusable = true}, SHIFT(3),
  [21] = {.count = 1, .reusable = false}, SHIFT(3),
  [23] = {.count = 1, .reusable = true}, SHIFT(30),
  [25] = {.count = 1, .reusable = true}, SHIFT(24),
  [27] = {.count = 1, .reusable = true}, SHIFT(17),
  [29] = {.count = 1, .reusable = true}, SHIFT(21),
  [31] = {.count = 1, .reusable = true}, SHIFT(16),
  [33] = {.count = 1, .reusable = true}, SHIFT(10),
  [35] = {.count = 1, .reusable = true}, SHIFT(39),
  [37] = {.count = 1, .reusable = true}, SHIFT(37),
  [39] = {.count = 1, .reusable = true}, SHIFT(18),
  [41] = {.count = 2, .reusable = true}, REDUCE(aux_sym_funcBody_repeat1, 2), SHIFT_REPEAT(13),
  [44] = {.count = 1, .reusable = true}, REDUCE(aux_sym_funcBody_repeat1, 2),
  [46] = {.count = 1, .reusable = true}, REDUCE(sym_funcBody, 1),
  [48] = {.count = 2, .reusable = true}, REDUCE(aux_sym_NAME_repeat1, 2), SHIFT_REPEAT(10),
  [51] = {.count = 1, .reusable = true}, REDUCE(sym_typeUse, 4),
  [53] = {.count = 1, .reusable = true}, SHIFT(23),
  [55] = {.count = 1, .reusable = true}, REDUCE(sym_instr, 1),
  [57] = {.count = 1, .reusable = true}, SHIFT(33),
  [59] = {.count = 2, .reusable = true}, REDUCE(aux_sym_module_repeat1, 2), SHIFT_REPEAT(39),
  [62] = {.count = 1, .reusable = true}, REDUCE(aux_sym_module_repeat1, 2),
  [64] = {.count = 1, .reusable = true}, SHIFT(4),
  [66] = {.count = 1, .reusable = true}, SHIFT(6),
  [68] = {.count = 1, .reusable = true}, SHIFT(29),
  [70] = {.count = 1, .reusable = true}, SHIFT(28),
  [72] = {.count = 1, .reusable = true}, SHIFT(35),
  [74] = {.count = 1, .reusable = true}, REDUCE(sym_func, 4),
  [76] = {.count = 1, .reusable = true}, REDUCE(sym_func, 3),
  [78] = {.count = 1, .reusable = true}, REDUCE(sym_func, 5),
  [80] = {.count = 1, .reusable = true}, REDUCE(sym_moduleField, 1),
  [82] = {.count = 1, .reusable = true}, SHIFT(36),
  [84] = {.count = 1, .reusable = true}, REDUCE(sym_funcFields, 2),
  [86] = {.count = 1, .reusable = true}, REDUCE(sym_module, 4),
  [88] = {.count = 1, .reusable = true}, SHIFT(22),
  [90] = {.count = 1, .reusable = true}, REDUCE(sym_funcResultBody, 1),
  [92] = {.count = 1, .reusable = true}, REDUCE(sym_funcFieldsBody, 1),
  [94] = {.count = 1, .reusable = true}, REDUCE(sym_module, 5),
  [96] = {.count = 1, .reusable = true}, SHIFT(25),
  [98] = {.count = 1, .reusable = true}, SHIFT(11),
  [100] = {.count = 1, .reusable = true}, REDUCE(sym_funcFields, 3),
  [102] = {.count = 1, .reusable = true}, REDUCE(sym_module, 3),
  [104] = {.count = 1, .reusable = true}, SHIFT(7),
  [106] = {.count = 1, .reusable = true}, SHIFT(5),
  [108] = {.count = 1, .reusable = true}, REDUCE(sym_module1, 1),
  [110] = {.count = 1, .reusable = true},  ACCEPT_INPUT(),
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
