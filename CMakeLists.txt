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

#link to the GLFW library
find_package(glfw3 3.3 REQUIRED)

# Create the executable
add_executable(SatMotionSim ${SOURCES})

# Link the GLFW library with your project
target_link_libraries(SatMotionSim PRIVATE glfw)

#link glew
find_package(GLEW REQUIRED)
target_link_libraries(SatMotionSim PRIVATE GLEW::GLEW)

#link opengl
find_package(OpenGL REQUIRED)
target_link_libraries(SatMotionSim PRIVATE OpenGL::GL)