/*
Authors : Tchadel Icard && Arthur Pons
Name : CHUPS.main
Date : 01/03/2021
*/

// 45.13.104.67
// Includes de la LIBC

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>

// Bibliothèques locales

#include "../include/common.h"
#include "../include/host.h"
#include "../include/textcolor.h"
#include "../include/synack.h"
#include "../include/menu.h"

void banner(void);
void menu(void);

int main(void) {

    banner(); // On affiche la bannière au moins une fois
    menu();
    return EXIT_SUCCESS;
}

void banner(void) {
    clearScreen();

    printf("\t\t\t");

    textcolor(RESET, RED, BLACK);
    printf("WELCOME TO CHUPS ! ver 0.1\n");
    textcolor(RESET, WHITE, BLACK);

    printf("\t\t");

    textcolor(BLINK, RED, BLACK);
    printf("%sCréé par un noir un blanc et un suisse (enfin pas encore...).%s\n", BLINKING, NORMAL);
    textcolor(RESET, WHITE, BLACK);
}

