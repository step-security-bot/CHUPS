/*
Authors : Tchadel Icard && Arthur Pons
Name : CHUPS.menuC
Date : 01/03/2021
*/

#include <stdio.h>
#include "../include/textcolor.h"
#include "../include/common.h"
#include "../include/host.h"
#include "../include/menu.h"

void menu(void) {

    textcolor(RESET, GREEN, BLACK);
    puts("#1  -  Look at hosts");
    puts("#2  -  Add an host");
    puts("#3  -  Quit");
    textcolor(RESET, WHITE, BLACK);

}

void addHost(void) {
    clearScreen();

    char name[128];
    enum scanType sType;
    char hostname[256];
    int port, tmpSType;

    printf("Name (displayed in table + logs) : ");
    safeStrInput(&name, 128);

    do
    {
        printf("Which Scan Type do you want to use ? : ");
        printf("\t0  -  ICMP\n");
        printf("\t1  -  SYN/ACK\n");
        printf("> ");

        safeIntInput(&tmpSType);

    } while (tmpSType != 0 || tmpSType != 1);

    sType = tmpSType;

    printf("IP Address : ");
    safeStrInput(hostname, 256);
}