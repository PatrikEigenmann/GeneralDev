#!/bin/python
# ***************************************************************************************************************************
# versionCompare.py - In this Python program, the compare_versions function splits the version numbers into parts using the
# split method and compares each part of the version numbers. If a version number has fewer parts than the other, those
# missing parts are not considered. The function returns a string indicating whether the first version number is greater than,
# less than, or equal to the second version number. You can replace '1.2.3.4.5' and '1.2.3.5.1' with your version numbers. 
# ---------------------------------------------------------------------------------------------------------------------------
# Author:       Patrik Eigenmann
# eMail:        p.eigenmann@gmx.net
# ---------------------------------------------------------------------------------------------------------------------------
# <day>		<date>          File created.							                                           Version: 00.01
# ***************************************************************************************************************************

# ---------------------------------------------------------------------------------------------------
# function compareVersion($version1, $version2)
# @param1 version1 - string of a version number
# @param2 version2 - string of a version numbe
# @return int
#      - if version1 < version2 return -1
#      - if version1 > version2 return 1
#      - if version1 = version2 return 0
# ---------------------------------------------------------------------------------------------------
def compare_versions(version1, version2):
    parts1 = [int(part) for part in version1.split('.')]    # Splitting version1 at '.' and create an array out of it
    parts2 = [int(part) for part in version2.split('.')]    # Splitting version2 at '.' and create an array out of it

    for part1, part2 in zip(parts1, parts2):
        if part1 > part2:
            return 1
        elif part1 < part2:
            return -1

    if len(parts1) > len(parts2):
        return 1
    elif len(parts1) < len(parts2):
        return -1

    return 0

# Test the function
print("{} {}".format("Result :",compare_versions('1.2.3.4.5', '1.2.3.5.1')))
print("{} {}".format("Result :",compare_versions('1.2.3.5.1', '1.2.3.4.5')))
print("{} {}".format("Result :",compare_versions('1.2.3.4.5', '1.2.3.4.5')))
