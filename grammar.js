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
	member: 21,
	pipe: 5, // |>
};

module.exports = grammar({
	name: "kcl",

	rules: {
		kcl_program: ($) =>
			seq(
				optional(field("shebang", $.shebang)),
				repeat(choice($.annotation, $.body_item)),
			),

		body_item: ($) =>
			choice(
				$.expr_stmt,
				$.variable_declaration,
				$.return_stmt,
				$.comment,
				$.import_stmt,
			),

		shebang: (_) => /#![^\n]*/,

		import_stmt: ($) =>
			seq(
				"import",
				choice(
					seq($.string, optional(seq("as", $.identifier))),
					seq(commaSep1($.identifier), "from", $.string),
				),
			),

		expr_stmt: ($) => $._expr,

		variable_declaration: ($) =>
			seq(optional("export"), choice($.fn_definition, $.non_fn_definition)),

		fn_definition: ($) =>
			seq(
				"fn",
				$.identifier,
				$.param_list,
				optional(seq(choice(":", "?:"), $.type_name)),
				"{",
				repeat($.body_item),
				"}",
			),

		param_list: ($) =>
			seq(
				"(",
				commaSep(seq(repeat(choice($.annotation, $.comment)), $.param)),
				optional(","),
				")",
			),

		param: ($) =>
			seq(
				optional("@"),
				$.identifier,
				optional("?"),
				optional(seq(":", $.type_name)),
				optional(seq("=", field("default", $._expr))),
			),

		type_name: ($) => seq($._one_type, repeat(seq("|", $._one_type))),

		_one_type: ($) =>
			choice(
				seq(
					$.identifier,
					optional(seq("(", field("units", $.identifier), ")")),
				),
				$.array_type,
				$.function_type,
				$.object_type,
			),

		array_type: ($) =>
			seq(
				"[",
				$.type_name,
				optional(seq(";", field("length", $.number), optional("+"))),
				"]",
			),

		function_type: ($) =>
			seq("fn", "(", commaSep($.type_name), ")", ":", $._one_type),

		object_type: (_) => seq("{", "}"),

		annotation: ($) =>
			choice(
				prec(1, seq("@", $.identifier, $._annotation_properties)),
				prec(-1, seq("@", $.identifier)),
				seq("@", $._annotation_properties),
			),

		_annotation_properties: ($) =>
			seq("(", commaSep1($.annotation_kv), optional(","), ")"),

		annotation_kv: ($) =>
			seq(
				$.identifier,
				"=",
				choice($.identifier, $.number, $.string, $.array_expr),
			),

		identifier: (_) => /[a-zA-Z_][a-zA-Z0-9_]*/,

		_expr: ($) =>
			choice(
				$.if_expr,
				$.number,
				$.string,
				$.boolean,
				$.identifier,
				$.binary_expr,
				$.prefix_expr,
				$.array_expr,
				$.member_expr,
				$.fn_call,
				$.sketch_block,
				$.sketch_var,
				$.pipe_sub,
			),

		array_expr: ($) => seq("[", optional(commaSep($._expr)), "]"),

		member_expr: ($) =>
			prec.left(
				PREC.member,
				seq(
					field("object", $.identifier),
					repeat1(seq(".", field("property", $.identifier))),
				),
			),

		sketch_var: ($) => prec.right(seq("var", optional($.number))),

		pipe_sub: (_) => "%",

		if_expr: ($) =>
			seq(
				"if",
				field("condition", $._expr),
				"{",
				field("if_clause", repeat(seq(optional($.annotation), $.body_item))),
				"}",
				repeat(
					seq(
						"else if",
						field("condition", $._expr),
						"{",
						field(
							"else_if_clause",
							repeat(seq(optional($.annotation), $.body_item)),
						),
						"}",
					),
				),
				"else",
				"{",
				field("else_clause", repeat(seq(optional($.annotation), $.body_item))),
				"}",
			),

		fn_call: ($) => seq(field("callee", $.identifier), $._call_arguments),

		sketch_block: ($) =>
			prec(1, seq("sketch", $._call_arguments, "{", repeat($.body_item), "}")),

		_call_arguments: ($) =>
			seq(
				"(",
				commaSep(choice(field("unlabeledArg", $._expr), $.labeledArg)),
				")",
			),

		labeledArg: ($) =>
			seq(field("label", $.identifier), "=", field("arg", $._expr)),

		function_body: ($) => seq("{", seq($.body_item), "}"),

		return_stmt: ($) => seq("return", $._expr),

		non_fn_definition: ($) => seq($.identifier, "=", $._expr),

		string: ($) =>
			choice(
				seq('"', optional($._string_content), '"'),
				seq("'", optional($._single_string_content), "'"),
			),

		boolean: (_) => choice("true", "false"),

		_string_content: ($) =>
			repeat1(choice($._normal_string_content, $.escape_sequence)),
		_single_string_content: ($) =>
			repeat1(choice($._normal_single_string_content, $.escape_sequence)),

		_normal_string_content: (_) => token.immediate(prec(1, /[^\\"\n]+/)),
		_normal_single_string_content: (_) => token.immediate(prec(1, /[^\\'\n]+/)),

		escape_sequence: (_) =>
			token.immediate(seq("\\", /("|'|\\|\/|b|f|n|r|t|u)/)),
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
				[prec.left, PREC.cmp, choice(">", "<", ">=", "<=")],
				[prec.left, PREC.eq, "=="],
				[prec.left, PREC.neq, "!="],
				[prec.left, PREC.add, choice("+", "-")],
				[prec.left, PREC.mul, choice("*", "/", "%")],
				[prec.right, PREC.and, "&"],
				[prec.left, PREC.or, "|"],
				[prec.left, PREC.pipe, "|>"],
			];

			return choice(
				...table.map(([fn, prec, op]) =>
					//@ts-expect-error
					fn(
						prec,
						seq(
							field("lhs", $._expr),
							//@ts-expect-error
							field("operator", alias(op, $.binary_operator)),
							field("rhs", $._expr),
						),
					),
				),
			);
		},

		number: (_) => {
			const decimalDigits = /\d+/;
			const signedInteger = seq(optional("-"), decimalDigits);
			const exponentPart = seq(choice("e", "E"), signedInteger);

			const decimalIntegerLiteral = seq(
				optional("-"),
				choice("0", seq(/[1-9]/, optional(decimalDigits))),
			);

			const decimalLiteral = choice(
				seq(
					decimalIntegerLiteral,
					".",
					optional(decimalDigits),
					optional(exponentPart),
				),
				seq(decimalIntegerLiteral, optional(exponentPart)),
			);

			return token(seq(decimalLiteral, optional(/[a-zA-Z]+/)));
		},

		comment: (_) => token(/\/\/[^\n]*(?:\n[ \t]*\/\/[^\n]*)*/),
	},
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
	return seq(rule, repeat(seq(",", rule)));
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
