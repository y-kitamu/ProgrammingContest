cmake_minimum_required(VERSION 3.10)
project(contest)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS_DEBUG "")
set(CMAKE_XCC_FLAGS_RELEASE "-O3")

include(../cmake/utility.cmake)

add_subdirectory(book)
