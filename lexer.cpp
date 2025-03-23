#include "lexer.h"
#include <regex>
#include <iostream>

std::vector<Token> lexer(const std::string &code) {
    std::vector<Token> tokens;
    std::regex tokenRegex("(int|float|if)|([a-zA-Z_][a-zA-Z0-9_]*)|(\\d+)|([=+<])");
    std::smatch match;

    std::string::const_iterator searchStart(code.cbegin());
    while (std::regex_search(searchStart, code.cend(), match, tokenRegex)) {
        if (!match.str(1).empty()) tokens.push_back({DATA_TYPE, match.str(1)});
        else if (!match.str(2).empty()) tokens.push_back({IDENTIFIER, match.str(2)});
        else if (!match.str(3).empty()) tokens.push_back({NUMBER, match.str(3)});
        else if (!match.str(4).empty()) tokens.push_back({OPERATOR, match.str(4)});
        searchStart = match.suffix().first;
    }
    tokens.push_back({EOF_TOK, ""});
    return tokens;
}
