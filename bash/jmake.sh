#!/bin/bash

# ---------------------------------------------------------------------
# Script: jmake.sh - Java Compiler.sh
# ---------------------------------------------------------------------
# Compiles all java files in the project folder. No parameter so far.
# ---------------------------------------------------------------------
# Author: Patrik Eigenmann
# Contact: p.eigenmann@gmx.net
# ---------------------------------------------------------------------
# Change Log:
# Sunday	2023-05-07	File created.
# ---------------------------------------------------------------------
find -name "*.java" > sources.txt
javac @sources.txt
rm sources.txt