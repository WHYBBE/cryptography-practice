cmake_minimum_required(VERSION 3.20)
project(cryptography-practice)

set(CMAKE_CXX_STANDARD 20)

message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")

if(CMAKE_BUILD_TYPE STREQUAL Debug)
    add_compile_options(-Wall -Wextra -Werror -pedantic)
endif()

if(CMAKE_BUILD_TYPE STREQUAL Release)
    add_compile_options(-O3)
endif()

add_subdirectory(include)
add_subdirectory(src)

option(BUILD_TEST "build tests" OFF)

if(BUILD_TEST)
    add_subdirectory(test)
endif()

install(TARGETS cryptography-practice RUNTIME DESTINATION bin)
