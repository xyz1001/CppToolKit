#ifndef SRC_TOOLS_PRINT_HEX_PRINT_HEX_H_
#define SRC_TOOLS_PRINT_HEX_PRINT_HEX_H_

#include <cstdint>

#include <iomanip>
#include <sstream>

/**
 * 将元素集合中的元素以十六进制的形式打印
 *
 * @tparam T 为cstdint中的类型，用于控制输出位数
 * @param s
 * 元素集合，需要支持std::begin()和std::end()方法，元素类型只能为基本类型
 *
 * @returns   元素集合中的元素以十六进制表示后的字符串，元素之间以空格分割
 */
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

#endif  // SRC_TOOLS_PRINT_HEX_PRINT_HEX_H_
