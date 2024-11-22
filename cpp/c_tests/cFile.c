/* ***************************************************************************************************************
 * The cFile.c program is an essential demonstration of handling file operations in C. This program efficiently
 * showcases how to check for file existence, open files, and prepare them for reading, providing a robust
 * foundation for more advanced file handling tasks.
 * 
 * This cross-platform program ensures compatibility with both Windows and macOS, allowing for versatile usage
 * across different operating systems. By addressing real-world file management scenarios, the cFile.c program
 * serves as a vital educational tool and a practical solution for developers.
 * 
 * Whether you are working on simple file operations or building complex file management systems, this program
 * exemplifies efficient and effective file handling techniques, ultimately contributing to a more organized and
 * reliable software development process.
 *
 * Compile instructions:
 * For Windows  -> gcc cFile.c -o cFile
 * For MacOS    -> clang cFile.c -o cFile
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

#ifdef _WIN32
    
    // Include Windows relevant libraries
    #include <io.h>
    
    #define _home() getenv("USERPROFILE")

    // Windows version of testing if the file exist.
    int doesFileExist(char *filename, char* firstln, int major, int minor) {
        char buffer[100] = "\0";
        sprintf(buffer, "%02d.%02d", major, minor);

        int test = strstr(firstln, buffer) != NULL;

        printf("%d\n", test);
        printf("%s\n", buffer);

        test &= (_access(filename, 0) != -1);

        printf("%d\n", test);

        return test;
    }
    
    // The command I use under Windows is more. More is the equivalent
    // of the UNIX less command.
    char command[255] = "more ";

    char *PATH = "\\AppData\\Local\\";    
#else
    // Include Unix relevant libraries
    #include <unistd.h>

    #define _home() getenv("HOME")

    // MacOS/Unix version of testing if the file exist.
    int doesFileExist(char *filename, char *firstln, int major, int minor) {
        
        return access(filename, F_OK) != -1;
    }

    // The command I use under MacOS/Unix is less. Less is the equivalent
    // of the Windows more command.
    char command[255] = "less ";

    char *PATH = "/.local/share/";
#endif

/* ------------------------------------------------------------------------------------------------------------------
 * main - In the vast, uncharted realms of cyberspace, there exists a function. Not just any function, but the main
 * function. It is the gatekeeper, the sentinel that stands at the threshold of every C and C++ program. It is the
 * beginning and the end, the alpha and the omega.
 * 
 * @param int argc     - Command argument count
 * @param char **argv  - Command argument strings
 * ------------------------------------------------------------------------------------------------------------------ */
int main (int argc, char **argv) {

    char *file = _home();

    char *firstline = "Hello World!v01.03\0";

    int maj = 1;
    int min = 3;


    strcat(file, PATH);
    strcat(file, "test.txt");

    printf("Filename: %s\n", file);

     if(!doesFileExist("test.txt", firstline, maj, min)) {
        
        printf("File doesn't exist! Writing it.\n");
        FILE *file = fopen("test.txt", "w");
        
        if (file == NULL) {
            printf("Error opening file!\n");
            return 1;
        }

        fprintf(file, "%s\n", firstline);
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

    strcat(command, " test.txt");
    system(command);
    
    return 0;
}