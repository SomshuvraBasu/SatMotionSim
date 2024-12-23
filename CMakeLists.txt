cmake_minimum_required(VERSION 3.10)
project(SatMotionSim)

set(CMAKE_CXX_STANDARD 17)

# Specify where the header files are located
include_directories(${CMAKE_SOURCE_DIR}/include)

# Automatically include all .cpp files in the src/ directory
file(GLOB SOURCES
    ${CMAKE_SOURCE_DIR}/src/*.cpp   # For all .cpp files in the src directory
)

# Automatically include all .cpp files in the src/common/ directory
file(GLOB SOURCES_COMMON
    ${CMAKE_SOURCE_DIR}/src/common/*.cpp  # For all .cpp files in the src/common directory
)

# Automatically include all .cpp files in the src/core/ directory
file(GLOB SOURCES_CORE
    ${CMAKE_SOURCE_DIR}/src/core/*.cpp  # For all .cpp files in the src/core directory
)

# Combine all the source files into one list
list(APPEND SOURCES ${SOURCES_COMMON} ${SOURCES_CORE})

# Create the executable
add_executable(SatelliteExample ${SOURCES})
