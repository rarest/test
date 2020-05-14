cmake_minimum_required(VERSION 3.4.1)

project(messageQueue)
aux_source_directory(. SRCS)
add_library(messageQueue ${SRCS})

