cmake_minimum_required(VERSION 3.15)
project(brackets CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_compile_options(-Wall -Wextra -pedantic)

add_library(brackets_lib STATIC src/stack.cpp src/brackets_checker.cpp)
target_include_directories(brackets_lib PUBLIC src)

add_executable(brackets src/main.cpp)
target_link_libraries(brackets PRIVATE brackets_lib)

enable_testing()
add_executable(tests tests/tests.cpp)
target_link_libraries(tests PRIVATE brackets_lib)
add_test(NAME tests COMMAND tests)
