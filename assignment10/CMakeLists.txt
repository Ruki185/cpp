cmake_minimum_required(VERSION 3.0.0)
project(a10 VERSION 0.0.0)

set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(a10 main.cpp objects.cpp)

target_compile_options(a10 PRIVATE -Wall -Wextra -pedantic -Werror)