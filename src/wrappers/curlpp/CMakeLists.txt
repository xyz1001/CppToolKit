aux_source_directory(. LIB_SRC)

add_library(curlpp SHARED ${LIB_SRC})

target_link_libraries(curlpp curl)
