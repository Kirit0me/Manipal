#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <message>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sock;
    struct sockaddr_in server_addr;
    char buffer[1024];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    send(sock, argv[1], strlen(argv[1]), 0);
    printf("Sent: %s\n", argv[1]);

    int n = read(sock, buffer, sizeof(buffer));
    if (n > 0) {
        buffer[n] = '\0';
        printf("Server response: %s\n", buffer);
    }

    close(sock);
    return 0;
}

