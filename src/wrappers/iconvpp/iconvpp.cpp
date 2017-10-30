/* Copyright (©) 2017 zgzf1001@gmail.com */

#include "iconvpp.h"

#include <cerrno>

#include <string>
#include <vector>

#include <iconv.h>

class Iconvpp::IconvppImpl {
public:
    IconvppImpl(const std::string& from_code, const std::string& to_code)
            : from_code_(from_code), to_code_(to_code) {}

    ~IconvppImpl() {
        if (cd_ != nullptr) { iconv_close(cd_); }
    }

public:
    ErrorCode Convert(const std::string& input, std::string& output) {
        if (cd_ == nullptr) {
            cd_ = iconv_open(to_code_.c_str(), from_code_.c_str());
            if (cd_ == iconv_t(-1)) {
                if (errno == EINVAL) {
                    return kWrongCode;
                } else {
                    return kUnknownError;
                }
            }
        }

        output.clear();

        std::vector<char> in_buf(input.begin(), input.end());
        char* src_ptr = &in_buf[0];
        size_t src_size = input.size();

        std::vector<char> buf(src_size * 4);
        std::string dest;
        while (src_size > 0) {
            char* dst_ptr = &buf[0];
            size_t dst_size = buf.size();
            size_t result =
                    iconv(cd_, &src_ptr, &src_size, &dst_ptr, &dst_size);
            if (result == static_cast<size_t>(-1)) {
                if (errno != E2BIG) { return FetchError(); }
            }
            dest.append(&buf[0], buf.size() - dst_size);
        }
        std::swap(output, dest);

        return kOk;
    }

private:
    ErrorCode FetchError() {
        switch (errno) {
            case EILSEQ:
                return kInvalidByte;
                break;
            case EINVAL:
                return kIncompleteByte;
                break;
            default:
                return kUnknownError;
        }
    }

private:
    std::string from_code_;
    std::string to_code_;
    iconv_t cd_ = nullptr;
};

Iconvpp::Iconvpp(const std::string& from_code, const std::string& to_code)
        : pimpl_(new IconvppImpl(from_code, to_code)) {}

Iconvpp::~Iconvpp() = default;

Iconvpp::ErrorCode Iconvpp::convert(const std::string& input,
                                    std::string& output) const {
    return pimpl_->Convert(input, output);
}
