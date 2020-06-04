cmake_minimum_required(VERSION 3.4.1)

project (59_maxInWindow)
include_directories(. ../../common)
aux_source_directory(. SRCS)
add_executable(59_maxInWindow ${SRCS})
target_link_libraries(59_maxInWindow common)

