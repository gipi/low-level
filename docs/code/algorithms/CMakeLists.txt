cmake_minimum_required(VERSION 3.5)

project(algorithms LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(algorithms SHARED
  linked.cpp
  linked.h
)

add_executable(test test.cpp)
target_link_libraries(test algorithms)

#target_compile_definitions(algorithms PRIVATE ALGORITHMS_LIBRARY)
