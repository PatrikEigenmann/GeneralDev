/* ***************************************************************************************************************
 * cHelloWorld.c - In the heart of a bustling city, there was a quiet, unassuming building. Within its walls, a
 * solitary computer sat, humming softly. It was a machine of immense power, capable of processing billions of
 * instructions per second. But it was idle, waiting for a purpose.
 * 
 * Suddenly, a new program was born. It was a simple program, a mere few lines of code, but it held a message for
 * the world. The program was written in C, a language known for its efficiency and control over hardware.
 * 
 * The first line of the program, #include <stdio.h>, was like a key, unlocking a vast library of functions for the
 * program to use. It was the first step in the program’s journey, preparing it for the task ahead.
 * 
 * The next line, int main() {, was the program’s heart. It was the starting point, the place where the program would
 * begin its life. It was a promise of things to come.
 * 
 * Then came the message, printf("Hello C World!");. It was a simple greeting, but it was also a declaration of
 * existence. The program was announcing itself to the world, ready to make its mark.
 * 
 * But the program was not yet complete. It needed to end gracefully, to show that it had completed its task without
 * error. So, it returned a zero, return 0;, a universal sign of success.
 * 
 * Finally, the program was complete. The closing brace, }, marked the end of the program’s journey. It had done its
 * job, delivering its message to the world.
 * 
 * And so, the computer hummed to life, executing the program. The screen flickered, and then, the words appeared:
 * “Hello C World!”. The program had fulfilled its purpose, delivering its message with precision and efficiency. It
 * was a small step for the program, but a giant leap for the world of computing. The simple program had proven that
 * even the smallest message could have a profound impact. And with that, the program ended, leaving behind a world
 * forever changed by its brief existence.
 *
 * Compile instructions:
 * For Windows  -> gcc cHelloWorld.c -o cHelloWorld
 * For MacOS    -> clang cHelloWorld.c -o cHelloWorld
 * ---------------------------------------------------------------------------------------------------------------
 * Author:       Patrik Eigenmann
 * eMail:        p.eigenmann@gmx.net
 * ---------------------------------------------------------------------------------------------------------------
 * Mon	2024-02-04	File created.                                                                   Version: 00.01
 * ***************************************************************************************************************/

#include<stdio.h>

// ------------------------------------------------------------------------------------------------------------------
// main - In the vast, uncharted realms of cyberspace, there exists a function. Not just any function, but the main
// function. It is the gatekeeper, the sentinel that stands at the threshold of every C and C++ program. It is the
// beginning and the end, the alpha and the omega.
// @param int argc     - Command argument count
// @param char **argv  - Command argument strings
// ------------------------------------------------------------------------------------------------------------------
int main (int argc, char **argv) {
    
    // Display "Hello C World!" in the terminal.
    printf("Hello C World!\n");
    
    return 0;
}