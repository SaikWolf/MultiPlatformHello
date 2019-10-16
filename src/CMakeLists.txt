
set(CMAKE_CXX_STANDARD 17)

message(STATUS "SRC Directories: ${PROJECT_SOURCE_DIR} ${PROJECT_BINARY_DIR} ${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR}")

include_directories("${PROJECT_SOURCE_DIR}/include")
add_executable(test tester.cpp)

add_executable(test2 tester2.cpp)
target_link_libraries(test2 LINK_PUBLIC MultiPlatformHello)