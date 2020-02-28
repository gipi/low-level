cmake_minimum_required(VERSION 3.5)

project(algorithms LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(algorithms SHARED
  linked.cpp
  tree.h
  linked.h
  stack.h
  strbuilder.h
  strbuilder.cpp
  arraylist.h
  arraylist.cpp
)

add_executable(test test.cpp)
add_executable(test_linked test_linked.cpp)
add_executable(test_stack test_stack.cpp)
target_link_libraries(test algorithms)

#target_compile_definitions(algorithms PRIVATE ALGORITHMS_LIBRARY)
