/*
Authors : Tchadel Icard && Arthur Pons
Name : CHUPS.hostC
Date : 01/03/2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/host.h"

// "Constructeur"

void initHost(Host *host, char *name, enum scanType stype, char *hostname, int port) {
    
    // Utilisation de strncpy pour éviter les buffer overflow (:la_chance:)
    
    strncpy(host->name, name, 128);
    host->sType = stype;
    strncpy(host->hostname, hostname, 256);
    host->port = port;
    host->state = OFFLINE;
}

// Getters & Setters

void setName(Host *host, char *name) {
    strncpy(host->name, name, 128);
}

void getName(Host *host, char *nameBuf) {
    strncpy(nameBuf, host->name, 128);
}

void setScanType(Host *host, enum scanType sType) {
    host->sType = sType;
}

enum scanType getScanType(Host *host) {
    return host->sType;
}

void setHostname(Host *host, char *hostname) {
    strncpy(host->hostname, hostname, 256);
}

void getHostname(Host *host, char *hostname) {
    strncpy(hostname, host->hostname, 256);
}

void setPort(Host *host, int port) {
    host->port = port;
}

int getPort(Host *host) {
    return host->port;
}

void setState(Host *host, enum State state) {
    host->state = state;
}

enum State getState(Host *host) {
    return host->state;
}