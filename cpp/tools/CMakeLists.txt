# Minimum required version of CMake
cmake_minimum_required(VERSION 3.0)

# Project name
project(pmake)

# Set the C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Add the executable
add_executable(pmake pmake.c)