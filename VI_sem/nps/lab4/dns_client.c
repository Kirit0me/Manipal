#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>

#define SOCKET_PATH "/tmp/dns_socket"

int main() {
    int sockfd;
    struct sockaddr_un server_addr;
    char domain[100], buffer[1024];

    sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
    server_addr.sun_family = AF_UNIX;
    strcpy(server_addr.sun_path, SOCKET_PATH);

    connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));

    printf("Enter domain to resolve: ");
    scanf("%s", domain);

    send(sockfd, domain, strlen(domain), 0);
    read(sockfd, buffer, sizeof(buffer));

    printf("Resolved IP: %s\n", buffer);

    close(sockfd);
    return 0;
}

