#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8081

int main() {
    int sockfd;
    struct sockaddr_in serv_addr;
    socklen_t addr_len = sizeof(serv_addr);
    char option[2], buffer[1024] = {0};

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    printf("Enter an option:\n1. Registration Number\n2. Name of Student\n3. Subject Code\nChoice: ");
    scanf("%s", option);

    sendto(sockfd, option, strlen(option), 0, (struct sockaddr*)&serv_addr, addr_len);
    recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&serv_addr, &addr_len);

    printf("Server Response: %s\n", buffer);
    close(sockfd);
    return 0;
}

