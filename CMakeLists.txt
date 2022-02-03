cmake_minimum_required(VERSION 3.21)
project(vectorLab C)

set(CMAKE_C_STANDARD 23)

add_executable(vectorLab main.c libs/data_structures/vector/vector.c libs/data_structures/vector/vector.h)
