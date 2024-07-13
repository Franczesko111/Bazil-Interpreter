#include <fstream>
#include <iostream>

int main()
{
    std::ifstream file("main.bz");
    std::string data;
    std::vector<std::string> tokens;
    while(file.eof() == false)
    {
        getline(file, data);
        std::cout << data << std::endl;
    }
    return 0;
}