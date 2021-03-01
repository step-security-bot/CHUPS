/*
Authors : Tchadel Icard && Arthur Pons
Name : CHUPS.main
Date : 01/03/2021
*/

// Includes de la LIBC

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>

// Bibliothèques locales

#include "../include/textcolor.h"
#include "../include/common.h"

// Codes couleurs
// Uniquement définis ici car seul main() affichera du contenu à l'écran.

#define RESET		0
#define BRIGHT 		1
#define DIM		    2
#define UNDERLINE 	3
#define BLINK		4
#define REVERSE		7
#define HIDDEN		8

#define BLACK 		0
#define RED		    1
#define GREEN		2
#define YELLOW		3
#define BLUE		4
#define MAGENTA		5
#define CYAN		6
#define	WHITE		7

void banner(void);

int main(void) {

    banner(); // On affiche la bannière au moins une fois

    return EXIT_SUCCESS;
}

void banner(void) {
    clearScreen();

    printf("\t\t");
    textcolor(BRIGHT, RED, BLACK);
    printf("WELCOME TO CHUPS ! ver 0.1\n");
    textcolor(RESET, WHITE, BLACK);
}