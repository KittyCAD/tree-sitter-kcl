module.exports = grammar({
  name: 'kcl',

  rules: {
    kcl_program: $ => repeat($.definition),

    definition: $ => seq(
      'let',
      $.identifier,
      '=',
      $._value,
    ),

    identifier: $ => seq(
      /[a-zA-Z][a-zA-Z0-9]*/
    ),

    _value: $ => choice(
      $.number,
    ),

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
