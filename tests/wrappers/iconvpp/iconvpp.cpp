/* Copyright (©) 2017 zgzf1001@gmail.com */

#include <iostream>

#include <fstream>
#include <iomanip>
#include <iterator>
#include <sstream>

#include "catch/catch.hpp"
#include "tools/view_in_hex/view_in_hex.hpp"
#include "wrappers/iconvpp/iconvpp.h"

TEST_CASE("Convert charset", "[wrapper][iconvpp]") {
    SECTION("convert gbk to utf-8") {
        std::ifstream fin(
                "/home/zix/Project/cpp/cpp-utils/tests/wrappers/iconvpp/"
                "gbk.txt");
        std::istreambuf_iterator<char> is(fin);
        std::istreambuf_iterator<char> end;
        std::string gbk_str(is, end), utf8_str;

        REQUIRE(GetHexView(gbk_str) ==
                "B2 E2 CA D4 D2 BB CF C2 69 63 6F 6E 76 B5 C4 CA B9 D3 C3 B7 "
                "BD B7 A8 A1 A3");

        Iconvpp converter("gbk", "utf-8");
        Iconvpp::ErrorCode ec = converter.convert(gbk_str, utf8_str);
        REQUIRE(ec == Iconvpp::kOk);

        REQUIRE(GetHexView(utf8_str) ==
                "E6 B5 8B E8 AF 95 E4 B8 80 E4 B8 8B 69 63 6F 6E 76 E7 9A 84 "
                "E4 BD BF E7 94 A8 E6 96 B9 E6 B3 95 E3 80 82");
    }

    SECTION("convert utf-8 to gbk") {
        std::ifstream fin(
                "/home/zix/Project/cpp/cpp-utils/tests/wrappers/iconvpp/"
                "utf8.txt");
        std::istreambuf_iterator<char> is(fin);
        std::istreambuf_iterator<char> end;
        std::string utf8_str(is, end), gbk_str;

        REQUIRE(GetHexView(utf8_str) ==
                "E6 B5 8B E8 AF 95 E4 B8 80 E4 B8 8B 69 63 6F 6E 76 E7 9A 84 "
                "E4 BD BF E7 94 A8 E6 96 B9 E6 B3 95 E3 80 82 0A");

        Iconvpp converter("utf-8", "gbk");
        Iconvpp::ErrorCode ec = converter.convert(utf8_str, gbk_str);
        REQUIRE(ec == Iconvpp::kOk);

        REQUIRE(GetHexView(gbk_str) ==
                "B2 E2 CA D4 D2 BB CF C2 69 63 6F 6E 76 B5 C4 CA B9 D3 C3 B7 "
                "BD B7 A8 A1 A3 0A");
    }
}
