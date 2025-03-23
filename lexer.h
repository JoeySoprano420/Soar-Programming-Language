#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>

enum TokenType { DATA_TYPE, IDENTIFIER, ASSIGN_OP, NUMBER, OPERATOR, EOF_TOK };

struct Token {
    TokenType type;
    std::string value;
};

std::vector<Token> lexer(const std::string& code);

#endif
