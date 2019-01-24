cmake_minimum_required(VERSION 3.10)

if( CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR AND NOT MSVC_IDE )
    message(FATAL_ERROR "You can't build in the root directory.")
endif()

set(CMAKE_CXX_STANDARD 17)

add_executable(ZiApiTest main.cpp API/IModule.hpp API/IHttpRequest.hpp API/IHttpResponse.hpp API/ZiLogger.hpp API/ZiExcept.hpp API/AModule.hpp)

target_include_directories(ZiApiTest PRIVATE "API")

target_compile_options(ZiApiTest PRIVATE -g3)