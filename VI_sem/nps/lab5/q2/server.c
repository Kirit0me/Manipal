#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>

#define PORT 8080

// Function to check if two strings are anagrams
int areAnagrams(char *str1, char *str2) {
    int count[256] = {0};

    // If lengths differ, they are not anagrams
    if (strlen(str1) != strlen(str2))
        return 0;

    // Count character frequencies
    for (int i = 0; str1[i] && str2[i]; i++) {
        count[(unsigned char)str1[i]]++;
        count[(unsigned char)str2[i]]--;
    }

    // Check if all counts are zero
    for (int i = 0; i < 256; i++) {
        if (count[i] != 0)
            return 0;
    }
    return 1;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    char buffer[1024], str1[512], str2[512];
    char client_ip[INET_ADDRSTRLEN];

    // Create a socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_fd, 5) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accept a client connection
        new_socket = accept(server_fd, (struct sockaddr*)&client_addr, &addr_len);
        if (new_socket < 0) {
            perror("Accept failed");
            continue;
        }

        // Get client IP
        inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, INET_ADDRSTRLEN);

        // Get current time
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        printf("Connected to client %s at %02d:%02d:%02d\n", client_ip, tm.tm_hour, tm.tm_min, tm.tm_sec);

        // Read data from client
        memset(buffer, 0, sizeof(buffer));
        read(new_socket, buffer, sizeof(buffer));

        // Parse received strings
        sscanf(buffer, "%s %s", str1, str2);
        printf("Received strings: \"%s\" and \"%s\" from %s\n", str1, str2, client_ip);

        // Check for anagrams
        char result[50];
        if (areAnagrams(str1, str2)) {
            strcpy(result, "Anagrams");
        } else {
            strcpy(result, "Not Anagrams");
        }

        // Send result back to client
        send(new_socket, result, strlen(result), 0);
        printf("Sent result: %s\n", result);

        // Close client connection
        close(new_socket);
    }

    close(server_fd);
    return 0;
}

