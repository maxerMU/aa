cmake_minimum_required(VERSION 3.5)

project(lab_06 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(COPY route.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(lab_06 main.cpp matrix.h brute.cpp brute.h ant_alg.cpp ant_alg.h ant.cpp ant.h base_comivoyadger_alg.h base_comivoyadger_alg.cpp)
