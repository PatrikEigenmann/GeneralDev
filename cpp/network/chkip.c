/* ***************************************************************************************************************
 * chkip.c - Our cutting-edge program efficiently pings and identifies online IP addresses within a specified
 * range. It dynamically updates the user on the progress, ensuring a seamless and transparent experience. The
 * results are presented in a visually structured table, accommodating varying IP address lengths for utmost
 * clarity. This tool is integral for network administrators, enhancing the accuracy and speed of network
 * diagnostics and management.
 *
 * Compile instructions:
 * For Windows  -> gcc chkip.c ..\mylibs\cVersion.o ..\mylibs\cProgress.o ..\mylibs\cManPage.o -o chkip
 * For MacOS    -> clang chkip.c ../mylibs/cVersion.o ../mylibs/cProgress.o ../mylibs/cManPage.o -o chkip
 * ---------------------------------------------------------------------------------------------------------------
 * Author:       Patrik Eigenmann
 * eMail:        p.eigenmann@gmx.net
 * ---------------------------------------------------------------------------------------------------------------
 * Fri 2024-10-25 File created and basic functionality programmed.                                  Version: 00.01
 * Fri 2024-10-25 Changed the ping commant option from -c 1 -W 1 to -n 1 because of Windows.        Version: 00.02
 * Fri 2024-10-25 Changed program to look for wildcards * as range checker.                         Version: 00.03
 * Fri 2024-10-25 Bugfix in the ip address, there was a dot (.) too much.                           Version: 00.04
 * Fri 2024-10-25 Revised the whole program, now instead of showing result in real time, store the  Version: 00.05
 *                result of the ip's found online in an array and display it at the end.
 * Sat 2024-10-26 Inplemented a Progress Bar.                                                       Version: 00.06
 * Sat 2024-10-26 Version Control and help file implemented.                                        Version: 00.07
 * Sun 2024-10-27 Progress bar implemented.                                                         Version: 00.08
 * Sun 2024-10-27 Instead of recursive functions, I use the top-down approach.                      Version: 00.09
 * Mon 2024-11-04 cManPage.h implemented.                                                           Version: 00.10
 * Wed 2024-11-06 Crossplatform Programming, made it conform for Windows/MacOS.                     Version: 00.11
 * Wed 2024-11-06 Changed wild card because in Unix, the wild card '*' causes an error.             Version: 00.12
 * Thu 2024-11-07 Changed things around, because under Unix things don't work quite right.          Version: 00.13
 * Fri 2024-11-07 Small changes because unter Unix the things are different.                        Version: 00.14
 * Tue 2024-11-19 Bugfix under Unix, ping doesn't result in "Reply from".                           Version: 00.15
 * Tue 2024-11-19 Bugfix under Windows, ping doesn't result in "1 packets received".                Version: 00.16
 * Thu 2024-11-21 Updated to the new create_manpage("chkip", manpage, v.major, v.minor);            Version: 00.17
 * *************************************************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
    #include "..\mylibs\cVersion.h"
    #include "..\mylibs\cProgress.h"
    #include "..\mylibs\cManPage.h"
#else
    #include "../mylibs/cVersion.h"
    #include "../mylibs/cProgress.h"
    #include "../mylibs/cManPage.h"
#endif

const int IP_MAX = 254;

/* ------------------------------------------------------------------------------------------------
 * print_help - This function is a helper function that prints out the help message for the cEnigma
 * program in man pages style. This message includes but is not limited to:
 *
 * NAME: A brief description of the program.
 *
 * SYNOPSIS: How to use the program, including the command-line arguments it accepts.
 *
 * DESCRIPTION: Detailed information about what the program does and how to use it. It explains the
 *              -e and -d options for encoding and decoding a text file, respectively.
 *
 *              -h, -H, -help -Help or no parameter at all: These options display the help message.
 *
 * AUTHOR: Information about the author of the program.
 *
 * COPYRIGHT: The copyright notice, license information, and a disclaimer.
 *
 * This function does not take any arguments and does not return any values. It simply prints the
 * help message to the standard output. It’s typically called when the user passes a help flag
 * (-h, -H, -help, or -Help) or when the program is used incorrectly. It helps users understand
 * how to use the program correctly.
 * ------------------------------------------------------------------------------------------------*/
void print_help() {
    
    // Version control implemented
    Version v = create_version(0, 17);
        
    // The buffer is needed to write
    // the correct formated version number.
    char buffer[6];
    
    // Format the buffer with the
    // correct version number.
    to_string(v, buffer);

    char *manpage = NULL;

    // Write the ManPage style help file.
    append_format(&manpage, "NAME\n");
    append_format(&manpage, "      chkip Version: %s\n", buffer);
    append_format(&manpage, "      Our cutting-edge cross-platform program efficiently pings and\n");
    append_format(&manpage, "      identifies online IP addresses within a specified range. It\n");
    append_format(&manpage, "      dynamically updates the user on the progress, ensuring a seamless\n");
    append_format(&manpage, "      and transparent experience. The results are presented in a visually\n");
    append_format(&manpage, "      structured table, accommodating varying IP address lengths for utmost\n");
    append_format(&manpage, "      clarity. This tool is integral for network administrators, enhancing the\n");
    append_format(&manpage, "      accuracy and speed of network diagnostics and management.\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "SYNOPSIS\n");
    append_format(&manpage, "      chkip <IP ADDRESS with ? as the wildcard>\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "DESCRIPTION\n");
    append_format(&manpage, "      <IP ADDRESS with ? as the wildcard>\n");
    append_format(&manpage, "      \"192.168.1.?\" means checking a range of 254 addresses.\n");
    append_format(&manpage, "      \"192.168.?.?\" means checking a range of 64,516 addresses.\n");
    append_format(&manpage, "                    Which means it will take hours to check all these addresses.\n");
    append_format(&manpage, "      \"192.?.?.?\"   Triggers the help, because it would have to test so many\n");
    append_format(&manpage, "                    ip address, the program would run for days.\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "      -h, -H, -help\n");
    append_format(&manpage, "                    Display this help message.\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "AUTHOR\n");
    append_format(&manpage, "      Patrik Eigenmann (p.eigenmann@gmx.net).\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "COPYRIGHT\n");
    append_format(&manpage, "      Copyright 2024 Free Software Foundation, Inc. License GPLv3+:\n");
    append_format(&manpage, "      GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>.\n");
    append_format(&manpage, "      This is free software: you are free to change and redistribute it.\n");
    append_format(&manpage, "      There is NO WARRANTY, to the extent permitted by law.\n");

    // Create the manpage in the file /temp/chkip.man
    create_manpage("chkip", manpage, v.major, v.minor);
    
    // Free up the memory.
    free(manpage);
}

// ---------------------------------------------------------------------------------------------------------------
// Our count_wildcards function is designed to bring unparalleled efficiency and clarity to your string processing
// tasks. With its precise algorithm, this function traverses any given string to count the occurrences of a
// specified wildcard character. Perfect for scenarios where tracking or validating wildcard usage is paramount,
// count_wildcards ensures that you can manage and manipulate strings with confidence and ease.
//
// By integrating count_wildcards, you enhance your ability to analyze and process strings, paving the way for
// robust data handling and validation mechanisms. It’s a simple yet powerful tool, poised to elevate your
// programming toolkit.
//
// @param str   The string in which to count wildcard characters.
// @return      The number of wildcard characters found in the string.
// ---------------------------------------------------------------------------------------------------------------
int count_wildcards(const char *str) {
    int count = 0;
    while (*str) {
        if (*str == '?') {
            count++;
        }
        str++;
    }
    return count;
}

// ---------------------------------------------------------------------------------------------------------------
// Our ping_ip function is a game-changer in network diagnostics, designed to efficiently determine the online
// status of any IP address. By leveraging system ping commands, this function accurately assesses connectivity,
// providing immediate feedback on network availability. Perfect for network administrators and developers, ping_ip
// offers a reliable method to verify IP address responsiveness.
//
// Incorporate ping_ip into your projects to streamline network checks and maintain high standards of connectivity.
// With its robust implementation, you can be assured of accurate and timely results.
//
// @param ip    The IP address to ping.
// @return      1 if the IP is online, otherwise 0.
// ---------------------------------------------------------------------------------------------------------------
int ping_ip(const char *ip) {
    char command[100];
    
    #ifdef _WIN32
        snprintf(command, sizeof(command), "ping -n 1 -w 5 %s", ip);
    #else
        snprintf(command, sizeof(command), "ping -c 1 -t 1 %s", ip);
    #endif

    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        perror("popen failed");
        return 0;
    }
    char result[100];
    int is_online = 0;
    while (fgets(result, sizeof(result), fp) != NULL) {
    #ifdef _WIN32
        if (strstr(result, "Received = 1") != NULL) {
            is_online = 1;
            break;
        }
    #else
        if (strstr(result, "1 packets received") != NULL) {
            is_online = 1;
            break;
        }
    #endif
    }

    pclose(fp);
    return is_online;
}

// ---------------------------------------------------------------------------------------------------------------
// Our replace_wildcard function is a revolutionary tool designed to streamline the process of dynamically
// configuring IP addresses. By replacing wildcard characters with specified values, this function ensures that
// your network configurations are both flexible and precise. Ideal for scenarios where IP ranges need to be
// dynamically managed, replace_wildcard offers an efficient solution to adapt and configure network settings on
// the fly.
//
// Incorporate replace_wildcard into your projects to enhance the adaptability and accuracy of your IP management
// processes. With its straightforward implementation, you can effortlessly handle complex IP configurations with
// ease.
//
// @param ip            The IP address containing the wildcard.
// @param replacement   The string to replace the wildcard with.
// @return              A new IP address string with the wildcard replaced.
// ---------------------------------------------------------------------------------------------------------------
char *replace_wildcard(const char *ip, const char *replacement) {
    static char new_ip[30];
    strcpy(new_ip, ip);
    char *pos = strchr(new_ip, '?');
    if (pos) {
        *pos = '\0';
    }
    strcat(new_ip, replacement);
    return new_ip;
}

// ---------------------------------------------------------------------------------------------------------------
// Our print_online_ips function is designed to deliver unparalleled clarity in network diagnostics, presenting
// the results of your IP address checks in a structured, visually appealing table. By dynamically adjusting to
// varying IP address lengths, this function ensures that the display remains clear, precise, and professional.
// Perfect for network administrators and IT professionals, print_online_ips transforms raw data into insightful
// information.
//
// Integrate print_online_ips into your network tools to enhance the presentation of your diagnostics, making it
// easier to interpret and act upon the results. With its clean and elegant output, you can ensure that your
// network status reports are both informative and accessible.
//
// @param online_ips    An array of strings containing the online IP addresses.
// @param count         The number of online IP addresses in the array.
// ---------------------------------------------------------------------------------------------------------------
void print_online_ips(char **online_ips, int count) {
    printf("+-----------------+\n");
    printf("| Online IPs      |\n");
    printf("+-----------------+\n");
    
    for (int i = 0; i < count; i++) {
        int ip_length = strlen(online_ips[i]);
        int dashes = 16 - ip_length; 

        printf("| %-s", online_ips[i]);
        for (int j = 0; j < dashes; j++) {
            printf(" ");
        }
        printf("|\n");
    }
    printf("+-----------------+\n");
}

// ---------------------------------------------------------------------------------------------------------------
// Our main function serves as the command center of your network diagnostics tool, orchestrating the seamless
// execution of all key operations. It handles user input, dynamically configures the scanning range, initiates
// progress tracking, and processes the results with utmost efficiency. Designed for top-down clarity, this function
// ensures that every step, from initialization to output, is executed with precision.
//
// By leveraging the main function, developers can effortlessly manage complex network diagnostics tasks, ensuring
// a streamlined and intuitive user experience. It integrates all components harmoniously, reflecting the highest
// standards of coding excellence.
//
// @param argc  The number of command-line arguments.
// @param argv  The array of command-line arguments.
// @return      0 on successful completion, 1 on error.
// ---------------------------------------------------------------------------------------------------------------
int main(int argc, char *argv[]) {
    
    // Check if the help is triggered.
    if(isHelpTriggered(argc, argv[1])) {
        print_help();
        return 1;
    }

    int counter = count_wildcards(argv[1]);
    int range = 0;
    int online = 0;

    // Check if the ip ranges are manageble if not
    // just display the help.
    if (counter == 1) {
        range = IP_MAX;
    } else if (counter == 2) {
        range = IP_MAX * IP_MAX;
    } else {
        print_help();
        return 1;
    }

    char base_ip[30];
    strcpy(base_ip, replace_wildcard(argv[1], "\0"));
    Progress p = create_progress("Pinging IP Range", range, 0);
    update_progress(p, 0);

    // Allocate memory for online IPs
    char **online_ips = malloc(range * sizeof(char *));
    for (int i = 0; i < range; i++) {
        online_ips[i] = malloc(16 * sizeof(char));
    }

    // Let's dive into the actual process of analyzing the network.
    switch (counter) {
        case 1:
            for (int i = 1; i <= IP_MAX; i++) {
                char ip_address[30];
                snprintf(ip_address, sizeof(ip_address), "%s%d", base_ip, i);
                if (ping_ip(ip_address)) {
                    strcpy(online_ips[online++], ip_address);
                }
                update_progress(p, i);
            }
            break;
        case 2:
            for (int i = 1; i <= IP_MAX; i++) {
                for (int j = 1; j <= IP_MAX; j++) {
                    char ip_address[30];
                    snprintf(ip_address, sizeof(ip_address), "%s%d.%d", base_ip, i, j);
                    if (ping_ip(ip_address)) {
                        strcpy(online_ips[online++], ip_address);
                    }
                    update_progress(p, (i - 1) * IP_MAX + j);
                }
            }
            break;
        default:
            print_help();
            return 1;
    }

    update_progress(p, range + 1);
    print_online_ips(online_ips, online);

    // Free allocated memory
    for (int i = 0; i < range; i++) {
        free(online_ips[i]);
    }
    free(online_ips);

    return 0;
}