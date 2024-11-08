/* ***************************************************************************************************************
 * cArg.c - A small test to figure out how to handle command line arguments. A simple showcase on what can I do and
 * and what not.
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

/* ***************************************************************************************************************
 * cFile.c - A small test to figure out how to handle files. A simple showcase to check files,
 * open them and prepaire to read them.
 *
 * Compile instructions:
 * For Windows  -> gcc cFile.c -o cFile.exe
 * For MacOS    -> clang cFile.c -o cFile.bin
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

void toLowerCase(char *str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}

// ------------------------------------------------------------------------------------------------------------------
// main - In the vast, uncharted realms of cyberspace, there exists a function. Not just any function, but the main
// function. It is the gatekeeper, the sentinel that stands at the threshold of every C and C++ program. It is the
// beginning and the end, the alpha and the omega.
// @param int argc     - Command argument count
// @param char **argv  - Command argument strings
// ------------------------------------------------------------------------------------------------------------------
int main (int argc, char **argv) {

    printf("Command Line Argument Count: %d\n", argc);

    for (int i = 0; i < argc; i++) {
        
        char *argument = argv[i];
        toLowerCase(argument);

        printf("Command Line Argument: %s\n", argument);
    }
    return 0;
}