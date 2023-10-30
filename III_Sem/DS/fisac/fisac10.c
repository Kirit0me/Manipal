#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(Node** head, int data) {
    Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        Node* temp = *head;
        while (temp->next != *head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = *head;
    }
}

int isPrime(int num) {
    if (num < 2)
        return 0;
    for (int i = 2; i*i <= num; i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

void deletePrimes(Node** head) {
    Node* current = *head;
    Node* prev = NULL;

    if (*head == NULL) return;

    do {
        if (isPrime(current->data)) {
            if (current == *head) {
                Node* temp = *head;
                while (temp->next != *head)
                    temp = temp->next;
                temp->next = (*head)->next;
                free(*head);
                *head = temp->next;
                current = *head;
				prev = temp;
            } else {
                prev->next = current->next;
                free(current);
                current = prev->next;
            }
        } else {
            prev = current;
            current = current->next;
        }
    } while (current != *head);
}

void printList(Node* head) {
    Node* temp = head;
    if (head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }
}

int main() {
    Node* head = NULL;

    insertEnd(&head, 4);
    insertEnd(&head, 3);
    insertEnd(&head, 5);
    insertEnd(&head, 7);
    insertEnd(&head, 11);
    insertEnd(&head, 6);
    insertEnd(&head, 9);

    printf("Original List: ");
    printList(head);

    deletePrimes(&head);

    printf("List after deleting primes: ");
    printList(head);
    return 0;
}
