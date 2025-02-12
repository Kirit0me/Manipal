#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

// Function to calculate the parity bit
char calculate_parity(char *data, char parity_type) {
    int count = 0;
    for (int i = 0; data[i] != '\0'; i++) {
        if (data[i] == '1') {
            count++;
        }
    }

    if (parity_type == 'o') { // Odd parity
        return (count % 2 == 0) ? '1' : '0';
    } else { // Even parity
        return (count % 2 == 0) ? '0' : '1';
    }
}

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char data[128], parity_type, parity_bit, transmitted_data[130];

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
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

    // Get binary data from user
    printf("Enter binary data (e.g., 1101011): ");
    scanf("%s", data);

    // Get parity type
    printf("Choose parity (o for odd, e for even): ");
    scanf(" %c", &parity_type);

    // Calculate parity bit
    parity_bit = calculate_parity(data, parity_type);
    
    // Append parity bit to the data
    snprintf(transmitted_data, sizeof(transmitted_data), "%s%c", data, parity_bit);

    // Send data to receiver
    send(sock, transmitted_data, strlen(transmitted_data), 0);
    printf("Sent data with parity bit: %s\n", transmitted_data);

    // Close socket
    close(sock);
    return 0;
}

