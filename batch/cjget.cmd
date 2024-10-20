@echo off
:: --------------------------------------------------------------------------------------------------------
:: cjget.cmd - Script to copy the c-template from the repository to specifically create dos application that
:: start the java virtual machine to run a specific java program.
::
:: call cjget.cmd <projectname> WARNING - you have to be in the actual folder you want to work in.
:: --------------------------------------------------------------------------------------------------------
:: author:     Patrik Eigenmann
:: email:      p.eigenmann@gmx.net
:: --------------------------------------------------------------------------------------------------------
:: Change Log:
:: Sat 2023-12-30   File created and tested.                                                  Version 00.01
:: Sun 2024-09-01   Changed name to cjget -> c/java get                                       Version 00.02
:: --------------------------------------------------------------------------------------------------------

setlocal

set projectname=%~1

copy "D:\Development\templates\c_java_template.c" ".\%projectname%.c"