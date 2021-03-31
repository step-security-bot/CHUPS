// Include de base
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Include UNIX
#include <unistd.h>
#include <errno.h>

// Include pour les sockets UNIX
#include <sys/types.h>
#include <sys/socket.h>

// Include pour les structures additionnelles
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>

// Include des libs custom
#include "../include/icmp.h"

int checksum(unsigned short *payload, int size) {
    int sum = 0;
    unsigned short *p = payload;
    unsigned short result = 0;

    while (size > 1) {
        sum += *p++;
        size -= 2;
    }

    if (size == 1) {
        *(unsigned char *) (&result) = *(unsigned char *) p;
        sum += result;
    }

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;

    return result;
}

//void sendPing(char *host) {
//    struct hostent *h;
//    struct sockaddr_in dest;
//    struct icmp *p;
//    int sock;
//    char packet[DEF_DATA_LEN + MAX_IP_LEN + MAX_ICMP_LEN];
//
//
//    // Verifier que le socket se créer correctement
//    if ((sock = socket(AF_INET, SOCK_RAW, 1)) < 0) {
//        printf("unable to create socket");
//        return;
//    }
//
//    // Affecter la taille d'une adresse IP à la variable dest
//    memset(&dest, 0, sizeof(struct sockaddr_in));
//
//    // dest.sin_family = AF_INET;
//
//    if (!(h = getaddrinfo(host))) {
//
//    }
//
//
//
//}

void sendPing(char *host) {
    struct addrinfo hints, *result;
    int sock, ioLen;
    // Le nombre de protocol 1 corresponds au protocol ICMP
    int protocol = 1;
    struct icmp *payload;
    char packet[DEF_DATA_LEN + MAX_IP_LEN + MAX_ICMP_LEN];

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = PF_UNSPEC;
    hints.ai_socktype = SOCK_RAW;

    if ((getaddrinfo(host, 0, &hints, &result)) < 0) {
        printf("L'adresse IP entrée est invalide");
        return;
    }

    if ((sock = socket(result->ai_family, result->ai_socktype, protocol)) < 0) {
        printf("Le socket ne s'est pas ouvert correctement");
        return;
    }

    payload = (struct icmp *) packet;
    memset(payload, 0, sizeof(packet));
    payload->icmp_type = ICMP_ECHO;
    payload->icmp_cksum = checksum((unsigned short *) payload, sizeof(packet));

    if (result->ai_family == AF_INET6)
        ioLen = sendto(sock, packet, sizeof(packet), 0, result->ai_addr, sizeof(struct sockaddr_in6));
    else
        ioLen = sendto(sock, packet, sizeof(packet), 0, result->ai_addr, sizeof(struct sockaddr_in));

    if (ioLen < 0 || ioLen != sizeof(packet)) {
        printf("Erreur lors de l'envoi du packet");
        return;
    }

    while (1) {
        if (result->ai_family == AF_INET6) {
            struct sockaddr_in6 source;
            socklen_t sourceLen = sizeof(source);

            if (( ioLen = recvfrom( sock, packet, sizeof(packet), 0, (struct sockaddr *) &source, &sourceLen ) ) < 0) {
                printf("L'hôte n'a pas répondu");
                continue;
            }

            if (ioLen >= 76) {
                struct iphdr * iphdr = (struct iphdr *) packet;

                payload = (struct icmp *) (packet + (iphdr->ihl << 2));

                if (payload->icmp_type == ICMP_ECHOREPLY)
                    break;
            }
        } else {
            struct sockaddr_in source;
            socklen_t sourceLen = sizeof(source);

            if (( ioLen = recvfrom( sock, packet, sizeof(packet), 0, (struct sockaddr *) &source, &sourceLen ) ) < 0) {
                printf("L'hôte n'a pas répondu");
                continue;
            }

            if (ioLen >= 76) {
                struct iphdr * iphdr = (struct iphdr *) packet;

                payload = (struct icmp *) (packet + (iphdr->ihl << 2));

                if (payload->icmp_type == ICMP_ECHOREPLY)
                    break;
            }
        }

    }
}
