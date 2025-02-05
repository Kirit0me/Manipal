#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int is_palindrome(const char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

void count_vowels(const char *str, int *vowel_count) {
    const char *vowels = "aeiouAEIOU";
    memset(vowel_count, 0, 5 * sizeof(int));
    for (int i = 0; str[i] != '\0'; i++) {
        char *ptr = strchr(vowels, str[i]);
        if (ptr) {
            vowel_count[(ptr - vowels) % 5]++;
        }
    }
}

int main() {
    int sockfd;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[BUFFER_SIZE];
    socklen_t len;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Server is running...\n");

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        len = sizeof(cliaddr);
        int n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&cliaddr, &len);
        buffer[n] = '\0';

        if (strcmp(buffer, "Halt") == 0) {
            printf("Received 'Halt', terminating server...\n");
            break;
        }

        printf("Received string: %s\n", buffer);

        int palindrome = is_palindrome(buffer);
        int vowel_count[5] = {0};
        count_vowels(buffer, vowel_count);
        int length = strlen(buffer);

        char response[BUFFER_SIZE];
        snprintf(response, BUFFER_SIZE, "Palindrome: %s\nLength: %d\nVowels: A:%d E:%d I:%d O:%d U:%d",
                 palindrome ? "Yes" : "No",
                 length,
                 vowel_count[0], vowel_count[1], vowel_count[2], vowel_count[3], vowel_count[4]);

        sendto(sockfd, response, strlen(response), 0, (const struct sockaddr *)&cliaddr, len);
        printf("Response sent to client.\n");
    }

    close(sockfd);
    return 0;
}

