#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Function to count occurrences of a substring
int count_occurrences(const char *text, const char *str) {
    int count = 0;
    const char *pos = text;
    while ((pos = strstr(pos, str)) != NULL) {
        count++;
        pos += strlen(str);
    }
    return count;
}

// Function to replace a substring in a string
void replace_string(char *text, const char *str1, const char *str2) {
    char buffer[BUFFER_SIZE];
    char *pos, *start = text;
    buffer[0] = '\0';

    while ((pos = strstr(start, str1)) != NULL) {
        strncat(buffer, start, pos - start);
        strcat(buffer, str2);
        start = pos + strlen(str1);
    }
    strcat(buffer, start);
    strcpy(text, buffer);
}

// Function to reorder the file contents
void reorder_file(char *text) {
    int len = strlen(text);
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (text[i] > text[j]) {
                char temp = text[i];
                text[i] = text[j];
                text[j] = temp;
            }
        }
    }
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    char buffer[BUFFER_SIZE], file_buffer[BUFFER_SIZE];
    socklen_t addrlen = sizeof(address);

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server is running...\n");

    // Accept connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, &addrlen)) < 0) {
        perror("Accept failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        read(new_socket, buffer, BUFFER_SIZE);

        // Exit on "4"
        if (strcmp(buffer, "4") == 0) {
            printf("Client disconnected.\n");
            break;
        }

        char file_name[BUFFER_SIZE], option;
        sscanf(buffer, "%c %s", &option, file_name);

        FILE *file = fopen(file_name, "r+");
        if (!file) {
            strcpy(buffer, "File not present");
            send(new_socket, buffer, strlen(buffer), 0);
            continue;
        }

        // Read file contents
        fseek(file, 0, SEEK_END);
        size_t file_size = ftell(file);
        rewind(file);
        fread(file_buffer, 1, file_size, file);
        file_buffer[file_size] = '\0';

        if (option == '1') {  // Search
            char search_str[BUFFER_SIZE];
            sscanf(buffer + 2 + strlen(file_name), "%s", search_str);
            int count = count_occurrences(file_buffer, search_str);
            if (count > 0) {
                snprintf(buffer, BUFFER_SIZE, "String found %d times", count);
            } else {
                strcpy(buffer, "String not found");
            }
        } else if (option == '2') {  // Replace
            char str1[BUFFER_SIZE], str2[BUFFER_SIZE];
            sscanf(buffer + 2 + strlen(file_name), "%s %s", str1, str2);
            if (strstr(file_buffer, str1)) {
                replace_string(file_buffer, str1, str2);
                rewind(file);
                ftruncate(fileno(file), 0);
                fwrite(file_buffer, 1, strlen(file_buffer), file);
                strcpy(buffer, "String replaced");
            } else {
                strcpy(buffer, "String not found");
            }
        } else if (option == '3') {  // Reorder
            reorder_file(file_buffer);
            rewind(file);
            ftruncate(fileno(file), 0);
            fwrite(file_buffer, 1, strlen(file_buffer), file);
            strcpy(buffer, "File reordered");
        }

        fclose(file);
        send(new_socket, buffer, strlen(buffer), 0);
    }

    close(new_socket);
    close(server_fd);
    return 0;
}

