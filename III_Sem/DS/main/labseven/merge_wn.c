#include <stdio.h>
#include <stdlib.h>

// Define the structure for a single node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to merge two sorted linked lists into a new sorted linked list
struct Node* mergeSortedLists(struct Node* X, struct Node* Y) {
    if (X == NULL) {
        return Y;
    }
    if (Y == NULL) {
        return X;
    }

    struct Node* Z = NULL; // The merged list
    struct Node* tail = NULL; // Tail of the merged list

    while (X != NULL && Y != NULL) {
        if (X->data < Y->data) {
            if (Z == NULL) {
                Z = X;
                tail = X;
            } else {
                tail->next = X;
                tail = X;
            }
            X = X->next;
        } else {
            if (Z == NULL) {
                Z = Y;
                tail = Y;
            } else {
                tail->next = Y;
                tail = Y;
            }
            Y = Y->next;
        }
    }

    if (X != NULL) {
        tail->next = X;
    }
    if (Y != NULL) {
        tail->next = Y;
    }

    return Z;
}

// Function to display the linked list
void displayLinkedList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* X = createNode(1);
    X->next = createNode(3);
    X->next->next = createNode(5);

    struct Node* Y = createNode(2);
    Y->next = createNode(4);
    Y->next->next = createNode(6);

    printf("List X: ");
    displayLinkedList(X);
    printf("List Y: ");
    displayLinkedList(Y);

    struct Node* Z = mergeSortedLists(X, Y);
    printf("Merged List Z: ");
    displayLinkedList(Z);

    // Free memory used by the linked lists
    while (Z != NULL) {
        struct Node* temp = Z;
        Z = Z->next;
        free(temp);
    }

    return 0;
}
