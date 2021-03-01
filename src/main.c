/*
Authors : Tchadel Icard && Arthur Pons
Name : CHUPS
Date : 01/03/2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>

int main(void) {
    return EXIT_SUCCESS;
}

void check_colors(void) {
    if (has_colors() == FALSE) {
        printf("Your terminal does not support color\n");
    }
}