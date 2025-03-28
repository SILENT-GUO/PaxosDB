cmake_minimum_required(VERSION 3.10)
project(PaxosDB)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)
include_directories(src)
include_directories(application)

# Collect source files
file(GLOB_RECURSE SRC_FILES
        src/*.cpp
        src/*.hpp
        include/*.hpp
        include/*.h
        application/*.cpp
)

# Collect header files (optional, for IDE purposes)
file(GLOB_RECURSE HEADER_FILES
        src/*.h
        src/*.hpp
        include/*.h
        include/*.hpp
        application/*.h
        application/*.hpp
)

# Remove main.cpp from SRC_FILES to avoid double inclusion
list(REMOVE_ITEM SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/application/main.cpp)

# Add executable
add_executable(PaxosDBSampleApplication application/main.cpp ${SRC_FILES} ${HEADER_FILES})

# Optional: Set output directory
set_target_properties(PaxosDBSampleApplication PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
