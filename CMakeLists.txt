cmake_minimum_required(VERSION 3.20)
project(Course C)

set(CMAKE_C_STANDARD 11)

add_executable(Course main.c)

add_subdirectory(libs)
target_link_libraries(Course data_structures)
target_link_libraries(Course algorithms)
