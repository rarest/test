cmake_minimum_required(VERSION 3.4.1)

project (test)
include_directories(. ../common)
aux_source_directory(. SRCS)
add_executable(test ${SRCS})
target_link_libraries(test common)
