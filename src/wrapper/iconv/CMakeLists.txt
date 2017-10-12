cmake_minimum_required (VERSION 3.0)

project (iconv)

SET(CMAKE_CXX_STANDARD 11)

SET(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")

set(CMAKE_BUILD_TYPE Debug)

add_executable(main
    main.cpp
    iconvpp.cpp)
