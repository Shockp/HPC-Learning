cmake_minimum_required(VERSION 3.10)
project(GenericSolver VERSION 1.0)

# Enforce C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable highest warnings and optimizations
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O3 -march=native")

# Create the executable from the source file
add_executable(solver src/main.cpp)

# Tell CMake where to find your .h files
target_include_directories(solver PRIVATE ${CMAKE_SOURCE_DIR}/include)