cmake_minimum_required(VERSION 3.4.1)

project(smartPtr)
aux_source_directory(. SRCS)
add_library(smartPtr ${SRCS})

