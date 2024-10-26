/* ***************************************************************************************************************
 * chkip.c - Our cutting-edge program efficiently pings and identifies online IP addresses within a specified
 * range. It dynamically updates the user on the progress, ensuring a seamless and transparent experience. The
 * results are presented in a visually structured table, accommodating varying IP address lengths for utmost
 * clarity. This tool is integral for network administrators, enhancing the accuracy and speed of network
 * diagnostics and management.
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
 * *************************************************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "..\mylibs\cVersion.h"

#define MAX_IPS 256

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
 *              /?, -?, -h, -H, -help: These options display the help message.
 *
 * AUTHOR: Information about the author of the program.
 *
 * COPYRIGHT: The copyright notice, license information, and a disclaimer.
 *
 * This function does not take any arguments and does not return any values. It simply prints the
 * help message to the standard output. It’s typically called when the user passes a help flag
 * (-h, -H, -help, -?, or /?) or when the program is used incorrectly. It helps users understand
 * how to use the program correctly.
 * ------------------------------------------------------------------------------------------------*/
void print_help() {
    
    // Version control implemented
    Version v = create_version(0, 7);
    
    // The buffer is needed to write
    // the correct formated version number.
    char buffer[6];
    
    // Format the buffer with the
    // correct version number.
    to_string(v, buffer);

    // Temporarly write the help message into
    // /tmp/myhelp.txt file.
    FILE *file = fopen("D:\\bin\\temp\\myhelp.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // Write the help message in the file.
    fprintf(file, "NAME\n");
    fprintf(file, "      chkip Version: %s\n", buffer);
    fprintf(file, "      Our cutting-edge program efficiently pings and identifies online\n");
    fprintf(file, "      IP addresses within a specified range. It dynamically updates the\n");
    fprintf(file, "      user on the progress, ensuring a seamless and transparent experience.\n");
    fprintf(file, "      The results are presented in a visually structured table, accommodating\n");
    fprintf(file, "      varying IP address lengths for utmost clarity. This tool is integral\n");
    fprintf(file, "      for network administrators, enhancing the accuracy and speed of network\n");
    fprintf(file, "      diagnostics and management.\n");
    fprintf(file, "\n");
    fprintf(file, "SYNOPSIS\n");
    fprintf(file, "      chkip <IP ADDRESS with * as the wildcard>\n");
    fprintf(file, "\n");
    fprintf(file, "DESCRIPTION\n");
    fprintf(file, "      <IP ADDRESS with * as the wildcard>\n");
    fprintf(file, "      192.168.1.* means checking a range of 254 addresses.\n");
    fprintf(file, "      192.168.*.* means checking a range of 64,516 addresses.\n");
    fprintf(file, "      Which means it will take hours to check all these addresses.\n");
    fprintf(file, "\n");
    fprintf(file, "      /?, -?, -h, -H, -help\n");
    fprintf(file, "            Display this help message.\n");
    fprintf(file, "\n");
    fprintf(file, "AUTHOR\n");
    fprintf(file, "      Patrik Eigenmann (p.eigenmann@gmx.net).\n");
    fprintf(file, "\n");
    fprintf(file, "COPYRIGHT\n");
    fprintf(file, "      Copyright © 2024 Free Software Foundation, Inc. License GPLv3+:\n");
    fprintf(file, "      GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>.\n");
    fprintf(file, "      This is free software: you are free to change and redistribute it.\n");
    fprintf(file, "      There is NO WARRANTY, to the extent permitted by law.\n");

    // Now we can close the file.
    fclose(file);

    // Now we do a system call and use the command less,
    // So we have the effect of scrolling through the message.
    system("more D:\\bin\\temp\\myhelp.txt");
}

void ping_ip(const char *ip, char online_ips[MAX_IPS][16], int *count) {
    char command[100];
    snprintf(command, sizeof(command), "ping -n 1 %s", ip);
    FILE *fp = _popen(command, "r");
    if (fp == NULL) {
        perror("popen failed");
        return;
    }
    char result[100];
    int is_online = 0;
    while (fgets(result, sizeof(result), fp) != NULL) {
        if (strstr(result, "Reply from") != NULL) {
            is_online = 1;
            break;
        }
    }
    _pclose(fp);
    if (is_online && *count < MAX_IPS) {
        strcpy(online_ips[*count], ip);
        (*count)++;
    }
}

void check_range(char *base_ip, int level, char online_ips[MAX_IPS][16]) {
    if (level == 4) {
        int count = 0;
        ping_ip(base_ip, online_ips, &count);
        return;
    }
    char ip[30];
    for (int i = 1; i <= 254; i++) {
        snprintf(ip, sizeof(ip), "%s%d", base_ip, i);
        if (level < 3) {
            strcat(ip, ".");
        }
        check_range(ip, level + 1, online_ips);

        // Progress indicator
        if (i % 4 == 0) {
            printf("=");
        }
    }
}

void print_online_ips(char online_ips[MAX_IPS][16], int count) {
    printf("+-------------------+\n");
    printf("| Online IPs        |\n");
    printf("+-------------------+\n");
    for (int i = 0; i < count; i++) {
        int ip_length = strlen(online_ips[i]);
        int dashes = 15 - ip_length; 

        printf("| %-s", online_ips[i]);
        for (int j = 0; j < dashes; j++) {
            printf(" ");
        }
        printf("|\n");
    }
    printf("+-------------------+\n");
}

int main(int argc, char *argv[]) {

    // Check if the correct number of arguments are provided
    if(argc != 3 || strcmp(argv[1], "/?") == 0
        || strcmp(argv[1], "-?") == 0 || strcmp(argv[1], "-h") == 0
        || strcmp(argv[1], "-H") == 0 || strcmp(argv[1], "-help") == 0) {
        print_help();
        return 1;
    }

    char base_ip[30];
    snprintf(base_ip, sizeof(base_ip), "%s", argv[1]);
    int levels = 0;
    for (int i = 0; i < strlen(base_ip); i++) {
        if (base_ip[i] == '.') {
            levels++;
        } else if (base_ip[i] == '*') {
            base_ip[i] = '\0';
            break;
        }
    }
    if (levels > 3) {
        printf("Invalid IP range\n");
        return 1;
    }
    char online_ips[MAX_IPS][16] = {{0}};

    int count = 0;

    printf("Pinging IP Range |");
    check_range(base_ip, levels, online_ips);
    printf("|\n");

    print_online_ips(online_ips, count);
    return 0;
}