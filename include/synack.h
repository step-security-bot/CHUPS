#ifndef __SYNACK__H
#define __SYNACK__H

#include "host.h"
#include <stdbool.h>

void isOnline(Host *h);
bool checkIp(const char* ip);

#endif