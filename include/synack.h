/*
Authors : Tchadel Icard && Arthur Pons
Name : CHUPS.synackH
Date : 02/03/2021
*/

#ifndef __SYNACK__H
#define __SYNACK__H

#include "host.h"
#include <stdbool.h>

void isOnline(Host *h);
bool checkIp(const char* ip);

#endif