#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include <vector>

struct ASTNode {
    std::string value;
    std::vector<ASTNode*> children;
    ASTNode(std::string val) : value(val) {}
};

ASTNode* parseAssignment(std::vector<Token> &tokens, int &index);

#endif
