cmake_minimum_required(VERSION 3.0)

project(string_format_checker)

SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_FLAGS "-Wextra -Wall -Werror")
set(CMAKE_BUILD_TYPE Debug)

aux_source_directory(./src LIB_SRC)
add_library(string_format_checker SHARED ${LIB_SRC})

aux_source_directory(./example EXAM_SRC)
add_executable(main ${EXAM_SRC})
target_link_libraries(main string_format_checker)
