cmake_minimum_required(VERSION 3.22)
project(OperatingSystems_Assignment1 C)

set(CMAKE_C_STANDARD 17)

add_executable(OperatingSystems_Assignment1 encode.c)

target_link_libraries(OperatingSystems_Assignment1 -ldl)


