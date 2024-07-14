#pragma once
#include <vector>
#include <iostream>

enum Keywords
{
    PRINT = 1,
    PLUS_SYMBOL,
    MINUS_SYMBOL,
    MULTIPLY_SYMBOL,
    DIVIDE_SYMBOL
};

void Execute(const std::vector<std::string> &tokens);
uint8_t Find(const std::string &data);
void Function(uint8_t id, std::string &buffer, const std::string &second_buffer, int8_t &current);