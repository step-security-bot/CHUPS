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
#include "../include/synack.h"
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
                
                lookAtHosts();
                break;
            case 2:
                clearScreen();
                addHost();
                clearScreen();
            case 3:
            default:
                break;
        }
    } while(choice != 3);

   printf("Thank you ! ~ ~ Tchadel && Arthur\n");

}

void lookAtHosts() {
    char lines[128][391]; // Pour stocker le fichier chups.dat
    Host host;
    int tmpPort,hostNumber;
    enum scanType tmpSType;
    char tmpHostname[256], tmpName[128];
    readFile("chups.dat",lines, &hostNumber);


    for(int i = 0; i < hostNumber; i++) {

        char* token = strtok(lines[i], ","); 
        if(token == NULL) continue;
        strncpy(tmpName, token, 128);

        token = strtok(NULL, ",");
        if(token == NULL) continue;
        sscanf(token, "%u", &tmpSType);

        token = strtok(NULL, ",");
        if(token == NULL) continue;
        strncpy(tmpHostname, token, 256);

        token= strtok(NULL, ",");
        if(token == NULL) continue;
        sscanf(token, "%d", &tmpPort);

        initHost(&host, tmpName, tmpSType, tmpHostname, tmpPort);

        isOnline(&host);

        if (host.state == ONLINE) {
            printf("%32s %5d  :  ", host.name, host.port);
            
            textcolor(RESET, BLACK, GREEN);
            printf("ONLINE\n");
            textcolor(RESET, WHITE, BLACK);
        } else {
            printf("%32s %5d  :  ", host.name, host.port);
            
            textcolor(RESET, BLACK, RED);
            printf("OFFLINE\n");
            textcolor(RESET, WHITE, BLACK);
        }
    }
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

    sprintf(finalString, "\n%s,%u,%s,%d", name, sType, hostname, port);

    addToFile("chups.dat", finalString);

}