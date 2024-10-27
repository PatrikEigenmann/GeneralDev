/* ***************************************************************************************************************
 * cProgress.h - Elevate your development experience with cProgress—a sophisticated and user-friendly progress bar
 * utility for C programming. Designed with precision and efficiency, cProgress transforms the way you visualize
 * task completion, providing clear, dynamic feedback on progress status.
 *
 * Imagine effortless integration of a progress bar that not only tracks but also visually communicates the
 * advancement of tasks with customizable markers and titles. cProgress empowers developers to maintain clear
 * oversight, enhancing both productivity and user engagement.
 * ---------------------------------------------------------------------------------------------------------------
 * Author:       Patrik Eigenmann
 * eMail:        p.eigenmann@gmx.net
 * ---------------------------------------------------------------------------------------------------------------
 * Fri 2024-10-25 File created.                                                                     Version: 00.01
 * Sun 2024-10-27 Implemented sleep time and the flag if Sleep is needed.                           Version: 00.02
 * ***************************************************************************************************************/
 #ifndef CPROGRESS_H
 #define CPROGRESS_H

// ***************************************************************************************************************
// The Progress struct is a cutting-edge tool designed to bring clarity and visual appeal to task management within
// your C programs. This innovative structure encapsulates all the necessary elements to create dynamic and
// interactive progress bars, providing real-time updates on task completion.
//
// By leveraging the Progress struct, developers can seamlessly integrate a visually engaging progress bar that
// enhances user experience and provides clear insights into the progress of any operation. It’s a perfect blend of
// simplicity and functionality, tailored for modern development needs.
//
// With the Progress struct, stay on top of your tasks and showcase progress like never before. Welcome to the
// future of intuitive and efficient progress tracking. 
// ***************************************************************************************************************
typedef struct {
    char *title;
    int full;
    int step;
    char startend;
    char marker;

    // Sleep time to delay the process. For no delay use 0;
    int time;
} Progress;

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
// @param titleIn The title of the progress bar.
// @param fullIn The total number of steps for the progress bar.
// @return A Progress struct initialized with the given title and total steps.
// ***************************************************************************************************************
Progress create_progress(char *titleIn, int fullIn, int timeIn);

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
void update_progress(Progress p, int counter);

#endif