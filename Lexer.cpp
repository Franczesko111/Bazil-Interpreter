#include "Lexer.hpp"

std::vector<std::string> Lexer(const std::string &data)
{
    std::vector<std::string> TOKENS;
    std::string token;

    for(char ch: data)
    {
        if(isblank(ch)) {
            if(token.size() > 0) {
                TOKENS.push_back(token);
                token.clear();
            }
            continue;
        }

        token += ch;
    }

    TOKENS.push_back(token);
    return TOKENS;
}