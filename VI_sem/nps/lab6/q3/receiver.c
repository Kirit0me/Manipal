#include <stdio.h>

// Function to detect and correct errors in received Hamming code
void detectAndCorrectError(int received[7]) {
    int p1, p2, p3, errorPosition;

    // Recalculating parity bits
    p1 = received[0] ^ received[2] ^ received[4] ^ received[6]; // P1
    p2 = received[1] ^ received[2] ^ received[5] ^ received[6]; // P2
    p3 = received[3] ^ received[4] ^ received[5] ^ received[6]; // P3

    // Finding error position
    errorPosition = (p3 * 4) + (p2 * 2) + (p1 * 1);

    if (errorPosition == 0) {
        printf("No error detected in received data.\n");
    } else {
        printf("Error detected at position: %d\n", errorPosition);
        // Correcting the error
        received[errorPosition - 1] ^= 1;
        printf("Corrected Hamming code: ");
        for (int i = 0; i < 7; i++) {
            printf("%d ", received[i]);
        }
        printf("\n");
    }
}

int main() {
    int received[7];

    // Get 7-bit received Hamming code
    printf("Enter received 7-bit Hamming code (space separated): ");
    for (int i = 0; i < 7; i++) {
        scanf("%d", &received[i]);
    }

    // Detect and correct errors
    detectAndCorrectError(received);

    return 0;
}

