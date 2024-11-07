/* ***************************************************************************************************************
 * cManPage.h - 
 * ---------------------------------------------------------------------------------------------------------------
 * Author:       Patrik Eigenmann
 * eMail:        p.eigenmann@gmx.net
 * ---------------------------------------------------------------------------------------------------------------
 * Mon 2024-10-28 File created.                                                                     Version: 00.01
 * Mon 2024-11-04 Fixed all bugs around the string concatination.                                   Version: 00.02
 * Mon 2024-11-05 Cross plattform implementation.                                                   Version: 00.03
 * ***************************************************************************************************************
 * To Do:
 * - The program checks if the particular manpage exist, if not it will write it. If it exist, it will just read
 *   it. That is incorrect, what if the content of the manpage changes? It should be rewritten if content changes
 *   are made.
 * ***************************************************************************************************************/

#include "cManPage.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#ifdef _WIN32
    
    // Include Windows relevant libraries
    #include <io.h>
    
    #define _home() getenv("USERPROFILE")

    // Windows version of testing if the file exist.
    int doesFileExist(char *filename) {
        return _access(filename, 0) != -1;
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
    int doesFileExist(char *filename) {
        return access(filename, F_OK) != -1;
    }

    // The command I use under MacOS/Unix is less. Less is the equivalent
    // of the Windows more command.
    char command[255] = "less ";

    char *PATH = "/.local/share/";
#endif

const char *FILE_EXTENTION = ".man";

/*
 */
void create_manpage(char *filenameIn, char *manualIn) {

    ManPage mp;

    mp.filename = NULL;
    append_format(&mp.filename, _home());
    append_format(&mp.filename, PATH);
    append_format(&mp.filename, filenameIn);
    append_format(&mp.filename, FILE_EXTENTION);

    mp.manual = NULL;
    append_format(&mp.manual, manualIn);

    if(!doesFileExist(mp.filename)) {
        
        FILE *file = fopen(mp.filename, "w");
        
        if (file == NULL) {
            printf("Error opening file!\n");
            return;
        }

        fprintf(file, "%s", mp.manual);

        // Now we can close the file.
        fclose(file);
    }

    strcat(command, mp.filename);
    system(command);
}

void append_format(char **dest, const char *format, ...) {
    va_list args;
    va_start(args, format);
    
    va_list args_copy;
    va_copy(args_copy, args);
    int size = vsnprintf(NULL, 0, format, args_copy) + 1;
    va_end(args_copy);

    char *temp = malloc(size);
    if (temp == NULL) {
        perror("malloc failed");
        va_end(args);
        return;
    }
    
    vsprintf(temp, format, args);
    va_end(args);

    if (*dest == NULL) {
        *dest = malloc(size);
        if (*dest == NULL) {
            perror("malloc failed");
            free(temp);
            return;
        }
        strcpy(*dest, temp);
    } else {
        *dest = realloc(*dest, strlen(*dest) + size);
        if (*dest == NULL) {
            perror("realloc failed");
            free(temp);
            return;
        }
        strcat(*dest, temp);
    }
    
    free(temp);
}