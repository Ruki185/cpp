cmake_minimum_required(VERSION 3.0.0)
project(a09 VERSION 0.0.0)

add_executable(a09 main.cpp renderer.cpp)

target_compile_features(a09 PUBLIC cxx_std_14)

target_compile_options(a09 PRIVATE -Wall -Wextra -pedantic -Werror)