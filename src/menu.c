/*
Authors : Tchadel Icard && Arthur Pons
Name : CHUPS.menuC
Date : 01/03/2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/textcolor.h"
#include "../include/common.h"
#include "../include/host.h"
#include "../include/menu.h"
#include "../include/file.h"

void menu(void) {

    int choice;

    do {
        textcolor(RESET, GREEN, BLACK);
        puts("#1  -  Look at hosts");
        puts("#2  -  Add an host");
        puts("#3  -  Quit");
        printf("> ");
        safeIntInput(&choice);
        textcolor(RESET, WHITE, BLACK);
        switch(choice) {
            case 1:
                // TODO add menu option
                break;
            case 2:
                addHost();
            case 3:
            default:
                break;
        }
    } while(choice != 3);

}

void addHost(void) {
    clearScreen();

    char name[128];
    char hostname[256];
    char finalString[391];
    enum scanType sType;

    int port, tmpSType;

    printf("Name (displayed in table + logs) : ");
    safeStrInput(name, 128);

    do
    {
        printf("Which Scan Type do you want to use ? : \n");
        printf("\t0  -  ICMP\n");
        printf("\t1  -  SYN/ACK\n");
        printf("> ");

        safeIntInput(&tmpSType);

    } while (tmpSType != 0 && tmpSType != 1);

    sType = tmpSType;

    printf("IP Address : ");
    safeStrInput(hostname, 256);

    if(sType == 0) {
        port = 0;
    } else {
        printf("Port number : ");
        safeIntInput(&port);
    }

    sanityzeString(name);
    sanityzeString(hostname);

    sprintf(finalString, "%s,%u,%s,%d\n", name, sType, hostname, port);

    addToFile("chups.dat", finalString);

}