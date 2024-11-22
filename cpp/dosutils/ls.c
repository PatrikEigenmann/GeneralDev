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
 *
 * compile instruction:
 * Windows: gcc ls.c ..\mylibs\cVersion.o ..\mylibs\cManPage.o -o ls
 * ---------------------------------------------------------------------------------------------------------------
 * Author:       Patrik Eigenmann
 * eMail:        p.eigenmann@gmx.net
 * ---------------------------------------------------------------------------------------------------------------
 * Thu 2024-10-24 File created and basic functionality programmed.                                  Version: 00.01
 * Thu 2024-10-24 Manpage style help implemented.                                                   Version: 00.02
 * Mon 2024-11-04 cManPage implemented. New Updates and Bug Fixes.                                  Version: 00.03
 * Mon 2024-11-05 cManPage.h implemented. New Update and Bug Fixes.                                 Version: 00.04
 * Mon 2024-11-11 Changed how the help is triggered.                                                Version: 00.05
 * Mon 2024-11-11 Method name change - instead show_help -> print_help.                             Version: 00.06
 * Thu 2024-11-21 Updated method create_manpage("ls", manpage, v.major, v.minor);                   Version: 00.07
 * *************************************************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    append_format(&manpage, "      ls Version: %s\n", buffer);
    append_format(&manpage, "      Introducing our new command-line utility, a sophisticated enhancement\n");
    append_format(&manpage, "      of the classic ls command designed for DOS environments. This tool\n");
    append_format(&manpage, "      streamlines directory navigation with precision and efficiency, embodying\n");
    append_format(&manpage, "      the elegance of simplicity combined with robust functionality. Users can\n");
    append_format(&manpage, "      now execute comprehensive directory listings, leveraging switches like -l\n");
    append_format(&manpage, "      for detailed views and -a for hidden files.\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "      The intuitive flag system enables seamless command combinations such as\n");
    append_format(&manpage, "      -al, ensuring users get exactly the information they need with minimal\n");
    append_format(&manpage, "      effort. Additionally, our user-friendly help feature, accessible via -?,\n");
    append_format(&manpage, "      guides you through the commands capabilities, mirroring the familiarity\n");
    append_format(&manpage, "      and ease of Unix man pages.\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "      Engineered to be both powerful and accessible, this utility empowers users\n");
    append_format(&manpage, "      to manage and explore their file systems with newfound ease. Say goodbye\n");
    append_format(&manpage, "      to the cumbersome default dir command—welcome to a sleek, modern, and highly\n");
    append_format(&manpage, "      functional directory listing tool. Ready to elevate your command-line\n");
    append_format(&manpage, "      experience? Dive into productivity with our refined ls utility.\n");
    append_format(&manpage, "SYNOPSIS\n");
    append_format(&manpage, "      ls [-l\\-a\\-la\\-al\\-h\\-H\\-help\\-Help]\n");
    append_format(&manpage, "DESCRIPTION\n");
    append_format(&manpage, "      -l\n");
    append_format(&manpage, "          Using long listing format to display the listing.\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "      -a\n");
    append_format(&manpage, "          All files are shown, even the hidden ones.\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "      -al\\-la\n");
    append_format(&manpage, "          Displaying hidden files and use long listing format.\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "      -H\\-h\\-Help\\-help\n");
    append_format(&manpage, "          Displaying this help and exit.\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "AUTHOR\n");
    append_format(&manpage, "      Patrik Eigenmann (p.eigenmann@gmx.net).\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "COPYRIGHT\n");
    append_format(&manpage, "      Copyright 2024 Free Software Foundation, Inc. License GPLv3+:\n");
    append_format(&manpage, "      GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>.\n");
    append_format(&manpage, "      This is free software: you are free to change and redistribute it.\n");
    append_format(&manpage, "      There is NO WARRANTY, to the extent permitted by law.\n");

    // Create the manpage in the file /temp/ls.man
    create_manpage("ls", manpage, v.major, v.minor);

    // Free up the memory.
    free(manpage);
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

    // Check if the help is triggered. For the ls command, the
    // help needs to be only triggered, when there is the command
    // line argument -h or -H or -help -Help. ls alone should
    // just list the files. Thank you.
    if(argc != 1) {
        if(isHelpTriggered(argc, argv[1])) {
            print_help();
            return 1;
        }
    }

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
                        print_help();
                        return 1;
                }
          }
    }

    printf("Executing: %s\n", command);
    system(command);

    return 0;
}