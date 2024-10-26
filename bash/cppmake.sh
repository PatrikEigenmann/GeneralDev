#! /bin/sh
# -------------------------------------------------------------------------------------------
# cmake.sh - bash script to compile all *.cpp files in the active folder. The .cpp files will
# compiled with the clang++ compiler. If you have libraries to compile with it, just give them
# as command line parameters to the script and the clang++ compiler will take care of it.
# -------------------------------------------------------------------------------------------
# Author: Patrik Eigenmann
# Contact: p.eigenmann@gmx.net
# -------------------------------------------------------------------------------------------
# Change Log:
# Sat 2023-05-27 File created.                                                  Version 00.01
# Fri 2024-10-25 Revised bash script.                                           Version 00.02
# -------------------------------------------------------------------------------------------

# Check if any libraries are provided
LIBS="$@"

for file in *.cpp; do
    echo "Compiling $file..."
    clang++ $file $LIBS -o "${file%.c}.bin"
done