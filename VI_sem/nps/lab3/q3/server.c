#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <ctype.h>
#include <sys/wait.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Compare function for ascending sort (digits)
int compare_asc(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

// Compare function for descending sort (characters)
int compare_desc(const void *a, const void *b) {
    return (*(char *)b - *(char *)a);
}

// Process digits and return sorted string
void process_numbers(const char *input, char *output) {
    char digits[BUFFER_SIZE];
    int d = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (isdigit(input[i])) digits[d++] = input[i];
    }
    digits[d] = '\0';
    qsort(digits, d, sizeof(char), compare_asc);
    snprintf(output, BUFFER_SIZE, "Child PID %d: %s\n", getpid(), digits);
}

// Process characters and return sorted string
void process_chars(const char *input, char *output) {
    char chars[BUFFER_SIZE];
    int c = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (isalpha(input[i])) chars[c++] = input[i];
    }
    chars[c] = '\0';
    qsort(chars, c, sizeof(char), compare_desc);
    snprintf(output, BUFFER_SIZE, "Parent PID %d: %s\n", getpid(), chars);
}

int main() {
    int server_fd, connfd;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket to port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accept incoming connection
        if ((connfd = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
            perror("accept failed");
            continue;
        }

        // Read client's string
        int valread = read(connfd, buffer, BUFFER_SIZE);
        buffer[valread] = '\0';
        printf("Received: %s\n", buffer);

        // Fork to handle client
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork failed");
            close(connfd);
            continue;
        }

        if (pid == 0) { // Child process (handles digits)
            close(server_fd); // Close listener in child

            char response[BUFFER_SIZE];
            process_numbers(buffer, response);
            send(connfd, response, strlen(response), 0);

            close(connfd);
            exit(EXIT_SUCCESS);
        } else { // Parent process (handles characters)
            wait(NULL); // Wait for child to finish

            char response[BUFFER_SIZE];
            process_chars(buffer, response);
            send(connfd, response, strlen(response), 0);

            close(connfd);
        }
    }

    return 0;
}
