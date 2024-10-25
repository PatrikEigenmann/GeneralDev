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
:: Friday   2024-10-25 Reprogrammed the script. Now it's only handling c files. Version 00.04
:: ------------------------------------------------------------------------------------------

setlocal

if "%~1"=="" (
    echo Usage: cmake.cmd library_files...
    exit /b 1
)

set "LIBS=%*"

for %%f in (*.c) do (
    echo Compiling %%f...
    gcc %%f %LIBS% -o %%~nf.exe
)

endlocal