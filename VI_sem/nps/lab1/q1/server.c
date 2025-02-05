#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void sort_array(int *arr, int size, int ascending) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if ((ascending && arr[i] > arr[j]) || (!ascending && arr[i] < arr[j])) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void split_odd_even(int *arr, int size, int *odd, int *even, int *odd_count, int *even_count) {
    *odd_count = *even_count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            even[(*even_count)++] = arr[i];
        } else {
            odd[(*odd_count)++] = arr[i];
        }
    }
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server is running...\n");

    new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
    if (new_socket < 0) {
        perror("Accept failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        read(new_socket, buffer, BUFFER_SIZE);

        if (strcmp(buffer, "exit") == 0) {
            printf("Client disconnected.\n");
            break;
        }

        int size, choice;
        int numbers[100], result[100], odd[100], even[100], odd_count, even_count;

        sscanf(buffer, "%d %d", &size, &choice);
        char *data = strchr(buffer, '|') + 1;

        for (int i = 0; i < size; i++) {
            sscanf(data, "%d", &numbers[i]);
            data = strchr(data, ' ') + 1;
        }

        switch (choice) {
            case 1: // Sort Ascending
                sort_array(numbers, size, 1);
                memcpy(result, numbers, size * sizeof(int));
                break;
            case 2: // Sort Descending
                sort_array(numbers, size, 0);
                memcpy(result, numbers, size * sizeof(int));
                break;
            case 3: // Split Odd and Even
                split_odd_even(numbers, size, odd, even, &odd_count, &even_count);
                break;
            default:
                strcpy(buffer, "Invalid choice");
                write(new_socket, buffer, strlen(buffer));
                continue;
        }

        memset(buffer, 0, BUFFER_SIZE);
        if (choice == 3) {
            sprintf(buffer, "Odd: ");
            for (int i = 0; i < odd_count; i++) {
                char temp[10];
                sprintf(temp, "%d ", odd[i]);
                strcat(buffer, temp);
            }
            strcat(buffer, "\nEven: ");
            for (int i = 0; i < even_count; i++) {
                char temp[10];
                sprintf(temp, "%d ", even[i]);
                strcat(buffer, temp);
            }
        } else {
            sprintf(buffer, "Result: ");
            for (int i = 0; i < size; i++) {
                char temp[10];
                sprintf(temp, "%d ", result[i]);
                strcat(buffer, temp);
            }
        }

        write(new_socket, buffer, strlen(buffer));
    }

    close(new_socket);
    close(server_fd);
    return 0;
}

