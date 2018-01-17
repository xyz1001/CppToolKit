/* Copyright (©) 2017 zgzf1001@gmail.com */

#include <cstring>

#include <iostream>
#include <vector>

#include "catch/catch.hpp"

#include "tools/view_in_hex/view_in_hex.hpp"

TEST_CASE("View in hex", "[tools][view_in_hex]") {
    SECTION("string") {
        std::string str = "123";
        REQUIRE(GetHexView(str) == "31 32 33");
    }

    SECTION("string") { REQUIRE(GetHexView("XYZ") == "58 59 5A 00"); }

    SECTION("string") {
        std::wstring wstr(L"字符串");
        REQUIRE(GetHexView(wstr) == "5B57 7B26 4E32");
    }

    SECTION("string") {
        std::vector<int> num_vector{1, 2, 3};
        REQUIRE(GetHexView(num_vector) == "01 02 03");
    }

    SECTION("string") {
        char s1[10] = "123";
        REQUIRE(GetHexView(s1, 3) == "31 32 33");
    }
}
