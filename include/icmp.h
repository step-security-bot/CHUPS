/*
Authors : Tchadel Icard && Arthur Pons
Name : CHUPS.icmpH
Date : 15/03/2021
*/

#ifndef __ICMP__H
#define __ICMP__H

#define DEF_DATA_LEN 56
#define MAX_IP_LEN 60
#define MAX_ICMP_LEN 76

int checksum(unsigned short *packet, int size);

#endif