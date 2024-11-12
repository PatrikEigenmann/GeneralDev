/* ***************************************************************************************************************
 * The cArg.c program is a straightforward yet powerful demonstration of handling command-line arguments in C.
 * Designed to test and showcase effective string manipulation, this program highlights key techniques for
 * processing user inputs directly from the command line, essential for building interactive and user-friendly
 * applications.
 * 
 * This program serves as an excellent educational tool and a foundation for developing more complex command-line
 * applications, ultimately contributing to a more polished and efficient software development process.
 * 
 * Compile instructions:
 * For Windows  -> gcc cArg.c -o cArg
 * For MacOS    -> clang cArg.c -o cArg
 * ---------------------------------------------------------------------------------------------------------------
 * Author:       Patrik Eigenmann
 * eMail:        p.eigenmann@gmx.net
 * ---------------------------------------------------------------------------------------------------------------
 * Sun 2024-02-04 File created.                                                                     Version: 00.01
 * Tue 2024-11-05 Crossplatform tests.                                                              Version: 00.02
 * ***************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* ---------------------------------------------------------------------------------------------------------------
 * By encapsulating the process of converting strings to lowercase within this method, we ensure a seamless and
 * efficient way to standardize text. This method not only enhances the maintainability and readability of your
 * codebase, but also guarantees that string transformations are performed consistently and reliably.
 * 
 * Adopting the toLowerCase method will streamline your text processing tasks, fostering better organization and
 * uniformity, and ultimately contributing to a more polished and user-friendly product.
 * 
 * @param char *str - The string to be converted to lowercase.
 * --------------------------------------------------------------------------------------------------------------- */
void toLowerCase(char *str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}

/* ------------------------------------------------------------------------------------------------------------------
 * main - In the vast, uncharted realms of cyberspace, there exists a function. Not just any function, but the main
 * function. It is the gatekeeper, the sentinel that stands at the threshold of every C and C++ program. It is the
 * beginning and the end, the alpha and the omega.
 * 
 * @param int argc     - Command argument count
 * @param char **argv  - Command argument strings
 * ------------------------------------------------------------------------------------------------------------------ */
int main (int argc, char **argv) {

    printf("Command Line Argument Count: %d\n", argc);

    for (int i = 0; i < argc; i++) {
        
        char *argument = argv[i];
        toLowerCase(argument);

        printf("Command Line Argument: %s\n", argument);
    }
    return 0;
}