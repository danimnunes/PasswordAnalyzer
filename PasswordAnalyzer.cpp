#include "PasswordAnalyzer.h"
#include <iostream>
#include <cmath>
#include <regex>
#include "APIClient.h"

PasswordAnalyzer::PasswordAnalyzer()
{
}

bool PasswordAnalyzer::checkLength(const std::string &password)
{
    return password.length() >= 8;
}

bool PasswordAnalyzer::checkVariety(const std::string &password)
{
    bool hasUpper = false, hasLower = false, hasDigit = false, hasSymbol = false;

    for (char c : password)
    {
        if (isupper(c))
            hasUpper = true;
        else if (islower(c))
            hasLower = true;
        else if (isdigit(c))
            hasDigit = true;
        else
            hasSymbol = true;
    }

    return hasUpper && hasLower && hasDigit && hasSymbol;
}

double PasswordAnalyzer::calculateEntropy(const std::string &password)
{
    std::unordered_map<char, int> freq;
    for (char c : password)
    {
        freq[c]++;
    }

    double entropy = 0.0;
    for (const auto &pair : freq)
    {
        double p = static_cast<double>(pair.second) / password.length();
        entropy -= p * log2(p);
    }

    return entropy;
}

bool PasswordAnalyzer::checkBreach(const std::string &password)
{
    APIClient apiClient;
    try
    {
        bool isBreached = apiClient.isPasswordBreached(password);

        return isBreached;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error checking breach status: " << e.what() << std::endl;
        return false;
    }
}

std::string PasswordAnalyzer::provideFeedback(bool isStrong, bool isBreached, double entropy)
{
    std::ostringstream feedback;

    if (!isStrong)
    {
        feedback << "Your password is weak. Consider making it longer and including a mix of uppercase, lowercase, digits, and symbols.\n";
    }
    if (isBreached)
    {
        feedback << "Your password has been found in a data breach. Data provided by Have I Been Pwned (https://haveibeenpwned.com). Avoid using it.\n";
    }
    if (entropy < 3.0)
    {
        feedback << "Your password has low entropy. Aim for greater randomness.\n";
    }

    if (feedback.str().empty())
    {
        feedback << "Your password is strong!\n";
    }

    return feedback.str();
}

std::string PasswordAnalyzer::analyzePassword(const std::string &password)
{
    bool isStrong = checkLength(password) && checkVariety(password);
    double entropy = calculateEntropy(password);
    bool isBreached = checkBreach(password);

    return provideFeedback(isStrong, isBreached, entropy);
}
