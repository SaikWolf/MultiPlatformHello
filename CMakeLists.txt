cmake_minimum_required(VERSION 3.0)
project(MultiPlatformHello VERSION 1.0.0)

message(STATUS "Directories: ${PROJECT_SOURCE_DIR} ${PROJECT_BINARY_DIR} ${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR}")

add_subdirectory(lib)
add_subdirectory(src)