module.exports = grammar({
  name: 'kcl',

  rules: {
    kcl_program: $ => repeat($._definition),

    _definition: $ => choice(
      $.fn_definition,
      $.non_fn_definition,
    ),

    non_fn_definition: $ => seq(
      'let',
      $.identifier,
      '=',
      $._value,
    ),

    fn_definition: $ => seq(
      'fn',
      $.identifier,
      '=',
      $.function,
    ),
    
    identifier: $ => seq(
      /[a-zA-Z][a-zA-Z0-9]*/
    ),

    _value: $ => choice(
      $.number,
      $.string,
      $.function,
    ),

    function: $ => seq(
      $.parameter_list,
      '=>',
      $.function_body,
    ),

    parameter_list: $ => seq(
      '(',
      commaSep($.identifier),
      ')',
    ),

    function_body: $ => seq(
      '{',
      seq($._body_item),
      '}',
    ),

    _body_item: $ => choice(
        $._definition,
        $.return_stmt,
    ),

    return_stmt: $ => seq(
      'return',
      $._value,
    ),
    
    string: $ => choice(
      seq('"', '"'),
      seq('"', $._string_content, '"'),
    ),

    _string_content: $ => repeat1(choice(
      $.string_content,
      $.escape_sequence,
    )),

    string_content: _ => token.immediate(prec(1, /[^\\"\n]+/)),

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
