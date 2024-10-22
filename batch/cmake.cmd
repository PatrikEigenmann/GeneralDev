@echo off

:: ------------------------------------------------------------------------------------------
:: cmake.cmd - batch script to compile all *.c or all *.cpp files, or a specific .c/.cpp file
:: in the active folder. c-files will be compiled with the gcc compiler and the cpp-files will
:: be compiled with the g++ compiler. Both compilers will generate .obj files, which later on
:: can be linked into executables. If there are libraries to link to the executable, the libs
:: can be added at the end as parameters.
:: ------------------------------------------------------------------------------------------
:: author:     Patrik Eigenmann
:: email:      p.eigenmann@gmx.net
:: ------------------------------------------------------------------------------------------
:: Change Log:
:: Saturday 2023-05-27 File created.                                            Version 00.01
:: Sunday   2023-05-28 Clean up script and add comments.                        Version 00.02
:: Tuesday  2024-10-22 Recreated the script.                                    Version 00.03
:: ------------------------------------------------------------------------------------------

setlocal

if "%1"=="/c" (
    set "COMPILER=gcc"
    set "EXT=c"
) else if "%1"=="/cpp" (
    set "COMPILER=g++"
    set "EXT=cpp"
) else (
    echo Usage: cmake.cmd [/c | /cpp] [/exe | /o] [filename.extension] [additional objects...]
    exit /b 1
)

if "%2"=="/exe" (
    set "OUTPUT=.exe"
    set "CFLAGS="
) else if "%2"=="/o" (
    set "OUTPUT=.o"
    set "CFLAGS=-c"
) else (
    echo Usage: cmake.cmd [/c | /cpp] [/exe | /o] [filename.extension] [additional objects...]
    exit /b 1
)

set "FILENAME=%3"
shift
shift
shift

if not "%FILENAME%"=="" (
    echo Compiling %FILENAME%...
    %COMPILER% %FILENAME% %* %CFLAGS% -o %FILENAME:~0,-2%%OUTPUT%
) else (
    for %%f in (*.%EXT%) do (
        echo Compiling %%f...
        %COMPILER% %%f %CFLAGS% -o %%~nf%OUTPUT%
    )
)

endlocal