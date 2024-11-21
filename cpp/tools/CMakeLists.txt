# ------------------------------------------------------------------------------------
# Makefile for the project pmake. Compile instruction to compile the c project.
# cmake will compile the project pmake.
# ------------------------------------------------------------------------------------
# Author: Patrik Eigenmann (p.eigenmann@gmx.net)
# ------------------------------------------------------------------------------------
# Change Log:
# Sat 2024-11-16 File created.                                          Version: 00.01
# Sun 2024-11-17 Changed the configuration to fit the project.          Version: 00.02
# ------------------------------------------------------------------------------------
# Specify the C and C++ compilers
set(CMAKE_C_COMPILER "C:/Program Files/mingw64/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/Program Files/mingw64/bin/g++.exe")

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