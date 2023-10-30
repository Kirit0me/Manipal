#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertEnd(Node** head, int data) {
    Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void deleteSmallest(Node** head) {
    if (*head == NULL) return;

    Node* current = *head;
    Node* smallest = current;

    while (current != NULL) {
        if (current->data < smallest->data)
            smallest = current;
        current = current->next;
    }

    if (smallest->prev != NULL)
        smallest->prev->next = smallest->next;
    if (smallest->next != NULL)
        smallest->next->prev = smallest->prev;

    if (*head == smallest)
        *head = smallest->next;

    free(smallest);
}
void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    insertEnd(&head, 10);
    insertEnd(&head, 5);
    insertEnd(&head, 15);
    insertEnd(&head, 7);
    insertEnd(&head, 3);
    printf("Original List: ");
    printList(head);
    deleteSmallest(&head);
    printf("List after deleting the smallest element: ");
    printList(head);
    return 0;
}
