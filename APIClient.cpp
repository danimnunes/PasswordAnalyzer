#include "APIClient.h"
#include <curl/curl.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>

bool APIClient::isPasswordBreached(const std::string &password)
{
    unsigned char hash[SHA_DIGEST_LENGTH];
    SHA1(reinterpret_cast<const unsigned char *>(password.c_str()), password.length(), hash);

    std::ostringstream oss;
    for (int i = 0; i < SHA_DIGEST_LENGTH; ++i)
    {
        oss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
    }

    std::string hashString = oss.str();
    std::string prefix = hashString.substr(0, 5);
    std::string suffix = hashString.substr(5);

    std::string url = "https://api.pwnedpasswords.com/range/" + prefix;
    std::string response;

    if (!makeRequest(url, response))
    {
        throw std::runtime_error("Failed to connect to Have I Been Pwned API.");
    }

    if (response.find(suffix) != std::string::npos)
    {
        return true;
    }

    return false;
}

size_t APIClient::writeCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string *)userp)->append((char *)contents, size * nmemb);
    return size * nmemb;
}

bool APIClient::makeRequest(const std::string &url, std::string &response)
{
    CURL *curl = curl_easy_init();
    if (!curl)
    {
        std::cerr << "CURL initialization failed." << std::endl;
        return false;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    CURLcode res = curl_easy_perform(curl);

    if (res != CURLE_OK)
    {
        std::cerr << "CURL request failed: " << curl_easy_strerror(res) << std::endl;
        curl_easy_cleanup(curl);
        return false;
    }

    curl_easy_cleanup(curl);
    return true;
}
