#include <stdio.h>
#include <stdlib.h>

// Define a structure for a single term in a polynomial
struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
};

// Function to create a new term
struct Term* createTerm(int coefficient, int exponent) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    return newTerm;
}

// Function to insert a term into a polynomial
void insertTerm(struct Term** poly, int coefficient, int exponent) {
    struct Term* newTerm = createTerm(coefficient, exponent);

    if (*poly == NULL) {
        *poly = newTerm;
    } else {
        struct Term* current = *poly;
        struct Term* prev = NULL;

        while (current != NULL && current->exponent > exponent) {
            prev = current;
            current = current->next;
        }

        if (current != NULL && current->exponent == exponent) {
            // If a term with the same exponent already exists, add coefficients
            current->coefficient += coefficient;
            free(newTerm);
        } else {
            // Otherwise, insert the new term at the appropriate position
            if (prev == NULL) {
                newTerm->next = *poly;
                *poly = newTerm;
            } else {
                prev->next = newTerm;
                newTerm->next = current;
            }
        }
    }
}

// Function to add two polynomials
struct Term* addPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;

    while (poly1 != NULL || poly2 != NULL) {
        if (poly1 == NULL) {
            insertTerm(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else if (poly2 == NULL) {
            insertTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent > poly2->exponent) {
            insertTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly2->exponent > poly1->exponent) {
            insertTerm(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            int sum = poly1->coefficient + poly2->coefficient;
            if (sum != 0) {
                insertTerm(&result, sum, poly1->exponent);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    return result;
}
struct Term* multiplyPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;

    while (poly1 != NULL) {
        struct Term* currentTerm = poly2;

        while (currentTerm != NULL) {
            int coefficient = poly1->coefficient * currentTerm->coefficient;
            int exponent = poly1->exponent + currentTerm->exponent;
            insertTerm(&result, coefficient, exponent);

            currentTerm = currentTerm->next;
        }

        poly1 = poly1->next;
    }

    return result;
}


// Function to display a polynomial
void displayPolynomial(struct Term* poly) {
    if (poly == NULL) {
        printf("0");
    } else {
        while (poly != NULL) {
            printf("%d", poly->coefficient);
            if (poly->exponent > 0) {
                printf("x^%d", poly->exponent);
            }
            if (poly->next != NULL) {
                printf(" + ");
            }
            poly = poly->next;
        }
    }
    printf("\n");
}

// Function to free memory used by a polynomial
void freePolynomial(struct Term* poly) {
    while (poly != NULL) {
        struct Term* temp = poly;
        poly = poly->next;
        free(temp);
    }
}

int main() {
    struct Term* poly1 = NULL;
    struct Term* poly2 = NULL;
    struct Term* result = NULL;

    // Insert terms into the first polynomial
    insertTerm(&poly1, 3, 2);
    insertTerm(&poly1, -2, 1);
    insertTerm(&poly1, 5, 0);

    // Insert terms into the second polynomial
    insertTerm(&poly2, 2, 3);
    insertTerm(&poly2, 4, 1);
    insertTerm(&poly2, -1, 0);

    printf("Polynomial 1: ");
    displayPolynomial(poly1);
    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    result = addPolynomials(poly1, poly2);
    printf("Addition Result: ");
    displayPolynomial(result);

    result = multiplyPolynomials(poly1, poly2);
    printf("Multiplication Result: ");
    displayPolynomial(result);

    // Free memory used by the linked lists
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);

    return 0;
}
