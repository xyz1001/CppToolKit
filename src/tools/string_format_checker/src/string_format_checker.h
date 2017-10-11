#ifndef SRC_TOOLS_STRING_FORMAT_CHECKER_SRC_STRING_FORMAT_CHECKER_H_
#define SRC_TOOLS_STRING_FORMAT_CHECKER_SRC_STRING_FORMAT_CHECKER_H_

#include <string>

namespace checker {

bool IsValidEmail(const std::string &email);

bool IsValidHttpUrl(const std::string url);

}  // namespace checker

#endif  // SRC_TOOLS_STRING_FORMAT_CHECKER_SRC_STRING_FORMAT_CHECKER_H_
