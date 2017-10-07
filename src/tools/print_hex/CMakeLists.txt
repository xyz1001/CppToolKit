cmake_minimum_required (VERSION 3.0)

project (print_hex)

SET(CMAKE_CXX_STANDARD 11)

SET(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")

add_executable(main
    main.cpp)
