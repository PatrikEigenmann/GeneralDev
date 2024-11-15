@echo off
:: --------------------------------------------------------------------------------------------------------
:: The cdget.cmd batch file exemplifies streamlined and efficient project setup by automating the creation
:: and population of development directories with the necessary templates. This utility not only enhances
:: productivity but also ensures consistency and organization across various programming languages.
::
:: This batch file simplifies the initial setup process for new projects, enabling developers to focus on
:: coding rather than manual setup tasks. By adopting the cdget.cmd batch file, you are investing in a more
:: organized, efficient, and productive workflow.
:: --------------------------------------------------------------------------------------------------------
:: author:     Patrik Eigenmann
:: email:      p.eigenmann@gmx.net
:: --------------------------------------------------------------------------------------------------------
:: Change Log:
:: Sat 2023-12-30 File created                                                                  Version 00.01
:: Sat 2023-12-30 Python file added                                                             Version 00.02
:: Sat 2023-12-30 PHP file added                                                                Version 00.03
:: Sat 2023-12-30 Perl file added                                                               Version 00.04
:: Sat 2023-12-30 Java file added                                                               Version 00.05
:: Sat 2023-12-30 C# file added                                                                 Version 00.06
:: Sat 2023-12-30 C file added                                                                  Version 00.07
:: Sat 2023-12-30 C++ file added                                                                Version 00.08
:: Sat 2023-12-30 C/C++ Header file added                                                       Version 00.09
:: Wed 2024-11-13 Description added.                                                            Version 00.10
:: Thu 2024-11-14 Added the Java starter program.                                               Version 00.11
:: --------------------------------------------------------------------------------------------------------

setlocal

set language=%~1
set filename=%~2

:: Python section
if "%language%"=="-py" (
    copy "D:\Development\templates\python_template.py" "%filename%.py"
)

:: PHP section
if "%language%"=="-php" (
    copy "D:\Development\templates\php_template.php" "%filename%.php"
)

:: Perl section
if "%language%"=="-pl" (
    copy "D:\Development\templates\perl_template.pl" "%filename%.pl"
)

:: Java section
if "%language%"=="-java" (
    copy "D:\Development\templates\java_template.java" "%filename%.java"
)

:: C# section
if "%language%"=="-c#" (
    copy "D:\Development\templates\c#_template.cs" "%filename%.cs"
)

:: C section
if "%language%"=="-c" (
    copy "D:\Development\templates\c_template.c" "%filename%.c"
)

:: C++ section
if "%language%"=="-cpp" (
    copy "D:\Development\templates\cpp_template.cpp" "%filename%.cpp"
)

:: C Header section
if "%language%"=="-h" (
    copy "D:\Development\templates\header_template.h" "%path%\%filename%.h"
)

:: Java starter C program section
if "%language%"=="-cj" (
    copy "D:\Development\templates\c_java_template.c" "%filename%.c"
)

:: Batch section
if "%language%"=="-cmd" (
    copy "D:\Development\templates\batch_template.cmd" "%filename%.cmd"
)
endlocal