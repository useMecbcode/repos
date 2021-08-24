cmake_minimum_required(VERSION 3.20)
project(RenderRect C)

set(CMAKE_C_STANDARD 11)
link_libraries(SDL2)
add_executable(RenderRect main.c)
