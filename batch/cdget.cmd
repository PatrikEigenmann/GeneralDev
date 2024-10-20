@echo off
:: --------------------------------------------------------------------------------------------------------
:: cdget.cmd - 
:: --------------------------------------------------------------------------------------------------------
:: author:     Patrik Eigenmann
:: email:      p.eigenmann@gmx.net
:: --------------------------------------------------------------------------------------------------------
:: Change Log:
:: Sat 2023-12-30   File created                                                              Version 01.00
:: Sat 2023-12-30   Python file added                                                         Version 01.01
:: Sat 2023-12-30   PHP file added                                                            Version 01.02
:: Sat 2023-12-30   Perl file added                                                           Version 01.03
:: Sat 2023-12-30   Java file added                                                           Version 01.04
:: Sat 2023-12-30   C# file added                                                             Version 01.05
:: Sat 2023-12-30   C file added                                                              Version 01.06
:: Sat 2023-12-30   C++ file added                                                            Version 01.07
:: Sat 2023-12-30   C/C++ Header file added                                                   Version 01.08
:: --------------------------------------------------------------------------------------------------------

setlocal

set language=%~1
set path=%~2
set filename=%~3

:: Python section
if "%language%"=="-py" (
    if not exist "D:\Development\python\%path%" mkdir "D:\Development\python\%path%"
    copy "D:\Development\templates\python_template.py" "%path%\%filename%.py"
)

:: PHP section
if "%language%"=="-php" (
    if not exist "D:\Development\php\%path%" mkdir "D:\Development\php\%path%"
    copy "D:\Development\templates\php_template.php" "%path%\%filename%.php"
)

:: Perl section
if "%language%"=="-pl" (
    if not exist "D:\Development\perl\%path%" mkdir "D:\Development\perl\%path%"
    copy "D:\Development\templates\perl_template.pl" "%path%\%filename%.pl"
)

:: Java section
if "%language%"=="-java" (
    if not exist "D:\Development\java_console\%path%" mkdir "D:\Development\java_console\%path%"
    copy "D:\Development\templates\java_template.java" "%path%\%filename%.java"
)

:: C# section
if "%language%"=="-c#" (
    if not exist "D:\Development\c#\%path%" mkdir "D:\Development\c#\%path%"
    copy "D:\Development\templates\c#_template.cs" "%path%\%filename%.cs"
)

:: C section
if "%language%"=="-c" (
    if not exist "D:\Development\c++\%path%" mkdir "D:\Development\c++\%path%"
    copy "D:\Development\templates\c_template.c" "%path%\%filename%.c"
)

:: C++ section
if "%language%"=="-cpp" (
    if not exist "D:\Development\c++\%path%" mkdir "D:\Development\c++\%path%"
    copy "D:\Development\templates\cpp_template.cpp" "%path%\%filename%.cpp"
)

:: C Header section
if "%language%"=="-h" (
    if not exist "D:\Development\c++\%path%" mkdir "D:\Development\c++\%path%"
    copy "D:\Development\templates\header_template.h" "%path%\%filename%.h"
)

endlocal