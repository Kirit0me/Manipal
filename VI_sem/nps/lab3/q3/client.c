#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};
    char input[BUFFER_SIZE];

    // Get input from user
    printf("Enter an alphanumeric string: ");
    fgets(input, BUFFER_SIZE, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation error");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4/IPv6 address to binary
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("invalid address");
        return -1;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connection failed");
        return -1;
    }

    // Send string to server
    send(sock, input, strlen(input), 0);
    printf("String sent: %s\n", input);

    // Receive and print server response
    int total_read = 0;
    while (1) {
        int bytes_read = read(sock, buffer + total_read, BUFFER_SIZE - total_read);
        if (bytes_read <= 0) break;
        total_read += bytes_read;
    }
    buffer[total_read] = '\0';
    printf("\nServer Response:\n%s", buffer);

    close(sock);
    return 0;
}
