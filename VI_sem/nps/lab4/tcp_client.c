#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    char option[2], buffer[1024] = {0};
    
    printf("Enter an option:\n1. Registration Number\n2. Name of Student\n3. Subject Code\nChoice: ");
    scanf("%s", option);
    
    send(sock, option, strlen(option), 0);
    read(sock, buffer, sizeof(buffer));
    
    printf("Server Response: %s\n", buffer);
    close(sock);
    return 0;
}

