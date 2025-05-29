module.exports = grammar({
  name: 'kcl',

  rules: {
    kcl_program: $ => repeat($.body_item),

    body_item: $ => choice(
      // $.expression,
      $.variable_declaration,
      $.return_stmt,
    ),

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
      $.identifier,
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

    _string_content: $ => repeat1(choice(
      $._normal_string_content,
      $.escape_sequence,
    )),

    _normal_string_content: _ => token.immediate(prec(1, /[^\\"\n]+/)),

    escape_sequence: _ => token.immediate(seq(
      '\\',
      /(\"|\\|\/|b|f|n|r|t|u)/,
    )),

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
