cmake_minimum_required (VERSION 3.10.2)
project (tp-lab-7)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lsfml-graphics -lsfml-window -lsfml-system")


set(tool_dest "bin")
set(lib_dest "lib")
set(include_dest "include/")

add_subdirectory(src)
add_compile_options(-lsfml-graphics -lsfml-window -lsfml-system)