/* Copyright (©) 2017 zgzf1001@gmail.com */

#include "curlpp.h"

namespace {

static size_t WriteCallback(void *contents, size_t size, size_t nmemb,
                            void *buffer) {
    ((std::string *)buffer)->append((char *)contents, size * nmemb);
    return size * nmemb;
}

}  // namespace

Curlpp::Curlpp(std::ostream &os) : out_stream_(os) {
    curl_ = curl_easy_init();
    curl_easy_setopt(curl_, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl_, CURLOPT_WRITEDATA, &buffer_);
}

Curlpp::~Curlpp() {
    curl_easy_cleanup(curl_);
    curl_slist_free_all(headers_);
}

bool Curlpp::SetUrl(const std::string &url) {
    if (curl_ == nullptr) { return false; }
    // TODO(Zhang Fan) check is url valid
    url_ = url;
    return true;
}

void Curlpp::AddParam(const std::string &key, const std::string &value) {
    params_.emplace(key, value);
}

void Curlpp::AddHeader(const std::string &key, const std::string &value) {
    headers_ = curl_slist_append(headers_, (key + ": " + value).c_str());
}

bool Curlpp::Get() {
    if (curl_ == nullptr) { return false; }

    if (headers_ != nullptr) {
        curl_easy_setopt(curl_, CURLOPT_HTTPHEADER, headers_);
    }

    std::string url = url_ + "?";

    for (auto &i : params_) { url += '&' + i.first + '=' + i.second; }
    curl_easy_setopt(curl_, CURLOPT_URL, url.c_str());

    CURLcode res = curl_easy_perform(curl_);  // 执行
    out_stream_ << buffer_;
    return res == 0;
}

bool Curlpp::Post() {
    if (curl_ == nullptr) { return false; }
    return false;
}
