/*
Authors : Tchadel Icard && Arthur Pons
Name : CHUPS.textcolorH
Date : 01/03/2021
*/

#ifndef __TEXTCOLOR__H__
#define __TEXTCOLOR__H__

// Codes couleurs

#define NORMAL "\x1b[0m"
#define BLINKING "\033[5m"


#define RESET		0
#define BRIGHT 		1
#define DIM 		2
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

void textcolor(int attr, int fg, int bg);

#endif