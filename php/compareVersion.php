#!/bin/php
<?php
/* ***************************************************************************************************
 * compareVersion.php - In this program, the compareVersions function splits the version numbers into
 * parts using the explode function. It then compares each part of the version numbers. If a version
 * number has fewer parts than the other, those missing parts are considered as 0. The function returns
 * a string indicating whether the first version number is greater than, less than, or equal to the
 * second version number. You can replace '1.2.3.4.5' and '1.2.3.5.1' with your version numbers.
 * ---------------------------------------------------------------------------------------------------
 * Author:       Patrik Eigenmann
 * eMail:        p.eigenmann@gmx.net
 * ---------------------------------------------------------------------------------------------------
 * Sat	2023-12-23		File created.													Version: 00.01
 * ***************************************************************************************************/

// ---------------------------------------------------------------------------------------------------
// function compareVersion($version1, $version2)
// @param1 $version1 - string of a version number
// @param2 $version2 - string of a version number
// @return int
//      - if $version1 < $version2 return -1
//      - if $version1 > $version2 return 1
//      - if $version1 = $version2 return 0
function compareVersions($version1, $version2) {
    $parts1 = explode('.', $version1);  // Split the $version1 string at '.' and create an array of it
    $parts2 = explode('.', $version2);  // Split the $version2 string at '.' and create an array of it

    // Iterate through the arrays and compare the parts
    for ($i = 0; $i < max(count($parts1), count($parts2)); $i++) {
        $part1 = $parts1[$i] ?? 0;
        $part2 = $parts2[$i] ?? 0;

        // if part1 is great than part2
        if ($part1 > $part2) {
            return 1;       // exit loop and return 1
        } 
        // or if part1 is smaller than part2
        elseif ($part1 < $part2) {
            return -1;      // exit loop and return -1
        }
    }

    return 0;
}

// Test the function
echo "Result :".compareVersions('1.2.3.4.5', '1.2.3.5.1')."\n";
echo "Result :".compareVersions('1.2.3.5.1', '1.2.3.4.5')."\n";
echo "Result :".compareVersions('1.2.3.4.5', '1.2.3.4.5')."\n";
?>

