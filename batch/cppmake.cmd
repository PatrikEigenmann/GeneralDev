@echo off
:: ------------------------------------------------------------------------------------------
:: cppmake.cmd - batch script to compile all *.cpp files in the active folder. The .cpp files
:: will compiled with the g++ compiler. If you have libraries to compile with it, just give
:: them as command line parameters to the script and the g++ compiler will take care of it.
:: ------------------------------------------------------------------------------------------
:: author:     Patrik Eigenmann
:: email:      p.eigenmann@gmx.net
:: ------------------------------------------------------------------------------------------
:: Change Log:
:: Friday   2024-10-25 File created.                                            Version 00.01
:: ------------------------------------------------------------------------------------------
setlocal

set "LIBS="
if not "%~1"=="" (
    set "LIBS=%*"
)

for %%f in (*.cpp) do (
    echo Compiling %%f...
    g++ %%f %LIBS% -o %%~nf.exe
)

endlocal