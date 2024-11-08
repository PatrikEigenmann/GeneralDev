/* ***************************************************************************************************************
 * cProgress.c - Elevate your development experience with cProgress—a sophisticated and user-friendly progress bar
 * utility for C programming. Designed with precision and efficiency, cProgress transforms the way you visualize
 * task completion, providing clear, dynamic feedback on progress status.
 *
 * Imagine effortless integration of a progress bar that not only tracks but also visually communicates the
 * advancement of tasks with customizable markers and titles. cProgress empowers developers to maintain clear
 * oversight, enhancing both productivity and user engagement.
 *
 * Compile instructions:
 * For Windows  -> gcc - c cProgress.c -o cProgress.o
 * For MacOS    -> clang - c cProgress.c -o cProgress.o
 * ---------------------------------------------------------------------------------------------------------------
 * Author:       Patrik Eigenmann
 * eMail:        p.eigenmann@gmx.net
 * ---------------------------------------------------------------------------------------------------------------
 * Mon 2024-10-25 File created.                                                                     Version: 00.01
 * Sun 2024-10-27 Small corrections and bug fixes.                                                  Version: 00.02
 * Sun 2024-10-27 Implemented sleep time and the flag if Sleep is needed.                           Version: 00.03
 * Tue 2024-11-05 Corrected Windows and MacOS differences.                                          Version: 00.04
 * Tue 2024-11-05 Created the crossplatform version of this library.                                Version: 00.05
 * Fri 2024-11-08 fflush the buffer stdout before printing a new character.                         Version: 00.06
 * ***************************************************************************************************************/
#include "cProgress.h"
#include <stdio.h>

/* ---------------------------------------------------------------------------------------------------------------
 * Crossplatform Preprocessor directive:
 * Windows: #include <windows.h> -> Sleep(miliseconds);
 * MacOS:   #include <unistd.h>  -> usleep(microseconds); [miliseconds * 1000]
 * --------------------------------------------------------------------------------------------------------------- */
#ifdef _WIN32
    // Include windows library
    #include <windows.h>

    // Now create the methode void goToSleep(int miliseconds) so it's Windows compatible.
    void goToSleep(int miliseconds) {
        Sleep(miliseconds);
    }
#else
    // Include Unix library
    #include <unistd.h>

    // Now create the methode void goToSleep(int miliseconds) so it's Windows compatible.
    void goToSleep(int miliseconds) {
        usleep(miliseconds * 1000);
    }
#endif

const int DIVIDER = 60;     // The DIVIDER defines how many markers are seen in the progress bar.

// ***************************************************************************************************************
// With create_progress, setting up a sophisticated progress bar is effortless. This powerful function encapsulates
// the essence of your task's progress, transforming it into a visually engaging and interactive experience. Simply
// provide a title and the total steps, and create_progress handles the rest, delivering a ready-to-use progress
// bar tailored to your needs.
//
// No more manual setups—create_progress ensures that your progress bar is initialized with clarity and precision,
// enhancing both development efficiency and user experience. It's the perfect starting point for any task, ensuring
// your progress is tracked and displayed with style and accuracy.
//
// Step into seamless progress tracking with create_progress and elevate your projects to new levels of
// transparency and engagement.
//
// @param titleIn   The title of the progress bar.
// @param fullIn    The total number of steps for the progress bar.
// @param timeIn    The time in milliseconds of how long the progress bar should sleep. If 0 no delay is applied.
// @return          A Progress struct initialized with the given title and total steps.
// ***************************************************************************************************************
Progress create_progress(char *titleIn, int fullIn, int timeIn) {
    Progress p;

    p.title = titleIn;
    p.full = fullIn;
    p.step = p.full / DIVIDER;
    p.startend = '|';
    p.marker = '=';
    p.time = timeIn;

    return p;
}

// ***************************************************************************************************************
// The update_progress function is your go-to solution for real-time progress tracking. This intuitive function
// dynamically updates your progress bar, ensuring that every step is clearly communicated and visually engaging.
// Whether starting the progress, marking significant milestones, or signaling completion, update_progress keeps
// your audience informed every step of the way.
//
// Incorporating flexible conditions, it seamlessly adapts to various stages of task completion, displaying the
// title, progress markers, and final boundary with impeccable precision. It’s designed to provide developers with
// an effortless way to maintain transparency and visual appeal in progress tracking.
//
// With update_progress, you don’t just show progress—you celebrate it. Elevate your user experience and enhance
// task management with this essential tool.
//
// @param p The Progress struct representing the progress bar.
// @param counter The current step count to update the progress bar.
// ***************************************************************************************************************
void update_progress(Progress p, int counter) {

    if (counter == 0) {
        printf("%s %c", p.title, p.startend);
    }
    else if ( counter > 0 && counter < p.full && counter % p.step == 0) {
        printf("%c", p.marker);
    }
    else if (counter >= p.full){
        printf("%c\n", p.startend);
    }

    // fflush the stdout buffer.
    fflush(stdout);

    if(p.time > 0) {
        goToSleep(p.time);
    }
}