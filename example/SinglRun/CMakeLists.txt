aux_source_directory(. SRC)
aux_source_directory(${PROJECT_SOURCE_DIR}/src/tools/SingleRun/ SRC)

message(${SRC})

add_executable(single_run ${SRC})

target_link_libraries(single_run ${LIBS})
