# Vincent Pierce ###################
# 08/15/2024 #######################
# root CMake #######################

cmake_minimum_required(VERSION 3.15)

# Set Project Name 
project(MyProject)

# Specify the C++ Standard
set(CMAKE_CXX_STANDARD)

# Add subdirectories containing its own CMakeLists.txt
add_subdirectory(src)

# Include the header files
#target_include_directories(myExecutable PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Include library
#target_link_libraries(myExecutable PUBLIC myLibrary)

# Printing example
#include(CMakePrintHelpers)
#cmake_print_variables(${PROJECT_SOURCE_DIR}/include)
#cmake_print_variables(${BINARY_DIR}/include)



# Git rid of malloc_safe and realloc_safe definitions inside header file, when CMake breaking because LNK1169 error, "multiple definitions of same function or variable"
# Whereever your main function is, thats the main recipe for your executable so call add_executable in the CMake in the same directory as main.cpp
# 