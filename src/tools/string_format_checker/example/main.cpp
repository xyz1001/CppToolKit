#include <iostream>

#include "../src/string_format_checker.h"

int main() {
    std::cout << checker::IsValidEmail("123@xx.xxx") << std::endl;
    std::cout << checker::IsValidEmail("123xx.xxx") << std::endl;
    std::cout << checker::IsValidEmail("123@xxxxx") << std::endl;
    std::cout << checker::IsValidEmail("@xx.xxx") << std::endl;
    std::cout << checker::IsValidEmail("123@.xxx") << std::endl;
    std::cout << checker::IsValidEmail("123@xx.") << std::endl;
    std::cout << std::endl;

    std::cout << checker::IsValidHttpUrl("http://www.example.com") << std::endl;
    std::cout << checker::IsValidHttpUrl("http://w_w.example.com") << std::endl;
    std::cout << checker::IsValidHttpUrl("www.example.com") << std::endl;
    std::cout << checker::IsValidHttpUrl("http//www.example.com") << std::endl;
    std::cout << checker::IsValidHttpUrl("http:www.example.com") << std::endl;
    std::cout << checker::IsValidHttpUrl("http://www.example.") << std::endl;
    std::cout << checker::IsValidHttpUrl("http://wwwexamplecom") << std::endl;
    std::cout << checker::IsValidHttpUrl("http://w*w.example.com") << std::endl;
    return 0;
}
