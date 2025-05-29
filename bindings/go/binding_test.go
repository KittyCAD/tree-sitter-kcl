package tree_sitter_kcl_test

import (
	"testing"

	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	tree_sitter_kcl "github.com/kittycad/tree-sitter-kcl/bindings/go"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_kcl.Language())
	if language == nil {
		t.Errorf("Error loading KCL grammar")
	}
}
