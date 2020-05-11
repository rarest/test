cmake_minimum_required(VERSION 3.4.1)

project (58reverse_sentence)
include_directories(. ../common)
aux_source_directory(. SRCS)
add_executable(58reverse_sentence ${SRCS})
target_link_libraries(58reverse_sentence common)

