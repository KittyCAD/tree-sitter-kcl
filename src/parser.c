#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 36
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 31
#define ALIAS_COUNT 0
#define TOKEN_COUNT 16
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 1

enum {
  anon_sym_let = 1,
  anon_sym_EQ = 2,
  anon_sym_fn = 3,
  aux_sym_identifier_token1 = 4,
  anon_sym_EQ_GT = 5,
  anon_sym_LPAREN = 6,
  anon_sym_COMMA = 7,
  anon_sym_RPAREN = 8,
  anon_sym_LBRACE = 9,
  anon_sym_RBRACE = 10,
  anon_sym_return = 11,
  anon_sym_DQUOTE = 12,
  sym_string_content = 13,
  sym_escape_sequence = 14,
  sym_number = 15,
  sym_kcl_program = 16,
  sym__definition = 17,
  sym_non_fn_definition = 18,
  sym_fn_definition = 19,
  sym_identifier = 20,
  sym__value = 21,
  sym_function = 22,
  sym_parameter_list = 23,
  sym_function_body = 24,
  sym__body_item = 25,
  sym_return_stmt = 26,
  sym_string = 27,
  aux_sym__string_content = 28,
  aux_sym_kcl_program_repeat1 = 29,
  aux_sym_parameter_list_repeat1 = 30,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_let] = "let",
  [anon_sym_EQ] = "=",
  [anon_sym_fn] = "fn",
  [aux_sym_identifier_token1] = "identifier_token1",
  [anon_sym_EQ_GT] = "=>",
  [anon_sym_LPAREN] = "(",
  [anon_sym_COMMA] = ",",
  [anon_sym_RPAREN] = ")",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_return] = "return",
  [anon_sym_DQUOTE] = "\"",
  [sym_string_content] = "string_content",
  [sym_escape_sequence] = "escape_sequence",
  [sym_number] = "number",
  [sym_kcl_program] = "kcl_program",
  [sym__definition] = "_definition",
  [sym_non_fn_definition] = "non_fn_definition",
  [sym_fn_definition] = "fn_definition",
  [sym_identifier] = "identifier",
  [sym__value] = "_value",
  [sym_function] = "function",
  [sym_parameter_list] = "parameter_list",
  [sym_function_body] = "function_body",
  [sym__body_item] = "_body_item",
  [sym_return_stmt] = "return_stmt",
  [sym_string] = "string",
  [aux_sym__string_content] = "_string_content",
  [aux_sym_kcl_program_repeat1] = "kcl_program_repeat1",
  [aux_sym_parameter_list_repeat1] = "parameter_list_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_let] = anon_sym_let,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_fn] = anon_sym_fn,
  [aux_sym_identifier_token1] = aux_sym_identifier_token1,
  [anon_sym_EQ_GT] = anon_sym_EQ_GT,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_return] = anon_sym_return,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [sym_string_content] = sym_string_content,
  [sym_escape_sequence] = sym_escape_sequence,
  [sym_number] = sym_number,
  [sym_kcl_program] = sym_kcl_program,
  [sym__definition] = sym__definition,
  [sym_non_fn_definition] = sym_non_fn_definition,
  [sym_fn_definition] = sym_fn_definition,
  [sym_identifier] = sym_identifier,
  [sym__value] = sym__value,
  [sym_function] = sym_function,
  [sym_parameter_list] = sym_parameter_list,
  [sym_function_body] = sym_function_body,
  [sym__body_item] = sym__body_item,
  [sym_return_stmt] = sym_return_stmt,
  [sym_string] = sym_string,
  [aux_sym__string_content] = aux_sym__string_content,
  [aux_sym_kcl_program_repeat1] = aux_sym_kcl_program_repeat1,
  [aux_sym_parameter_list_repeat1] = aux_sym_parameter_list_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_let] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_fn] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_identifier_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_EQ_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_return] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [sym_string_content] = {
    .visible = true,
    .named = true,
  },
  [sym_escape_sequence] = {
    .visible = true,
    .named = true,
  },
  [sym_number] = {
    .visible = true,
    .named = true,
  },
  [sym_kcl_program] = {
    .visible = true,
    .named = true,
  },
  [sym__definition] = {
    .visible = false,
    .named = true,
  },
  [sym_non_fn_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_fn_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym__value] = {
    .visible = false,
    .named = true,
  },
  [sym_function] = {
    .visible = true,
    .named = true,
  },
  [sym_parameter_list] = {
    .visible = true,
    .named = true,
  },
  [sym_function_body] = {
    .visible = true,
    .named = true,
  },
  [sym__body_item] = {
    .visible = false,
    .named = true,
  },
  [sym_return_stmt] = {
    .visible = true,
    .named = true,
  },
  [sym_string] = {
    .visible = true,
    .named = true,
  },
  [aux_sym__string_content] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_kcl_program_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_parameter_list_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(19);
      if (lookahead == '"') ADVANCE(32);
      if (lookahead == '(') ADVANCE(26);
      if (lookahead == ')') ADVANCE(28);
      if (lookahead == ',') ADVANCE(27);
      if (lookahead == '-') ADVANCE(5);
      if (lookahead == '0') ADVANCE(36);
      if (lookahead == '=') ADVANCE(22);
      if (lookahead == '\\') ADVANCE(16);
      if (lookahead == 'f') ADVANCE(10);
      if (lookahead == 'l') ADVANCE(8);
      if (lookahead == 'r') ADVANCE(9);
      if (lookahead == '{') ADVANCE(29);
      if (lookahead == '}') ADVANCE(30);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(18)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(37);
      END_STATE();
    case 1:
      if (lookahead == '\n') SKIP(2)
      if (lookahead == '"') ADVANCE(32);
      if (lookahead == '\\') ADVANCE(16);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(33);
      if (lookahead != 0) ADVANCE(34);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(32);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(2)
      END_STATE();
    case 3:
      if (lookahead == ')') ADVANCE(28);
      if (lookahead == ',') ADVANCE(27);
      if (lookahead == '=') ADVANCE(21);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(3)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(24);
      END_STATE();
    case 4:
      if (lookahead == '-') ADVANCE(17);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(39);
      END_STATE();
    case 5:
      if (lookahead == '0') ADVANCE(36);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(37);
      END_STATE();
    case 6:
      if (lookahead == '=') ADVANCE(7);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(6)
      END_STATE();
    case 7:
      if (lookahead == '>') ADVANCE(25);
      END_STATE();
    case 8:
      if (lookahead == 'e') ADVANCE(13);
      END_STATE();
    case 9:
      if (lookahead == 'e') ADVANCE(14);
      END_STATE();
    case 10:
      if (lookahead == 'n') ADVANCE(23);
      END_STATE();
    case 11:
      if (lookahead == 'n') ADVANCE(31);
      END_STATE();
    case 12:
      if (lookahead == 'r') ADVANCE(11);
      END_STATE();
    case 13:
      if (lookahead == 't') ADVANCE(20);
      END_STATE();
    case 14:
      if (lookahead == 't') ADVANCE(15);
      END_STATE();
    case 15:
      if (lookahead == 'u') ADVANCE(12);
      END_STATE();
    case 16:
      if (lookahead == '"' ||
          lookahead == '/' ||
          lookahead == '\\' ||
          lookahead == 'b' ||
          lookahead == 'f' ||
          lookahead == 'n' ||
          lookahead == 'r' ||
          lookahead == 't' ||
          lookahead == 'u') ADVANCE(35);
      END_STATE();
    case 17:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(39);
      END_STATE();
    case 18:
      if (eof) ADVANCE(19);
      if (lookahead == '"') ADVANCE(32);
      if (lookahead == '(') ADVANCE(26);
      if (lookahead == ')') ADVANCE(28);
      if (lookahead == ',') ADVANCE(27);
      if (lookahead == '-') ADVANCE(5);
      if (lookahead == '0') ADVANCE(36);
      if (lookahead == '=') ADVANCE(22);
      if (lookahead == 'f') ADVANCE(10);
      if (lookahead == 'l') ADVANCE(8);
      if (lookahead == 'r') ADVANCE(9);
      if (lookahead == '{') ADVANCE(29);
      if (lookahead == '}') ADVANCE(30);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(18)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(37);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_let);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '>') ADVANCE(25);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_fn);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(24);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_EQ_GT);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_return);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym_string_content);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(33);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(34);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym_string_content);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(34);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym_escape_sequence);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '.') ADVANCE(38);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(4);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '.') ADVANCE(38);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(4);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(37);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(4);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(38);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(39);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 1},
  [11] = {.lex_state = 1},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 1},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 3},
  [17] = {.lex_state = 3},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 3},
  [24] = {.lex_state = 3},
  [25] = {.lex_state = 3},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 6},
  [28] = {.lex_state = 3},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 3},
  [31] = {.lex_state = 6},
  [32] = {.lex_state = 6},
  [33] = {.lex_state = 6},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_let] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_fn] = ACTIONS(1),
    [anon_sym_EQ_GT] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_return] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [sym_escape_sequence] = ACTIONS(1),
    [sym_number] = ACTIONS(1),
  },
  [1] = {
    [sym_kcl_program] = STATE(29),
    [sym__definition] = STATE(6),
    [sym_non_fn_definition] = STATE(6),
    [sym_fn_definition] = STATE(6),
    [aux_sym_kcl_program_repeat1] = STATE(6),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_let] = ACTIONS(5),
    [anon_sym_fn] = ACTIONS(7),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 4,
    ACTIONS(5), 1,
      anon_sym_let,
    ACTIONS(7), 1,
      anon_sym_fn,
    ACTIONS(9), 1,
      anon_sym_return,
    STATE(34), 5,
      sym__definition,
      sym_non_fn_definition,
      sym_fn_definition,
      sym__body_item,
      sym_return_stmt,
  [17] = 4,
    ACTIONS(11), 1,
      ts_builtin_sym_end,
    ACTIONS(13), 1,
      anon_sym_let,
    ACTIONS(16), 1,
      anon_sym_fn,
    STATE(3), 4,
      sym__definition,
      sym_non_fn_definition,
      sym_fn_definition,
      aux_sym_kcl_program_repeat1,
  [33] = 5,
    ACTIONS(19), 1,
      anon_sym_LPAREN,
    ACTIONS(21), 1,
      anon_sym_DQUOTE,
    ACTIONS(23), 1,
      sym_number,
    STATE(33), 1,
      sym_parameter_list,
    STATE(12), 3,
      sym__value,
      sym_function,
      sym_string,
  [51] = 5,
    ACTIONS(19), 1,
      anon_sym_LPAREN,
    ACTIONS(21), 1,
      anon_sym_DQUOTE,
    ACTIONS(25), 1,
      sym_number,
    STATE(33), 1,
      sym_parameter_list,
    STATE(35), 3,
      sym__value,
      sym_function,
      sym_string,
  [69] = 4,
    ACTIONS(5), 1,
      anon_sym_let,
    ACTIONS(7), 1,
      anon_sym_fn,
    ACTIONS(27), 1,
      ts_builtin_sym_end,
    STATE(3), 4,
      sym__definition,
      sym_non_fn_definition,
      sym_fn_definition,
      aux_sym_kcl_program_repeat1,
  [85] = 1,
    ACTIONS(29), 4,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_fn,
      anon_sym_RBRACE,
  [92] = 1,
    ACTIONS(31), 4,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_fn,
      anon_sym_RBRACE,
  [99] = 1,
    ACTIONS(33), 4,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_fn,
      anon_sym_RBRACE,
  [106] = 3,
    ACTIONS(35), 1,
      anon_sym_DQUOTE,
    STATE(14), 1,
      aux_sym__string_content,
    ACTIONS(37), 2,
      sym_string_content,
      sym_escape_sequence,
  [117] = 3,
    ACTIONS(39), 1,
      anon_sym_DQUOTE,
    STATE(10), 1,
      aux_sym__string_content,
    ACTIONS(41), 2,
      sym_string_content,
      sym_escape_sequence,
  [128] = 1,
    ACTIONS(43), 4,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_fn,
      anon_sym_RBRACE,
  [135] = 1,
    ACTIONS(45), 4,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_fn,
      anon_sym_RBRACE,
  [142] = 3,
    ACTIONS(47), 1,
      anon_sym_DQUOTE,
    STATE(14), 1,
      aux_sym__string_content,
    ACTIONS(49), 2,
      sym_string_content,
      sym_escape_sequence,
  [153] = 1,
    ACTIONS(52), 4,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_fn,
      anon_sym_RBRACE,
  [160] = 1,
    ACTIONS(54), 3,
      anon_sym_EQ,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [166] = 3,
    ACTIONS(56), 1,
      aux_sym_identifier_token1,
    ACTIONS(58), 1,
      anon_sym_RPAREN,
    STATE(19), 1,
      sym_identifier,
  [176] = 3,
    ACTIONS(60), 1,
      anon_sym_COMMA,
    ACTIONS(63), 1,
      anon_sym_RPAREN,
    STATE(18), 1,
      aux_sym_parameter_list_repeat1,
  [186] = 3,
    ACTIONS(65), 1,
      anon_sym_COMMA,
    ACTIONS(67), 1,
      anon_sym_RPAREN,
    STATE(20), 1,
      aux_sym_parameter_list_repeat1,
  [196] = 3,
    ACTIONS(65), 1,
      anon_sym_COMMA,
    ACTIONS(69), 1,
      anon_sym_RPAREN,
    STATE(18), 1,
      aux_sym_parameter_list_repeat1,
  [206] = 3,
    ACTIONS(19), 1,
      anon_sym_LPAREN,
    STATE(13), 1,
      sym_function,
    STATE(33), 1,
      sym_parameter_list,
  [216] = 2,
    ACTIONS(71), 1,
      anon_sym_LBRACE,
    STATE(7), 1,
      sym_function_body,
  [223] = 2,
    ACTIONS(56), 1,
      aux_sym_identifier_token1,
    STATE(26), 1,
      sym_identifier,
  [230] = 2,
    ACTIONS(56), 1,
      aux_sym_identifier_token1,
    STATE(30), 1,
      sym_identifier,
  [237] = 2,
    ACTIONS(56), 1,
      aux_sym_identifier_token1,
    STATE(28), 1,
      sym_identifier,
  [244] = 1,
    ACTIONS(63), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [249] = 1,
    ACTIONS(73), 1,
      anon_sym_EQ_GT,
  [253] = 1,
    ACTIONS(75), 1,
      anon_sym_EQ,
  [257] = 1,
    ACTIONS(77), 1,
      ts_builtin_sym_end,
  [261] = 1,
    ACTIONS(79), 1,
      anon_sym_EQ,
  [265] = 1,
    ACTIONS(81), 1,
      anon_sym_EQ_GT,
  [269] = 1,
    ACTIONS(83), 1,
      anon_sym_EQ_GT,
  [273] = 1,
    ACTIONS(85), 1,
      anon_sym_EQ_GT,
  [277] = 1,
    ACTIONS(87), 1,
      anon_sym_RBRACE,
  [281] = 1,
    ACTIONS(89), 1,
      anon_sym_RBRACE,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 17,
  [SMALL_STATE(4)] = 33,
  [SMALL_STATE(5)] = 51,
  [SMALL_STATE(6)] = 69,
  [SMALL_STATE(7)] = 85,
  [SMALL_STATE(8)] = 92,
  [SMALL_STATE(9)] = 99,
  [SMALL_STATE(10)] = 106,
  [SMALL_STATE(11)] = 117,
  [SMALL_STATE(12)] = 128,
  [SMALL_STATE(13)] = 135,
  [SMALL_STATE(14)] = 142,
  [SMALL_STATE(15)] = 153,
  [SMALL_STATE(16)] = 160,
  [SMALL_STATE(17)] = 166,
  [SMALL_STATE(18)] = 176,
  [SMALL_STATE(19)] = 186,
  [SMALL_STATE(20)] = 196,
  [SMALL_STATE(21)] = 206,
  [SMALL_STATE(22)] = 216,
  [SMALL_STATE(23)] = 223,
  [SMALL_STATE(24)] = 230,
  [SMALL_STATE(25)] = 237,
  [SMALL_STATE(26)] = 244,
  [SMALL_STATE(27)] = 249,
  [SMALL_STATE(28)] = 253,
  [SMALL_STATE(29)] = 257,
  [SMALL_STATE(30)] = 261,
  [SMALL_STATE(31)] = 265,
  [SMALL_STATE(32)] = 269,
  [SMALL_STATE(33)] = 273,
  [SMALL_STATE(34)] = 277,
  [SMALL_STATE(35)] = 281,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_kcl_program, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_kcl_program_repeat1, 2),
  [13] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_kcl_program_repeat1, 2), SHIFT_REPEAT(24),
  [16] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_kcl_program_repeat1, 2), SHIFT_REPEAT(25),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_kcl_program, 1),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function, 3),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_body, 3),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 2),
  [35] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [39] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_non_fn_definition, 4),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fn_definition, 4),
  [47] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__string_content, 2),
  [49] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__string_content, 2), SHIFT_REPEAT(14),
  [52] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 3),
  [54] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identifier, 1),
  [56] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [58] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [60] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_parameter_list_repeat1, 2), SHIFT_REPEAT(23),
  [63] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_parameter_list_repeat1, 2),
  [65] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [67] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [69] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [71] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [73] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter_list, 3),
  [75] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [77] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [79] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter_list, 4),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter_list, 2),
  [85] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [87] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_return_stmt, 2),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_kcl(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
