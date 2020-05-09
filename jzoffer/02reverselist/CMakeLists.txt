cmake_minimum_required(VERSION 3.4.1)

project (02reverselist)

aux_source_directory(. SRCS)
add_executable(02reverselist ${SRCS})
