# 1. VERSION CHECK
# We require CMake 3.20 or newer.
# WHY: This ensures we have modern support for C++20 features and better
# handling of different compilers (like MSVC vs GCC) without weird bugs.
cmake_minimum_required(VERSION 3.20)

# 2. PROJECT DEFINITION
# Defines the project name and its version.
# WHY: Standard practice. It also automatically detects your compiler
# (GCC, Clang, or MSVC) so we can check for it later.
project(Tour_of_CPP VERSION 1.0)

# 3. C++ STANDARD (The "Modern" Rule)
# Request C++20.
# WHY: Necessary for 'consteval', 'concepts', and modern ranges used in HPC.
set(CMAKE_CXX_STANDARD 20)

# Force the compiler to fail if it doesn't support C++20.
# WHY: Prevents "silent failures" where code might compile as C++17
# but break your modern features.
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Disable compiler-specific extensions (like GCC's Variable Length Arrays).
# WHY: Google Style Guide mandates standard-compliant code. This ensures
# your code is portable and follows strict ISO C++ rules.
set(CMAKE_CXX_EXTENSIONS OFF)

# 4. COMPILER FLAGS (The "Performance & Safety" Block)
# Check if we are using Visual Studio (MSVC).
if(MSVC)
    # /O2 = Maximize Speed (Letter 'O', not Zero).
    # /W4 = Warning Level 4 (Strict warnings).
    add_compile_options(/O2 /W4)
else()
    # If using GCC or Clang (Linux/Mac/WSL):
    # -O3: Aggressive optimization (inlining, loop unrolling).
    # -march=native: HPC OPTIMIZATION. Tells the compiler to use specific
    #   instructions (AVX, etc.) for *your* specific CPU.
    # -Wall -Wextra -Wpedantic: Google Style safety. Catches bugs and
    #   non-standard code usage.
    add_compile_options(-O3 -march=native -Wall -Wextra -Wpedantic)
endif()

# 5. FILE DISCOVERY
# Scan the "Tour_of_CPP" folder (and all subfolders) for .cpp files.
# GLOB_RECURSE: Looks inside subdirectories too.
# CONFIGURE_DEPENDS: Automatically re-runs CMake if you add a new file.
# pattern: */Exercises/*.cpp looks into "Any Folder -> Exercises -> .cpp"
# WHY: Automates the build. You can add "2_UserDefined_Types/Exercises/NewTask.cpp"
# and simply run 'make' without editing this file again.
file(GLOB_RECURSE EXERCISE_SOURCES CONFIGURE_DEPENDS 
    "${CMAKE_CURRENT_SOURCE_DIR}/*/Exercises/*.cpp"
)

# 6. EXECUTABLE GENERATION LOOP
# Loop through every .cpp file found in the step above.
foreach(SOURCE_FILE ${EXERCISE_SOURCES})

    # A. GET FILE NAME
    # Extract the file name WITHOUT the extension (e.g., "1_Physics.cpp" -> "1_Physics").
    get_filename_component(EXE_NAME ${SOURCE_FILE} NAME_WE)

    # B. GET FOLDER STRUCTURE
    # Get the directory where this source file lives.
    get_filename_component(PARENT_DIR ${SOURCE_FILE} DIRECTORY)

    # Calculate the path relative to the main project folder.
    # Example: If file is in "1_The_Basics/Exercises", this variable becomes "1_The_Basics/Exercises".
    # WHY: We need this to tell CMake to recreate this specific folder structure inside 'build'.
    file(RELATIVE_PATH RELATIVE_PATH_STR ${CMAKE_CURRENT_SOURCE_DIR} ${PARENT_DIR})

    # C. CREATE EXECUTABLE
    # Create the executable target.
    add_executable(${EXE_NAME} ${SOURCE_FILE})

    # D. ORGANIZE OUTPUT
    # Tell CMake to put the finished binary into "build/<RelativePath>".
    # PROPERTIES RUNTIME_OUTPUT_DIRECTORY: The setting that controls where the .exe/.out goes.
    set_target_properties(${EXE_NAME} PROPERTIES 
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${RELATIVE_PATH_STR}"
    )

    # Print a log message to the terminal.
    # WHY: Sanity check to see exactly where files are going.
    message(STATUS "Compiling ${EXE_NAME} -> build/${RELATIVE_PATH_STR}/${EXE_NAME}")

endforeach()