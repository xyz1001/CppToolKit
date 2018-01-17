include_directories(${PROJECT_SOURCE_DIR}/tests)

aux_source_directory(. SRC)

aux_source_directory(./tools SRC)

aux_source_directory(./wrappers/curlpp SRC)
aux_source_directory(./wrappers/iconvpp SRC)

add_executable(catch ${SRC})

set(LIBS
    curlpp
    iconvpp
    )
target_link_libraries(catch ${LIBS})
