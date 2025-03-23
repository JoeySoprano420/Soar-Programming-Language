#include <iostream>
#include <vector>
#include <string>
#include "lexer.h"
#include "parser.h"

int main() {
    std::string code = "int a = 5; if (a > 3) { a = a + 1; }";

    // Step 1: Tokenize the source code using lexer
    std::vector<Token> tokens = lexer(code);

    // Step 2: Parse the tokens into an Abstract Syntax Tree (AST)
    int index = 0;
    ASTNode* root = parseAssignment(tokens, index);

    // Step 3: Print parsed AST and generate hex code
    std::cout << "Parsed AST:\n";
    std::cout << root->value << " " << root->children[0]->value << " " << root->children[1]->value << std::endl;

    std::cout << "Hexadecimal Code: 0x04 0x01 0x05" << std::endl;  // Example output
    return 0;
}
