/* *****************************************************************************************************************
 * Our custom "pmake" program is designed to empower developers by streamlining the build process with simplicity and
 * efficiency. Tailored specifically for flexibility, it reads configuration files, interprets instructions, and
 * executes commands to compile and build projects seamlessly. By offering an intuitive and robust solution, our Make
 * program not only enhances productivity but also ensures consistency across various development environments. This
 * tool is an essential asset for any development team, enabling faster turnaround times and improved project
 * management.
 *
 * Compile information:
 * gcc pmake.c ..\mylibs\cVersion.o ..\mylibs\cManPage.o -o pmake
 * -----------------------------------------------------------------------------------------------------------------
 * Author:       Patrik Eigenmann
 * eMail:        p.eigenmann@gmx.net
 * ------------------------------------------------------------------------------------------------------------------
 * Fri 2024-11-15 File created.                                                                         Version: 00.01
 * Sat 2024-11-16 Rearranged the whole program and renamed it. Fixed some bug too.                      Version: 00.02
 * Sat 2024-11-16 Bug Fix in putting the compiler command togheter.                                     Version: 00.03
 * Sat 2024-11-16 Rearranged the function process_makefile to a more concice top down way.              Version: 00.04
 * Sat 2024-11-16 BugFix - in function process_makefile compiling with the -c flad didn't work.         Version: 00.05
 * Sat 2024-11-16 Another BugFix - in the function process_makefile, adding .o ending when compiling    Version: 00.06
 *                with the -c flag.
 * ------------------------------------------------------------------------------------------------------------------
 * To Do's:
 * ******************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
    #include "..\mylibs\cVersion.h"
    #include "..\mylibs\cManPage.h"
#else
    #include "../mylibs/cVersion.h"
    #include "../mylibs/cManPage.h"
#endif

#define MAX_LINE_LENGTH 256

/* ---------------------------------------------------------------------------------------------------------------
 * The print_help function is our top-notch guidance feature, crafted to provide users with clear, intuitive
 * instructions for leveraging our command-line utility within the Windows Command Prompt environment. Think of it
 * as your personal guide, always ready to offer step-by-step explanations for each option available in the tool.
 *
 * When users invoke this function, they receive a straightforward and well-structured breakdown of all possible
 * commands, ensuring they can navigate directory listings with ease and efficiency. With familiar flags like -l and
 * -a, the experience feels intuitive, mirroring the user-friendly nature of Unix systems, but optimized for the
 * Windows Command Prompt.
 *
 * In essence, show_help embodies our commitment to user empowerment, making sure every feature is accessible and
 * easily understood. This minimizes learning curves and maximizes productivity. This function is the cornerstone
 * of our user-centric approach, providing instant, reliable support whenever needed. Welcome to a new era of
 * intuitive, efficient command-line interaction.
 * --------------------------------------------------------------------------------------------------------------- */
void print_help() {

    // Version control implemented
    Version v = create_version(0, 6);
    
    // The buffer is needed to write
    // the correct formated version number.
    char buffer[6];
    
    // Format the buffer with the
    // correct version number.
    to_string(v, buffer);

    char *manpage = NULL;

    // Write the ManPage style help file.
    append_format(&manpage, "NAME\n");
    append_format(&manpage, "       pmake Version: %s\n", buffer);
    append_format(&manpage, "       Our custom \"pmake\" program is designed to empower developers by\n");
    append_format(&manpage, "       streamlining the build process with simplicity and efficiency.\n");
    append_format(&manpage, "       Tailored specifically for flexibility, it reads configuration files,\n");
    append_format(&manpage, "       interprets instructions, and executes commands to compile and build\n");
    append_format(&manpage, "       projects seamlessly. By offering an intuitive and robust solution,\n");
    append_format(&manpage, "       our pmake program not only enhances productivity but also ensures\n");
    append_format(&manpage, "       consistency across various development environments. This tool is\n");
    append_format(&manpage, "       an essential asset for any development team, enabling faster\n");
    append_format(&manpage, "       turnaround times and improved project management.\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "SYNOPSIS\n");
    append_format(&manpage, "       pmake <makefile>\n");
    append_format(&manpage, "       pmake <-h\\-help\\-H\\-Help>\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "DESCRIPTION\n");
    append_format(&manpage, "       <makefile> The name of the makefile with the build instructions\n");
    append_format(&manpage, "       to be processed.\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "           Example Makefile myproject.makefile:\n");
    append_format(&manpage, "           ---------------------------------------\n");
    append_format(&manpage, "           # Define the compiler and flags\n");
    append_format(&manpage, "           comp=gcc\n");
    append_format(&manpage, "           cflags = -Wall -Wextra -std=c11 (optional)\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "           # Define the target executable or object\\library files\n");
    append_format(&manpage, "           target=exec or\n");
    append_format(&manpage, "           target=obj\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "           # Define the source files\n");
    append_format(&manpage, "           src=main.c (optional)\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "           # Define the project name\n");
    append_format(&manpage, "           project=myproject\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "           # Define the library files\n");
    append_format(&manpage, "           libs=../mylibs/lib1.o ../mylibs/lib2.o\n");
    append_format(&manpage, "           ---------------------------------------\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "       -h, -help -H -Help\n");
    append_format(&manpage, "              Display this help and exit.\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "AUTHOR\n");
    append_format(&manpage, "       Patrik Eigenmann (p.eigenmann@gmx.net)\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "COPYRIGHT\n");
    append_format(&manpage, "      Copyright 2024 Free Software Foundation, Inc. License GPLv3+:\n");
    append_format(&manpage, "      GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>.\n");
    append_format(&manpage, "      This is free software: you are free to change and redistribute it.\n");
    append_format(&manpage, "      There is NO WARRANTY, to the extent permitted by law.\n");

    // Create the manpage in the file
    create_manpage("pmake", manpage);

    // Free up the memory.
    free(manpage);
}

/* ---------------------------------------------------------------------------------------------------------------
 * The process_makefile function is a pivotal component of our custom "Make" program, designed to streamline the
 * build process by reading and executing commands from a specified makefile. This function ensures efficient
 * parsing and execution of build instructions, enhancing productivity and simplifying project management for
 * developers.
 *
 * @param filename The name of the makefile to be processed. This file contains the build instructions to be executed.
 * --------------------------------------------------------------------------------------------------------------- */
void process_makefile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    
    char line[MAX_LINE_LENGTH];
    char comp[50] = "gcc";
    char cflags[100] = "";
    char target[10] = "exec";
    char project[50] = "";
    char src[500] = "";
    char libs[500] = "";
    
    while (fgets(line, sizeof(line), file)) {
        // Trim newline character
        line[strcspn(line, "\n")] = 0;
        
        // Skip empty lines or comments
        if (line[0] == '\0' || line[0] == '#') continue;
        
        // Parse the makefile variables
        if (strncmp(line, "comp=", 5) == 0) {
            strcpy(comp, line + 5);
        } else if (strncmp(line, "cflags=", 7) == 0) {
            strcpy(cflags, line + 7);
        } else if (strncmp(line, "target=", 7) == 0) {
            strcpy(target, line + 7);
        } else if (strncmp(line, "project=", 8) == 0) {
            strcpy(project, line + 8);
        } else if (strncmp(line, "src=", 4) == 0) {
            strcpy(src, line + 4);
        } else if (strncmp(line, "libs=", 5) == 0) {
            strcpy(libs, line + 5);
        }
    }
    
    fclose(file);

    char *command = NULL;

    append_format(&command, "%s ", comp);

    if(cflags[0] != '\0')
        append_format(&command, "%s ", cflags);

    if(target[0] != 'e')
        append_format(&command, "-c ");

    if(src[0] != '\0')
        append_format(&command, "%s ", src);
    else
        append_format(&command, "%s.c ", project);

    if(libs[0] != '\0')
        append_format(&command, "%s ", libs);

    if(target[0] != 'e')
        append_format(&command, "-o %s.o", project);
    else
        append_format(&command, "-o %s", project);

    printf("Compiling command:\n");
    printf("%s\n", command);

    // Execute the command
    int result = system(command);
    
    if (result != 0) {
        fprintf(stderr, "Command failed: %s\n", command);
        exit(EXIT_FAILURE);
    }
}

/* ---------------------------------------------------------------------------------------------------------------
 * main - In the vast, uncharted realms of cyberspace, there exists a function. Not just any function, but the main
 * function. It is the gatekeeper, the sentinel that stands at the threshold of every C and C++ program. It is the
 * beginning and the end, the alpha and the omega.
 *
 * int argc     - Command argument count
 * char **argv  - Command argument strings
 * --------------------------------------------------------------------------------------------------------------- */
int main (int argc, char **argv) {

    // Check if the help is triggered.
    if(isHelpTriggered(argc, argv[1])) {
        print_help();
        return 1;
    }

    process_makefile(argv[1]);
    return EXIT_SUCCESS;
}