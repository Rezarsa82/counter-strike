cmake_minimum_required(VERSION 3.21)
project(counter)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

add_subdirectory(Tests)
add_subdirectory(Source)

