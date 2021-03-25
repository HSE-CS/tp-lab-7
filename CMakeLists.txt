cmake_minimum_required(VERSION 3.10.2)
project(tp-lab-7)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -g")
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)


set(tool_dest "bin")
set(lib_dest "lib")
set(include_dest "include/")

add_subdirectory(src)
