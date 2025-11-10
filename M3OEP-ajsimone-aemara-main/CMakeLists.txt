cmake_minimum_required(VERSION 3.15)
project(M2OEP-ajsimone-aemara)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Automatically collect all .cpp files in the project directory
file(GLOB SOURCES "*.cpp")

# Create the executable with all source files
add_executable(${PROJECT_NAME} ${SOURCES})
