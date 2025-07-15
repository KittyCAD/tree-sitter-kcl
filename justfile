test:
    just generate
    tree-sitter test

# Rerun tests every time grammar or tests change
test-watch:
    fswatch -o test/corpus/statements.txt grammar.js | xargs -n1 -I{} just test

# Compiles grammar.js, puts artifacts into src/
generate:
    tree-sitter generate

# Launch the tree-sitter playground
playground:
    just generate
    tree-sitter build --wasm && tree-sitter playground

# Check src/ matches grammar.js
# Note this will fail if your local tree-sitter version is outdated,
# CI uses latest treesitter.
check-no-gen-changes:
    tree-sitter -V
    # The src/ directory should always be up to date with the grammar in grammar.js
    just generate
    git diff --exit-code src

fmt:
    npx @biomejs/biome format --write grammar.js

fmt-helix:
    npx @biomejs/biome format --write --stdin-file-path=foo.ts

