# Variable for source files
set(SRC_UNIQ
    ${PROJECT_SOURCE_DIR}/src/uniq.cpp
)

# Specify the target and recipe - main.cpp
add_executable(myExecutable 
    main.cpp
    uniq.cpp
    )

# Specify header files location
target_include_directories(myExecutable PUBLIC ${PROJECT_SOURCE_DIR}/include)
