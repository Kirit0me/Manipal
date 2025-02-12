#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

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
    int sock;
    struct sockaddr_in server_addr;
    char data[128], choice;
    unsigned int crc_poly, crc_value;
    int crc_width;

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Connect to server
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // Get data from user
    printf("Enter data to send: ");
    scanf("%s", data);

    // Choose CRC type
    printf("Choose CRC type (1: CRC-12, 2: CRC-16, 3: CRC-CCITT): ");
    scanf(" %c", &choice);

    // Set CRC polynomial
    switch (choice) {
        case '1': crc_poly = 0x180D; crc_width = 12; break;
        case '2': crc_poly = 0x8005; crc_width = 16; break;
        case '3': crc_poly = 0x1021; crc_width = 16; break;
        default: printf("Invalid choice\n"); close(sock); exit(1);
    }

    // Compute CRC
    crc_value = compute_crc(data, crc_poly, crc_width);

    // Send data with CRC
    char transmitted_data[150];
    snprintf(transmitted_data, sizeof(transmitted_data), "%s|%X", data, crc_value);
    send(sock, transmitted_data, strlen(transmitted_data), 0);
    printf("Sent: %s\n", transmitted_data);

    // Close socket
    close(sock);
    return 0;
}

