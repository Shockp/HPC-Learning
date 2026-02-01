cmake_minimum_required(VERSION 3.28)

project(Tour_of_CPP VERSION 1.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
    add_compile_options(/O2 /W4)
else()
    add_compile_options(-O3 -march=native -Wall -Wextra -Wpedantic)
endif()

file(GLOB_RECURSE EXERCISE_SOURCES CONFIGURE_DEPENDS 
    "${CMAKE_CURRENT_SOURCE_DIR}/*/Exercises/*.cpp"
)

foreach(SOURCE_FILE ${EXERCISE_SOURCES})
    get_filename_component(EXE_NAME ${SOURCE_FILE} NAME_WE)
    get_filename_component(PARENT_DIR ${SOURCE_FILE} DIRECTORY)
    
    file(RELATIVE_PATH RELATIVE_PATH_STR ${CMAKE_CURRENT_SOURCE_DIR} ${PARENT_DIR})

    add_executable(${EXE_NAME} ${SOURCE_FILE})

    set_target_properties(${EXE_NAME} PROPERTIES 
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${RELATIVE_PATH_STR}"
    )

    message(STATUS "Compiling ${EXE_NAME} -> build/${RELATIVE_PATH_STR}/${EXE_NAME}")
endforeach()