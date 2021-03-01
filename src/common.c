/*
Authors : Tchadel Icard && Arthur Pons
Name : CHUPS.commonC
Date : 01/03/2021
*/

#include <stdio.h>
#include "../include/common.h"
void clearScreen(void) {
    printf("\e[1;1H\e[2J\n");
}