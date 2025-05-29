/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

const PREC = {
  mul: 12,
  div: 12,
  mod: 12,
  add: 11,
  sub: 11,
  pow: 13,
  cmp: 9,
  eq: 8,
  neq: 8,
  and: 7,
  or: 6,
  prefix: 20,
  pipe: 5, // |>
};

module.exports = grammar({
  name: 'kcl',

  rules: {

    kcl_program: $ => repeat($.body_item),

    body_item: $ => choice(
      $.expr_stmt,
      $.variable_declaration,
      $.return_stmt,
    ),

    expr_stmt: $ => $._expr,

    variable_declaration: $ => choice(
      $.fn_definition,
      $.non_fn_definition,
    ),

    fn_definition: $ => seq(
      'fn',
      $.identifier,
      '(',
      ')',
      '{',
      repeat($.body_item),
      '}',
    ),

    identifier: $ =>
      /[a-zA-Z][a-zA-Z0-9]*/,

    _expr: $ => choice(
      $.number,
      $.string,
      $.boolean,
      $.identifier,
      $.binary_expr,
      $.prefix_expr,
      $.fn_call,
    ),

    fn_call: $ => seq(
      $.identifier,
      '(',
      optional(field("unlabeledFirstArg", $._expr)),
      optional(seq(',', commaSep1(field("labeledArg", seq($.identifier, '=', $._expr))))),
      ')'
    ),

    function_body: $ => seq(
      '{',
      seq($.body_item),
      '}',
    ),

    return_stmt: $ => seq(
      'return',
      $._expr,
    ),

    non_fn_definition: $ => seq(
      $.identifier,
      '=',
      $._expr,
    ),

    string: $ => choice(
      seq('"', '"'),
      seq('"', $._string_content, '"'),
    ),

    boolean: $ => choice("true", "false"),

    _string_content: $ => repeat1(choice(
      $._normal_string_content,
      $.escape_sequence,
    )),

    _normal_string_content: _ => token.immediate(prec(1, /[^\\"\n]+/)),

    escape_sequence: _ => token.immediate(seq(
      '\\',
      /(\"|\\|\/|b|f|n|r|t|u)/,
    )),
    prefix_expr: ($) =>
      prec.right(
        PREC.prefix,
        seq(field("operator", $.prefix_operator), field("operand", $._expr)),
      ),

    prefix_operator: (_) => choice("!", "-"),

    binary_operator: (_) =>
      choice(
        "+",
        "-",
        "/",
        "*",
        "^",
        "%",
        "==",
        "!=",
        ">",
        ">=",
        "<",
        "<=",
        "|",
        "&",
        "|>",
      ),

    binary_expr: ($) => {
      const table = [
        [prec.right, PREC.pow, "^"],
        [
          prec.left,
          PREC.cmp,
          choice(">", "<", ">=", "<="),
        ],
        [prec.left, PREC.eq, "=="],
        [prec.left, PREC.neq, "!="],
        [prec.left, PREC.add, choice("+", "-",)],
        [prec.left, PREC.mul, choice("*", "/", "%")],
        [prec.right, PREC.and, "&"],
        [prec.left, PREC.or, "|"],
        [prec.left, PREC.pipe, "|>"],
      ];

      return choice(
        ...table.map(([fn, prec, op]) =>
          //@ts-ignore
          fn(
            prec,
            seq(
              field("lhs", $._expr),
              //@ts-ignore
              field("operator", alias(op, $.binary_operator)),
              field("rhs", $._expr),
            ),
          ),
        ),
      );
    },

    number: _ => {
      const decimalDigits = /\d+/;
      const signedInteger = seq(optional('-'), decimalDigits);
      const exponentPart = seq(choice('e', 'E'), signedInteger);

      const decimalIntegerLiteral = seq(
        optional('-'),
        choice(
          '0',
          seq(/[1-9]/, optional(decimalDigits)),
        ),
      );

      const decimalLiteral = choice(
        seq(decimalIntegerLiteral, '.', optional(decimalDigits), optional(exponentPart)),
        seq(decimalIntegerLiteral, optional(exponentPart)),
      );

      return token(decimalLiteral);
    },
  }


});
/**
* Creates a rule to match one or more of the rules separated by a comma
*
* @param {RuleOrLiteral} rule
*
* @return {SeqRule}
*
*/
function commaSep1(rule) {
  return seq(rule, repeat(seq(',', rule)));
}

/**
 * Creates a rule to optionally match one or more of the rules separated by a comma
 *
 * @param {RuleOrLiteral} rule
 *
 * @return {ChoiceRule}
 *
 */
function commaSep(rule) {
  return optional(commaSep1(rule));
}
