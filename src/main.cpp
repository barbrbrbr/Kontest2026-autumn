#include "brackets_checker.hpp"

#include <iostream>
#include <string>

int main()
{
    std::string input;
    std::getline(std::cin, input);

    std::cout << (bracketsChecker(input) ? "да" : "нет") << '\n';
    return 0;
}
