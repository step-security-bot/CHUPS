#include <stdio.h>
#include "../include/textcolor.h"
#include "../include/menu.h"


void menu(void) {
    textcolor(RESET, GREEN, BLACK);
    puts("#1  -  Look at hosts");
    puts("#2  -  Add an host");
    puts("#3  -  Quit");
    textcolor(RESET, WHITE, BLACK);
}