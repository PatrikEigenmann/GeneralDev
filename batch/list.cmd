@echo off
:: ----------------------------------------------------------------------------------------------------------
:: This batch script is designed to streamline the process of listing the contents of the "C:\Program Files"
:: directory and displaying the results. By automating these tasks, the script provides a quick and efficient
:: way to generate a directory listing and immediately review the contents, enhancing productivity and
:: reducing manual effort. With built-in metadata for version control, the script maintains clarity and
:: organization, making it an essential tool for developers and IT professionals.
:: ----------------------------------------------------------------------------------------------------------
:: author:     Patrik Eigenmann
:: email:      p.eigenmann@gmx.net
:: ----------------------------------------------------------------------------------------------------------
:: Change Log:
:: Fri 2024-11-15 File created                                                                  Version 00.01
:: ----------------------------------------------------------------------------------------------------------

:: List the directory "C:\Program Files" and write it in the text file list. 
dir "C:\Program Files" > list.txt

:: Display the newly created file.
more list.txt

:: Delete the text file, because it's not used anymore.
del /Q list.txt