#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation error");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("Invalid address/Address not supported");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        return -1;
    }

    while (1) {
        int size, choice;
        printf("Enter number of integers: ");
        scanf("%d", &size);

        printf("Enter the integers: ");
        int numbers[100];
        for (int i = 0; i < size; i++) {
            scanf("%d", &numbers[i]);
        }

        printf("Choose operation:\n1. Sort Ascending\n2. Sort Descending\n3. Split Odd and Even\n4. Exit\n");
        scanf("%d", &choice);

        if (choice == 4) {
            strcpy(buffer, "exit");
            send(sock, buffer, strlen(buffer), 0);
            break;
        }

        memset(buffer, 0, BUFFER_SIZE);
        sprintf(buffer, "%d %d|", size, choice);
        for (int i = 0; i < size; i++) {
            char temp[10];
            sprintf(temp, "%d ", numbers[i]);
            strcat(buffer, temp);
        }

        send(sock, buffer, strlen(buffer), 0);
        memset(buffer, 0, BUFFER_SIZE);
        read(sock, buffer, BUFFER_SIZE);
        printf("Server response: %s\n", buffer);
    }

    close(sock);
    return 0;
}

