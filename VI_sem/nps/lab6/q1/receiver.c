#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

// Function to check parity
int check_parity(char *data, char parity_type) {
    int count = 0;
    int length = strlen(data);
    
    // Count the number of 1s in the received data
    for (int i = 0; i < length - 1; i++) {
        if (data[i] == '1') {
            count++;
        }
    }

    // Extract the received parity bit
    char received_parity = data[length - 1];

    // Compute expected parity bit
    char expected_parity;
    if (parity_type == 'o') { // Odd parity
        expected_parity = (count % 2 == 0) ? '1' : '0';
    } else { // Even parity
        expected_parity = (count % 2 == 0) ? '0' : '1';
    }

    // Compare received parity with expected parity
    return (received_parity == expected_parity);
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    char received_data[130], parity_type;

    // Create socket
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

    // Accept client connection
    new_socket = accept(server_fd, (struct sockaddr*)&client_addr, &addr_len);
    if (new_socket < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    // Receive data from sender
    read(new_socket, received_data, sizeof(received_data));
    received_data[strcspn(received_data, "\n")] = 0; // Remove newline if present

    // Ask for parity type
    printf("Received data: %s\n", received_data);
    printf("Enter parity type used (o for odd, e for even): ");
    scanf(" %c", &parity_type);

    // Check parity
    if (check_parity(received_data, parity_type)) {
        printf("Data is NOT corrupted.\n");
    } else {
        printf("Data is CORRUPTED!\n");
    }

    // Close socket
    close(new_socket);
    close(server_fd);
    return 0;
}

