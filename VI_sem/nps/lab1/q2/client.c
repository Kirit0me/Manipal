#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[BUFFER_SIZE];
    char input[BUFFER_SIZE];
    socklen_t len;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    while (1) {
        printf("Enter a string (or 'Halt' to exit): ");
        fgets(input, BUFFER_SIZE, stdin);
        input[strcspn(input, "\n")] = '\0'; // Remove newline character

        sendto(sockfd, input, strlen(input), 0, (const struct sockaddr *)&servaddr, sizeof(servaddr));

        if (strcmp(input, "Halt") == 0) {
            printf("Terminating client...\n");
            break;
        }

        memset(buffer, 0, BUFFER_SIZE);
        len = sizeof(servaddr);
        int n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&servaddr, &len);
        buffer[n] = '\0';

        printf("Server response:\n%s\n", buffer);
    }

    close(sockfd);
    return 0;
}

