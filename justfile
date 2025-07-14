test:
    just generate
    tree-sitter test

test-watch:
    fswatch -o test/corpus/statements.txt grammar.js | xargs -n1 -I{} just test

generate:
    tree-sitter generate

playground:
    just generate
    tree-sitter build --wasm && tree-sitter playground
