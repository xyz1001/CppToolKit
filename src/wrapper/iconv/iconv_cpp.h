#ifndef SRC_WRAPPER_ICONV_ICONV_CPP_H_
#define SRC_WRAPPER_ICONV_ICONV_CPP_H_

#include <memory>
#include <string>

class Iconv {
public:
    /**
     * 错误码
     */
    enum ErrorCode {
        kOk = 0,              // 转换成功
        kWrongCode = 1,       //错误的编码格式
        kInvalidByte = 2,     //无法转换的非法字节
        kIncompleteByte = 3,  //不完整的多字节序列
        kUnknownError = 5,    //未知错误
    };

public:
    /**
     * @param from_code 要转换的字符串的编码格式
     * @param to_code 转换的目标编码格式
     *
     * @note from_code和to_code需为`iconv -l`列出的类型
     */
    Iconv(const std::string& from_code, const std::string& to_code);
    ~Iconv();

    /**
     * 转换字符串的编码
     *
     * @param input 要转换的字符串
     * @param output 转换后的字符串
     *
     * @returns   错误码
     */
    ErrorCode convert(const std::string& input, std::string& output) const;

private:
    class IconvImpl;
    std::unique_ptr<IconvImpl> pimpl_;
};

#endif  // SRC_WRAPPER_ICONV_ICONV_CPP_H_
