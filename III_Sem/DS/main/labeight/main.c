#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;
// Function prototypes
Node* createNode(int data);
void rear_insert(Node* header, int data);
void display(Node* header);

int main() {

    Node* header = createNode(-1); // Header node with data -1
    int choice, data;
    while (1) {
        printf("\n1. Insert an element at the rear\n");
        printf("2. Display the doubly linked list\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                rear_insert(header, data);
                break;
            case 2:
                display(header);
                break;
            case 3:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
// Function to insert a new element at the end of the doubly linked list
void rear_insert(Node* header, int data) {
    Node* newNode = createNode(data);
    Node* current = header;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}
// Function to display the elements of the doubly linked list
void display(Node* header) {
    if (header->next == NULL) {
        printf("Doubly linked list is empty.\n");
        return;
    }
    Node* current = header->next;
    printf("Doubly linked list elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
