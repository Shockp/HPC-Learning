cmake_minimum_required(VERSION 3.28)

project(HPC_Engineer VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set global compiler options
if(MSVC)
    add_compile_options(/O2 /W4)
else()
    add_compile_options(-O3 -march=native -Wall -Wextra -Wpedantic)
endif()

# Add subdirectories
add_subdirectory(01_Foundation/Tour_of_CPP)
