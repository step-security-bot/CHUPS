/*
Authors : Tchadel Icard && Arthur Pons
Name : CHUPS.synackC
Date : 02/03/2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <sys/select.h>
#include <sys/time.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>


#include "../include/host.h"
#include "../include/synack.h"

int connect_wait (int sockno, struct sockaddr * addr, size_t addrlen, struct timeval * timeout)
{
	int res, opt;

	// get socket flags
	if ((opt = fcntl (sockno, F_GETFL, NULL)) < 0) {
		return -1;
	}

	// set socket non-blocking
	if (fcntl (sockno, F_SETFL, opt | O_NONBLOCK) < 0) {
		return -1;
	}

	// try to connect
	if ((res = connect (sockno, addr, addrlen)) < 0) {
		if (errno == EINPROGRESS) {
			fd_set wait_set;

			// make file descriptor set with socket
			FD_ZERO (&wait_set);
			FD_SET (sockno, &wait_set);

			// wait for socket to be writable; return after given timeout
			res = select (sockno + 1, NULL, &wait_set, NULL, timeout);
		}
	}
	// connection was successful immediately
	else {
		res = 1;
	}

	// reset socket flags
	if (fcntl (sockno, F_SETFL, opt) < 0) {
		return -1;
	}

	// an error occured in connect or select
	if (res < 0) {
		return -1;
	}
	// select timed out
	else if (res == 0) {
		errno = ETIMEDOUT;
		return 1;
	}
	// almost finished...
	else {
		socklen_t len = sizeof (opt);

		// check for errors in socket layer
		if (getsockopt (sockno, SOL_SOCKET, SO_ERROR, &opt, &len) < 0) {
			return -1;
		}

		// there was an error
		if (opt) {
			errno = opt;
			return -1;
		}
	}

	return 0;
}

void isOnline(Host *h, float *pingTime) {

    char hostname[256];
    getHostname(h, hostname);

    if(!checkIp(hostname)) {
        printf("HostnameError : IP Address %s is not valid. Couldn't verify host's availability.", hostname);
        setState(h, OFFLINE);
        return;
    } else if (getPort(h) > 65535 || getPort(h) < 1) {
        printf("PortNumberError : Port %d is not valid. Couldn't verify host's availability.", getPort(h));
        setState(h, OFFLINE);
        return;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in hint;

    hint.sin_family = AF_INET;
    hint.sin_port = htons(getPort(h));

    inet_pton(AF_INET, hostname, &hint.sin_addr);

    struct timeval tv;
    tv.tv_sec = 2; // Mettre un timeout de 2 secondes
    tv.tv_usec = 0;


    //int isConnected = connect(sock, (struct sockaddr*)&hint, sizeof(hint));

	clock_t start, end;

	start = clock();
    
	int isConnected = connect_wait (sock, (struct sockaddr *)&hint, sizeof(hint), &tv); // Fonction utilisant un timeout
	
	end = clock();
	*pingTime = ( ((double) (end - start)) / CLOCKS_PER_SEC) * 100000;

    close(sock);

    if (isConnected != 0)
        setState(h, OFFLINE);
    else
        setState(h, ONLINE);
}

bool checkIp(const char* ip)
{
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ip, &(sa.sin_addr));
    return result != 0;
}