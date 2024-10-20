#! /bin/sh
# ----------------------------------------------------------------------------
# cmake.sh - Compile all the .c and .cpp files with either the gcc or
# the g++ in the active folder.
# ----------------------------------------------------------------------------
# Author: Patrik Eigenmann
# Contact: p.eigenmann@gmx.net
# ----------------------------------------------------------------------------
# Change Log:
# Sat	2023-05-27	File created.				 Version 00.01
# ----------------------------------------------------------------------------

# Iterate through all the .c files and compile them with the gcc.
# Supress the warnings if there aren't any .c in the folder.
for c_files in *.c; do
  echo "gcc $c_files -o ${c_files%.c}.o"
  gcc -c $c_files -o ${c_files%.c}.o 2>/dev/null
done

for cpp_files in *.cpp; do
  echo "g++ $cpp_files -o ${cpp_files%.cpp}.o"
  g++ -c $cpp_files -o ${cpp_files%.cpp}.o 2>/dev/null
done