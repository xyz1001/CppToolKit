/* Copyright (©) 2018 xyz1001 All rights reserved.
 * Author: xyz1001 <zgzf1001@gmail.com>
 *
 * -*- coding: uft-8 -*-
 */

#include <iostream>

#include "tools/SingleRun/single_run.h"

int main() {
    if (!utils::IsSingleRun()) {
        std::cout << "APPNAME already running..." << std::endl;
        return 0;
    }
    std::cin.get();
    return 0;
}
