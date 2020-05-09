cmake_minimum_required(VERSION 3.4.1)

project (common)

aux_source_directory(. SRCS)
add_library(common ${SRCS})
