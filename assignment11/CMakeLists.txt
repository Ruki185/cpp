cmake_minimum_required(VERSION 3.0.0)
project(a11 VERSION 0.0.0)

set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(a11 main.cpp renderer.cpp treeprocessor.cpp)

target_compile_options(a11 PRIVATE -Wall -Wextra -pedantic -Werror)