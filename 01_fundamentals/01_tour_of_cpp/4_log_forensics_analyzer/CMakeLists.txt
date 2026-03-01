cmake_minimum_required(VERSION 3.10)
project(LogForensicsAnalyzer VERSION 1.0)

# Enforce C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable highest warnings and optimizations
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O3 -march=native")

# Create the executable from all source files
add_executable(log_analyzer
    src/main.cpp
    src/log_analyzer.cpp
    src/log_generator.cpp
)

# Tell CMake where to find your .h files
target_include_directories(log_analyzer PRIVATE ${CMAKE_SOURCE_DIR}/include)
