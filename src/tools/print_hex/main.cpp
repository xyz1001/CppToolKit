#include <cstring>

#include <iostream>
#include <vector>

#include "print_hex.h"

template <typename T>
void PrintAsHex(const T &str) {
    // std::cout << "string: "<< str <<std::endl;
    std::cout << "Hex: " << ToHex(str) << std::endl;
}

int main() {
    std::string str = "123";
    PrintAsHex(str);

    PrintAsHex("XYZ");

    std::wstring wstr(L"字符串");
    PrintAsHex(wstr);

    std::vector<int> int_vec{1, 2, 3};
    PrintAsHex(int_vec);

    char s1[10] = "123";
    PrintAsHex(std::string(s1, 3));
}
