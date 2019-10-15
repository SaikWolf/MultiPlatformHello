cmake_minimum_required(VERSION 3.0)
project(MultiPlatformHello VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)

message(STATUS "Directories: ${PROJECT_SOURCE_DIR} ${PROJECT_BINARY_DIR} ${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR}")

include_directories("${PROJECT_SOURCE_DIR}/include")
add_executable(test src/tester.cpp)


