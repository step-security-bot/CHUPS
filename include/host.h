/*
Authors : Tchadel Icard && Arthur Pons
Name : CHUPS.hostH
Date : 01/03/2021
*/

#ifndef __HOST__H__
#define __HOST__H__

enum scanType{ICMP, SYNACK};
enum State{ONLINE, OFFLINE};

typedef struct Host {
    char name[128]; // Nom générique donné a l'hôte à l'intérieur du programme. Affiché dans le tableau d'affichage et dans les logs.
    enum scanType sType; // Défini le type de scan
    char hostname[256]; // Pour stocker l'IP ou le nom de domaine
    int port; // Port utilisé pour le scan SYNACK. 0 si scan ICMP.
    enum State state;
} Host;

// Prototype du constructeur

void initHost(Host *host, char *name, enum scanType stype, char *hostname, int port);

// Prototypes des Getters & des Setters

void setName(Host *host, char *name);
void getName(Host *host, char *nameBuf);

void setScanType(Host *host, enum scanType sType);
enum scanType getScanType(Host *host);

void setPort(Host *host, int port);
int getPort(Host *host);

void setHostname(Host *host, char *hostname);
void getHostname(Host *host, char *hostname);

void setState(Host *host, enum State state);
enum State getState(Host *host);

#endif