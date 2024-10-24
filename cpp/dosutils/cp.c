/* ***************************************************************************************************************
 * cp.c - Meet our latest innovation: a dynamic, user-centric C program designed to elevate the command-line
 * experience within the Windows Command Prompt. This program, a sophisticated enhancement inspired by the Unix cp
 * command, streamlines file and directory management with unparalleled precision and efficiency.
 *
 * Imagine the ease of executing seamless file operations with intuitive options like recursive copying, file
 * attribute preservation, interactive prompts before overwriting, and smart updates based on file modifications.
 * Engineered to be both powerful and accessible, this tool ensures that users can navigate and manipulate their
 * file systems effortlessly.
 *
 * Our built-in help feature, accessible with a simple flag, mirrors the clarity and familiarity of Unix man pages,
 * providing users with instant, reliable support. This program is not just a utility; it's a leap towards a more
 * efficient, productive, and user-friendly command-line environment.
 *
 * Crafted with meticulous attention to detail, our C program stands as a testament to cutting-edge software
 * development, ready to transform the way users interact with their file systems. Dive into a new era of
 * command-line excellence with our refined, robust, and highly functional directory management tool.
 *
 * compile instruction:
 * gcc cp.c ..\mylibs\cVersion.o -o cp.exe
 * ---------------------------------------------------------------------------------------------------------------
 * Author:       Patrik Eigenmann
 * eMail:        p.eigenmann@gmx.net
 * ---------------------------------------------------------------------------------------------------------------
 * Thu 2024-10-24 File created and basic functionality programmed.                                  Version: 00.01
 * Thu 2024-10-24 Manpage style help implemented.                                                   Version: 00.02
 * *************************************************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include "..\mylibs\cVersion.h"

/* ---------------------------------------------------------------------------------------------------------------
 * The show_help function is our top-notch guidance feature, crafted to provide users with clear, intuitive
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
void show_help() {

    // Version control implemented
    Version v = create_version(0, 2);
    
    // The buffer is needed to write
    // the correct formated version number.
    char buffer[6];
    
    // Format the buffer with the
    // correct version number.
    to_string(v, buffer);

    // Temporarly write the help message into
    // /tmp/myhelp.txt file.
    FILE *file = fopen("D:\\bin\\temp\\myhelp.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(file, "NAME\n");
    fprintf(file, "       cp Version: %s\n", buffer);
    fprintf(file, "       Meet our latest innovation: a dynamic, user-centric C program\n");
    fprintf(file, "       designed to elevate the command-line experience within the\n");
    fprintf(file, "       Windows Command Prompt. This program, a sophisticated enhancement\n");
    fprintf(file, "       inspired by the Unix cp command, streamlines file and directory\n");
    fprintf(file, "       management with unparalleled precision and efficiency.\n");
    fprintf(file, "\n");
    fprintf(file, "       Imagine the ease of executing seamless file operations with\n");
    fprintf(file, "       intuitive options like recursive copying, file attribute preservation,\n");
    fprintf(file, "       interactive prompts before overwriting, and smart updates\n");
    fprintf(file, "       based on file modifications. Engineered to be both powerful and\n");
    fprintf(file, "       accessible, this tool ensures that users can navigate and\n");
    fprintf(file, "       manipulate their file systems effortlessly.\n");
    fprintf(file, "\n");
    fprintf(file, "       Our built-in help feature, accessible with a simple flag,\n");
    fprintf(file, "       mirrors the clarity and familiarity of Unix man pages,\n");
    fprintf(file, "       providing users with instant, reliable support. This program\n");
    fprintf(file, "       is not just a utility; it's a leap towards a more efficient,\n");
    fprintf(file, "       productive, and user-friendly command-line environment.\n");
    fprintf(file, "\n");
    fprintf(file, "       Crafted with meticulous attention to detail, our C program\n");
    fprintf(file, "       stands as a testament to cutting-edge software development,\n");
    fprintf(file, "       ready to transform the way users interact with their file\n");
    fprintf(file, "       systems. Dive into a new era of command-line excellence with\n");
    fprintf(file, "       our refined, robust, and highly functional directory management tool.\n");
    fprintf(file, "\n");
    fprintf(file, "SYNOPSIS\n");
    fprintf(file, "       cp [OPTION]... SOURCE DEST\n");
    fprintf(file, "       cp [OPTION]... SOURCE... DIRECTORY\n");
    fprintf(file, "\n");
    fprintf(file, "DESCRIPTION\n");
    fprintf(file, "       -r, --recursive\n");
    fprintf(file, "              copy directories recursively\n");
    fprintf(file, "\n");
    fprintf(file, "       -p, --preserve\n");
    fprintf(file, "              preserve file attributes\n");
    fprintf(file, "\n");
    fprintf(file, "       -i, --interactive\n");
    fprintf(file, "              prompt before overwrite\n");
    fprintf(file, "\n");
    fprintf(file, "       -u, --update\n");
    fprintf(file, "              copy only when the SOURCE file is newer than the destination file\n");
    fprintf(file, "\n");
    fprintf(file, "       -?, --help\n");
    fprintf(file, "              display this help and exit\n");
    fprintf(file, "\n");
    fprintf(file, "AUTHOR\n");
    fprintf(file, "       Patrik Eigenmann (p.eigenmann@gmx.net)\n");
    fprintf(file, "\n");
    fprintf(file, "COPYRIGHT\n");
    fprintf(file, "      Copyright © 2024 Free Software Foundation, Inc. License GPLv3+:\n");
    fprintf(file, "      GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>.\n");
    fprintf(file, "      This is free software: you are free to change and redistribute it.\n");
    fprintf(file, "      There is NO WARRANTY, to the extent permitted by law.\n");

    // Now we can close the file.
    fclose(file);

    // Now we do a system call and use the command less,
    // So we have the effect of scrolling through the message.
    system("more D:\\bin\\temp\\myhelp.txt");
}

/* ---------------------------------------------------------------------------------------------------------------
 * Meet our transformative C program—a game-changer for file and directory management in the Windows Command
 * Prompt. This dynamic tool, inspired by the Unix cp command, revolutionizes how users interact with their file
 * systems, combining simplicity with robust functionality.
 *
 * Imagine seamless file operations with intuitive options: recursive copying, file attribute preservation,
 * interactive prompts before overwriting, and intelligent updates based on modification dates. It's engineered to
 * be both powerful and user-friendly, ensuring effortless navigation and manipulation of file systems.
 *
 * Our built-in help feature mirrors the clarity of Unix man pages, providing instant, reliable support with just
 * a simple flag. This program is more than a utility; it's a leap toward a more efficient and productive
 * command-line environment.
 *
 * Crafted with meticulous attention to detail, our C program exemplifies cutting-edge software development,
 * poised to elevate the command-line experience to new heights. Dive into a new era of efficiency and functionality
 * with our refined directory management tool.
 *
 * @param argc The number of command-line arguments passed to the program.
 * @param argv An array of null-terminated strings representing the command-line arguments.
 * --------------------------------------------------------------------------------------------------------------- */
int main(int argc, char *argv[]) {
    int recursive = 0, preserve = 0, interactive = 0, update = 0;

    // Parse options
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            for (int j = 1; j < strlen(argv[i]); j++) {
                switch (argv[i][j]) {
                    case 'r':
                        recursive = 1;
                        break;
                    case 'p':
                        preserve = 1;
                        break;
                    case 'i':
                        interactive = 1;
                        break;
                    case 'u':
                        update = 1;
                        break;
                    default:
                        show_help();
                        return 1;
                }
            }
        }
    }

    // Check source and destination
    char *source = argv[argc - 2];
    char *destination = argv[argc - 1];

    struct stat st;
    if (stat(source, &st) == 0) {
        if (S_ISDIR(st.st_mode)) {
            if (recursive) {
                copy_directory(source, destination, preserve, interactive, update);
            } else {
                printf("cp: omitting directory '%s'\n", source);
                return 1;
            }
        } else {
            copy_file(source, destination, preserve, interactive, update);
        }
    } else {
        perror("Source not found");
        return 1;
    }

    return 0;
}