#include "Lexer.hpp"

std::vector<std::string> Lexer(const std::string &data)
{
    std::vector<std::string> TOKENS;
    std::string token;

    bool math[2] = { false, false };

    for(char ch: data)
    {
        if(isblank(ch)) {
            if(token.size() > 0) {
                TOKENS.push_back(token);
                token.clear();
            }
            continue;
        }
        
        if(ch == '+' || ch == '-') math[0] = true;
        if(ch == '*' || ch == '/') math[1] = true;

        token += ch;
    }

    TOKENS.push_back(token);

    if(math[0] == true && math[1] == true)
        TOKENS.push_back("MATH");
    else
        TOKENS.push_back("NONE");

    return TOKENS;
}