#include "parser.h"
#include <iostream>

ASTNode* parseAssignment(std::vector<Token> &tokens, int &index) {
    if (tokens[index].type == IDENTIFIER) {
        ASTNode* assignNode = new ASTNode("=");
        assignNode->children.push_back(new ASTNode(tokens[index++].value));  // Identifier
        index++;  // Skip '='
        assignNode->children.push_back(new ASTNode(tokens[index++].value));  // Number
        return assignNode;
    }
    return nullptr;
}
