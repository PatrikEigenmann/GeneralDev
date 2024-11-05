/* ***************************************************************************************************************
 * cManPage.h - 
 * ---------------------------------------------------------------------------------------------------------------
 * Author:       Patrik Eigenmann
 * eMail:        p.eigenmann@gmx.net
 * ---------------------------------------------------------------------------------------------------------------
 * Mon 2024-10-28 File created.                                                                     Version: 00.01
 * Mon 2024-11-04 Fixed all bugs around the string concatination.                                   Version: 00.02
 * ***************************************************************************************************************/

#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "cManPage.h"

const char *FILE_EXTENTION = ".man";

// MacOS is "temp/";
// Windows is "temp\\";
char *PATH = "temp\\";

void create_manpage(char *filenameIn, char *manualIn) {

    ManPage mp;

    mp.filename = NULL;
    append_format(&mp.filename, PATH);
    append_format(&mp.filename, filenameIn);
    append_format(&mp.filename, FILE_EXTENTION);

    mp.manual = NULL;
    append_format(&mp.manual, manualIn);

    //printf("Filename: %s\n", mp.filename);
    //printf("Manual: %s\n", mp.manual);

    if(_access(mp.filename, 0) != 0) {
        
        FILE *file = fopen(mp.filename, "w");
        
        if (file == NULL) {
            printf("Error opening file!\n");
            return;
        }

        fprintf(file, mp.manual);

        // Now we can close the file.
        fclose(file);
    }

    char command[255] = "more ";
    strcat(command, mp.filename);
    //printf("Command: %s\n", command);
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