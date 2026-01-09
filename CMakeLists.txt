cmake_minimum_required(VERSION 3.10)
project(ComputerVisionProject)

# Set the path to OpenCV
set(OpenCV_DIR "${CMAKE_SOURCE_DIR}/opencv")

# Find OpenCV
find_package(OpenCV REQUIRED)

if(OpenCV_FOUND)
    message(STATUS "OpenCV library status:")
    message(STATUS "    version: ${OpenCV_VERSION}")
    message(STATUS "    libraries: ${OpenCV_LIBS}")
    message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")
else()
    message(FATAL_ERROR "OpenCV not found in ${OpenCV_DIR}")
endif()

# Include directories
include_directories(${OpenCV_INCLUDE_DIRS})

# Create executable
add_executable(main main.cpp)

# Link libraries
target_link_libraries(main ${OpenCV_LIBS})
