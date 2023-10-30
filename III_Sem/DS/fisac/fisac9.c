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
    } else {
        Node* temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Function to delete a node from the list
void deleteNode(Node** head, Node* target) {
    if (*head == NULL || target == NULL) return;

    if (*head == target) {
        *head = target->next;
        free(target);
        return;
    }

    Node* current = *head;
    while (current->next != target)
        current = current->next;

    current->next = target->next;
    free(target);
}

void symmetricDifference(Node** list1, Node** list2) {
    Node* current1 = *list1;
    Node* current2 = *list2;
    Node* prev1 = NULL;
    Node* prev2 = NULL;

    while (current1 != NULL && current2 != NULL) {
        if (current1->data < current2->data) {
            prev1 = current1;
            current1 = current1->next;
        } else if (current1->data > current2->data) {
            prev2 = current2;
            current2 = current2->next;
        } else {
            if (prev1 == NULL)
                *list1 = current1->next;
            else
                prev1->next = current1->next;

            if (prev2 == NULL)
                *list2 = current2->next;
            else
                prev2->next = current2->next;

            free(current1);
            free(current2);

            current1 = (prev1 == NULL) ? *list1 : prev1->next;
            current2 = (prev2 == NULL) ? *list2 : prev2->next;
        }
    }
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("\n");
}


int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;

    // Insert elements into the first SLL
    insertEnd(&list1, 1);
    insertEnd(&list1, 3);
    insertEnd(&list1, 5);

    // Insert elements into the second SLL
    insertEnd(&list2, 3);
    insertEnd(&list2, 4);
    insertEnd(&list2, 5);

    // Print original lists
    printf("Original List 1: ");
    printList(list1);
    printf("Original List 2: ");
    printList(list2);

    // Find symmetric difference
    symmetricDifference(&list1, &list2);

    // Print symmetric difference
    printf("Symmetric Difference: ");
    printList(list1);
    return 0;
}
