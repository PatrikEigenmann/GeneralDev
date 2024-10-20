@echo off
:: ----------------------------------------------------------
:: jmake - batch script to javac all *.java files in the
:: active folder. 
:: ----------------------------------------------------------
:: author:     Patrik Eigenmann
:: email:      p.eigenmann@gmx.net
:: Date:       2023-05-27
:: ----------------------------------------------------------
echo delete: old *.class files.
del *.class

echo create: compile.txt
dir *.java /B /S > compile.txt

echo execute: javac @compile.txt
javac @compile.txt

echo delete: compile.txt
del compile.txt