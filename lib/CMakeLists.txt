
set(CMAKE_CXX_STANDARD 17)

message(STATUS "LIB Directories: ${PROJECT_SOURCE_DIR} ${PROJECT_BINARY_DIR} ${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR}")


add_library(MultiPlatformHello input.cpp)
target_include_directories(MultiPlatformHello PUBLIC ${PROJECT_SOURCE_DIR}/include)

IF(MSVC)
    target_compile_definitions(MultiPlatformHello PUBLIC MULTIPLATFORMHELLO_EXPORT)
ENDIF(MSVC)