#include <fstream>
#include <iostream>
#include "Lexer.hpp"

void Print(const std::vector<std::string> &tokens);

int main()
{
    std::ifstream file("main.bz");
    std::string data;
    std::vector<std::string> tokens;
    while(file.eof() == false)
    {
        getline(file, data);
        tokens = Lexer(data);
        Print(tokens);
    }
    return 0;
}

void Print(const std::vector<std::string> &tokens)
{
    std::cout << "[";
    for(uint8_t i = 0; i < tokens.size(); i++) {
        std::cout << tokens[i];
        if(tokens.size()-1 > i) std::cout << " ";
    }
    std::cout << "]" << std::endl;
}