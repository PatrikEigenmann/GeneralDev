@echo off
:: ------------------------------------------------------------------------------------------
:: cmake.cmd - batch script to compile all *.c files in the active folder. The .c files will
:: compiled with the gcc compiler. If you have libraries to compile with it, just give them
:: as command line parameters to the script and the gcc compiler will take care of it.
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

set "LIBS="
if not "%~1"=="" (
    set "LIBS=%*"
)

for %%f in (*.c) do (
    echo Compiling %%f...
    gcc %%f %LIBS% -o %%~nf.exe
)

endlocal