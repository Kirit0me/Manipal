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

void concatenateLists(Node** X1, Node* X2) {
    if (*X1 == NULL) {
        *X1 = X2;
    } else {
        Node* temp = *X1;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = X2;
        X2->prev = temp;
    }
}

void printListForward(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* X1 = NULL;
    Node* X2 = NULL;

    insertEnd(&X1, 10);
    insertEnd(&X1, 20);
    insertEnd(&X1, 30);

    insertEnd(&X2, 40);
    insertEnd(&X2, 50);

    concatenateLists(&X1, X2);

    printf("Concatenated List (Forward): ");
    printListForward(X1);
    return 0;
}
