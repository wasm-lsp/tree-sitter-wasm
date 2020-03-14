#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 11
#define STATE_COUNT 44
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 38
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
  sym_funcFieldImport = 5,
  sym_inlineExport = 6,
  sym_inlineImport = 7,
  sym_instrCall = 8,
  sym_instrPlain = 9,
  sym_instrBlock = 10,
  anon_sym_module = 11,
  anon_sym_type = 12,
  sym_NAT = 13,
  aux_sym__digit_token1 = 14,
  sym__hexdigit = 15,
  anon_sym__ = 16,
  anon_sym_DOLLAR = 17,
  aux_sym__name_token1 = 18,
  aux_sym__name_token2 = 19,
  sym_file = 20,
  sym__bindVar = 21,
  sym_func = 22,
  sym_funcBody = 23,
  sym_funcField = 24,
  sym_funcFieldBody = 25,
  sym_funcResultBody = 26,
  sym_instr = 27,
  sym_module = 28,
  sym_moduleField = 29,
  sym__moduleVar = 30,
  sym_typeUse = 31,
  sym_VAR = 32,
  sym__name = 33,
  sym__var = 34,
  aux_sym_funcBody_repeat1 = 35,
  aux_sym_module_repeat1 = 36,
  aux_sym__name_repeat1 = 37,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_expr] = "expr",
  [anon_sym_LPAREN] = "(",
  [anon_sym_func] = "func",
  [anon_sym_RPAREN] = ")",
  [sym_funcFieldImport] = "funcFieldImport",
  [sym_inlineExport] = "inlineExport",
  [sym_inlineImport] = "inlineImport",
  [sym_instrCall] = "instrCall",
  [sym_instrPlain] = "instrPlain",
  [sym_instrBlock] = "instrBlock",
  [anon_sym_module] = "module",
  [anon_sym_type] = "type",
  [sym_NAT] = "NAT",
  [aux_sym__digit_token1] = "_digit_token1",
  [sym__hexdigit] = "_hexdigit",
  [anon_sym__] = "_",
  [anon_sym_DOLLAR] = "$",
  [aux_sym__name_token1] = "_name_token1",
  [aux_sym__name_token2] = "_name_token2",
  [sym_file] = "file",
  [sym__bindVar] = "_bindVar",
  [sym_func] = "func",
  [sym_funcBody] = "funcBody",
  [sym_funcField] = "funcField",
  [sym_funcFieldBody] = "funcFieldBody",
  [sym_funcResultBody] = "funcResultBody",
  [sym_instr] = "instr",
  [sym_module] = "module",
  [sym_moduleField] = "moduleField",
  [sym__moduleVar] = "_moduleVar",
  [sym_typeUse] = "typeUse",
  [sym_VAR] = "VAR",
  [sym__name] = "_name",
  [sym__var] = "_var",
  [aux_sym_funcBody_repeat1] = "funcBody_repeat1",
  [aux_sym_module_repeat1] = "module_repeat1",
  [aux_sym__name_repeat1] = "_name_repeat1",
};

static TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_expr] = sym_expr,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_func] = anon_sym_func,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [sym_funcFieldImport] = sym_funcFieldImport,
  [sym_inlineExport] = sym_inlineExport,
  [sym_inlineImport] = sym_inlineImport,
  [sym_instrCall] = sym_instrCall,
  [sym_instrPlain] = sym_instrPlain,
  [sym_instrBlock] = sym_instrBlock,
  [anon_sym_module] = anon_sym_module,
  [anon_sym_type] = anon_sym_type,
  [sym_NAT] = sym_NAT,
  [aux_sym__digit_token1] = aux_sym__digit_token1,
  [sym__hexdigit] = sym__hexdigit,
  [anon_sym__] = anon_sym__,
  [anon_sym_DOLLAR] = anon_sym_DOLLAR,
  [aux_sym__name_token1] = aux_sym__name_token1,
  [aux_sym__name_token2] = aux_sym__name_token2,
  [sym_file] = sym_file,
  [sym__bindVar] = sym__bindVar,
  [sym_func] = sym_func,
  [sym_funcBody] = sym_funcBody,
  [sym_funcField] = sym_funcField,
  [sym_funcFieldBody] = sym_funcFieldBody,
  [sym_funcResultBody] = sym_funcResultBody,
  [sym_instr] = sym_instr,
  [sym_module] = sym_module,
  [sym_moduleField] = sym_moduleField,
  [sym__moduleVar] = sym__moduleVar,
  [sym_typeUse] = sym_typeUse,
  [sym_VAR] = sym_VAR,
  [sym__name] = sym__name,
  [sym__var] = sym__var,
  [aux_sym_funcBody_repeat1] = aux_sym_funcBody_repeat1,
  [aux_sym_module_repeat1] = aux_sym_module_repeat1,
  [aux_sym__name_repeat1] = aux_sym__name_repeat1,
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
  [sym_NAT] = {
    .visible = true,
    .named = true,
  },
  [aux_sym__digit_token1] = {
    .visible = false,
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
  [sym_VAR] = {
    .visible = true,
    .named = true,
  },
  [sym__name] = {
    .visible = false,
    .named = true,
  },
  [sym__var] = {
    .visible = false,
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
  [aux_sym__name_repeat1] = {
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
      if (eof) ADVANCE(64);
      if (lookahead == '$') ADVANCE(81);
      if (lookahead == '(') ADVANCE(66);
      if (lookahead == ')') ADVANCE(68);
      if (lookahead == '_') ADVANCE(80);
      if (lookahead == 'i') ADVANCE(83);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(77);
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
      if (lookahead == '(') ADVANCE(66);
      if (lookahead == ')') ADVANCE(68);
      if (lookahead == 'e') ADVANCE(62);
      if (lookahead == 'f') ADVANCE(59);
      if (lookahead == 'i') ADVANCE(35);
      if (lookahead == 'm') ADVANCE(40);
      if (lookahead == 't') ADVANCE(63);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(77);
      END_STATE();
    case 2:
      if (lookahead == '(') ADVANCE(66);
      if (lookahead == ')') ADVANCE(68);
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
      if (lookahead == '(') ADVANCE(66);
      if (lookahead == ')') ADVANCE(68);
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
      if (lookahead == 'E') ADVANCE(61);
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
      if (lookahead == 'c') ADVANCE(67);
      END_STATE();
    case 13:
      if (lookahead == 'd') ADVANCE(7);
      END_STATE();
    case 14:
      if (lookahead == 'd') ADVANCE(58);
      END_STATE();
    case 15:
      if (lookahead == 'e') ADVANCE(5);
      END_STATE();
    case 16:
      if (lookahead == 'e') ADVANCE(76);
      END_STATE();
    case 17:
      if (lookahead == 'e') ADVANCE(75);
      END_STATE();
    case 18:
      if (lookahead == 'e') ADVANCE(27);
      END_STATE();
    case 19:
      if (lookahead == 'f') ADVANCE(60);
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
      if (lookahead == 'k') ADVANCE(74);
      END_STATE();
    case 24:
      if (lookahead == 'l') ADVANCE(20);
      END_STATE();
    case 25:
      if (lookahead == 'l') ADVANCE(20);
      if (lookahead == 's') ADVANCE(57);
      END_STATE();
    case 26:
      if (lookahead == 'l') ADVANCE(72);
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
      if (lookahead == 'n') ADVANCE(73);
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
      if (lookahead == 'r') ADVANCE(54);
      END_STATE();
    case 50:
      if (lookahead == 'r') ADVANCE(65);
      END_STATE();
    case 51:
      if (lookahead == 'r') ADVANCE(4);
      END_STATE();
    case 52:
      if (lookahead == 'r') ADVANCE(55);
      END_STATE();
    case 53:
      if (lookahead == 'r') ADVANCE(56);
      END_STATE();
    case 54:
      if (lookahead == 't') ADVANCE(70);
      END_STATE();
    case 55:
      if (lookahead == 't') ADVANCE(71);
      END_STATE();
    case 56:
      if (lookahead == 't') ADVANCE(69);
      END_STATE();
    case 57:
      if (lookahead == 't') ADVANCE(51);
      END_STATE();
    case 58:
      if (lookahead == 'u') ADVANCE(29);
      END_STATE();
    case 59:
      if (lookahead == 'u') ADVANCE(36);
      END_STATE();
    case 60:
      if (lookahead == 'u') ADVANCE(38);
      END_STATE();
    case 61:
      if (lookahead == 'x') ADVANCE(44);
      END_STATE();
    case 62:
      if (lookahead == 'x') ADVANCE(46);
      END_STATE();
    case 63:
      if (lookahead == 'y') ADVANCE(45);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym_expr);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_func);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym_funcFieldImport);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_inlineExport);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym_inlineImport);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym_instrCall);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(sym_instrPlain);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(sym_instrBlock);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(anon_sym_module);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(anon_sym_type);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(sym_NAT);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(77);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(aux_sym__digit_token1);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(sym__hexdigit);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(anon_sym__);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(anon_sym_DOLLAR);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(aux_sym__name_token1);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(aux_sym__name_token1);
      if (lookahead == 'n') ADVANCE(24);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(aux_sym__name_token2);
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
  [4] = {.lex_state = 2},
  [5] = {.lex_state = 2},
  [6] = {.lex_state = 1},
  [7] = {.lex_state = 3},
  [8] = {.lex_state = 1},
  [9] = {.lex_state = 3},
  [10] = {.lex_state = 1},
  [11] = {.lex_state = 1},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 1},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 1},
  [19] = {.lex_state = 3},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 3},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 1},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 1},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 1},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 1},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 19},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
};

static uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [sym_inlineExport] = ACTIONS(1),
    [sym_inlineImport] = ACTIONS(1),
    [sym_NAT] = ACTIONS(1),
    [aux_sym__digit_token1] = ACTIONS(1),
    [sym__hexdigit] = ACTIONS(1),
    [anon_sym__] = ACTIONS(1),
    [anon_sym_DOLLAR] = ACTIONS(1),
    [aux_sym__name_token1] = ACTIONS(1),
    [aux_sym__name_token2] = ACTIONS(1),
  },
  [1] = {
    [sym_file] = STATE(43),
    [sym_module] = STATE(42),
    [anon_sym_LPAREN] = ACTIONS(3),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 6,
    ACTIONS(7), 1,
      anon_sym_RPAREN,
    STATE(28), 1,
      sym_funcFieldBody,
    STATE(33), 1,
      sym_funcBody,
    STATE(34), 1,
      sym_funcResultBody,
    STATE(10), 2,
      sym_instr,
      aux_sym_funcBody_repeat1,
    ACTIONS(5), 4,
      sym_expr,
      sym_instrCall,
      sym_instrPlain,
      sym_instrBlock,
  [23] = 9,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      anon_sym_RPAREN,
    ACTIONS(13), 1,
      sym_inlineExport,
    ACTIONS(15), 1,
      sym_inlineImport,
    ACTIONS(17), 1,
      anon_sym_DOLLAR,
    STATE(2), 1,
      sym_typeUse,
    STATE(22), 1,
      sym__name,
    STATE(29), 1,
      sym_funcField,
    STATE(12), 2,
      sym__bindVar,
      sym_VAR,
  [52] = 4,
    ACTIONS(24), 1,
      aux_sym__name_token1,
    STATE(4), 1,
      aux_sym__name_repeat1,
    ACTIONS(21), 3,
      aux_sym__digit_token1,
      anon_sym__,
      aux_sym__name_token2,
    ACTIONS(19), 4,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      sym_inlineExport,
      sym_inlineImport,
  [70] = 4,
    ACTIONS(31), 1,
      aux_sym__name_token1,
    STATE(4), 1,
      aux_sym__name_repeat1,
    ACTIONS(29), 3,
      aux_sym__digit_token1,
      anon_sym__,
      aux_sym__name_token2,
    ACTIONS(27), 4,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      sym_inlineExport,
      sym_inlineImport,
  [88] = 7,
    ACTIONS(33), 1,
      anon_sym_LPAREN,
    ACTIONS(35), 1,
      anon_sym_RPAREN,
    ACTIONS(37), 1,
      anon_sym_DOLLAR,
    STATE(22), 1,
      sym__name,
    STATE(25), 1,
      sym_func,
    STATE(13), 2,
      sym__moduleVar,
      sym_VAR,
    STATE(14), 2,
      sym_moduleField,
      aux_sym_module_repeat1,
  [112] = 3,
    STATE(9), 1,
      aux_sym__name_repeat1,
    ACTIONS(27), 2,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
    ACTIONS(39), 4,
      aux_sym__digit_token1,
      anon_sym__,
      aux_sym__name_token1,
      aux_sym__name_token2,
  [126] = 3,
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
  [140] = 3,
    STATE(9), 1,
      aux_sym__name_repeat1,
    ACTIONS(19), 2,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
    ACTIONS(46), 4,
      aux_sym__digit_token1,
      anon_sym__,
      aux_sym__name_token1,
      aux_sym__name_token2,
  [154] = 3,
    ACTIONS(49), 1,
      anon_sym_RPAREN,
    STATE(8), 2,
      sym_instr,
      aux_sym_funcBody_repeat1,
    ACTIONS(5), 4,
      sym_expr,
      sym_instrCall,
      sym_instrPlain,
      sym_instrBlock,
  [168] = 1,
    ACTIONS(51), 6,
      sym_expr,
      anon_sym_RPAREN,
      sym_funcFieldImport,
      sym_instrCall,
      sym_instrPlain,
      sym_instrBlock,
  [177] = 6,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(13), 1,
      sym_inlineExport,
    ACTIONS(15), 1,
      sym_inlineImport,
    ACTIONS(53), 1,
      anon_sym_RPAREN,
    STATE(2), 1,
      sym_typeUse,
    STATE(31), 1,
      sym_funcField,
  [196] = 4,
    ACTIONS(33), 1,
      anon_sym_LPAREN,
    ACTIONS(55), 1,
      anon_sym_RPAREN,
    STATE(25), 1,
      sym_func,
    STATE(16), 2,
      sym_moduleField,
      aux_sym_module_repeat1,
  [210] = 4,
    ACTIONS(33), 1,
      anon_sym_LPAREN,
    ACTIONS(55), 1,
      anon_sym_RPAREN,
    STATE(25), 1,
      sym_func,
    STATE(17), 2,
      sym_moduleField,
      aux_sym_module_repeat1,
  [224] = 1,
    ACTIONS(57), 5,
      sym_expr,
      anon_sym_RPAREN,
      sym_instrCall,
      sym_instrPlain,
      sym_instrBlock,
  [232] = 4,
    ACTIONS(33), 1,
      anon_sym_LPAREN,
    ACTIONS(59), 1,
      anon_sym_RPAREN,
    STATE(25), 1,
      sym_func,
    STATE(17), 2,
      sym_moduleField,
      aux_sym_module_repeat1,
  [246] = 4,
    ACTIONS(61), 1,
      anon_sym_LPAREN,
    ACTIONS(64), 1,
      anon_sym_RPAREN,
    STATE(25), 1,
      sym_func,
    STATE(17), 2,
      sym_moduleField,
      aux_sym_module_repeat1,
  [260] = 4,
    ACTIONS(37), 1,
      anon_sym_DOLLAR,
    ACTIONS(66), 1,
      sym_NAT,
    STATE(22), 1,
      sym__name,
    STATE(36), 2,
      sym_VAR,
      sym__var,
  [274] = 2,
    STATE(5), 1,
      aux_sym__name_repeat1,
    ACTIONS(68), 4,
      aux_sym__digit_token1,
      anon_sym__,
      aux_sym__name_token1,
      aux_sym__name_token2,
  [284] = 5,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(13), 1,
      sym_inlineExport,
    ACTIONS(15), 1,
      sym_inlineImport,
    STATE(2), 1,
      sym_typeUse,
    STATE(28), 1,
      sym_funcField,
  [300] = 2,
    STATE(7), 1,
      aux_sym__name_repeat1,
    ACTIONS(70), 4,
      aux_sym__digit_token1,
      anon_sym__,
      aux_sym__name_token1,
      aux_sym__name_token2,
  [310] = 1,
    ACTIONS(72), 4,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      sym_inlineExport,
      sym_inlineImport,
  [317] = 3,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(74), 1,
      sym_funcFieldImport,
    STATE(30), 1,
      sym_typeUse,
  [327] = 1,
    ACTIONS(76), 2,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [332] = 1,
    ACTIONS(78), 2,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [337] = 1,
    ACTIONS(80), 2,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [342] = 1,
    ACTIONS(82), 2,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
  [347] = 1,
    ACTIONS(84), 1,
      anon_sym_RPAREN,
  [351] = 1,
    ACTIONS(53), 1,
      anon_sym_RPAREN,
  [355] = 1,
    ACTIONS(86), 1,
      sym_funcFieldImport,
  [359] = 1,
    ACTIONS(88), 1,
      anon_sym_RPAREN,
  [363] = 1,
    ACTIONS(90), 1,
      anon_sym_type,
  [367] = 1,
    ACTIONS(92), 1,
      anon_sym_RPAREN,
  [371] = 1,
    ACTIONS(94), 1,
      anon_sym_RPAREN,
  [375] = 1,
    ACTIONS(96), 1,
      ts_builtin_sym_end,
  [379] = 1,
    ACTIONS(98), 1,
      anon_sym_RPAREN,
  [383] = 1,
    ACTIONS(100), 1,
      anon_sym_RPAREN,
  [387] = 1,
    ACTIONS(102), 1,
      anon_sym_module,
  [391] = 1,
    ACTIONS(104), 1,
      ts_builtin_sym_end,
  [395] = 1,
    ACTIONS(106), 1,
      ts_builtin_sym_end,
  [399] = 1,
    ACTIONS(108), 1,
      anon_sym_func,
  [403] = 1,
    ACTIONS(110), 1,
      ts_builtin_sym_end,
  [407] = 1,
    ACTIONS(112), 1,
      ts_builtin_sym_end,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 23,
  [SMALL_STATE(4)] = 52,
  [SMALL_STATE(5)] = 70,
  [SMALL_STATE(6)] = 88,
  [SMALL_STATE(7)] = 112,
  [SMALL_STATE(8)] = 126,
  [SMALL_STATE(9)] = 140,
  [SMALL_STATE(10)] = 154,
  [SMALL_STATE(11)] = 168,
  [SMALL_STATE(12)] = 177,
  [SMALL_STATE(13)] = 196,
  [SMALL_STATE(14)] = 210,
  [SMALL_STATE(15)] = 224,
  [SMALL_STATE(16)] = 232,
  [SMALL_STATE(17)] = 246,
  [SMALL_STATE(18)] = 260,
  [SMALL_STATE(19)] = 274,
  [SMALL_STATE(20)] = 284,
  [SMALL_STATE(21)] = 300,
  [SMALL_STATE(22)] = 310,
  [SMALL_STATE(23)] = 317,
  [SMALL_STATE(24)] = 327,
  [SMALL_STATE(25)] = 332,
  [SMALL_STATE(26)] = 337,
  [SMALL_STATE(27)] = 342,
  [SMALL_STATE(28)] = 347,
  [SMALL_STATE(29)] = 351,
  [SMALL_STATE(30)] = 355,
  [SMALL_STATE(31)] = 359,
  [SMALL_STATE(32)] = 363,
  [SMALL_STATE(33)] = 367,
  [SMALL_STATE(34)] = 371,
  [SMALL_STATE(35)] = 375,
  [SMALL_STATE(36)] = 379,
  [SMALL_STATE(37)] = 383,
  [SMALL_STATE(38)] = 387,
  [SMALL_STATE(39)] = 391,
  [SMALL_STATE(40)] = 395,
  [SMALL_STATE(41)] = 399,
  [SMALL_STATE(42)] = 403,
  [SMALL_STATE(43)] = 407,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.count = 0, .reusable = false},
  [1] = {.count = 1, .reusable = false}, RECOVER(),
  [3] = {.count = 1, .reusable = true}, SHIFT(38),
  [5] = {.count = 1, .reusable = true}, SHIFT(15),
  [7] = {.count = 1, .reusable = true}, REDUCE(sym_funcField, 1),
  [9] = {.count = 1, .reusable = true}, SHIFT(32),
  [11] = {.count = 1, .reusable = true}, SHIFT(27),
  [13] = {.count = 1, .reusable = true}, SHIFT(20),
  [15] = {.count = 1, .reusable = true}, SHIFT(23),
  [17] = {.count = 1, .reusable = true}, SHIFT(19),
  [19] = {.count = 1, .reusable = true}, REDUCE(aux_sym__name_repeat1, 2),
  [21] = {.count = 2, .reusable = true}, REDUCE(aux_sym__name_repeat1, 2), SHIFT_REPEAT(4),
  [24] = {.count = 2, .reusable = false}, REDUCE(aux_sym__name_repeat1, 2), SHIFT_REPEAT(4),
  [27] = {.count = 1, .reusable = true}, REDUCE(sym__name, 2),
  [29] = {.count = 1, .reusable = true}, SHIFT(4),
  [31] = {.count = 1, .reusable = false}, SHIFT(4),
  [33] = {.count = 1, .reusable = true}, SHIFT(41),
  [35] = {.count = 1, .reusable = true}, SHIFT(40),
  [37] = {.count = 1, .reusable = true}, SHIFT(21),
  [39] = {.count = 1, .reusable = true}, SHIFT(9),
  [41] = {.count = 2, .reusable = true}, REDUCE(aux_sym_funcBody_repeat1, 2), SHIFT_REPEAT(15),
  [44] = {.count = 1, .reusable = true}, REDUCE(aux_sym_funcBody_repeat1, 2),
  [46] = {.count = 2, .reusable = true}, REDUCE(aux_sym__name_repeat1, 2), SHIFT_REPEAT(9),
  [49] = {.count = 1, .reusable = true}, REDUCE(sym_funcBody, 1),
  [51] = {.count = 1, .reusable = true}, REDUCE(sym_typeUse, 4),
  [53] = {.count = 1, .reusable = true}, SHIFT(24),
  [55] = {.count = 1, .reusable = true}, SHIFT(35),
  [57] = {.count = 1, .reusable = true}, REDUCE(sym_instr, 1),
  [59] = {.count = 1, .reusable = true}, SHIFT(39),
  [61] = {.count = 2, .reusable = true}, REDUCE(aux_sym_module_repeat1, 2), SHIFT_REPEAT(41),
  [64] = {.count = 1, .reusable = true}, REDUCE(aux_sym_module_repeat1, 2),
  [66] = {.count = 1, .reusable = true}, SHIFT(36),
  [68] = {.count = 1, .reusable = true}, SHIFT(5),
  [70] = {.count = 1, .reusable = true}, SHIFT(7),
  [72] = {.count = 1, .reusable = true}, REDUCE(sym_VAR, 1),
  [74] = {.count = 1, .reusable = true}, SHIFT(28),
  [76] = {.count = 1, .reusable = true}, REDUCE(sym_func, 4),
  [78] = {.count = 1, .reusable = true}, REDUCE(sym_moduleField, 1),
  [80] = {.count = 1, .reusable = true}, REDUCE(sym_func, 5),
  [82] = {.count = 1, .reusable = true}, REDUCE(sym_func, 3),
  [84] = {.count = 1, .reusable = true}, REDUCE(sym_funcField, 2),
  [86] = {.count = 1, .reusable = true}, SHIFT(37),
  [88] = {.count = 1, .reusable = true}, SHIFT(26),
  [90] = {.count = 1, .reusable = true}, SHIFT(18),
  [92] = {.count = 1, .reusable = true}, REDUCE(sym_funcResultBody, 1),
  [94] = {.count = 1, .reusable = true}, REDUCE(sym_funcFieldBody, 1),
  [96] = {.count = 1, .reusable = true}, REDUCE(sym_module, 4),
  [98] = {.count = 1, .reusable = true}, SHIFT(11),
  [100] = {.count = 1, .reusable = true}, REDUCE(sym_funcField, 3),
  [102] = {.count = 1, .reusable = true}, SHIFT(6),
  [104] = {.count = 1, .reusable = true}, REDUCE(sym_module, 5),
  [106] = {.count = 1, .reusable = true}, REDUCE(sym_module, 3),
  [108] = {.count = 1, .reusable = true}, SHIFT(3),
  [110] = {.count = 1, .reusable = true}, REDUCE(sym_file, 1),
  [112] = {.count = 1, .reusable = true},  ACCEPT_INPUT(),
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
