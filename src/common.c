/*
Authors : Tchadel Icard && Arthur Pons
Name : CHUPS.commonC
Date : 01/03/2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../include/common.h"

void clearScreen(void) {
    printf("\e[1;1H\e[2J\n");
}

void waitSecs(int seconds) {
    usleep(seconds * 1000000);
}

void safeStrInput(char *buf, int size) {
    char tmp[size];

    if(fgets(tmp, size, stdin)) strncpy(buf, tmp, size);
    else puts("ERROR while getting input...");
}

void safeIntInput(int *buf) {
    char strBuf[11];
    if(fgets(strBuf, 10, stdin)) {
        sscanf(strBuf, "%d", buf);
    } else {
        puts("ERROR while getting an int...");
    }
}

void sanityzeString(char *str) {
    int i = 0;

    while(str[i++] != '\0') {
        if(str[i] == '\n') str[i] = '\0';
    }
}