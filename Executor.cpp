#include "Executor.hpp"

void Execute(std::vector<std::string> &tokens)
{
    std::string buffer;
    std::string second_buffer;
    uint8_t id;
    int8_t current;

    uint8_t execute_function = Find(tokens[0]);
    //special flags
    Function(Find(tokens[tokens.size()-1]), buffer, second_buffer, current, tokens);

    for(current = 1; current < tokens.size()-1; current++)
    {
        id = Find(tokens[current]);
        if(id == false) buffer += tokens[current];
        else {
            second_buffer = tokens[current+1];
            Function(id, buffer, second_buffer, current, tokens);
        }
    } 

    Function(execute_function, buffer, second_buffer, current, tokens);
}

void Function(uint8_t id, std::string &buffer, const std::string &second_buffer, int8_t &current, std::vector<std::string> &tokens)
{
    switch(id)
    {
        case NONE: break;

        case PRINT:
            std::cout << buffer << std::endl; break;
        
        case MATH:
        {
            std::string result;
            uint8_t temp_current;
            uint8_t id;
            bool finish = false;
            bool math;
            while(finish == false)
            {
                math = false;
                for(temp_current = 1; temp_current < tokens.size()-1; temp_current++)
                {
                    id = Find(tokens[temp_current]);
                    if(id == MULTIPLY_SYMBOL || id == DIVIDE_SYMBOL) {
                        math = true;
                        result = tokens[temp_current-1];
                        Function(id, result, tokens[temp_current+1], current, tokens);
                        tokens[temp_current-1] = result;
                        RemoveElementInArray(tokens, temp_current, 2);
                    }
                }
                if(math == false) finish = true;
            }
        }
        break;
        
        case PLUS_SYMBOL:
        {
            int x = stoi(buffer);
            int y = stoi(second_buffer);
            int result = x + y;
            buffer = std::to_string(result);
            current++;
        }
        break;
        
        case MINUS_SYMBOL:
        {
            int x = stoi(buffer);
            int y = stoi(second_buffer);
            int result = x - y;
            buffer = std::to_string(result);
            current++;
        }
        break;

        case MULTIPLY_SYMBOL:
        {
            int x = stoi(buffer);
            int y = stoi(second_buffer);
            int result = x * y;
            buffer = std::to_string(result);
            current++;
        }
        break;
        
        case DIVIDE_SYMBOL:
        {
            int x = stoi(buffer);
            int y = stoi(second_buffer);
            int result = x / y;
            buffer = std::to_string(result);
            current++;
        }
        break;
        
        default: break;
    }
}

uint8_t Find(const std::string &data)
{
    if(data == "NONE") return NONE;
    if(data == "PRINT") return PRINT;
    if(data == "MATH") return MATH;
    else if(data == "+") return PLUS_SYMBOL;
    else if(data == "-") return MINUS_SYMBOL;
    else if(data == "*") return MULTIPLY_SYMBOL;
    else if(data == "/") return DIVIDE_SYMBOL;
    else return 0;
}

void RemoveElementInArray(std::vector<std::string> &tokens, uint8_t index, uint8_t amount)
{
    tokens[index].clear();
    for(uint8_t i = index; i < tokens.size()-amount; i++) {
        tokens[i] = tokens[i+amount];
    }
    for(uint8_t i = tokens.size()-amount; i <= tokens.size()-1; i++) tokens[i].clear();
    tokens.shrink_to_fit();
}