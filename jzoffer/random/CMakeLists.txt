cmake_minimum_required(VERSION 3.4.1)

project (random)
include_directories(. ../../common)
aux_source_directory(. SRCS)
add_executable(random ${SRCS})
target_link_libraries(random common)
