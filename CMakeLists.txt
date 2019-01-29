cmake_minimum_required(VERSION 3.10)

if( CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR AND NOT MSVC_IDE )
    message(FATAL_ERROR "You can't build in the root directory.")
endif()

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "-Wextra -Wall -O3 -Woverloaded-virtual -Wlogical-op")

add_executable(ZiApiTest main.cpp)

include_directories(API/)
include_directories(API/HTTP)
include_directories(API/utils)

target_include_directories(ZiApiTest PRIVATE "API")

target_compile_options(ZiApiTest PRIVATE -g3)