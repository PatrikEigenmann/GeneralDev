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
 * Sun 2024-02-04 File created.                                                                   Version: 00.01
 * ***************************************************************************************************************/
#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char **argv) {

    if(_access("test.txt", 0) != 0) {
        
        printf("File doesn't exist! Writing it.\n");
        FILE *file = fopen("test.txt", "w");
        
        if (file == NULL) {
            printf("Error opening file!\n");
            return 1;
        }

        fprintf(file, "Hello C World!\n");
        fprintf(file, "AUTHOR\n");
        fprintf(file, "      Patrik Eigenmann (p.eigenmann@gmx.net).\n");
        fprintf(file, "\n");
        fprintf(file, "COPYRIGHT\n");
        fprintf(file, "      Copyright © 2024 Free Software Foundation, Inc. License GPLv3+:\n");
        fprintf(file, "      GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>.\n");
        fprintf(file, "      This is free software: you are free to change and redistribute it.\n");
        fprintf(file, "      There is NO WARRANTY, to the extent permitted by law.\n");
        
        // Now we can close the file.
        fclose(file);
    }

    system("more test.txt");

    return 0;
}