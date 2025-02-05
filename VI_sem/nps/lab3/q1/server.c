#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Structure to pass socket descriptor to threads
typedef struct {
    int sock;
} ThreadArgs;

// Thread function to handle receiving messages
void* receive_handler(void* arg) {
    ThreadArgs* args = (ThreadArgs*)arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = read(args->sock, buffer, BUFFER_SIZE)) > 0) {
        buffer[bytes_read] = '\0';
        printf("Client: %s", buffer);
    }

    // Cleanup
    free(args);
    pthread_exit(NULL);
}

// Thread function to handle sending messages
void* send_handler(void* arg) {
    ThreadArgs* args = (ThreadArgs*)arg;
    char buffer[BUFFER_SIZE];

    while (1) {
        fgets(buffer, BUFFER_SIZE, stdin);
        if (write(args->sock, buffer, strlen(buffer)) <= 0) {
            perror("Write failed");
            break;
        }
    }

    // Cleanup
    free(args);
    pthread_exit(NULL);
}

// Handle client connection with separate send/receive threads
void* handle_client(void* arg) {
    int client_sock = *((int*)arg);
    free(arg); // Free the malloc'ed socket descriptor

    printf("Child Process: PID=%d, PPID=%d\n", getpid(), getppid());

    // Create argument structures for threads
    ThreadArgs *recv_args = malloc(sizeof(ThreadArgs));
    ThreadArgs *send_args = malloc(sizeof(ThreadArgs));
    recv_args->sock = client_sock;
    send_args->sock = client_sock;

    pthread_t recv_tid, send_tid;
    pthread_create(&recv_tid, NULL, receive_handler, recv_args);
    pthread_create(&send_tid, NULL, send_handler, send_args);

    // Wait for threads to finish (though they loop indefinitely)
    pthread_join(recv_tid, NULL);
    pthread_join(send_tid, NULL);

    close(client_sock);
    printf("Client disconnected.\n");
    pthread_exit(NULL);
}

int main() {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_sock, 5);

    printf("Server listening on port %d...\n", PORT);
    printf("Parent Process: PID=%d, PPID=%d\n", getpid(), getppid());

    while (1) {
        client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &client_len);
        if (client_sock < 0) {
            perror("Accept failed");
            continue;
        }

        printf("Client connected.\n");

        // Pass socket descriptor safely to the thread
        int* client_sock_ptr = malloc(sizeof(int));
        *client_sock_ptr = client_sock;
        pthread_t tid;
        pthread_create(&tid, NULL, handle_client, client_sock_ptr);
    }

    close(server_sock);
    return 0;
}
