cmake_minimum_required(VERSION 3.0.0)
project(a07 VERSION 0.0.0)

add_executable(a07 main.cpp)

target_compile_options(a07 PRIVATE -Wall -Wextra -pedantic)