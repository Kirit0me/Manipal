#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define SERVER_IP "127.0.0.1"
#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Create UDP socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        perror("Invalid server address");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Client is running (PID: %d, PPID: %d)\n", getpid(), getppid());
    printf("Enter a string: ");
    
    // Read input from user
    fgets(buffer, BUFFER_SIZE, stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove trailing newline

    // Send data to server
    sendto(sockfd, buffer, strlen(buffer), 0,
          (struct sockaddr*)&server_addr, sizeof(server_addr));

    printf("String sent to server: %s\n", buffer);
    close(sockfd);
    return 0;
}
