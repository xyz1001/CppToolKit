/* Copyright (©) 2017 zgzf1001@gmail.com */

#include "string_format_checker.h"

#include <regex>

namespace checker {

namespace {

bool CheckValidation(const std::string &str, const std::string &pattern) {
    std::regex rx(pattern);
    return std::regex_match(str, rx);
}

}  // namespace
bool IsValidEmail(const std::string &email) {
    std::string pattern = R"(^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$)";
    return CheckValidation(email, pattern);
}

bool IsValidHttpUrl(const std::string url) {
    std::string pattern =
            R"(https?:\/\/(www\.)?[-a-zA-Z0-9@:%._\+~#=]{2,256}\.[a-z]{2,6}\b([-a-zA-Z0-9@:%_\+.~#?&//=]*))";
    return CheckValidation(url, pattern);
}

}  // namespace checker
