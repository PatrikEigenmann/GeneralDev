/* ***************************************************************************************************************
 * ls.c - Introducing our new command-line utility, a sophisticated enhancement of the classic ls command designed
 * for DOS environments. This tool streamlines directory navigation with precision and efficiency, embodying the
 * elegance of simplicity combined with robust functionality. Users can now execute comprehensive directory listings,
 * leveraging switches like -l for detailed views and -a for hidden files.
 *
 * The intuitive flag system enables seamless command combinations such as -al, ensuring users get exactly the
 * information they need with minimal effort. Additionally, our user-friendly help feature, accessible via -?,
 * guides you through the command’s capabilities, mirroring the familiarity and ease of Unix man pages.
 *
 * Engineered to be both powerful and accessible, this utility empowers users to manage and explore their file
 * systems with newfound ease. Say goodbye to the cumbersome default dir command—welcome to a sleek, modern, and
 * highly functional directory listing tool. Ready to elevate your command-line experience? Dive into productivity
 * with our refined ls utility. 
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
    fprintf(file, "      ls Version: %s\n", buffer);
    fprintf(file, "      Introducing our new command-line utility, a sophisticated enhancement\n");
    fprintf(file, "      of the classic ls command designed for DOS environments. This tool\n");
    fprintf(file, "      streamlines directory navigation with precision and efficiency, embodying\n");
    fprintf(file, "      the elegance of simplicity combined with robust functionality. Users can\n");
    fprintf(file, "      now execute comprehensive directory listings, leveraging switches like -l\n");
    fprintf(file, "      for detailed views and -a for hidden files.\n");
    fprintf(file, "\n");
    fprintf(file, "      The intuitive flag system enables seamless command combinations such as\n");
    fprintf(file, "      -al, ensuring users get exactly the information they need with minimal\n");
    fprintf(file, "      effort. Additionally, our user-friendly help feature, accessible via -?,\n");
    fprintf(file, "      guides you through the command’s capabilities, mirroring the familiarity\n");
    fprintf(file, "      and ease of Unix man pages.\n");
    fprintf(file, "\n");
    fprintf(file, "      Engineered to be both powerful and accessible, this utility empowers users\n");
    fprintf(file, "      to manage and explore their file systems with newfound ease. Say goodbye\n");
    fprintf(file, "      to the cumbersome default dir command—welcome to a sleek, modern, and highly\n");
    fprintf(file, "      functional directory listing tool. Ready to elevate your command-line\n");
    fprintf(file, "      experience? Dive into productivity with our refined ls utility.\n");
    fprintf(file, "SYNOPSIS\n");
    fprintf(file, "      ls [-l\\-a\\-la\\-al\\-?]\n");
    fprintf(file, "DESCRIPTION\n");
    fprintf(file, "      -l\n");
    fprintf(file, "          Using long listing format to display the listing.\n");
    fprintf(file, "\n");
    fprintf(file, "      -a\n");
    fprintf(file, "          All files are shown, even the hidden ones.\n");
    fprintf(file, "\n");
    fprintf(file, "      -al\\-la\n");
    fprintf(file, "          Displaying hidden files and use long listing format.\n");
    fprintf(file, "\n");
    fprintf(file, "      /?\\-?\\/H\\-H\\/h\\-h\\/help\\-help\n");
    fprintf(file, "          Displaying this help and exit.\n");
    fprintf(file, "\n");
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

    // Now we do a system call and use the command less,
    // So we have the effect of scrolling through the message.
    system("more D:\\bin\\temp\\myhelp.txt");
}

/* ---------------------------------------------------------------------------------------------------------------
 * The int main(int argc, char* argv[]) function serves as the entry point for our command-line utility, designed
 * to interpret user inputs and execute the appropriate actions within the Windows Command Prompt. Acting as the
 * brains of the operation, this function seamlessly processes command-line arguments, making it possible to
 * customize and enhance directory listings on the fly.
 *
 * By accepting argc (argument count) and argv (argument vector), it skillfully handles multiple user inputs,
 * ensuring that each flag or option is correctly interpreted and executed. This robust design allows the program
 * to dynamically build the command string based on the provided arguments, whether it's a simple dir call or an
 * enhanced dir /Q /A for detailed and hidden file listings.
 *
 * Moreover, this function integrates seamlessly with our show_help feature, offering immediate assistance whenever
 * needed. It ensures users can easily access guidance on available options, minimizing confusion and maximizing
 * efficiency.
 *
 * In essence, int main(int argc, char* argv[]) embodies our commitment to creating a versatile, user-friendly tool
 * that adapts to various user needs. It drives the core functionality, translating complex user requests into
 * straightforward, executable commands, elevating the command-line experience to new heights.
 *
 * @param argc The number of command-line arguments passed to the program.
 * @param argv An array of null-terminated strings representing the command-line arguments.
 * --------------------------------------------------------------------------------------------------------------- */
int main(int argc, char *argv[]) {
    char command[100] = "dir";

    for (int i = 1; i < argc; i++) {
         for (int j = 1; j < strlen(argv[i]); j++) {
                switch (argv[i][j]) {
                    case 'l':
                        strcat(command, " /Q");
                        break;
                    case 'a':
                        strcat(command, " /A");
                        break;
                    default:
                        show_help();
                        return 1;
                }
          }
    }

    printf("Executing: %s\n", command);
    system(command);

    return 0;
}