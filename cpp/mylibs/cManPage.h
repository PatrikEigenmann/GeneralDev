/* ***************************************************************************************************************
 * cManPage.h - 
 * ---------------------------------------------------------------------------------------------------------------
 * Author:       Patrik Eigenmann
 * eMail:        p.eigenmann@gmx.net
 * ---------------------------------------------------------------------------------------------------------------
 * Mon 2024-10-28 File created.                                                                     Version: 00.01
 * ***************************************************************************************************************/
#ifndef CMANPAGE_H
#define CMANPAGE_H

typedef struct {
    char *filename;
    char *manual;
} ManPage;

void create_manpage(char *filenameIn, char *manualIn);

void append_format(char **dest, const char *format, ...);

#endif