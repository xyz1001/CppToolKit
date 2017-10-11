#include <fstream>
#include "../src/curlpp.h"

int main() {
    std::ofstream fin("./163.json");
    Curlpp curlpp(fin);
    // curlpp.AddHeader("Referer", "http://music.163.com");
    // curlpp.AddHeader("Cookie", "appver=1.5.0.75771");

    curlpp.AddParam("id", "139558");
    curlpp.AddParam("ids", "[139558]");

    curlpp.SetUrl("http://music.163.com/api/song/detail/");
    curlpp.Get();

    return 0;
}
