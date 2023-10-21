cmake_minimum_required(VERSION 3.12)

set(CMAKE_C_COMPILER /usr/bin/clang)
set(CMAKE_CXX_COMPILER /usr/bin/clang++)
# set(CMAKE_C_COMPILER /usr/bin/gcc)
# set(CMAKE_CXX_COMPILER /usr/bin/g++)

project(contest)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "-Wall -isystem")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_XCC_FLAGS_RELEASE "-O3 -DNDEBUG")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(./cmake/utility.cmake)

include_directories(AFTER ${CMAKE_CURRENT_SOURCE_DIR}/libs)

add_subdirectory(book)
add_subdirectory(AtCoder)
add_subdirectory(CodeForces)
add_subdirectory(LeetCode)
add_subdirectory(AOJ)
add_subdirectory(AOJ2)

add_subdirectory(tests)
