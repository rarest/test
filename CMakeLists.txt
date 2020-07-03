cmake_minimum_required(VERSION 3.4.1)

project(interview)

if (NOT CMAKE_BUILD_TYPE)
    SET(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif (NOT CMAKE_BUILD_TYPE)

list(APPEND CMAKE_CXX_FLAGS "-std=c++14")

#make libs
macro(make_lib libname dir)
    file(GLOB src
            ${dir}/*.h
            ${dir}/*.cpp)
    add_library(${libname} ${src})
endmacro()

#make exes
macro(make_exe lib dir libs includes)
    file(GLOB src
            ${dir}/*.h
            ${dir}/*.cpp
            )
    add_executable(${lib} ${src})
    target_link_libraries(${lib} ${libs})
    target_include_directories(${lib} PRIVATE ${includes})

endmacro()

#search sub dirs
macro(sub_dir_list result dir)
    file(GLOB children RELATIVE ${dir} ${dir}/*)
    set(dirlist "")
    foreach(child ${children})
        if(IS_DIRECTORY ${dir}/${child})
            LIST(APPEND dirlist ${child})
        endif()
    endforeach()
    set(${result} ${dirlist})
endmacro()

#make common lib
make_lib(common ${CMAKE_SOURCE_DIR}/common)

set(LIBS ${LIBS} common)

set(INCLUDES ${INCLUDES} ${CMAKE_SOURCE_DIR}/common)

#search dirs in src
sub_dir_list(src_sub_dirs ${CMAKE_SOURCE_DIR}/src)

#make exe for each sub dirs for dirs in src
foreach (src_sub_dir ${src_sub_dirs})
    sub_dir_list(${src_sub_dir} ${CMAKE_SOURCE_DIR}/src/${src_sub_dir})
    foreach (demo ${${src_sub_dir}})
        set(NAME ${src_sub_dir}_${demo})
        make_exe(${NAME} ${CMAKE_SOURCE_DIR}/src/${src_sub_dir}/${demo} ${LIBS} ${INCLUDES})
    endforeach (demo)
endforeach (src_sub_dir)
