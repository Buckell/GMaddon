cmake_minimum_required(VERSION 3.23)
project(gmaddon)

set(CMAKE_CXX_STANDARD 20)

set(FMT_LIB_INCLUDE "C:\\dev\\staging\\fmt-9.1.0\\include")
set(FMT_LIB_SOURCE "C:/dev/staging/fmt-9.1.0/src")

include_directories(
    "${CMAKE_SOURCE_DIR}/include"
    "${FMT_LIB_INCLUDE}"
)

file(GLOB_RECURSE SOURCE_FILES
        "${FMT_LIB_SOURCE}/format.cc"
        "${FMT_LIB_SOURCE}/os.cc"
)

add_executable(gmaddon main.cpp ${SOURCE_FILES})
