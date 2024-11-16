@echo off
:: ----------------------------------------------------------------------------------------------------------
:: The "hello.cmd" script serves as an introductory tool for understanding and utilizing batch scripting.
:: This simple yet effective script demonstrates the basics of batch file operations, providing a clear and
:: accessible example of how to automate tasks using the command line.
::
:: By running "hello.cmd," users can quickly grasp the fundamentals of scripting, making it an ideal starting
:: point for both beginners and those looking to refresh their skills. This script embodies simplicity and
:: functionality, paving the way for more complex scripting and automation tasks in the future.
:: ----------------------------------------------------------------------------------------------------------
:: author:     Patrik Eigenmann
:: email:      p.eigenmann@gmx.net
:: ----------------------------------------------------------------------------------------------------------
:: Change Log:
:: Thu 2024-11-14 File created                                                                  Version 00.01
:: ----------------------------------------------------------------------------------------------------------

:: Setting the string into the variable message.
set message=Hello Batch World!

:: Display the string in the variable message.
echo %message%