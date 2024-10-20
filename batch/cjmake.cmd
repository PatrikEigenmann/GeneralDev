@echo off

:: ------------------------------------------------------------------------------------------------------
:: cjmake.cmd - batch script to compile and link a specific
:: c program as a wrapper to start a java application.
::
:: call cjmake.cmd <project-name>
:: ------------------------------------------------------------------------------------------------------
:: author:     Patrik Eigenmann
:: email:      p.eigenmann@gmx.net
:: ------------------------------------------------------------------------------------------------------
:: Change Log:
:: Sun 2023-05-27 File created and tested.                                                  Version 00.01
:: ------------------------------------------------------------------------------------------------------

setlocal

set projectname=%~1

gcc -o ".\%projectname%.exe" ".\%projectname%.c"