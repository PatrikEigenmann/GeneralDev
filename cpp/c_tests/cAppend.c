/* ***************************************************************************************************************
 * cAppend.c - A small test to figure out how to handle strings in functions. A simple showcase differen ways to
 * handle strings as parameters and change the memory inside the function.
 *
 * Compile instructions:
 * For Windows  -> gcc cAppend.c -o cAppend.exe
 * For MacOS    -> clang cAppend.c -o cAppend.bin
 * ---------------------------------------------------------------------------------------------------------------
 * Author:       Patrik Eigenmann
 * eMail:        p.eigenmann@gmx.net
 * ---------------------------------------------------------------------------------------------------------------
 * Sun 2024-02-04 File created.                                                                   Version: 00.01
 * ***************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

// ---------------------------------------------------------------------------------------------------------------
// The foo function demonstrates the dynamic enhancement of a foundational string by appending a user-provided
// value. This process culminates in the display of the augmented string, showcasing the seamless integration of
// flexible string manipulation within our robust framework.
// @param String test - User provided test string.
// ---------------------------------------------------------------------------------------------------------------
void foo(char *test) {
    char string[100] = "D:\\bin\\temp\\";

    strcat(string, test);
    
    printf("String: %s.man\n", string);
}

// ------------------------------------------------------------------------------------------------------------------
// main - In the vast, uncharted realms of cyberspace, there exists a function. Not just any function, but the main
// function. It is the gatekeeper, the sentinel that stands at the threshold of every C and C++ program. It is the
// beginning and the end, the alpha and the omega.
// @param int argc     - Command argument count
// @param char **argv  - Command argument strings
// ------------------------------------------------------------------------------------------------------------------
int main() {

    foo("MyTest");
 
    return 0;
}