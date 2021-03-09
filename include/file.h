/*
Authors : Tchadel Icard && Arthur Pons
Name : CHUPS.fileH
Date : 03/03/2021
*/

#ifndef __FILE__H__
#define __FILE__H__

void addToFile(const char *filename, const char *content);
void readFile(const char*filename, char linesBuf[128][391], int *hostNumber);

#endif