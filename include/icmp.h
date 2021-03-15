/*
Authors : Tchadel Icard && Arthur Pons
Name : CHUPS.icmpH
Date : 15/03/2021
*/

#ifdef __ICMP__H

#include <netinet/ip_icmp.h>

#define PING_PACKET_SIZE

typedef struct {
    struct icmp header;
    char msg[PING_PACKET_SIZE-sizeof(struct icmphdr)];
} pingPacket;

unsigned short checksum(void *packet, int length);

#endif
