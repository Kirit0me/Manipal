#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Swap characters at positions `i` and `j` in the string
void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

// Generate and print all permutations of the string
void permute(char *str, int l, int r) {
    if (l == r) {
        printf("%s\n", str);
    } else {
        for (int i = l; i <= r; i++) {
            swap(&str[l], &str[i]);
            permute(str, l + 1, r);
            swap(&str[l], &str[i]); // Backtrack
        }
    }
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];

    // Create UDP socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket to the address
    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Server is running (PID: %d, PPID: %d)\n", getpid(), getppid());

    while (1) {
        // Receive data from client
        int bytes_received = recvfrom(sockfd, buffer, BUFFER_SIZE, 0,
                                     (struct sockaddr*)&client_addr, &client_len);
        if (bytes_received < 0) {
            perror("recvfrom failed");
            continue;
        }

        buffer[bytes_received] = '\0'; // Null-terminate the received string
        printf("\nReceived from client: %s\n", buffer);
        printf("All permutations:\n");
        
        // Compute and print permutations
        permute(buffer, 0, strlen(buffer) - 1);
    }

    close(sockfd);
    return 0;
}
