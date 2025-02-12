#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

// CRC function
unsigned int compute_crc(char *data, unsigned int poly, int width) {
    unsigned int crc = 0;
    int data_len = strlen(data);

    for (int i = 0; i < data_len; i++) {
        crc ^= (unsigned char)data[i] << (width - 8);
        for (int j = 0; j < 8; j++) {
            if (crc & (1 << (width - 1))) {
                crc = (crc << 1) ^ poly;
            } else {
                crc <<= 1;
            }
        }
    }
    return crc & ((1 << width) - 1);
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    char received_data[150], data[128], crc_str[10], choice;
    unsigned int crc_poly, crc_value, computed_crc;
    int crc_width;

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
    sscanf(received_data, "%[^|]|%s", data, crc_str);
    crc_value = strtoul(crc_str, NULL, 16);
    
    // Ask user for CRC type used
    printf("Received data: %s\n", data);
    printf("Enter CRC type used (1: CRC-12, 2: CRC-16, 3: CRC-CCITT): ");
    scanf(" %c", &choice);

    // Set CRC polynomial
    switch (choice) {
        case '1': crc_poly = 0x180D; crc_width = 12; break;
        case '2': crc_poly = 0x8005; crc_width = 16; break;
        case '3': crc_poly = 0x1021; crc_width = 16; break;
        default: printf("Invalid choice\n"); close(new_socket); close(server_fd); exit(1);
    }

    // Compute CRC
    computed_crc = compute_crc(data, crc_poly, crc_width);

    // Verify CRC
    if (computed_crc == crc_value) {
        printf("Data is NOT corrupted.\n");
    } else {
        printf("Data is CORRUPTED!\n");
    }

    // Close socket
    close(new_socket);
    close(server_fd);
    return 0;
}

