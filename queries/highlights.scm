;; Maps AST nodes (left) to highlighting classes (right)
;; See https://docs.helix-editor.com/themes.html#scopes
;; for the supported scopes.

"fn" @keyword.function
"return" @keyword.return
"import" @keyword.import
"export" @keyword.import

; [
;  "if"
;  "else"
;  ] @keyword.conditional
(identifier) @variable

;; highlight type names
(type_name
  (identifier) @type
) @type

(fn_call
  callee: (identifier) @function
  (labeledArg
    label: (identifier) @variable.parameter
  )
)


;; operators
(binary_operator) @operator
(prefix_operator) @operator

;; punctuation

; ".." @punctuation.special

"(" @punctuation.bracket
")" @punctuation.bracket
"[" @punctuation.bracket
"]" @punctuation.bracket
"{" @punctuation.bracket
"}" @punctuation.bracket

; "." @punctuation.delimiter
"," @punctuation.delimiter
; ":" @punctuation.delimiter
; ";" @punctuation.delimiter

;; literals
(boolean) @constant.builtin.boolean
(string) @string
(number) @constant.numeric

;; comments
(shebang) @keyword.directive
(comment) @comment


