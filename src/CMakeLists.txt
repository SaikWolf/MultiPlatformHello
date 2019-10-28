
set(CMAKE_CXX_STANDARD 17)

message(STATUS "SRC Directories: ${PROJECT_SOURCE_DIR} ${PROJECT_BINARY_DIR} ${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR}")

include_directories("${PROJECT_SOURCE_DIR}/include")
add_executable(test tester.cpp)
IF(MSVC)
    target_compile_options(test PUBLIC /EHsc /W4)
ENDIF(MSVC)

add_executable(test2 tester2.cpp)
target_link_libraries(test2 LINK_PUBLIC MultiPlatformHello)
IF(MSVC)
    target_compile_options(test2 PUBLIC /EHsc /W4)
ENDIF(MSVC)

add_executable(test3 tester3.cpp)
IF(MSVC)
    target_compile_options(test3 PUBLIC /EHsc /W4)
ENDIF(MSVC)