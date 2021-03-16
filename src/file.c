/*
Authors : Tchadel Icard && Arthur Pons
Name : CHUPS.fileC
Date : 03/03/2021
*/

#include <stdio.h>
#include "../include/file.h"

void addToFile(const char *filename, const char *content) {
    FILE *f = fopen(filename, "ab");

    fputs(content, f);

    fclose(f);
}

void readFile(const char*filename, char linesBuf[128][391], int *hostNumber) {
    FILE *f = fopen(filename, "rb");
    int i = 0;
    while (fgets(linesBuf[i++], 391, f));
    *hostNumber = i;
}