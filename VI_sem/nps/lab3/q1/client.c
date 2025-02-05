#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define SERVER_IP "127.0.0.1"
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
        printf("Server: %s", buffer);
    }

    free(args);
    printf("Server disconnected.\n");
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

    free(args);
    pthread_exit(NULL);
}

int main() {
    int sock;
    struct sockaddr_in server_addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr));
    printf("Connected to server.\n");
    printf("Client Process: PID=%d, PPID=%d\n", getpid(), getppid());

    // Create argument structures for threads
    ThreadArgs *recv_args = malloc(sizeof(ThreadArgs));
    ThreadArgs *send_args = malloc(sizeof(ThreadArgs));
    recv_args->sock = sock;
    send_args->sock = sock;

    pthread_t recv_tid, send_tid;
    pthread_create(&recv_tid, NULL, receive_handler, recv_args);
    pthread_create(&send_tid, NULL, send_handler, send_args);

    // Wait indefinitely (threads run in loops)
    pthread_join(recv_tid, NULL);
    pthread_join(send_tid, NULL);

    close(sock);
    return 0;
}
