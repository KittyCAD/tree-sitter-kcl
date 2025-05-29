;; Maps AST nodes (left) to 
(identifier) @variable

[
; "if",
; "else",
; "for",
; "while",
"return"
; "break",
; "continue",
"fn"
; "let",
; "mut",
; "as",
; "loop",
; "nil",
; "and",
; "or",
; "not",
; "var",
; "const",
; "import",
; "export",
; "type",
; "interface",
; "new",
; "self",
; "from",
; "record",
; "struct",
; "object",
] @keyword

"fn" @keyword.function

"import" @keyword.import

; [
;  "if"
;  "else"
;  ] @keyword.conditional

;; operators
(binary_operator) @operator
(prefix_operator) @operator

;; punctuation

; ".." @punctuation.special

"(" @punctuation.bracket
")" @punctuation.bracket
; "[" @punctuation.bracket
; "]" @punctuation.bracket
"{" @punctuation.bracket
"}" @punctuation.bracket

; "." @punctuation.delimiter
"," @punctuation.delimiter
; ":" @punctuation.delimiter
; ";" @punctuation.delimiter

;; literals
(boolean) @boolean
(string) @string
(number) @number

;; comments
(shebang) @keyword.directive
(comment) @comment
