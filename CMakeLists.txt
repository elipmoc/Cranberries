cmake_minimum_required(VERSION 2.8)

project(cranberries)

set(DEBUG_FLAGS "-std=c++14 -g -O1 -Wall -Wextra -pedantic")
set(RELEASE_FLAGS "-std=c++14 -O3 -Wall -Wextra -pedantic")

set(CMAKE_CXX_FLAGS ${RELEASE_FLAGS})
set(CMAKE_CXX_FLAGS_DEBUG ${DEBUG_FLAGS})
set(CMAKE_CONFIGURATION_TYPES Debug Release)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR})

enable_testing()

add_subdirectory(test)