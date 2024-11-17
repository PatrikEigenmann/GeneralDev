#!/bin/bash
# ************************************************************************************
# cdget.sh - Script will create a copy of the desired template in the desired folder.
# cdget.sh <option: -py>	<path> <filename>		{for python files}
# cdget.sh <option: -php>	<path> <filename>		{for php files}
# cdget.sh <option: -wphp>	<path> <filename>		{for web php files}
# cdget.sh <option: -c>		<path> <filename>		{for c files}
# cdget.sh <option: -cpp>	<path> <filename>		{for c++ files}
# cdget.sh <option: -h>		<path> <filename>		{for c\c++ header files}
# cdget.sh <option: -j>		<path> <filename>		{for java class files}
# cdget.sh <option: -b>		<path> <filename>		{for bash files}
# cdget.sh <option: -?>					        {call the help}
# ------------------------------------------------------------------------------------
# Author:		Patrik Eigenmann
# eMail:		p.eigenmann@gmx.net
# ------------------------------------------------------------------------------------
# Change Log:
# Tuesday	2023-06-13	File created.                                   Version: 00.01
# Tuesday	2023-06-13	-py	    python files implemented.	            Version: 00.02
# Tuesday	2023-06-13	-php	php files implemented.		            Version: 00.03
# Tuesday	2023-06-13	-wphp	web php files implemented.	            Version: 00.04
# Tuesday	2023-06-13	-c	    files implemented.		                Version: 00.05
# Tuesday	2023-06-13	-cpp	c++ files implemented.		            Version: 00.06
# Tuesday	2023-06-13	-h	    c\c++ header files implemented.	        Version: 00.06
# Wednesday	2023-06-14	-b	    bash files implemented.		            Version: 00.07
# Wednesday	2023-06-14	-?	    call the help manpages style.	        Version: 00.08
# Wednesday	2023-06-14	Moved script into a working release.	        Version: 01.00
# Wednesday	2023-12-22	-c#	    c# class file implemented	            Version: 01.01
# ************************************************************************************

# ---------------------------------------------------------------------
# display_help - displayes a helpful description alla man pages style.
# A brief description of all the parameters and how to use the script.
# ---------------------------------------------------------------------
display_help () {
    echo "NAME:"
    echo "      cdget.sh - Version: 01.00"
    echo " "
    echo "SYNOPSIS:"
    echo "      cdget.sh <option: -py,php,wphp,c,cpp,h,j,?> <path> <filename>"
    echo " "
    echo "DESCRIPTION:"
    echo "      The script will make a copy of a specified template to make coder's"
    echo "      life very easy. All parameters explained as follows!"
    echo " "
    echo "      -?"
    echo "          Option -? displays this help file. With calling the help file,"
    echo "          no other parameter are required!"
    echo " "
    echo "      -py"
    echo "          Option -py to get a python template in the working folder."
    echo " "
    echo "      -php"
    echo "          Option -php to get a PHP template in the working folder."
    echo " "
    echo "      -wphp"
    echo "          Option -wphp to get a Website PHP template in the working folder."
    echo " "
    echo "      -c"
    echo "          Option -c to get a c program template in the working folder."
    echo " "
    echo "      -c"
    echo "          Option -c to get a c program template in the working folder."
    echo " "
    echo "      -cpp"
    echo "          Option -cpp to get a c++ program template in the working folder."
    echo " "
    echo "      -h"
    echo "          Option -h to get a c/C++ header template in the working folder."
    echo " "
    echo "      -j"
    echo "          Option -j to get a java class template in the working folder."
    echo " "
    echo "      -b"
    echo "          Option -b to get a bash script template in the working folder."
    echo " "
    echo "      <path>"
    echo "          The secod parameter defines the path. It can be either ./ or a name."
    echo " "
    echo "      <filename>"
    echo "          The third parameter defines the filename with a given name."
    echo " "
    echo "AUTHOR:"
    echo "      Written by Patrik Eigenmann. My email is p.eigenmann@gmx.net."
    echo " "
    echo "COPYRIGHT:"
    echo "      Copyright © 2023 Free Software Foundation, Inc. This software is under the GPLv3+ license."
    echo "      GNU GPL version 3 or later https://gnu.org/licenses/gpl.html."
    echo "      This is free software: you are free to change and redistribute it. There is NO WARRANTY, to the extent"
    echo "      permitted by law."
    
}

x=1
language=""
filename=""

# -----------------------------
# Parameter loop
# -----------------------------
for p in $@
do
	if [ $x -eq 1 ]; then
		language="$p"
	fi

	if [ $x -eq 2 ]; then
		filename=$p
	fi

	x=$(( x + 1 ))
done

# -----------------------------
# Python section
# -----------------------------
if [ $language = "-py" ]; then
	cp ~/development/templates/python_template.py $filename.py
fi

# -----------------------------
# PHP section
# -----------------------------
if [ $language = "-php" ]; then
	cp ~/development/templates/php_template.php $filename.php
fi

# -----------------------------
# Web-PHP section
# -----------------------------
if [ $language = "-wphp" ]; then
	cp ~/development/templates/www-php_template.php $filename.php
fi

# -----------------------------
# c-Program section
# -----------------------------
if [ $language = "-c" ]; then
	cp ~/development/templates/c_template.c $filename.c
fi

# -----------------------------
# c#-Program section
# -----------------------------
if [ $language = "-c#" ]; then
	cp ~/development/templates/c#_template.cs $filename.cs
fi

# -----------------------------
# c++ Program section
# -----------------------------
if [ $language = "-cpp" ]; then
	cp ~/development/templates/cpp_template.cpp $filename.cpp
fi

# -----------------------------
# C\C++ Header section
# -----------------------------
if [ $language = "-h" ]; then
	cp ~/development/templates/header_template.h $filename.h
fi

# -----------------------------
# Java Class section
# -----------------------------
if [ $language = "-j" ]; then
	cp ~/development/templates/java_template.java $filename.java
fi

# -----------------------------
# bash files sections
# -----------------------------
if [ $language = "-b" ]; then
	cp ~/development/templates/bash_template.sh $filename.sh
fi

# -----------------------------
# Help section
# -----------------------------
if [ $language = "-?" ]; then
	display_help
fi
