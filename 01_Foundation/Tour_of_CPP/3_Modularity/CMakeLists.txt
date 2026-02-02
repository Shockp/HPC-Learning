# Iterate over all items in Exercises
file(GLOB children RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/Exercises ${CMAKE_CURRENT_SOURCE_DIR}/Exercises/*)

foreach(child ${children})
    if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Exercises/${child})
        # Find all .cpp files in the subdirectory
        file(GLOB_RECURSE source_files "${CMAKE_CURRENT_SOURCE_DIR}/Exercises/${child}/*.cpp")
        
        # Create executable with the name of the folder
        add_executable(${child} ${source_files})
    endif()
endforeach()
