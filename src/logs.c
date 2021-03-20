/*
Authors : Tchadel Icard && Arthur Pons
Name : CHUPS.logsC
Date : 18/03/2021
*/

#include <stdio.h>
#include <string.h>
#include "../include/logs.h"
#include "../include/host.h"
#include "../include/file.h"

void makeLog(Host *h, const float pingTime) {
    char log[1024], filename[512];
    char hostname[256];
    char name[128];
    
    int port = getPort(h);
    enum State state = getState(h);

    getHostname(h, hostname);
    getName(h, name);
    sprintf(filename, "%s.%s", name, "lastest");

    sprintf(log, "%s,%s,%d,%u,%.1f", name, hostname, port, state, pingTime);
    writeToFile(filename, log);
}