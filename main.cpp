#include <iostream>
#include <string>
#include "PasswordAnalyzer.h"

int main()
{
    PasswordAnalyzer analyzer;

    std::string password;
    std::cout << "Enter a password to analyze: ";
    std::cin >> password;

    std::string feedback = analyzer.analyzePassword(password);
    std::cout << feedback << std::endl;

    return 0;
}
