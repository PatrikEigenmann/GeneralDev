@echo off

:: ----------------------------------------------------------
:: cmake.cmd - batch script to compile all *.c and all *.cpp
:: files in the active folder. c-files will be compiled with
:: the gcc compiler and the cpp-files will be compiled with
:: the g++ compiler. Both compilers will generate .obj files,
:: which later on can be linked into executables.
:: 
:: TODO: Make the search for *.c or *.cpp recursive. Here is
:: where I'm struggeling with. If I start creating subfolders
:: for my libraries, as example my_libs\utils.h & my_libs\utils.c
:: I probably overcomplicate everything. So, I'm not sure if
:: I'll implement a recursive search in this script.
::
:: TODO: clink.cmd. The linker script. I have some Ideas;
:: <clink.cmd /[c:cpp] main my_lib1 my_lib2 my_lib3 ...> would
:: be an idea, which will create the main.exe with all libs
:: linked together. For now, I do it by hand which is:
:: "gcc main.obj my_lib1.obj my_lib2.obj my_lib3.obj -o main"
:: ----------------------------------------------------------
:: author:     Patrik Eigenmann
:: email:      p.eigenmann@gmx.net
:: ----------------------------------------------------------
:: Change Log:
:: Saturday 2023-05-27      File created.
:: Sunday   2023-05-28      Clean up script and add comments.
:: ----------------------------------------------------------

:: ----------------------------------------------------------
:: compiling all C files with the gcc compiler.
:: ----------------------------------------------------------

:: Create the compile.txt with all
:: the C source code files.
dir /S /B *.c > compile.txt

:: Going through each file and run
:: it through the gcc compiler.
::for /f %%i in (compile.txt) do (
    :: if file is at eof or
    :: there are no files found.
::    if [%%i] == [] goto :cpp
    
    :: run the compiler and create
    :: object files to link later on.
::    gcc -o %%~ni.obj -c %%i
::)

:: ----------------------------------------------------------
:: compiling all CPP files with the g++ compiler.
:: ----------------------------------------------------------
:cpp

:: Create the compile.txt with all
:: the cpp source code files.
::dir /S /B *.cpp > compile.txt

:: Going through each file and run
:: it through the gcc compiler.
::for /f %%i in (compile.txt) do (
    ::if file is at eof or
    :: there are no files found.
::    if [%%i] == [] goto :last_command

    :: run the compiler and create
    :: object files to link later on.
::    g++ -o %%~ni.obj -c %%i
::)

:: ----------------------------------------------------------
:: Section :last_command is just cleaning up after work.
:: ----------------------------------------------------------
:last_command

:: delete all temporary created files
::del compile.txt