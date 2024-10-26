#! /bin/sh
# -----------------------------------------------------------------------------------------
# cmake.sh - batch script to compile all *.c files in the active folder. The .c files will
# compiled with the gcc compiler. If you have libraries to compile with it, just give them
# as command line parameters to the script and the gcc compiler will take care of it.
# -----------------------------------------------------------------------------------------
# Author: Patrik Eigenmann
# Contact: p.eigenmann@gmx.net
# -----------------------------------------------------------------------------------------
# Change Log:
# Sat	2023-05-27	File created.				                                        Version 00.01
# Fri 2024-10-25  Revised bash script.                                        Version 00.02
# -----------------------------------------------------------------------------------------

# Check if any libraries are provided
LIBS="$@"

for file in *.c; do
    echo "Compiling $file..."
    gcc $file $LIBS -o "${file%.c}.out"
done