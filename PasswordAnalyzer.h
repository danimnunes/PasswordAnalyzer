#ifndef PASSWORD_ANALYZER_H
#define PASSWORD_ANALYZER_H

#include <string>

class PasswordAnalyzer
{
public:
    PasswordAnalyzer();

    std::string analyzePassword(const std::string &password);

private:
    bool checkLength(const std::string &password);
    bool checkVariety(const std::string &password);
    double calculateEntropy(const std::string &password);
    bool checkBreach(const std::string &password);

    std::string provideFeedback(bool isStrong, bool isBreached, double entropy);
};

#endif // PASSWORD_ANALYZER_H
