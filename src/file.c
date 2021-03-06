/*
Authors : Tchadel Icard && Arthur Pons
Name : CHUPS.fileC
Date : 03/03/2021
*/

#include <stdio.h>
#include "../include/file.h"

void addToFile(const char *filename, const char *content) {
    FILE *f = fopen(filename, "ab");

    fputs(content, f);

    fclose(f);
}