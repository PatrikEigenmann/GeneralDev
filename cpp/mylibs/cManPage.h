/* ***************************************************************************************************************
 * cManPage.h - This header file provides an interface for managing and manipulating manual pages in C. It
 * includes essential functions and data structures for creating, modifying, and verifying manual pages, ensuring
 * cross-platform compatibility and ease of use.
 * 
 * This header file serves as a foundational component for applications that require efficient documentation
 * handling.
 * ---------------------------------------------------------------------------------------------------------------
 * Author:       Patrik Eigenmann
 * eMail:        p.eigenmann@gmx.net
 * ---------------------------------------------------------------------------------------------------------------
 * Mon 2024-10-28 File created.                                                                     Version: 00.01
 * Thu 2024-11-07 Added functionality to get it to work poperly under MacOS.                        Version: 00.02
 * ***************************************************************************************************************/
#ifndef CMANPAGE_H
#define CMANPAGE_H

/* ---------------------------------------------------------------------------------------------------------------
 * The ManPage struct is a crucial data structure designed to streamline and enhance the management of manual
 * pages within your applications. It encapsulates all the necessary details of a manual page, including the
 * filename and its corresponding content, into a single, organized unit. This structured approach not only
 * simplifies the creation and modification of documentation but also ensures that your manual pages are
 * consistently and efficiently handled across different platforms.
 * 
 * By leveraging the ManPage struct, your development team can achieve greater efficiency, maintainability, and
 * clarity in managing application documentation, ultimately contributing to a more robust and user-friendly
 * software experience.
 * --------------------------------------------------------------------------------------------------------------- */
typedef struct {
    char *filename;
    char *manual;
} ManPage;

/* ---------------------------------------------------------------------------------------------------------------
 * By encapsulating the creation of manual pages within this method, we ensure a seamless and efficient process
 * for generating documentation. This not only enhances the maintainability and readability of your codebase, but
 * also guarantees that manual pages are consistently formatted and easily accessible.
 * 
 * Adopting the create_manpage method will streamline your documentation process, fostering better organization
 * and accessibility, and ultimately contributing to a more polished and user-friendly product.
 * 
 * @param char *filenameIn - The filename to the ManPage text file.
 * @param char *manualIn - The content of the ManPage text.
 * --------------------------------------------------------------------------------------------------------------- */
void create_manpage(char *filenameIn, char *manualIn, int major, int minor);

/* ---------------------------------------------------------------------------------------------------------------
 * By encapsulating the process of appending formatted content within this method, we ensure a seamless and
 * efficient way to dynamically build strings. This method not only enhances the maintainability and readability
 * of your codebase, but also guarantees that formatted content is appended consistently and effectively.
 * 
 * Adopting the append_format method will streamline your string manipulation tasks, fostering better organization
 * and flexibility, and ultimately contributing to a more polished and efficient product.
 * 
 * @param char **dest - The destination string to which formatted content will be appended.
 * @param const char *format - The format string.
 * @param ... - Additional arguments to format and append to the destination string.
 * --------------------------------------------------------------------------------------------------------------- */
void append_format(char **dest, const char *format, ...);

/* ---------------------------------------------------------------------------------------------------------------
 * By encapsulating the file existence check within this method, we ensure a seamless and efficient way to verify
 * the presence of files. This method not only enhances the maintainability and readability of your codebase, but
 * also guarantees that file existence checks are performed consistently and reliably.
 * 
 * Adopting the doesFileExist method will streamline your file handling processes, fostering better organization
 * and error handling, and ultimately contributing to a more robust and user-friendly product.
 * 
 * @param char *filename - The name of the file to check for existence.
 * @return int - Returns 1 if the file exists, and 0 if it does not.
 * --------------------------------------------------------------------------------------------------------------- */
int doesFileExist(char *filename, int major, int minor);

/* ---------------------------------------------------------------------------------------------------------------
 * By encapsulating the detection of help command triggers within this method, we ensure a seamless and efficient
 * way to handle user requests for help or usage information. This method not only enhances the maintainability
 * and readability of your codebase but also guarantees that help commands are consistently and accurately
 * recognized.
 * 
 * Adopting the isHelpTriggered method will streamline your application's user interaction processes, fostering
 * better user experience and accessibility, and ultimately contributing to a more user-friendly product.
 * 
 * @param int argcIn - The number of command-line arguments.
 * @param char *argvIn - The first string of the command-line arguments array.
 * @return int - Returns 1 if the help command is triggered, and 0 otherwise.
 * --------------------------------------------------------------------------------------------------------------- */
int isHelpTriggered(int argcIn, char *argvIn);
#endif