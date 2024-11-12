/* ***************************************************************************************************************
 * The cForward.c program is a concise yet impactful demonstration of handling real-time progress updates within a
 * loop using the printf function. This program effectively illustrates the dynamic display of progress, ensuring
 * consistent and interactive feedback throughout the iteration process.
 * 
 * This program is cross-platform, providing compile instructions for both Windows and macOS, making it versatile
 * and accessible. By showcasing real-time progress visualization, the cForward.c program serves as an excellent
 * educational tool and a practical solution for developers needing efficient and interactive progress tracking.
 * 
 * Whether you're handling simple loops or building complex iterative processes, this program exemplifies effective
 * progress management techniques, contributing to a more user-friendly and interactive software development
 * experience.
 *
 * Compile instructions:
 * For Windows  -> gcc cForward.c -o cForward
 * For MacOS    -> clang cForward.c -o cForward
 * ---------------------------------------------------------------------------------------------------------------
 * Author:       Patrik Eigenmann
 * eMail:        p.eigenmann@gmx.net
 * ---------------------------------------------------------------------------------------------------------------
 * Sun 2024-02-04 File created.                                                                     Version: 00.01
 * Tue 2024-11-05 Crossplatform tests.                                                              Version: 00.02
 * ***************************************************************************************************************/
#include <stdio.h>
#include <unistd.h>

/* ---------------------------------------------------------------------------------------------------------------
 * By encapsulating the process of visualizing progress within this method, we ensure a seamless and efficient way
 * to display progress updates. This method not only enhances the maintainability and readability of your codebase,
 * but also guarantees that progress is displayed consistently and interactively.
 * 
 * Adopting the foo method will streamline your progress tracking tasks, fostering better real-time feedback and
 * user interaction, and ultimately contributing to a more polished and user-friendly product.
 * 
 * @param int i - The current iteration count.
 * @param int max - The maximum iteration count. 
 * --------------------------------------------------------------------------------------------------------------- */
void foo(int i, int max) {
    if(i == 0) {
        printf("Start |");
    } else if ( i > 0 && i < max && (i % (max / 60)) == 0) {
        printf("=");
    }
    else if(i == max) {
        printf("|\n");
    }
    fflush(stdout);
    usleep(100000);
}

/* ------------------------------------------------------------------------------------------------------------------
 * main - In the vast, uncharted realms of cyberspace, there exists a function. Not just any function, but the main
 * function. It is the gatekeeper, the sentinel that stands at the threshold of every C and C++ program. It is the
 * beginning and the end, the alpha and the omega.
 * 
 * @param int argc     - Command argument count
 * @param char **argv  - Command argument strings
 * ------------------------------------------------------------------------------------------------------------------ */
int main(int argc, char *argv[]) {
    
    for(int j=0; j <= 800; j++)
        foo(j, 800);
    
    return 0;
}