#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX_CLIENTS 2

int main() {
    int server_fd, new_socket, client_count = 0;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    char buffer[1024];
    char client_msgs[2][1024];
    char client_ips[2][INET_ADDRSTRLEN];

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (client_count < MAX_CLIENTS) {
        new_socket = accept(server_fd, (struct sockaddr*)&client_addr, &addr_len);
        if (new_socket < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        inet_ntop(AF_INET, &client_addr.sin_addr, client_ips[client_count], INET_ADDRSTRLEN);
        read(new_socket, buffer, sizeof(buffer));
        strcpy(client_msgs[client_count], buffer);
        
        printf("Received: %s from %s\n", buffer, client_ips[client_count]);
        client_count++;

        if (client_count == MAX_CLIENTS) {
            FILE *file = fopen("data.txt", "r");
            char file_content[1024];
            if (file) {
                fgets(file_content, sizeof(file_content), file);
                fclose(file);
            } else {
                strcpy(file_content, "Manipal");
            }

            printf("Final Message: %s %s %s\n", file_content, client_msgs[0], client_msgs[1]);

            close(new_socket);
        }
    }

    // Handling third client connection
    new_socket = accept(server_fd, (struct sockaddr*)&client_addr, &addr_len);
    if (new_socket > 0) {
        char terminate_msg[] = "terminate session";
        send(new_socket, terminate_msg, strlen(terminate_msg), 0);
        printf("Terminating session...\n");
        close(new_socket);
    }

    close(server_fd);
    return 0;
}

