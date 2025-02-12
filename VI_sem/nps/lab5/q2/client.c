#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char str1[512], str2[512], buffer[1024];

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Connect to the server
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // Get user input
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    // Send strings to server
    snprintf(buffer, sizeof(buffer), "%s %s", str1, str2);
    send(sock, buffer, strlen(buffer), 0);
    printf("Sent: \"%s\" and \"%s\"\n", str1, str2);

    // Receive result from server
    memset(buffer, 0, sizeof(buffer));
    read(sock, buffer, sizeof(buffer));
    printf("Server response: %s\n", buffer);

    // Close socket
    close(sock);
    return 0;
}

