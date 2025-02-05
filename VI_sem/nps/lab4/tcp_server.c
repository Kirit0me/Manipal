#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 5

void* handle_request(void* arg) {
    int new_socket = *((int*)arg);
    free(arg);

    char buffer[1024] = {0};
    read(new_socket, buffer, sizeof(buffer));

    int pid = getpid();
    char response[1024];

    if (strncmp(buffer, "1", 1) == 0) {
        snprintf(response, sizeof(response), "Name: John Doe, Address: 123 Main St [PID: %d]", pid);
    } else if (strncmp(buffer, "2", 1) == 0) {
        snprintf(response, sizeof(response), "Dept: CS, Semester: 5, Section: A, Courses: 4 [PID: %d]", pid);
    } else if (strncmp(buffer, "3", 1) == 0) {
        snprintf(response, sizeof(response), "Marks: 85/100 in CS101 [PID: %d]", pid);
    } else {
        snprintf(response, sizeof(response), "Invalid request [PID: %d]", pid);
    }

    send(new_socket, response, strlen(response), 0);
    close(new_socket);
    return NULL;
}

int main() {
    int server_fd, *new_socket;
    struct sockaddr_in address;
    socklen_t addrlen = sizeof(address);
    pthread_t thread_id;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr*)&address, sizeof(address));
    listen(server_fd, MAX_CLIENTS);

    printf("TCP Server listening on port %d...\n", PORT);

    while (1) {
        new_socket = malloc(sizeof(int));
        *new_socket = accept(server_fd, (struct sockaddr*)&address, &addrlen);

        pthread_create(&thread_id, NULL, handle_request, new_socket);
        pthread_detach(thread_id); // Automatically cleans up finished threads
    }

    return 0;
}

