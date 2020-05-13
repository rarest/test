cmake_minimum_required(VERSION 3.4.1)

project (24_reverseList)
include_directories(. ../common)
aux_source_directory(. SRCS)
add_executable(24_reverseList ${SRCS})
target_link_libraries(24_reverseList common)
