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
 * Thu	2024-10-24	File created and basic functionality programmed.                                Version: 00.01
 * *************************************************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    printf("Usage: ls [OPTION]...\n");
    printf("List information about the FILEs (the current directory by default).\n");
    printf("Options:\n");
    printf("  -l         use a long listing format\n");
    printf("  -a         do not ignore entries starting with .\n");
    printf("  -al or la  use a long listing format and show all entries\n");
    printf("  -?         display this help and exit\n");
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