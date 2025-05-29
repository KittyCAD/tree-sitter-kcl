import XCTest
import SwiftTreeSitter
import TreeSitterKcl

final class TreeSitterKclTests: XCTestCase {
    func testCanLoadGrammar() throws {
        let parser = Parser()
        let language = Language(language: tree_sitter_kcl())
        XCTAssertNoThrow(try parser.setLanguage(language),
                         "Error loading KCL grammar")
    }
}
