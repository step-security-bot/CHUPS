/*
Authors : Tchadel Icard && Arthur Pons
Name : CHUPS.commonH
Date : 01/03/2021
*/

#ifndef __COMMON__H__
#define __COMMON__H__

void clearScreen();
void waitSecs(int seconds);
void safeStrInput(char *buf, int size);
void safeIntInput(int *buf);
void sanityzeString(char *str);

#endif