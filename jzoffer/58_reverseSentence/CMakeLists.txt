cmake_minimum_required(VERSION 3.4.1)

project (58_reverseSentence)
include_directories(. ../../common)
aux_source_directory(. SRCS)
add_executable(58_reverseSentence ${SRCS})
target_link_libraries(58_reverseSentence common)

