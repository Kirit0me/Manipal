#include <stdio.h>

// Function to calculate parity bits and generate Hamming code
void generateHammingCode(int data[4], int hammingCode[7]) {
    // Assigning data bits
    hammingCode[2] = data[0]; // D1
    hammingCode[4] = data[1]; // D2
    hammingCode[5] = data[2]; // D3
    hammingCode[6] = data[3]; // D4

    // Calculating parity bits (even parity)
    hammingCode[0] = hammingCode[2] ^ hammingCode[4] ^ hammingCode[6]; // P1
    hammingCode[1] = hammingCode[2] ^ hammingCode[5] ^ hammingCode[6]; // P2
    hammingCode[3] = hammingCode[4] ^ hammingCode[5] ^ hammingCode[6]; // P3
}

// Function to introduce an error at a given position
void introduceError(int hammingCode[7], int position) {
    if (position >= 1 && position <= 7) {
        hammingCode[position - 1] ^= 1; // Flip the bit at the given position
    }
}

int main() {
    int data[4];
    int hammingCode[7];

    // Get 4-bit data from user
    printf("Enter 4-bit data (space separated, e.g., 1 0 1 1): ");
    for (int i = 0; i < 4; i++) {
        scanf("%d", &data[i]);
    }

    // Generate Hamming code
    generateHammingCode(data, hammingCode);

    // Print generated Hamming code
    printf("Generated Hamming code: ");
    for (int i = 0; i < 7; i++) {
        printf("%d ", hammingCode[i]);
    }
    printf("\n");

    // Introduce an error (optional)
    int errorPosition;
    printf("Enter error bit position (1-7) to introduce error (0 for no error): ");
    scanf("%d", &errorPosition);
    if (errorPosition != 0) {
        introduceError(hammingCode, errorPosition);
        printf("Hamming code with error: ");
        for (int i = 0; i < 7; i++) {
            printf("%d ", hammingCode[i]);
        }
        printf("\n");
    }

    return 0;
}

