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
 * *************************************************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IPS 256

#define MAX_IPS 256

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
    if (is_online) {
        strcpy(online_ips[*count], ip);
        (*count)++;
    }
}

void check_range(char *base_ip, int level, char online_ips[MAX_IPS][16]) {
    if (level == 4) {
        ping_ip(base_ip, online_ips);
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
        if (i % 20 == 0) {
            printf("=");
        }
    }
}

void print_online_ips(char online_ips[MAX_IPS][16], int count) {
    printf("+-------------------+\n");  // Adjust for longer IP addresses
    printf("| Online IPs        |\n");
    printf("+-------------------+\n");
    for (int i = 0; i < count; i++) {
        int ip_length = strlen(online_ips[i]);
        int dashes = 15 - ip_length;  // 15 dashes total

        printf("| %-s", online_ips[i]);
        for (int j = 0; j < dashes; j++) {
            printf(" ");
        }
        printf("|\n");
    }
    printf("+-------------------+\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <ip_range>\n", argv[0]);
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
    check_range(base_ip, levels, online_ips, &count);
    printf("|\n");

    print_online_ips(online_ips, count);
    return 0;
}