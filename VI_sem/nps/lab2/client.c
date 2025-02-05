#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[BUFFER_SIZE], file_name[BUFFER_SIZE], input[BUFFER_SIZE];

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    while (1) {
        printf("Enter file name: ");
        scanf("%s", file_name);

        printf("Menu:\n1. Search\n2. Replace\n3. Reorder\n4. Exit\nEnter your choice: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 4) {
            write(sockfd, "4", 1);
            printf("Exiting client...\n");
            break;
        }

        if (choice == 1) {
            printf("Enter string to search: ");
            char search_str[BUFFER_SIZE];
            scanf("%s", search_str);
            snprintf(buffer, BUFFER_SIZE, "%d %s %s", choice, file_name, search_str);
        } else if (choice == 2) {
            printf("Enter string to replace and replacement string: ");
            char str1[BUFFER_SIZE], str2[BUFFER_SIZE];
            scanf("%s %s", str1, str2);
            snprintf(buffer, BUFFER_SIZE, "%d %s %s %s", choice, file_name, str1, str2);
        } else if (choice == 3) {
            snprintf(buffer, BUFFER_SIZE, "%d %s", choice, file_name);
        }

        write(sockfd, buffer, strlen(buffer));

        memset(buffer, 0, BUFFER_SIZE);
        read(sockfd, buffer, BUFFER_SIZE);
        printf("Server response: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}

