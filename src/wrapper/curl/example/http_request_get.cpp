#include <fstream>
#include <iostream>
#include "../src/curlpp.h"

int main() {
    // std::ofstream fin("./163.json");
    Curlpp curlpp(std::cout);
    curlpp.AddHeader("Referer", "http://music.163.com");
    curlpp.AddHeader("Cookie", "appver=1.5.0.75771");

    curlpp.AddParam("id", "139558");
    curlpp.AddParam("ids", "[139558]");

    curlpp.SetUrl("http://music.163.com/api/song/detail/");
    curlpp.Get();

    std::cout << std::endl;
    std::cout << std::endl;

    curlpp.Reset();
    curlpp.AddHeader("Referer", "http://music.163.com");
    curlpp.AddHeader("Cookie", "appver=1.5.0.75771");

    curlpp.AddParam("s", "a little love");
    curlpp.AddParam("limit", "1");
    curlpp.AddParam("type", "1");
    curlpp.AddParam("offset", "0");

    curlpp.SetUrl("http://music.163.com/api/search/get/");
    curlpp.Post();

    return 0;
}
