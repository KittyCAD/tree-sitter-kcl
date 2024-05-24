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
      $.int,
    ),

    int: $ => /\d+/,
  }
});
