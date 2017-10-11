#ifndef SRC_WRAPPER_CURL_SRC_CURLPP_H_
#define SRC_WRAPPER_CURL_SRC_CURLPP_H_

#include <curl/curl.h>

#include <ostream>
#include <string>
#include <unordered_map>

class Curlpp {
public:
    Curlpp(std::ostream &os);
    ~Curlpp();

public:
    bool SetUrl(const std::string &url);
    void AddParam(const std::string &key, const std::string &value);
    void AddHeader(const std::string &key, const std::string &value);

public:
    bool Get();
    bool Post();

private:
    std::ostream &out_stream_;
    std::string url_;
    std::unordered_map<std::string, std::string> params_;
    std::string buffer_;

    CURL *curl_ = nullptr;
    curl_slist *headers_ = nullptr;
};

#endif  // SRC_WRAPPER_CURL_SRC_CURLPP_H_
