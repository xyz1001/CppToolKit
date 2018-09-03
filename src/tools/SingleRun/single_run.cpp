/* Copyright (©) 2018 xyz1001 All rights reserved.
 * Author: xyz1001 <zgzf1001@gmail.com>
 *
 * -*- coding: uft-8 -*-
 */

#include "single_run.h"

#ifdef _WIN32  // for win
#include <windows.h>

namespace utils {

bool IsSingleRun() {
    HANDLE mutex = CreateMutex(nullptr, FALSE, APPNAME);
    if (GetLastError() == ERROR_ALREADY_EXISTS) {
        CloseHandle(mutex);
        mutex = nullptr;
        return false;
    } else {
        return true;
    }
}

}  // namespace utils
#endif

#if defined(unix) || defined(__unix__) || defined(__unix)
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

namespace utils {

bool IsSingleRun() {
    const char filename[] = "/tmp/" APPNAME;
    int fd = open(filename, O_WRONLY | O_CREAT, 0644);
    int flock = lockf(fd, F_TLOCK, 0);
    if (fd == -1) { return false; }
    if (flock == -1) { return false; }
    return true;
}

}  // namespace utils
#endif
