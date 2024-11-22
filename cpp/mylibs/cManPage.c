/* ***************************************************************************************************************
 * cManPage.c - The cManPage.c file provides an interface for managing and manipulating manual pages in C. It
 * includes essential functions and data structures for creating, modifying, and verifying manual pages, ensuring
 * cross-platform compatibility and ease of use.
 * 
 * This library file serves as a foundational component for applications that require efficient documentation
 * handling.
 * ---------------------------------------------------------------------------------------------------------------
 * Author:       Patrik Eigenmann
 * eMail:        p.eigenmann@gmx.net
 * ---------------------------------------------------------------------------------------------------------------
 * Mon 2024-10-28 File created.                                                                     Version: 00.01
 * Mon 2024-11-04 Fixed all bugs around the string concatination.                                   Version: 00.02
 * Mon 2024-11-05 Cross plattform implementation.                                                   Version: 00.03
 * Thu 2024-11-07 Take the check if the file exist away for now. Let's write it every time.         Version: 00.04
 * Thu 2024-11-21 Added major and minor to the methodes.                                            Version: 00.05
 * ***************************************************************************************************************
 * To Do:
 * - The program checks if the particular manpage exist, if not it will write it. If it exist, it will just read
 *   it. That is incorrect, what if the content of the manpage changes? It should be rewritten if content changes
 *   are made.                                                                                      -> Temporary
 * - doesFileExist methode is fixed, now I need to extensively test the method.                     -> Done
 * ***************************************************************************************************************/

#include "cManPage.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

#ifdef _WIN32
    
    // Include Windows relevant libraries
    #include <io.h>
    
    #define _home() getenv("USERPROFILE")

    /* --------------------------------------------------------------------------------------------------------
     * Windows version:
     * By encapsulating the file existence check within this method, we ensure a seamless and efficient way to
     * verify the presence of files. This method not only enhances the maintainability and readability of your
     * codebase, but also guarantees that file existence checks are performed consistently and reliably.
     * 
     * Adopting the doesFileExist method will streamline your file handling processes, fostering better
     * organization and error handling, and ultimately contributing to a more robust and user-friendly product.
     * 
     * @param char *filename - The name of the file to check for existence.
     * @return int - Returns 1 if the file exists, and 0 if it does not.
     * -------------------------------------------------------------------------------------------------------- */
    int doesFileExist(char *filename, int major, int minor) {

        int i = (_access(filename, 0) != -1);

        if(i > 0) {
            FILE *file;
            char *buffer;
            char version[100] = "\0";
            long file_size;

            // Open the file for reading
            file = fopen(filename, "r");
                        
            // Determine the file size
            fseek(file, 0, SEEK_END);
            file_size = ftell(file);
            rewind(file);
            
            // Allocate memory for the buffer
            buffer = (char *)malloc(sizeof(char) * (file_size + 1));
            
            if (buffer == NULL) {
                printf("Memory allocation failed.\n");
                fclose(file);
                return 1;
            }
            
            // Read the file content into the buffer
            fread(buffer, sizeof(char), file_size, file);
            
            // Null-terminate the string
            buffer[file_size] = '\0';
            
            
            // Close the file
            fclose(file);

            sprintf(version, "%02d.%02d", major, minor);

            i &= (strstr(buffer, version) != NULL);
        }

        return i;
    }
    
    // The command I use under Windows is more. More is the equivalent
    // of the UNIX less command.
    char command[255] = "more ";

    char *PATH = "\\AppData\\Local\\";
#else
    // Include Unix relevant libraries
    #include <unistd.h>

    #define _home() getenv("HOME")

    /* --------------------------------------------------------------------------------------------------------
     * MacOS version:
     * By encapsulating the file existence check within this method, we ensure a seamless and efficient way to
     * verify the presence of files. This method not only enhances the maintainability and readability of your
     * codebase, but also guarantees that file existence checks are performed consistently and reliably.
     * 
     * Adopting the doesFileExist method will streamline your file handling processes, fostering better
     * organization and error handling, and ultimately contributing to a more robust and user-friendly product.
     * 
     * @param char *filename - The name of the file to check for existence.
     * @return int - Returns 1 if the file exists, and 0 if it does not.
     * -------------------------------------------------------------------------------------------------------- */
    int doesFileExist(char *filename, int major, int minor) {

        int i = (access(filename, F_OK) != -1);

        if(i > 0) {
            FILE *file;
            char *buffer;
            char version[100] = "\0";
            long file_size;

            // Open the file for reading
            file = fopen(filename, "r");
                        
            // Determine the file size
            fseek(file, 0, SEEK_END);
            file_size = ftell(file);
            rewind(file);
            
            // Allocate memory for the buffer
            buffer = (char *)malloc(sizeof(char) * (file_size + 1));
            
            if (buffer == NULL) {
                printf("Memory allocation failed.\n");
                fclose(file);
                return 1;
            }
            
            // Read the file content into the buffer
            fread(buffer, sizeof(char), file_size, file);
            
            // Null-terminate the string
            buffer[file_size] = '\0';
            
            
            // Close the file
            fclose(file);

            sprintf(version, "%02d.%02d", major, minor);

            i &= (strstr(buffer, version) != NULL);
        }

        return i; 
    }

    // The command I use under MacOS/Unix is less. Less is the equivalent
    // of the Windows more command.
    char command[255] = "less ";

    char *PATH = "/.local/share/";
#endif

const char *FILE_EXTENTION = ".man";

/* ---------------------------------------------------------------------------------------------------------------
 * By encapsulating the creation of manual pages within this method, we ensure a seamless and efficient process
 * for generating documentation. This not only enhances the maintainability and readability of your codebase, but
 * also guarantees that manual pages are consistently formatted and easily accessible.
 * 
 * Adopting the create_manpage method will streamline your documentation process, fostering better organization
 * and accessibility, and ultimately contributing to a more polished and user-friendly product.
 * 
 * @param char *filenameIn - The filename to the ManPage text file.
 * @param char *manualIn - The content of the ManPage text.
 * --------------------------------------------------------------------------------------------------------------- */
void create_manpage(char *filenameIn, char *manualIn, int major, int minor) {

    ManPage mp;

    mp.filename = NULL;
    append_format(&mp.filename, _home());
    append_format(&mp.filename, PATH);
    append_format(&mp.filename, filenameIn);
    append_format(&mp.filename, FILE_EXTENTION);

    mp.manual = NULL;
    append_format(&mp.manual, manualIn);

    if(!doesFileExist(mp.filename, major, minor)) {
        
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

/* ---------------------------------------------------------------------------------------------------------------
 * By encapsulating the process of appending formatted content within this method, we ensure a seamless and
 * efficient way to dynamically build strings. This method not only enhances the maintainability and readability
 * of your codebase, but also guarantees that formatted content is appended consistently and effectively.
 * 
 * Adopting the append_format method will streamline your string manipulation tasks, fostering better organization
 * and flexibility, and ultimately contributing to a more polished and efficient product.
 * 
 * @param char **dest - The destination string to which formatted content will be appended.
 * @param const char *format - The format string.
 * @param ... - Additional arguments to format and append to the destination string.
 * --------------------------------------------------------------------------------------------------------------- */
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

/* ---------------------------------------------------------------------------------------------------------------
 * By encapsulating the detection of help command triggers within this method, we ensure a seamless and efficient
 * way to handle user requests for help or usage information. This method not only enhances the maintainability
 * and readability of your codebase but also guarantees that help commands are consistently and accurately
 * recognized.
 * 
 * Adopting the isHelpTriggered method will streamline your application's user interaction processes, fostering
 * better user experience and accessibility, and ultimately contributing to a more user-friendly product.
 * 
 * @param int argcIn - The number of command-line arguments.
 * @param char *argvIn - The first string of the command-line arguments array.
 * @return int - Returns 1 if the help command is triggered, and 0 otherwise.
 * --------------------------------------------------------------------------------------------------------------- */
int isHelpTriggered(int argcIn, char *argvIn) {
    
    /* ------------------------------------------------------- 
     * Help / Manpage is trigger if program call are like:
     *  - <program> or
     *  - <program> -h or
     *  - <program> -H or
     *  - <program> -help or
     *  - <program> -Help
     * ------------------------------------------------------- */
    return (argcIn == 1 ||
        strcmp(argvIn, "-h") == 0 ||
        strcmp(argvIn, "-H") == 0 ||
        strcmp(argvIn, "-help") == 0 ||
        strcmp(argvIn, "-Help") == 0);
}