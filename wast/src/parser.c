#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 11
#define STATE_COUNT 56
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 56
#define ALIAS_COUNT 0
#define TOKEN_COUNT 41
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 7

enum {
  anon_sym_ = 1,
  sym__format = 2,
  anon_sym_SEMI_SEMI = 3,
  anon_sym_LF = 4,
  anon_sym_LPAREN_SEMI = 5,
  anon_sym_SEMI_RPAREN = 6,
  aux_sym__blockchar_token1 = 7,
  aux_sym__blockchar_token2 = 8,
  aux_sym__blockchar_token3 = 9,
  sym__sign = 10,
  sym__digit = 11,
  sym__hexdigit = 12,
  anon_sym__ = 13,
  anon_sym_DOT = 14,
  aux_sym__float_token1 = 15,
  aux_sym__hexfloat_token1 = 16,
  anon_sym_DQUOTE = 17,
  anon_sym_BSLASH = 18,
  aux_sym__stringchar_token1 = 19,
  anon_sym_RBRACE = 20,
  aux_sym__char_token1 = 21,
  sym__ascii = 22,
  sym__asciiline = 23,
  sym__utf8cont = 24,
  aux_sym__utf8enc_token1 = 25,
  aux_sym__utf8enc_token2 = 26,
  aux_sym__utf8enc_token3 = 27,
  aux_sym__utf8enc_token4 = 28,
  aux_sym__utf8enc_token5 = 29,
  aux_sym__utf8enc_token6 = 30,
  aux_sym__utf8enc_token7 = 31,
  aux_sym__utf8enc_token8 = 32,
  aux_sym__utf8enc_token9 = 33,
  aux_sym__utf8enc_token10 = 34,
  aux_sym__utf8enc_token11 = 35,
  anon_sym_DOLLAR = 36,
  sym__idchar = 37,
  anon_sym_LPAREN = 38,
  anon_sym_module = 39,
  anon_sym_RPAREN = 40,
  sym_start = 41,
  sym__space = 42,
  sym__comment = 43,
  sym_linecomment = 44,
  sym__linechar = 45,
  sym_blockcomment = 46,
  sym__blockchar = 47,
  sym__utf8enc = 48,
  sym__utf8line = 49,
  sym__id = 50,
  sym_module = 51,
  aux_sym_start_repeat1 = 52,
  aux_sym_linecomment_repeat1 = 53,
  aux_sym_blockcomment_repeat1 = 54,
  aux_sym__id_repeat1 = 55,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_] = " ",
  [sym__format] = "_format",
  [anon_sym_SEMI_SEMI] = ";;",
  [anon_sym_LF] = "\n",
  [anon_sym_LPAREN_SEMI] = "(;",
  [anon_sym_SEMI_RPAREN] = ";)",
  [aux_sym__blockchar_token1] = "_blockchar_token1",
  [aux_sym__blockchar_token2] = "_blockchar_token2",
  [aux_sym__blockchar_token3] = "_blockchar_token3",
  [sym__sign] = "_sign",
  [sym__digit] = "_digit",
  [sym__hexdigit] = "_hexdigit",
  [anon_sym__] = "_",
  [anon_sym_DOT] = ".",
  [aux_sym__float_token1] = "_float_token1",
  [aux_sym__hexfloat_token1] = "_hexfloat_token1",
  [anon_sym_DQUOTE] = "\"",
  [anon_sym_BSLASH] = "\\",
  [aux_sym__stringchar_token1] = "_stringchar_token1",
  [anon_sym_RBRACE] = "}",
  [aux_sym__char_token1] = "_char_token1",
  [sym__ascii] = "_ascii",
  [sym__asciiline] = "_asciiline",
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
  [anon_sym_DOLLAR] = "$",
  [sym__idchar] = "_idchar",
  [anon_sym_LPAREN] = "(",
  [anon_sym_module] = "module",
  [anon_sym_RPAREN] = ")",
  [sym_start] = "start",
  [sym__space] = "_space",
  [sym__comment] = "_comment",
  [sym_linecomment] = "linecomment",
  [sym__linechar] = "_linechar",
  [sym_blockcomment] = "blockcomment",
  [sym__blockchar] = "_blockchar",
  [sym__utf8enc] = "_utf8enc",
  [sym__utf8line] = "_utf8line",
  [sym__id] = "_id",
  [sym_module] = "module",
  [aux_sym_start_repeat1] = "start_repeat1",
  [aux_sym_linecomment_repeat1] = "linecomment_repeat1",
  [aux_sym_blockcomment_repeat1] = "blockcomment_repeat1",
  [aux_sym__id_repeat1] = "_id_repeat1",
};

static TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_] = anon_sym_,
  [sym__format] = sym__format,
  [anon_sym_SEMI_SEMI] = anon_sym_SEMI_SEMI,
  [anon_sym_LF] = anon_sym_LF,
  [anon_sym_LPAREN_SEMI] = anon_sym_LPAREN_SEMI,
  [anon_sym_SEMI_RPAREN] = anon_sym_SEMI_RPAREN,
  [aux_sym__blockchar_token1] = aux_sym__blockchar_token1,
  [aux_sym__blockchar_token2] = aux_sym__blockchar_token2,
  [aux_sym__blockchar_token3] = aux_sym__blockchar_token3,
  [sym__sign] = sym__sign,
  [sym__digit] = sym__digit,
  [sym__hexdigit] = sym__hexdigit,
  [anon_sym__] = anon_sym__,
  [anon_sym_DOT] = anon_sym_DOT,
  [aux_sym__float_token1] = aux_sym__float_token1,
  [aux_sym__hexfloat_token1] = aux_sym__hexfloat_token1,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [anon_sym_BSLASH] = anon_sym_BSLASH,
  [aux_sym__stringchar_token1] = aux_sym__stringchar_token1,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [aux_sym__char_token1] = aux_sym__char_token1,
  [sym__ascii] = sym__ascii,
  [sym__asciiline] = sym__asciiline,
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
  [anon_sym_DOLLAR] = anon_sym_DOLLAR,
  [sym__idchar] = sym__idchar,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_module] = anon_sym_module,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [sym_start] = sym_start,
  [sym__space] = sym__space,
  [sym__comment] = sym__comment,
  [sym_linecomment] = sym_linecomment,
  [sym__linechar] = sym__linechar,
  [sym_blockcomment] = sym_blockcomment,
  [sym__blockchar] = sym__blockchar,
  [sym__utf8enc] = sym__utf8enc,
  [sym__utf8line] = sym__utf8line,
  [sym__id] = sym__id,
  [sym_module] = sym_module,
  [aux_sym_start_repeat1] = aux_sym_start_repeat1,
  [aux_sym_linecomment_repeat1] = aux_sym_linecomment_repeat1,
  [aux_sym_blockcomment_repeat1] = aux_sym_blockcomment_repeat1,
  [aux_sym__id_repeat1] = aux_sym__id_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_] = {
    .visible = true,
    .named = false,
  },
  [sym__format] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_SEMI_SEMI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LF] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN_SEMI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SEMI_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [aux_sym__blockchar_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__blockchar_token2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__blockchar_token3] = {
    .visible = false,
    .named = false,
  },
  [sym__sign] = {
    .visible = false,
    .named = true,
  },
  [sym__digit] = {
    .visible = false,
    .named = true,
  },
  [sym__hexdigit] = {
    .visible = false,
    .named = true,
  },
  [anon_sym__] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOT] = {
    .visible = true,
    .named = false,
  },
  [aux_sym__float_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__hexfloat_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BSLASH] = {
    .visible = true,
    .named = false,
  },
  [aux_sym__stringchar_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym__char_token1] = {
    .visible = false,
    .named = false,
  },
  [sym__ascii] = {
    .visible = false,
    .named = true,
  },
  [sym__asciiline] = {
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
  [anon_sym_DOLLAR] = {
    .visible = true,
    .named = false,
  },
  [sym__idchar] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_module] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [sym_start] = {
    .visible = true,
    .named = true,
  },
  [sym__space] = {
    .visible = false,
    .named = true,
  },
  [sym__comment] = {
    .visible = false,
    .named = true,
  },
  [sym_linecomment] = {
    .visible = true,
    .named = true,
  },
  [sym__linechar] = {
    .visible = false,
    .named = true,
  },
  [sym_blockcomment] = {
    .visible = true,
    .named = true,
  },
  [sym__blockchar] = {
    .visible = false,
    .named = true,
  },
  [sym__utf8enc] = {
    .visible = false,
    .named = true,
  },
  [sym__utf8line] = {
    .visible = false,
    .named = true,
  },
  [sym__id] = {
    .visible = false,
    .named = true,
  },
  [sym_module] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_start_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_linecomment_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_blockcomment_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__id_repeat1] = {
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
      if (eof) ADVANCE(14);
      if (lookahead == '\n') ADVANCE(18);
      if (lookahead == ' ') ADVANCE(15);
      if (lookahead == '"') ADVANCE(26);
      if (lookahead == '$') ADVANCE(43);
      if (lookahead == '(') ADVANCE(45);
      if (lookahead == ')') ADVANCE(48);
      if (lookahead == '.') ADVANCE(25);
      if (lookahead == ';') ADVANCE(29);
      if (lookahead == '\\') ADVANCE(27);
      if (lookahead == '_') ADVANCE(24);
      if (lookahead == '}') ADVANCE(28);
      if (lookahead == 224) ADVANCE(21);
      if (lookahead == 237) ADVANCE(21);
      if (lookahead == 240) ADVANCE(21);
      if (lookahead == 244) ADVANCE(21);
      if (lookahead == '\t' ||
          lookahead == '\r') ADVANCE(16);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(21);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(21);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(21);
      if ((241 <= lookahead && lookahead <= 243)) ADVANCE(21);
      if (lookahead == '\'' ||
          lookahead == 'n' ||
          lookahead == 'r' ||
          lookahead == 't') ADVANCE(21);
      if (('[' <= lookahead && lookahead <= ']') ||
          lookahead == '`' ||
          lookahead == '{') ADVANCE(21);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(21);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(21);
      if (lookahead == 192 ||
          lookahead == 193 ||
          (245 <= lookahead && lookahead <= 255)) ADVANCE(21);
      if ((225 <= lookahead && lookahead <= 239)) ADVANCE(21);
      if ((128 <= lookahead && lookahead <= 143)) ADVANCE(21);
      if ((144 <= lookahead && lookahead <= 159)) ADVANCE(21);
      if ((0 <= lookahead && lookahead <= 31) ||
          lookahead == 127) ADVANCE(21);
      if ((194 <= lookahead && lookahead <= 223)) ADVANCE(21);
      if ((160 <= lookahead && lookahead <= 191)) ADVANCE(21);
      if (('!' <= lookahead && lookahead <= '~')) ADVANCE(21);
      if (lookahead != 0) ADVANCE(21);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(18);
      if (lookahead == 224) ADVANCE(33);
      if (lookahead == 237) ADVANCE(35);
      if (lookahead == 240) ADVANCE(38);
      if (lookahead == 244) ADVANCE(40);
      if ((241 <= lookahead && lookahead <= 243)) ADVANCE(42);
      if ((225 <= lookahead && lookahead <= 239)) ADVANCE(37);
      if ((194 <= lookahead && lookahead <= 223)) ADVANCE(32);
      if ((128 <= lookahead && lookahead <= 191)) ADVANCE(31);
      if ((0 <= lookahead && lookahead <= 127)) ADVANCE(30);
      END_STATE();
    case 2:
      if (lookahead == ' ') ADVANCE(15);
      if (lookahead == '(') ADVANCE(5);
      if (lookahead == ')') ADVANCE(48);
      if (lookahead == ';') ADVANCE(7);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r') ADVANCE(16);
      if ((128 <= lookahead && lookahead <= 159)) ADVANCE(36);
      if ((160 <= lookahead && lookahead <= 191)) ADVANCE(34);
      if (lookahead == '!' ||
          ('#' <= lookahead && lookahead <= 'Z') ||
          lookahead == '\\' ||
          lookahead == '^' ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '|' ||
          lookahead == '~') ADVANCE(44);
      END_STATE();
    case 3:
      if (lookahead == '(') ADVANCE(6);
      if (lookahead == ';') ADVANCE(4);
      if (lookahead != 0) ADVANCE(21);
      END_STATE();
    case 4:
      if (lookahead == ')') ADVANCE(20);
      if (lookahead != 0) ADVANCE(22);
      END_STATE();
    case 5:
      if (lookahead == ';') ADVANCE(19);
      END_STATE();
    case 6:
      if (lookahead == ';') ADVANCE(19);
      if (lookahead != 0) ADVANCE(23);
      END_STATE();
    case 7:
      if (lookahead == ';') ADVANCE(17);
      END_STATE();
    case 8:
      if (lookahead == 'd') ADVANCE(12);
      END_STATE();
    case 9:
      if (lookahead == 'e') ADVANCE(47);
      END_STATE();
    case 10:
      if (lookahead == 'l') ADVANCE(9);
      END_STATE();
    case 11:
      if (lookahead == 'o') ADVANCE(8);
      END_STATE();
    case 12:
      if (lookahead == 'u') ADVANCE(10);
      END_STATE();
    case 13:
      if (eof) ADVANCE(14);
      if (lookahead == ' ') ADVANCE(15);
      if (lookahead == '$') ADVANCE(43);
      if (lookahead == '(') ADVANCE(46);
      if (lookahead == ')') ADVANCE(48);
      if (lookahead == ';') ADVANCE(7);
      if (lookahead == 'm') ADVANCE(11);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r') ADVANCE(16);
      if ((128 <= lookahead && lookahead <= 143)) ADVANCE(41);
      if ((144 <= lookahead && lookahead <= 191)) ADVANCE(39);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(anon_sym_);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(sym__format);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_SEMI_SEMI);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_LF);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_LPAREN_SEMI);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_SEMI_RPAREN);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(aux_sym__blockchar_token1);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(aux_sym__blockchar_token2);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(aux_sym__blockchar_token3);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym__);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_BSLASH);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(aux_sym__char_token1);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym__asciiline);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym__utf8cont);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(aux_sym__utf8enc_token1);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(aux_sym__utf8enc_token2);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(aux_sym__utf8enc_token3);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(aux_sym__utf8enc_token4);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(aux_sym__utf8enc_token5);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(aux_sym__utf8enc_token6);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(aux_sym__utf8enc_token7);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(aux_sym__utf8enc_token8);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(aux_sym__utf8enc_token9);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(aux_sym__utf8enc_token10);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(aux_sym__utf8enc_token11);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_DOLLAR);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym__idchar);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      if (lookahead == ';') ADVANCE(19);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(anon_sym_module);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 13},
  [2] = {.lex_state = 13},
  [3] = {.lex_state = 1},
  [4] = {.lex_state = 1},
  [5] = {.lex_state = 1},
  [6] = {.lex_state = 13},
  [7] = {.lex_state = 13},
  [8] = {.lex_state = 13},
  [9] = {.lex_state = 13},
  [10] = {.lex_state = 13},
  [11] = {.lex_state = 13},
  [12] = {.lex_state = 13},
  [13] = {.lex_state = 13},
  [14] = {.lex_state = 13},
  [15] = {.lex_state = 13},
  [16] = {.lex_state = 13},
  [17] = {.lex_state = 13},
  [18] = {.lex_state = 13},
  [19] = {.lex_state = 13},
  [20] = {.lex_state = 13},
  [21] = {.lex_state = 13},
  [22] = {.lex_state = 13},
  [23] = {.lex_state = 13},
  [24] = {.lex_state = 1},
  [25] = {.lex_state = 13},
  [26] = {.lex_state = 13},
  [27] = {.lex_state = 1},
  [28] = {.lex_state = 13},
  [29] = {.lex_state = 1},
  [30] = {.lex_state = 3},
  [31] = {.lex_state = 3},
  [32] = {.lex_state = 3},
  [33] = {.lex_state = 3},
  [34] = {.lex_state = 3},
  [35] = {.lex_state = 2},
  [36] = {.lex_state = 2},
  [37] = {.lex_state = 13},
  [38] = {.lex_state = 13},
  [39] = {.lex_state = 13},
  [40] = {.lex_state = 13},
  [41] = {.lex_state = 13},
  [42] = {.lex_state = 3},
  [43] = {.lex_state = 3},
  [44] = {.lex_state = 2},
  [45] = {.lex_state = 13},
  [46] = {.lex_state = 1},
  [47] = {.lex_state = 1},
  [48] = {.lex_state = 2},
  [49] = {.lex_state = 2},
  [50] = {.lex_state = 1},
  [51] = {.lex_state = 13},
  [52] = {.lex_state = 1},
  [53] = {.lex_state = 1},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 1},
};

static uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_] = ACTIONS(1),
    [sym__format] = ACTIONS(1),
    [anon_sym_LF] = ACTIONS(1),
    [aux_sym__blockchar_token1] = ACTIONS(1),
    [sym__sign] = ACTIONS(1),
    [sym__digit] = ACTIONS(1),
    [sym__hexdigit] = ACTIONS(1),
    [anon_sym__] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [aux_sym__float_token1] = ACTIONS(1),
    [aux_sym__hexfloat_token1] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_BSLASH] = ACTIONS(1),
    [aux_sym__stringchar_token1] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [aux_sym__char_token1] = ACTIONS(1),
    [sym__ascii] = ACTIONS(1),
    [sym__asciiline] = ACTIONS(1),
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
    [anon_sym_DOLLAR] = ACTIONS(1),
    [sym__idchar] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
  },
  [1] = {
    [sym_start] = STATE(54),
    [sym__space] = STATE(10),
    [sym__comment] = STATE(10),
    [sym_linecomment] = STATE(10),
    [sym_blockcomment] = STATE(10),
    [sym_module] = STATE(17),
    [aux_sym_start_repeat1] = STATE(10),
    [anon_sym_] = ACTIONS(3),
    [sym__format] = ACTIONS(3),
    [anon_sym_SEMI_SEMI] = ACTIONS(5),
    [anon_sym_LPAREN_SEMI] = ACTIONS(7),
    [anon_sym_LPAREN] = ACTIONS(9),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 6,
    ACTIONS(16), 1,
      anon_sym_SEMI_SEMI,
    ACTIONS(19), 1,
      anon_sym_LPAREN_SEMI,
    ACTIONS(22), 1,
      anon_sym_LPAREN,
    ACTIONS(13), 2,
      anon_sym_,
      sym__format,
    ACTIONS(11), 4,
      ts_builtin_sym_end,
      anon_sym_DOLLAR,
      anon_sym_module,
      anon_sym_RPAREN,
    STATE(2), 5,
      sym__space,
      sym__comment,
      sym_linecomment,
      sym_blockcomment,
      aux_sym_start_repeat1,
  [27] = 10,
    ACTIONS(24), 1,
      anon_sym_LF,
    ACTIONS(26), 1,
      sym__asciiline,
    ACTIONS(28), 1,
      aux_sym__utf8enc_token1,
    ACTIONS(30), 1,
      aux_sym__utf8enc_token2,
    ACTIONS(32), 1,
      aux_sym__utf8enc_token4,
    ACTIONS(34), 1,
      aux_sym__utf8enc_token6,
    ACTIONS(36), 1,
      aux_sym__utf8enc_token7,
    ACTIONS(38), 1,
      aux_sym__utf8enc_token9,
    ACTIONS(40), 1,
      aux_sym__utf8enc_token11,
    STATE(5), 4,
      sym__linechar,
      sym__utf8enc,
      sym__utf8line,
      aux_sym_linecomment_repeat1,
  [61] = 10,
    ACTIONS(42), 1,
      anon_sym_LF,
    ACTIONS(44), 1,
      sym__asciiline,
    ACTIONS(47), 1,
      aux_sym__utf8enc_token1,
    ACTIONS(50), 1,
      aux_sym__utf8enc_token2,
    ACTIONS(53), 1,
      aux_sym__utf8enc_token4,
    ACTIONS(56), 1,
      aux_sym__utf8enc_token6,
    ACTIONS(59), 1,
      aux_sym__utf8enc_token7,
    ACTIONS(62), 1,
      aux_sym__utf8enc_token9,
    ACTIONS(65), 1,
      aux_sym__utf8enc_token11,
    STATE(4), 4,
      sym__linechar,
      sym__utf8enc,
      sym__utf8line,
      aux_sym_linecomment_repeat1,
  [95] = 10,
    ACTIONS(28), 1,
      aux_sym__utf8enc_token1,
    ACTIONS(30), 1,
      aux_sym__utf8enc_token2,
    ACTIONS(32), 1,
      aux_sym__utf8enc_token4,
    ACTIONS(34), 1,
      aux_sym__utf8enc_token6,
    ACTIONS(36), 1,
      aux_sym__utf8enc_token7,
    ACTIONS(38), 1,
      aux_sym__utf8enc_token9,
    ACTIONS(40), 1,
      aux_sym__utf8enc_token11,
    ACTIONS(68), 1,
      anon_sym_LF,
    ACTIONS(70), 1,
      sym__asciiline,
    STATE(4), 4,
      sym__linechar,
      sym__utf8enc,
      sym__utf8line,
      aux_sym_linecomment_repeat1,
  [129] = 7,
    ACTIONS(5), 1,
      anon_sym_SEMI_SEMI,
    ACTIONS(7), 1,
      anon_sym_LPAREN_SEMI,
    ACTIONS(74), 1,
      anon_sym_DOLLAR,
    ACTIONS(76), 1,
      anon_sym_RPAREN,
    STATE(11), 1,
      sym__id,
    ACTIONS(72), 2,
      anon_sym_,
      sym__format,
    STATE(9), 5,
      sym__space,
      sym__comment,
      sym_linecomment,
      sym_blockcomment,
      aux_sym_start_repeat1,
  [156] = 7,
    ACTIONS(5), 1,
      anon_sym_SEMI_SEMI,
    ACTIONS(7), 1,
      anon_sym_LPAREN_SEMI,
    ACTIONS(74), 1,
      anon_sym_DOLLAR,
    ACTIONS(80), 1,
      anon_sym_RPAREN,
    STATE(15), 1,
      sym__id,
    ACTIONS(78), 2,
      anon_sym_,
      sym__format,
    STATE(8), 5,
      sym__space,
      sym__comment,
      sym_linecomment,
      sym_blockcomment,
      aux_sym_start_repeat1,
  [183] = 7,
    ACTIONS(5), 1,
      anon_sym_SEMI_SEMI,
    ACTIONS(7), 1,
      anon_sym_LPAREN_SEMI,
    ACTIONS(74), 1,
      anon_sym_DOLLAR,
    ACTIONS(76), 1,
      anon_sym_RPAREN,
    STATE(11), 1,
      sym__id,
    ACTIONS(82), 2,
      anon_sym_,
      sym__format,
    STATE(2), 5,
      sym__space,
      sym__comment,
      sym_linecomment,
      sym_blockcomment,
      aux_sym_start_repeat1,
  [210] = 7,
    ACTIONS(5), 1,
      anon_sym_SEMI_SEMI,
    ACTIONS(7), 1,
      anon_sym_LPAREN_SEMI,
    ACTIONS(74), 1,
      anon_sym_DOLLAR,
    ACTIONS(84), 1,
      anon_sym_RPAREN,
    STATE(18), 1,
      sym__id,
    ACTIONS(82), 2,
      anon_sym_,
      sym__format,
    STATE(2), 5,
      sym__space,
      sym__comment,
      sym_linecomment,
      sym_blockcomment,
      aux_sym_start_repeat1,
  [237] = 6,
    ACTIONS(5), 1,
      anon_sym_SEMI_SEMI,
    ACTIONS(7), 1,
      anon_sym_LPAREN_SEMI,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    STATE(22), 1,
      sym_module,
    ACTIONS(82), 2,
      anon_sym_,
      sym__format,
    STATE(2), 5,
      sym__space,
      sym__comment,
      sym_linecomment,
      sym_blockcomment,
      aux_sym_start_repeat1,
  [261] = 5,
    ACTIONS(5), 1,
      anon_sym_SEMI_SEMI,
    ACTIONS(7), 1,
      anon_sym_LPAREN_SEMI,
    ACTIONS(84), 1,
      anon_sym_RPAREN,
    ACTIONS(86), 2,
      anon_sym_,
      sym__format,
    STATE(16), 5,
      sym__space,
      sym__comment,
      sym_linecomment,
      sym_blockcomment,
      aux_sym_start_repeat1,
  [282] = 5,
    ACTIONS(5), 1,
      anon_sym_SEMI_SEMI,
    ACTIONS(7), 1,
      anon_sym_LPAREN_SEMI,
    ACTIONS(88), 1,
      ts_builtin_sym_end,
    ACTIONS(82), 2,
      anon_sym_,
      sym__format,
    STATE(2), 5,
      sym__space,
      sym__comment,
      sym_linecomment,
      sym_blockcomment,
      aux_sym_start_repeat1,
  [303] = 5,
    ACTIONS(5), 1,
      anon_sym_SEMI_SEMI,
    ACTIONS(7), 1,
      anon_sym_LPAREN_SEMI,
    ACTIONS(84), 1,
      anon_sym_RPAREN,
    ACTIONS(82), 2,
      anon_sym_,
      sym__format,
    STATE(2), 5,
      sym__space,
      sym__comment,
      sym_linecomment,
      sym_blockcomment,
      aux_sym_start_repeat1,
  [324] = 5,
    ACTIONS(5), 1,
      anon_sym_SEMI_SEMI,
    ACTIONS(7), 1,
      anon_sym_LPAREN_SEMI,
    ACTIONS(90), 1,
      anon_sym_RPAREN,
    ACTIONS(82), 2,
      anon_sym_,
      sym__format,
    STATE(2), 5,
      sym__space,
      sym__comment,
      sym_linecomment,
      sym_blockcomment,
      aux_sym_start_repeat1,
  [345] = 5,
    ACTIONS(5), 1,
      anon_sym_SEMI_SEMI,
    ACTIONS(7), 1,
      anon_sym_LPAREN_SEMI,
    ACTIONS(76), 1,
      anon_sym_RPAREN,
    ACTIONS(92), 2,
      anon_sym_,
      sym__format,
    STATE(13), 5,
      sym__space,
      sym__comment,
      sym_linecomment,
      sym_blockcomment,
      aux_sym_start_repeat1,
  [366] = 5,
    ACTIONS(5), 1,
      anon_sym_SEMI_SEMI,
    ACTIONS(7), 1,
      anon_sym_LPAREN_SEMI,
    ACTIONS(94), 1,
      anon_sym_RPAREN,
    ACTIONS(82), 2,
      anon_sym_,
      sym__format,
    STATE(2), 5,
      sym__space,
      sym__comment,
      sym_linecomment,
      sym_blockcomment,
      aux_sym_start_repeat1,
  [387] = 5,
    ACTIONS(5), 1,
      anon_sym_SEMI_SEMI,
    ACTIONS(7), 1,
      anon_sym_LPAREN_SEMI,
    ACTIONS(96), 1,
      ts_builtin_sym_end,
    ACTIONS(98), 2,
      anon_sym_,
      sym__format,
    STATE(21), 5,
      sym__space,
      sym__comment,
      sym_linecomment,
      sym_blockcomment,
      aux_sym_start_repeat1,
  [408] = 5,
    ACTIONS(5), 1,
      anon_sym_SEMI_SEMI,
    ACTIONS(7), 1,
      anon_sym_LPAREN_SEMI,
    ACTIONS(94), 1,
      anon_sym_RPAREN,
    ACTIONS(100), 2,
      anon_sym_,
      sym__format,
    STATE(14), 5,
      sym__space,
      sym__comment,
      sym_linecomment,
      sym_blockcomment,
      aux_sym_start_repeat1,
  [429] = 5,
    ACTIONS(5), 1,
      anon_sym_SEMI_SEMI,
    ACTIONS(7), 1,
      anon_sym_LPAREN_SEMI,
    ACTIONS(104), 1,
      anon_sym_module,
    ACTIONS(102), 2,
      anon_sym_,
      sym__format,
    STATE(20), 5,
      sym__space,
      sym__comment,
      sym_linecomment,
      sym_blockcomment,
      aux_sym_start_repeat1,
  [450] = 5,
    ACTIONS(5), 1,
      anon_sym_SEMI_SEMI,
    ACTIONS(7), 1,
      anon_sym_LPAREN_SEMI,
    ACTIONS(106), 1,
      anon_sym_module,
    ACTIONS(82), 2,
      anon_sym_,
      sym__format,
    STATE(2), 5,
      sym__space,
      sym__comment,
      sym_linecomment,
      sym_blockcomment,
      aux_sym_start_repeat1,
  [471] = 5,
    ACTIONS(5), 1,
      anon_sym_SEMI_SEMI,
    ACTIONS(7), 1,
      anon_sym_LPAREN_SEMI,
    ACTIONS(108), 1,
      ts_builtin_sym_end,
    ACTIONS(82), 2,
      anon_sym_,
      sym__format,
    STATE(2), 5,
      sym__space,
      sym__comment,
      sym_linecomment,
      sym_blockcomment,
      aux_sym_start_repeat1,
  [492] = 5,
    ACTIONS(5), 1,
      anon_sym_SEMI_SEMI,
    ACTIONS(7), 1,
      anon_sym_LPAREN_SEMI,
    ACTIONS(108), 1,
      ts_builtin_sym_end,
    ACTIONS(110), 2,
      anon_sym_,
      sym__format,
    STATE(12), 5,
      sym__space,
      sym__comment,
      sym_linecomment,
      sym_blockcomment,
      aux_sym_start_repeat1,
  [513] = 2,
    ACTIONS(114), 1,
      anon_sym_LPAREN,
    ACTIONS(112), 8,
      ts_builtin_sym_end,
      anon_sym_,
      sym__format,
      anon_sym_SEMI_SEMI,
      anon_sym_LPAREN_SEMI,
      anon_sym_DOLLAR,
      anon_sym_module,
      anon_sym_RPAREN,
  [527] = 1,
    ACTIONS(116), 9,
      anon_sym_LF,
      sym__asciiline,
      aux_sym__utf8enc_token1,
      aux_sym__utf8enc_token2,
      aux_sym__utf8enc_token4,
      aux_sym__utf8enc_token6,
      aux_sym__utf8enc_token7,
      aux_sym__utf8enc_token9,
      aux_sym__utf8enc_token11,
  [539] = 2,
    ACTIONS(120), 1,
      anon_sym_LPAREN,
    ACTIONS(118), 8,
      ts_builtin_sym_end,
      anon_sym_,
      sym__format,
      anon_sym_SEMI_SEMI,
      anon_sym_LPAREN_SEMI,
      anon_sym_DOLLAR,
      anon_sym_module,
      anon_sym_RPAREN,
  [553] = 2,
    ACTIONS(124), 1,
      anon_sym_LPAREN,
    ACTIONS(122), 8,
      ts_builtin_sym_end,
      anon_sym_,
      sym__format,
      anon_sym_SEMI_SEMI,
      anon_sym_LPAREN_SEMI,
      anon_sym_DOLLAR,
      anon_sym_module,
      anon_sym_RPAREN,
  [567] = 1,
    ACTIONS(126), 9,
      anon_sym_LF,
      sym__asciiline,
      aux_sym__utf8enc_token1,
      aux_sym__utf8enc_token2,
      aux_sym__utf8enc_token4,
      aux_sym__utf8enc_token6,
      aux_sym__utf8enc_token7,
      aux_sym__utf8enc_token9,
      aux_sym__utf8enc_token11,
  [579] = 2,
    ACTIONS(130), 1,
      anon_sym_LPAREN,
    ACTIONS(128), 8,
      ts_builtin_sym_end,
      anon_sym_,
      sym__format,
      anon_sym_SEMI_SEMI,
      anon_sym_LPAREN_SEMI,
      anon_sym_DOLLAR,
      anon_sym_module,
      anon_sym_RPAREN,
  [593] = 1,
    ACTIONS(132), 9,
      anon_sym_LF,
      sym__asciiline,
      aux_sym__utf8enc_token1,
      aux_sym__utf8enc_token2,
      aux_sym__utf8enc_token4,
      aux_sym__utf8enc_token6,
      aux_sym__utf8enc_token7,
      aux_sym__utf8enc_token9,
      aux_sym__utf8enc_token11,
  [605] = 4,
    ACTIONS(134), 1,
      anon_sym_LPAREN_SEMI,
    ACTIONS(136), 1,
      anon_sym_SEMI_RPAREN,
    ACTIONS(138), 3,
      aux_sym__blockchar_token1,
      aux_sym__blockchar_token2,
      aux_sym__blockchar_token3,
    STATE(34), 3,
      sym_blockcomment,
      sym__blockchar,
      aux_sym_blockcomment_repeat1,
  [622] = 4,
    ACTIONS(134), 1,
      anon_sym_LPAREN_SEMI,
    ACTIONS(140), 1,
      anon_sym_SEMI_RPAREN,
    ACTIONS(142), 3,
      aux_sym__blockchar_token1,
      aux_sym__blockchar_token2,
      aux_sym__blockchar_token3,
    STATE(30), 3,
      sym_blockcomment,
      sym__blockchar,
      aux_sym_blockcomment_repeat1,
  [639] = 4,
    ACTIONS(134), 1,
      anon_sym_LPAREN_SEMI,
    ACTIONS(144), 1,
      anon_sym_SEMI_RPAREN,
    ACTIONS(146), 3,
      aux_sym__blockchar_token1,
      aux_sym__blockchar_token2,
      aux_sym__blockchar_token3,
    STATE(33), 3,
      sym_blockcomment,
      sym__blockchar,
      aux_sym_blockcomment_repeat1,
  [656] = 4,
    ACTIONS(134), 1,
      anon_sym_LPAREN_SEMI,
    ACTIONS(148), 1,
      anon_sym_SEMI_RPAREN,
    ACTIONS(138), 3,
      aux_sym__blockchar_token1,
      aux_sym__blockchar_token2,
      aux_sym__blockchar_token3,
    STATE(34), 3,
      sym_blockcomment,
      sym__blockchar,
      aux_sym_blockcomment_repeat1,
  [673] = 4,
    ACTIONS(150), 1,
      anon_sym_LPAREN_SEMI,
    ACTIONS(153), 1,
      anon_sym_SEMI_RPAREN,
    ACTIONS(155), 3,
      aux_sym__blockchar_token1,
      aux_sym__blockchar_token2,
      aux_sym__blockchar_token3,
    STATE(34), 3,
      sym_blockcomment,
      sym__blockchar,
      aux_sym_blockcomment_repeat1,
  [690] = 3,
    ACTIONS(160), 1,
      sym__idchar,
    STATE(35), 1,
      aux_sym__id_repeat1,
    ACTIONS(158), 5,
      anon_sym_,
      sym__format,
      anon_sym_SEMI_SEMI,
      anon_sym_LPAREN_SEMI,
      anon_sym_RPAREN,
  [704] = 3,
    ACTIONS(165), 1,
      sym__idchar,
    STATE(35), 1,
      aux_sym__id_repeat1,
    ACTIONS(163), 5,
      anon_sym_,
      sym__format,
      anon_sym_SEMI_SEMI,
      anon_sym_LPAREN_SEMI,
      anon_sym_RPAREN,
  [718] = 1,
    ACTIONS(167), 5,
      ts_builtin_sym_end,
      anon_sym_,
      sym__format,
      anon_sym_SEMI_SEMI,
      anon_sym_LPAREN_SEMI,
  [726] = 1,
    ACTIONS(169), 5,
      ts_builtin_sym_end,
      anon_sym_,
      sym__format,
      anon_sym_SEMI_SEMI,
      anon_sym_LPAREN_SEMI,
  [734] = 1,
    ACTIONS(171), 5,
      ts_builtin_sym_end,
      anon_sym_,
      sym__format,
      anon_sym_SEMI_SEMI,
      anon_sym_LPAREN_SEMI,
  [742] = 1,
    ACTIONS(173), 5,
      ts_builtin_sym_end,
      anon_sym_,
      sym__format,
      anon_sym_SEMI_SEMI,
      anon_sym_LPAREN_SEMI,
  [750] = 1,
    ACTIONS(175), 5,
      ts_builtin_sym_end,
      anon_sym_,
      sym__format,
      anon_sym_SEMI_SEMI,
      anon_sym_LPAREN_SEMI,
  [758] = 1,
    ACTIONS(128), 5,
      anon_sym_LPAREN_SEMI,
      anon_sym_SEMI_RPAREN,
      aux_sym__blockchar_token1,
      aux_sym__blockchar_token2,
      aux_sym__blockchar_token3,
  [766] = 1,
    ACTIONS(118), 5,
      anon_sym_LPAREN_SEMI,
      anon_sym_SEMI_RPAREN,
      aux_sym__blockchar_token1,
      aux_sym__blockchar_token2,
      aux_sym__blockchar_token3,
  [774] = 2,
    ACTIONS(177), 1,
      sym__idchar,
    STATE(36), 1,
      aux_sym__id_repeat1,
  [781] = 1,
    ACTIONS(179), 1,
      aux_sym__utf8enc_token8,
  [785] = 1,
    ACTIONS(181), 1,
      sym__utf8cont,
  [789] = 1,
    ACTIONS(183), 1,
      sym__utf8cont,
  [793] = 1,
    ACTIONS(183), 1,
      aux_sym__utf8enc_token5,
  [797] = 1,
    ACTIONS(183), 1,
      aux_sym__utf8enc_token3,
  [801] = 1,
    ACTIONS(185), 1,
      sym__utf8cont,
  [805] = 1,
    ACTIONS(179), 1,
      aux_sym__utf8enc_token10,
  [809] = 1,
    ACTIONS(187), 1,
      sym__utf8cont,
  [813] = 1,
    ACTIONS(179), 1,
      sym__utf8cont,
  [817] = 1,
    ACTIONS(189), 1,
      ts_builtin_sym_end,
  [821] = 1,
    ACTIONS(191), 1,
      sym__utf8cont,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 27,
  [SMALL_STATE(4)] = 61,
  [SMALL_STATE(5)] = 95,
  [SMALL_STATE(6)] = 129,
  [SMALL_STATE(7)] = 156,
  [SMALL_STATE(8)] = 183,
  [SMALL_STATE(9)] = 210,
  [SMALL_STATE(10)] = 237,
  [SMALL_STATE(11)] = 261,
  [SMALL_STATE(12)] = 282,
  [SMALL_STATE(13)] = 303,
  [SMALL_STATE(14)] = 324,
  [SMALL_STATE(15)] = 345,
  [SMALL_STATE(16)] = 366,
  [SMALL_STATE(17)] = 387,
  [SMALL_STATE(18)] = 408,
  [SMALL_STATE(19)] = 429,
  [SMALL_STATE(20)] = 450,
  [SMALL_STATE(21)] = 471,
  [SMALL_STATE(22)] = 492,
  [SMALL_STATE(23)] = 513,
  [SMALL_STATE(24)] = 527,
  [SMALL_STATE(25)] = 539,
  [SMALL_STATE(26)] = 553,
  [SMALL_STATE(27)] = 567,
  [SMALL_STATE(28)] = 579,
  [SMALL_STATE(29)] = 593,
  [SMALL_STATE(30)] = 605,
  [SMALL_STATE(31)] = 622,
  [SMALL_STATE(32)] = 639,
  [SMALL_STATE(33)] = 656,
  [SMALL_STATE(34)] = 673,
  [SMALL_STATE(35)] = 690,
  [SMALL_STATE(36)] = 704,
  [SMALL_STATE(37)] = 718,
  [SMALL_STATE(38)] = 726,
  [SMALL_STATE(39)] = 734,
  [SMALL_STATE(40)] = 742,
  [SMALL_STATE(41)] = 750,
  [SMALL_STATE(42)] = 758,
  [SMALL_STATE(43)] = 766,
  [SMALL_STATE(44)] = 774,
  [SMALL_STATE(45)] = 781,
  [SMALL_STATE(46)] = 785,
  [SMALL_STATE(47)] = 789,
  [SMALL_STATE(48)] = 793,
  [SMALL_STATE(49)] = 797,
  [SMALL_STATE(50)] = 801,
  [SMALL_STATE(51)] = 805,
  [SMALL_STATE(52)] = 809,
  [SMALL_STATE(53)] = 813,
  [SMALL_STATE(54)] = 817,
  [SMALL_STATE(55)] = 821,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.count = 0, .reusable = false},
  [1] = {.count = 1, .reusable = false}, RECOVER(),
  [3] = {.count = 1, .reusable = true}, SHIFT(10),
  [5] = {.count = 1, .reusable = true}, SHIFT(3),
  [7] = {.count = 1, .reusable = true}, SHIFT(32),
  [9] = {.count = 1, .reusable = false}, SHIFT(19),
  [11] = {.count = 1, .reusable = true}, REDUCE(aux_sym_start_repeat1, 2),
  [13] = {.count = 2, .reusable = true}, REDUCE(aux_sym_start_repeat1, 2), SHIFT_REPEAT(2),
  [16] = {.count = 2, .reusable = true}, REDUCE(aux_sym_start_repeat1, 2), SHIFT_REPEAT(3),
  [19] = {.count = 2, .reusable = true}, REDUCE(aux_sym_start_repeat1, 2), SHIFT_REPEAT(32),
  [22] = {.count = 1, .reusable = false}, REDUCE(aux_sym_start_repeat1, 2),
  [24] = {.count = 1, .reusable = true}, SHIFT(26),
  [26] = {.count = 1, .reusable = true}, SHIFT(5),
  [28] = {.count = 1, .reusable = true}, SHIFT(52),
  [30] = {.count = 1, .reusable = true}, SHIFT(49),
  [32] = {.count = 1, .reusable = true}, SHIFT(48),
  [34] = {.count = 1, .reusable = true}, SHIFT(47),
  [36] = {.count = 1, .reusable = true}, SHIFT(45),
  [38] = {.count = 1, .reusable = true}, SHIFT(51),
  [40] = {.count = 1, .reusable = true}, SHIFT(53),
  [42] = {.count = 1, .reusable = true}, REDUCE(aux_sym_linecomment_repeat1, 2),
  [44] = {.count = 2, .reusable = true}, REDUCE(aux_sym_linecomment_repeat1, 2), SHIFT_REPEAT(4),
  [47] = {.count = 2, .reusable = true}, REDUCE(aux_sym_linecomment_repeat1, 2), SHIFT_REPEAT(52),
  [50] = {.count = 2, .reusable = true}, REDUCE(aux_sym_linecomment_repeat1, 2), SHIFT_REPEAT(49),
  [53] = {.count = 2, .reusable = true}, REDUCE(aux_sym_linecomment_repeat1, 2), SHIFT_REPEAT(48),
  [56] = {.count = 2, .reusable = true}, REDUCE(aux_sym_linecomment_repeat1, 2), SHIFT_REPEAT(47),
  [59] = {.count = 2, .reusable = true}, REDUCE(aux_sym_linecomment_repeat1, 2), SHIFT_REPEAT(45),
  [62] = {.count = 2, .reusable = true}, REDUCE(aux_sym_linecomment_repeat1, 2), SHIFT_REPEAT(51),
  [65] = {.count = 2, .reusable = true}, REDUCE(aux_sym_linecomment_repeat1, 2), SHIFT_REPEAT(53),
  [68] = {.count = 1, .reusable = true}, SHIFT(23),
  [70] = {.count = 1, .reusable = true}, SHIFT(4),
  [72] = {.count = 1, .reusable = true}, SHIFT(9),
  [74] = {.count = 1, .reusable = true}, SHIFT(44),
  [76] = {.count = 1, .reusable = true}, SHIFT(38),
  [78] = {.count = 1, .reusable = true}, SHIFT(8),
  [80] = {.count = 1, .reusable = true}, SHIFT(37),
  [82] = {.count = 1, .reusable = true}, SHIFT(2),
  [84] = {.count = 1, .reusable = true}, SHIFT(39),
  [86] = {.count = 1, .reusable = true}, SHIFT(16),
  [88] = {.count = 1, .reusable = true}, REDUCE(sym_start, 3),
  [90] = {.count = 1, .reusable = true}, SHIFT(41),
  [92] = {.count = 1, .reusable = true}, SHIFT(13),
  [94] = {.count = 1, .reusable = true}, SHIFT(40),
  [96] = {.count = 1, .reusable = true}, REDUCE(sym_start, 1),
  [98] = {.count = 1, .reusable = true}, SHIFT(21),
  [100] = {.count = 1, .reusable = true}, SHIFT(14),
  [102] = {.count = 1, .reusable = true}, SHIFT(20),
  [104] = {.count = 1, .reusable = true}, SHIFT(7),
  [106] = {.count = 1, .reusable = true}, SHIFT(6),
  [108] = {.count = 1, .reusable = true}, REDUCE(sym_start, 2),
  [110] = {.count = 1, .reusable = true}, SHIFT(12),
  [112] = {.count = 1, .reusable = true}, REDUCE(sym_linecomment, 3),
  [114] = {.count = 1, .reusable = false}, REDUCE(sym_linecomment, 3),
  [116] = {.count = 1, .reusable = true}, REDUCE(sym__utf8enc, 3),
  [118] = {.count = 1, .reusable = true}, REDUCE(sym_blockcomment, 3),
  [120] = {.count = 1, .reusable = false}, REDUCE(sym_blockcomment, 3),
  [122] = {.count = 1, .reusable = true}, REDUCE(sym_linecomment, 2),
  [124] = {.count = 1, .reusable = false}, REDUCE(sym_linecomment, 2),
  [126] = {.count = 1, .reusable = true}, REDUCE(sym__utf8enc, 2),
  [128] = {.count = 1, .reusable = true}, REDUCE(sym_blockcomment, 2),
  [130] = {.count = 1, .reusable = false}, REDUCE(sym_blockcomment, 2),
  [132] = {.count = 1, .reusable = true}, REDUCE(sym__utf8enc, 4),
  [134] = {.count = 1, .reusable = true}, SHIFT(31),
  [136] = {.count = 1, .reusable = true}, SHIFT(43),
  [138] = {.count = 1, .reusable = true}, SHIFT(34),
  [140] = {.count = 1, .reusable = true}, SHIFT(42),
  [142] = {.count = 1, .reusable = true}, SHIFT(30),
  [144] = {.count = 1, .reusable = true}, SHIFT(28),
  [146] = {.count = 1, .reusable = true}, SHIFT(33),
  [148] = {.count = 1, .reusable = true}, SHIFT(25),
  [150] = {.count = 2, .reusable = true}, REDUCE(aux_sym_blockcomment_repeat1, 2), SHIFT_REPEAT(31),
  [153] = {.count = 1, .reusable = true}, REDUCE(aux_sym_blockcomment_repeat1, 2),
  [155] = {.count = 2, .reusable = true}, REDUCE(aux_sym_blockcomment_repeat1, 2), SHIFT_REPEAT(34),
  [158] = {.count = 1, .reusable = true}, REDUCE(aux_sym__id_repeat1, 2),
  [160] = {.count = 2, .reusable = true}, REDUCE(aux_sym__id_repeat1, 2), SHIFT_REPEAT(35),
  [163] = {.count = 1, .reusable = true}, REDUCE(sym__id, 2),
  [165] = {.count = 1, .reusable = true}, SHIFT(35),
  [167] = {.count = 1, .reusable = true}, REDUCE(sym_module, 3),
  [169] = {.count = 1, .reusable = true}, REDUCE(sym_module, 4),
  [171] = {.count = 1, .reusable = true}, REDUCE(sym_module, 5),
  [173] = {.count = 1, .reusable = true}, REDUCE(sym_module, 6),
  [175] = {.count = 1, .reusable = true}, REDUCE(sym_module, 7),
  [177] = {.count = 1, .reusable = true}, SHIFT(36),
  [179] = {.count = 1, .reusable = true}, SHIFT(55),
  [181] = {.count = 1, .reusable = true}, SHIFT(29),
  [183] = {.count = 1, .reusable = true}, SHIFT(50),
  [185] = {.count = 1, .reusable = true}, SHIFT(24),
  [187] = {.count = 1, .reusable = true}, SHIFT(27),
  [189] = {.count = 1, .reusable = true},  ACCEPT_INPUT(),
  [191] = {.count = 1, .reusable = true}, SHIFT(46),
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
