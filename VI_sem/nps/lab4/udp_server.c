#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8081

int main() {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    char buffer[1024];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));

    printf("UDP Server listening on port %d...\n", PORT);

    while (1) {
        recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&client_addr, &addr_len);
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

        sendto(sockfd, response, strlen(response), 0, (struct sockaddr*)&client_addr, addr_len);
    }
    return 0;
}

