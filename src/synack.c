/*
Authors : Tchadel Icard && Arthur Pons
Name : CHUPS.synackC
Date : 02/03/2021
*/

// Includes de base
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Includes UNIX
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

// Includes pour les sockets UNIX
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/select.h>
#include <sys/time.h>
#include <time.h>

// Includes pour les tructures additionnelles
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>

// Includes des libs custom
#include "../include/host.h"
#include "../include/synack.h"

int connect_wait (int sockno, struct sockaddr * addr, size_t addrlen, struct timeval * timeout)
{
	int res, opt;
	
	// Récupère les flags des sockets
	if ((opt = fcntl (sockno, F_GETFL, NULL)) < 0) {
		return -1;
	}

	// Mettre le socket en non bloquant
	if (fcntl (sockno, F_SETFL, opt | O_NONBLOCK) < 0) {
		return -1;
	}

	// Tentative de connexion
	if ((res = connect (sockno, addr, addrlen)) < 0) {
		if (errno == EINPROGRESS) {
			fd_set wait_set;

			// Initialiser un file descriptor avec le socket dedans
			FD_ZERO (&wait_set);
			FD_SET (sockno, &wait_set);

			// Attendre que le socket soit utilisable, couper à la fin du timeout
			res = select (sockno + 1, NULL, &wait_set, NULL, timeout);
		}
	}
	// Connexion effective de suite
	else {
		res = 1;
	}

	// Réinitialisation des flags des sockets
	if (fcntl (sockno, F_SETFL, opt) < 0) {
		return -1;
	}

	// Erreur dans le socket ou dans select
	if (res < 0) {
		return -1;
	}
	// Erreur : temps écoulé
	else if (res == 0) {
		errno = ETIMEDOUT;
		return 1;
	}

	else {
		socklen_t len = sizeof (opt);

		// Vérification des erreurs dans le socket
		if (getsockopt (sockno, SOL_SOCKET, SO_ERROR, &opt, &len) < 0) {
			return -1;
		}

		// Dernière verification d'erreur
		if (opt) {
			errno = opt;
			return -1;
		}
	}

	return 0;
}

void isOnline(Host *h, float *pingTime) {

	int sock;
	int isConnected;
	int ipv6Detect = 0;
	
	char hostname[256];
	char port[6]; // Un port contient 6 charactères max avec le \0
	clock_t start, end;

	struct timeval tv;
	struct addrinfo hint; // Sert à déterminer si c'est IPV4 ou IPV6 qui va être utilisé

	getHostname(h, hostname);
	/*	snprintf(port, 6, "%d", getPort(h));
	getaddrinfo(hostname, port, &hint, &hint); // PRODUIT BCP DE BUGS */

	for(int i = 0; i < strlen(hostname); i++){
		if(hostname[i] == ':') {
			ipv6Detect++;
			break;
		}
	}

	if(ipv6Detect == 1) {
		//struct sockaddr_in6 hint;

		struct sockaddr_in6 hint6;

		sock = socket(AF_INET6, SOCK_STREAM, 0);
		hint6.sin6_family = AF_INET6;

		//inet_pton(PF_INET6, hostname, &hint.sin_addr);
		inet_pton(AF_INET6, hostname, &hint6.sin6_addr);

		hint6.sin6_port = htons(getPort(h));
	
		tv.tv_sec = 2; // Mettre un timeout de 2 secondes
		tv.tv_usec = 0;

		start = clock();
		
		isConnected = connect_wait (sock, (struct sockaddr *)&hint6, sizeof(hint6), &tv); // Fonction utilisant un timeout

		//int isConnected = connect(sock, (struct sockaddr*)&hint, sizeof(hint));
		end = clock();

		*pingTime = ( ((double) (end - start)) / CLOCKS_PER_SEC) * 100000; // Convertir en millisecondes

	} else {
		
		struct sockaddr_in hint4;

		sock = socket(AF_INET, SOCK_STREAM, 0);
		hint4.sin_family = AF_INET;
		inet_pton(AF_INET, hostname, &hint4.sin_addr);

		hint4.sin_port = htons(getPort(h));
		
		tv.tv_sec = 2; // Mettre un timeout de 2 secondes
		tv.tv_usec = 0;

		start = clock();
		
		isConnected = connect_wait (sock, (struct sockaddr *)&hint4, sizeof(hint4), &tv); // Fonction utilisant un timeout
		//int isConnected = connect(sock, (struct sockaddr*)&hint, sizeof(hint));
		end = clock();

		*pingTime = ( ((double) (end - start)) / CLOCKS_PER_SEC) * 100000; // Convertir en millisecondes
	}

    close(sock);

    if (isConnected != 0)
        setState(h, OFFLINE);
    else
        setState(h, ONLINE);
}

bool checkIp(const char* ip)
{
	struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ip, &(sa.sin_addr)) || inet_pton(AF_INET6, ip, &(sa.sin_addr)); // On check si l'IP est valide en V4 ou en V6
    return result != 0;
}