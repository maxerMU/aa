cmake_minimum_required(VERSION 3.16)
project(src)

set(CMAKE_CXX_STANDARD 17)

find_package(Threads REQUIRED)
add_executable(src main.cpp Conveyor/Conveyor.cpp Conveyor/Conveyor.h)

target_link_libraries(src PRIVATE Threads::Threads)
