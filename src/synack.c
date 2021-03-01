#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdbool.h>
#include <string.h>

#include "../include/host.h"
#include "../include/synack.h"

void isOnline(Host *h) {

    char hostname[256];
    getHostname(h, &hostname);

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

    int isConnected = connect(sock, (struct sockaddr*)&hint, sizeof(hint));

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