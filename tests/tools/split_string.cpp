/* Copyright (©) 2017 Zix zgzf1001@gmail.com */

#include <string>
#include <vector>

#include "catch/catch.hpp"

#include "tools/split_string/split.hpp"

TEST_CASE("split string", "[tools][split]") {
    SECTION("split string with space") {
        std::string str("a bc def gh i ");
        std::vector<std::string> string_list = split(str, ' ');
        std::vector<std::string> split_list{"a", "bc", "def", "gh", "i"};
        REQUIRE(string_list == split_list);
    }

    SECTION("split string with continuous delim") {
        std::string str("One.Two.Three...");
        std::vector<std::string> string_list(split(str, '.'));
        std::vector<std::string> split_list{"One", "Two", "Three"};
        REQUIRE(string_list == split_list);
    }
}
