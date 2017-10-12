#include <iostream>

#include <fstream>
#include <iomanip>
#include <iterator>
#include <sstream>

#include "iconvpp.h"

template <typename T, typename U>
std::string ToHex(const U &s) {
    std::ostringstream hex;

    hex << std::hex << std::uppercase;
    for (auto &i : s) {
        hex << std::setw(2) << std::setfill('0')
            << static_cast<uint64_t>(static_cast<T>(i)) << ' ';
    }
    return hex.str();
}

int main() {
    std::ifstream fin(
            "/home/zix/Project/cpp/cpp_libs/src/wrapper/iconv/test.txt");
    std::istreambuf_iterator<char> is(fin);
    std::istreambuf_iterator<char> end;
    std::string raw_str(is, end), utf8_str;

    std::cout << "raw string: " << ToHex<uint8_t>(raw_str) << std::endl
              << std::endl;
    Iconvpp converter("gbk", "utf-8");
    Iconvpp::ErrorCode ec = converter.convert(raw_str, utf8_str);
    if (ec != Iconvpp::kOk) { return -1; }
    std::cout << "utf-8 string: " << utf8_str << std::endl;

    return 0;
}
