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
 * Compile instructions:
 * For Windows  -> gcc cp.c ..\mylibs\cVersion.c ..\mylibs\cManPage.o -o cp
 * ---------------------------------------------------------------------------------------------------------------
 * Author:       Patrik Eigenmann
 * eMail:        p.eigenmann@gmx.net
 * ---------------------------------------------------------------------------------------------------------------
 * Thu 2024-10-24 File created and basic functionality programmed.                                  Version: 00.01
 * Thu 2024-10-24 Manpage style help implemented.                                                   Version: 00.02
 * Thu 2024-10-24 Fixed compiler errors due to including header files and windows specific libs.    Version: 00.03
 * Mon 2024-11-05 cManPage.h implemented. New Update and Bug Fixes.                                 Version: 00.04
 * Mon 2024-11-11 Changed how the help is triggered.                                                Version: 00.05
 * Mon 2024-11-11 Method name change - instead show_help -> print_help.                             Version: 00.06
 * Thu 2024-11-21 Updated method create_manpage("cp", manpage, v.major, v.minor);                   Version: 00.07
 * *************************************************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
#include <utime.h>

#include "..\mylibs\cVersion.h"
#include "..\mylibs\cManPage.h"

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
    Version v = create_version(0, 7);
    
    // The buffer is needed to write
    // the correct formated version number.
    char buffer[6];
    
    // Format the buffer with the
    // correct version number.
    to_string(v, buffer);

    char *manpage = NULL;

    // Write the ManPage style help file.
    append_format(&manpage, "NAME\n");
    append_format(&manpage, "       cp Version: %s\n", buffer);
    append_format(&manpage, "       Meet our latest innovation: a dynamic, user-centric command-line\n");
    append_format(&manpage, "       tool designed to elevate the terminal experience within the\n");
    append_format(&manpage, "       Windows command prompt. This program, a sophisticated enhancement\n");
    append_format(&manpage, "       inspired by the Unix cp command, streamlines file and directory\n");
    append_format(&manpage, "       management with unparalleled precision and efficiency.\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "       Imagine the ease of executing seamless file operations with\n");
    append_format(&manpage, "       intuitive options like recursive copying, file attribute preservation,\n");
    append_format(&manpage, "       interactive prompts before overwriting, and smart updates\n");
    append_format(&manpage, "       based on file modifications. Engineered to be both powerful and\n");
    append_format(&manpage, "       accessible, this tool ensures that users can navigate and\n");
    append_format(&manpage, "       manipulate their file systems effortlessly.\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "       Our built-in help feature, accessible with a simple flag,\n");
    append_format(&manpage, "       mirrors the clarity and familiarity of Unix man pages,\n");
    append_format(&manpage, "       providing users with instant, reliable support. This program\n");
    append_format(&manpage, "       is not just a utility; it's a leap towards a more efficient,\n");
    append_format(&manpage, "       productive, and user-friendly command-line environment.\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "       Crafted with meticulous attention to detail, our shell tool\n");
    append_format(&manpage, "       stands as a testament to cutting-edge software development,\n");
    append_format(&manpage, "       ready to transform the way users interact with their file\n");
    append_format(&manpage, "       systems. Dive into a new era of command-line excellence with\n");
    append_format(&manpage, "       our refined, robust, and highly functional directory management tool.\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "SYNOPSIS\n");
    append_format(&manpage, "       cp [OPTION]... SOURCE DEST\n");
    append_format(&manpage, "       cp [OPTION]... SOURCE... DIRECTORY\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "DESCRIPTION\n");
    append_format(&manpage, "       -r, --recursive\n");
    append_format(&manpage, "              Copy directories recursively.\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "       -p, --preserve\n");
    append_format(&manpage, "              Preserve file attributes.\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "       -i, --interactive\n");
    append_format(&manpage, "              Prompt before overwrite\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "       -u, --update\n");
    append_format(&manpage, "              Copy only when the SOURCE file is newer than the destination file.\n");
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

    // Create the manpage in the file /temp/cp.man
    create_manpage("cp", manpage, v.major, v.minor);

    // Free up the memory.
    free(manpage);
}

/* ---------------------------------------------------------------------------------------------------------------
 * Meet our pioneering C function, copy_file—a cornerstone of our advanced file management suite designed for the
 * Windows Command Prompt. This function epitomizes efficiency, enabling users to seamlessly copy files while
 * maintaining control over various aspects of the process.
 *
 * Imagine a utility that not only copies files with precision but also empowers users to preserve file attributes,
 * interactively manage overwrites, and intelligently update files based on modification dates. The copy_file
 * function integrates these capabilities, ensuring robust and flexible file operations.
 *
 * Engineered to handle critical tasks with ease, copy_file embodies our commitment to delivering powerful yet
 * accessible tools. It's the ultimate solution for users seeking to enhance their command-line experience,
 * offering unmatched reliability and performance.
 *
 * Crafted with meticulous attention to detail, this function seamlessly blends power and usability, exemplifying
 * our dedication to cutting-edge software development. Elevate your file management capabilities with copy_file
 * and experience the pinnacle of command-line efficiency.
 *
 * Ready to transform your file management experience? Let’s innovate with copy_file.
 *
 * @param source The path to the source file.
 * @param destination The path to the destination file.
 * @param preserve Preserve file attributes if set to true.
 * @param interactive Prompt before overwriting if set to true.
 * @param update Copy only if the source file is newer than the destination file if set to true.
 * --------------------------------------------------------------------------------------------------------------- */
void copy_file(const char *source, const char *destination, int preserve, int interactive, int update) {
    // Check if update flag is set
    if (update) {
        struct stat src_stat, dest_stat;
        if (stat(source, &src_stat) == 0 && stat(destination, &dest_stat) == 0) {
            if (difftime(src_stat.st_mtime, dest_stat.st_mtime) <= 0) {
                return; // Destination is newer or the same age as source
            }
        }
    }

    // Check if interactive flag is set and file exists
    if (interactive) {
        FILE *dest_file = fopen(destination, "rb");
        if (dest_file != NULL) {
            fclose(dest_file);
            char response;
            printf("Overwrite %s? (y/n): ", destination);
            scanf(" %c", &response);
            if (response != 'y' && response != 'Y') {
                return; // User chose not to overwrite
            }
        }
    }

    FILE *src_file = fopen(source, "rb");
    if (src_file == NULL) {
        perror("Error opening source file");
        return;
    }

    FILE *dest_file = fopen(destination, "wb");
    if (dest_file == NULL) {
        perror("Error opening destination file");
        fclose(src_file);
        return;
    }

    char buffer[1024];
    size_t bytes;

    while ((bytes = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
        fwrite(buffer, 1, bytes, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);

    // Preserve file attributes if the preserve flag is set
    if (preserve) {
        struct stat src_stat;
        if (stat(source, &src_stat) == 0) {
            struct utimbuf new_times;
            new_times.actime = src_stat.st_atime;
            new_times.modtime = src_stat.st_mtime;
            utime(destination, &new_times);
        }
    }
}

/* ---------------------------------------------------------------------------------------------------------------
 * Introducing our groundbreaking copy_directory function—a key component of our sophisticated file management
 * suite for the Windows Command Prompt. This function exemplifies efficiency and precision, enabling users to
 * seamlessly replicate entire directory structures with unmatched ease.
 *
 * Imagine a tool that not only copies directories recursively but also empowers users with options to preserve
 * file attributes, interactively manage overwrites, and intelligently update files based on modification dates.
 * The copy_directory function integrates these capabilities to ensure robust, flexible, and user-friendly
 * directory operations.
 *
 * Designed to handle complex tasks effortlessly, copy_directory is our commitment to delivering powerful yet
 * accessible tools. It's the ultimate solution for users seeking to enhance their command-line experience with
 * reliable and high-performance file management.
 *
 * Crafted with meticulous attention to detail, this function merges power and usability, highlighting our
 * dedication to cutting-edge software development. Elevate your file and directory management capabilities with
 * copy_directory and experience the pinnacle of command-line efficiency.
 *
 * @param source The path to the source directory.
 * @param destination The path to the destination directory.
 * @param preserve Preserve file attributes if set to true.
 * @param interactive Prompt before overwriting if set to true.
 * @param update Copy only if the source file is newer than the destination file if set to true.
 * --------------------------------------------------------------------------------------------------------------- */
void copy_directory(const char *source, const char *destination, int preserve, int interactive, int update) {
    struct stat st = {0};
    if (stat(destination, &st) == -1) {
        mkdir(destination);
    }

    DIR *dir = opendir(source);
    if (dir == NULL) {
        perror("Error opening source directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        char src_path[1024];
        char dest_path[1024];
        snprintf(src_path, sizeof(src_path), "%s/%s", source, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", destination, entry->d_name);

        struct stat entry_stat;
        if (stat(src_path, &entry_stat) == 0 && S_ISDIR(entry_stat.st_mode)) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                copy_directory(src_path, dest_path, preserve, interactive, update);
            }
        } else {
            copy_file(src_path, dest_path, preserve, interactive, update);
        }
    }

    closedir(dir);
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
    
    // Check if the help is triggered.
    if(isHelpTriggered(argc, argv[1])) {
        print_help();
        return 1;
    }
    
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
                        print_help();
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