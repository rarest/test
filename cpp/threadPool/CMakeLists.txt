cmake_minimum_required(VERSION 3.4.1)

project(threadPool)
aux_source_directory(. SRCS)
add_library(threadPool ${SRCS})

