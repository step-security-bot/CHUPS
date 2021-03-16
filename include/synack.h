/*
Authors : Tchadel Icard && Arthur Pons
Name : CHUPS.synackH
Date : 02/03/2021
*/

#ifndef __SYNACK__H
#define __SYNACK__H

#include "host.h"
#include <stdbool.h>

int connect_wait (int sockno, struct sockaddr * addr, size_t addrlen, struct timeval * timeout);
void isOnline(Host *h, float *pingTime);
bool checkIp(const char* ip);

#endif