# Treesitter KCL

Treesitter is a grammar generator which helps write IDE tools. For example, Neovim and Helix use treesitter to navigate and add syntax highlighting to files.

## Developing

Use `just test` to check your code. 

Typical workflow:

 - Update [`statements.txt`](https://github.com/KittyCAD/tree-sitter-kcl/blob/main/test/corpus/statements.txt) with a failing test case
 - Run `just test-watch` to start running tests. They will rerun whenever you change the tests or grammar.
 - Update [`grammar.js`](https://github.com/KittyCAD/tree-sitter-kcl/blob/main/grammar.js)
 - Check that your `just test-watch` reports all tests are passing.
 - Consider updating [`highlights.scm`](https://github.com/KittyCAD/tree-sitter-kcl/blob/main/queries/highlights.scm) to highlight whatever you added properly. No need to, this is strictly optional.
 - Open a PR.

You can also launch the tree-sitter playground with `just playground`, then paste in some KCL and see where it's failing.
