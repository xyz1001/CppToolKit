/* Copyright (©) 2017 zgzf1001@gmail.com */

#include <fstream>
#include <sstream>

#include "catch/catch.hpp"
#include "wrappers/curlpp/curlpp.h"

TEST_CASE("Make http request", "[wrapper][curlpp]") {
    std::ostringstream os;
    Curlpp curlpp(os);

    SECTION("get request") {
        curlpp.AddHeader("Referer", "http://music.163.com");
        curlpp.AddHeader("Cookie", "appver=1.5.0.75771");

        curlpp.AddParam("id", "139558");
        curlpp.AddParam("ids", "[139558]");

        curlpp.SetUrl("http://music.163.com/api/song/detail/");
        curlpp.Get();
        REQUIRE_THAT(os.str(), Catch::Contains("200"));
    }

    SECTION("post request") {
        curlpp.AddHeader("Referer", "http://music.163.com");
        curlpp.AddHeader("Cookie", "appver=1.5.0.75771");

        curlpp.AddParam("s", "a little love");
        curlpp.AddParam("limit", "1");
        curlpp.AddParam("type", "1");
        curlpp.AddParam("offset", "0");

        curlpp.SetUrl("http://music.163.com/api/search/get/");
        curlpp.Post();

        REQUIRE_THAT(os.str(), Catch::Contains("200"));
    }
}
