#include "Executor.hpp"

void Execute(const std::vector<std::string> &tokens)
{
    std::string buffer;
    std::string second_buffer;
    uint8_t id;
    int8_t current;

    for(current = tokens.size(); current > -1; current--)
    {
        id = Find(tokens[current]);
        if(id == false) buffer += tokens[current];
        else {
            second_buffer = tokens[current-1];
            Function(id, buffer, second_buffer, current);
        }
    }
}

void Function(uint8_t id, std::string &buffer, const std::string &second_buffer, int8_t &current)
{
    switch(id)
    {
        case PRINT:
            std::cout << buffer << std::endl; break;
        
        case PLUS_SYMBOL:
        {
            int x = stoi(buffer);
            int y = stoi(second_buffer);
            int result = x + y;
            buffer = std::to_string(result);
            current--;
        }
        break;
        
        case MINUS_SYMBOL:
        {
            int x = stoi(buffer);
            int y = stoi(second_buffer);
            int result = y - x;
            buffer = std::to_string(result);
            current--;
        }
        break;

        case MULTIPLY_SYMBOL:
        {
            int x = stoi(buffer);
            int y = stoi(second_buffer);
            int result = x * y;
            buffer = std::to_string(result);
            current--;
        }
        break;
        
        case DIVIDE_SYMBOL:
        {
            int x = stoi(buffer);
            int y = stoi(second_buffer);
            int result = y / x;
            buffer = std::to_string(result);
            current--;
        }
        break;
        
        default: break;
    }
}

uint8_t Find(const std::string &data)
{
    if(data == "PRINT") return PRINT;
    else if(data == "+") return PLUS_SYMBOL;
    else if(data == "-") return MINUS_SYMBOL;
    else if(data == "*") return MULTIPLY_SYMBOL;
    else if(data == "/") return DIVIDE_SYMBOL;
    else return 0;
}