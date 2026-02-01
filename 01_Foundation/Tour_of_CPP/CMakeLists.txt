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
# Scan the "Basics/Exercises" folder (and all subfolders) for .cpp files.
# GLOB_RECURSE: Looks inside subdirectories too.
# EXERCISE_SOURCES: The variable where the list of files is stored.
# WHY: Automates the build so you don't have to list every file manually.
file(GLOB_RECURSE EXERCISE_SOURCES "Basics/Exercises/*.cpp")

# 6. EXECUTABLE GENERATION LOOP
# Loop through every .cpp file found in the step above.
foreach(SOURCE_FILE ${EXERCISE_SOURCES})
    
    # Extract the file name WITHOUT the extension (e.g., "1_Physics.cpp" -> "1_Physics").
    # NAME_WE = Name Without Extension.
    # EXE_NAME: Holds this clean name.
    get_filename_component(EXE_NAME ${SOURCE_FILE} NAME_WE)

    # Create a separate executable for this specific file.
    # WHY: Since every exercise has its own 'main()' function, they cannot
    # be in the same executable. This builds them as separate programs.
    add_executable(${EXE_NAME} ${SOURCE_FILE})

    # Print a log message to the terminal.
    # WHY: sanity check. It confirms which files CMake actually found.
    message(STATUS "Compiling ${SOURCE_FILE} into ${EXE_NAME}")

endforeach()