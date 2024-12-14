#ifndef APICLIENT_H
#define APICLIENT_H

#include <string>

class APIClient
{
public:
    bool isPasswordBreached(const std::string &password);

private:
    static size_t writeCallback(void *contents, size_t size, size_t nmemb, void *userp);
    bool makeRequest(const std::string &url, std::string &response);
};

#endif // APICLIENT_H
