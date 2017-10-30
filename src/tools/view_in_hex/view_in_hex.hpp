/* Copyright (©) 2017 zgzf1001@gmail.com */

#ifndef SRC_TOOLS_VIEW_IN_HEX_VIEW_IN_HEX_HPP_
#define SRC_TOOLS_VIEW_IN_HEX_VIEW_IN_HEX_HPP_

#include <cstdint>

#include <iomanip>
#include <sstream>

template <size_t n>
class UintType {};

template <>
class UintType<1> {
public:
    using type = uint8_t;
};

template <>
class UintType<2> {
public:
    using type = uint16_t;
};

template <>
class UintType<4> {
public:
    using type = uint32_t;
};

template <>
class UintType<8> {
public:
    using type = uint64_t;
};

template <typename U, typename T>
void ConvertToHex(const T &elem, std::ostringstream &os) {
    os << std::setw(2) << std::setfill('0')
       << static_cast<uint64_t>(static_cast<U>(elem)) << ' ';
}

// 作用于字符容器
template <typename T,
          typename U = typename UintType<sizeof(typename T::value_type)>::type>
std::string Convert(const T &s, std::ostringstream &os) {
    for (auto &i : s) { ConvertToHex<U>(i, os); }
    return os.str();
}

//作用于字符数组
template <typename T, size_t N, typename U = typename UintType<sizeof(T)>::type>
std::string Convert(const T (&arr)[N], std::ostringstream &os) {
    for (auto &i : arr) { ConvertToHex<U>(i, os); }
    return os.str();
}

//作用于字符串指针
template <typename T, typename U = typename UintType<sizeof(T)>::type>
std::string Convert(const T *arr, size_t size, std::ostringstream &os) {
    for (size_t i = 0; i < size; ++i) { ConvertToHex<U>(arr[i], os); }
    return os.str();
}

/**
 * 将元素集合中的元素以十六进制的形式打印
 *
 * @tparam Args 要转换的参数类型，可以处理字符容器、字符数组和字符串指针
 * @param args 要转换的对象，字符串指针需要额外传入转换的字符数参数
 *
 * @returns   元素集合中的元素以十六进制表示后的字符串，元素之间以空格分割
 */
template <typename... Args>
std::string GetHexView(Args &&... args) {
    std::ostringstream hex;

    hex << std::hex << std::uppercase;
    std::string hex_str = Convert(std::forward<Args>(args)..., hex);
    hex_str.pop_back();
    return hex_str;
}

#endif  // SRC_TOOLS_VIEW_IN_HEX_VIEW_IN_HEX_HPP_
