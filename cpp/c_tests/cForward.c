/* ***************************************************************************************************************
 * cArg.c - A small test to figure out how to handle printf within a for loop.
 *
 * Compile instructions:
 * For Windows  -> gcc cArg.c -o cArg
 * For MacOS    -> clang cArg.c -o cArg
 * ---------------------------------------------------------------------------------------------------------------
 * Author:       Patrik Eigenmann
 * eMail:        p.eigenmann@gmx.net
 * ---------------------------------------------------------------------------------------------------------------
 * Sun 2024-02-04 File created.                                                                     Version: 00.01
 * Tue 2024-11-05 Crossplatform tests.                                                              Version: 00.02
 * ***************************************************************************************************************/
#include <stdio.h>
#include <unistd.h>

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

int main(int argc, char *argv[]) {
    
    for(int j=0; j <= 800; j++) foo(j, 800);
    
    return 0;
}