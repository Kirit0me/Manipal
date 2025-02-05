#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>

#define SOCKET_PATH "/tmp/dns_socket"

char* lookup_ip(const char* domain) {
    static char ip[50];
    FILE* file = fopen("database.txt", "r");
    if (!file) {
        perror("Error opening database.txt");
        return "Error";
    }

    char db_domain[100], db_ip[50];
    while (fscanf(file, "%s %s", db_domain, db_ip) != EOF) {
        if (strcmp(domain, db_domain) == 0) {
            fclose(file);
            strcpy(ip, db_ip);
            return ip;
        }
    }

    fclose(file);
    return "Not Found";
}

int main() {
    int server_fd, client_fd;
    struct sockaddr_un server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[1024];

    server_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    server_addr.sun_family = AF_UNIX;
    strcpy(server_addr.sun_path, SOCKET_PATH);
    
    unlink(SOCKET_PATH);
    bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_fd, 5);

    printf("DNS Server running...\n");

    while (1) {
        client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_len);
        if (fork() == 0) { // Handle each client in a child process
            read(client_fd, buffer, sizeof(buffer));
            printf("Lookup request: %s\n", buffer);
            char* response = lookup_ip(buffer);
            send(client_fd, response, strlen(response), 0);
            close(client_fd);
            exit(0);
        }
        close(client_fd);
    }

    close(server_fd);
    unlink(SOCKET_PATH);
    return 0;
}

