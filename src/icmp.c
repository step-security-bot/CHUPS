#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/ip_icmp.h>
#include "../include/icmp.h"

unsigned short checksum(void *packet, int length) {
    unsigned short *p = packet;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; length > 1; length -= 2)
        sum += *p++;
    if (length == 1)
        sum += *(unsigned char*)p;

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;

    return result;
}

void sendPing(int ping_sockfd,
              struct sockaddr_in *ping_addr,
              char *ping_dom,
              char *ping_ip,
              char *rev_host) {


}
