cmake_minimum_required(VERSION 3.10)

project(Objektinis VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB SOURCES "src/*.cpp" "src/*.h")

add_executable(Objektinis ${SOURCES})
