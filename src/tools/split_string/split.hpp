/* Copyright (©) 2017 Zix zgzf1001@gmail.com */

#ifndef SRC_TOOLS_SPLIT_STRING_SPLIT_HPP_
#define SRC_TOOLS_SPLIT_STRING_SPLIT_HPP_

#include <iterator>
#include <sstream>
#include <string>
#include <vector>

template <typename Out>
void split(const std::string &str, char delim, Out result) {
    std::stringstream ss(str);
    std::string item;
    while (std::getline(ss, item, delim)) {
        if (item.empty()) { continue; }
        *(result++) = item;
    }
}

std::vector<std::string> split(const std::string &str, char delim) {
    std::vector<std::string> elems;
    split(str, delim, std::back_inserter(elems));
    return elems;
}

#endif  // SRC_TOOLS_SPLIT_STRING_SPLIT_HPP_
