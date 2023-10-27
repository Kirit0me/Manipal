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

// Function to merge two lists as specified
struct Node* mergeLists(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }

    struct Node* mergedList = createNode(list1->data);
    struct Node* tail = mergedList;
    list1 = list1->next;

    while (list1 != NULL || list2 != NULL) {
        if (list2 != NULL) {
            tail->next = createNode(list2->data);
            tail = tail->next;
            list2 = list2->next;
        }
        if (list1 != NULL) {
            tail->next = createNode(list1->data);
            tail = tail->next;
            list1 = list1->next;
        }
    }

    return mergedList;
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
    struct Node* list1 = createNode(1);
    list1->next = createNode(2);
    list1->next->next = createNode(3);

    struct Node* list2 = createNode(4);
    list2->next = createNode(5);

    printf("List 1: ");
    displayLinkedList(list1);
    printf("List 2: ");
    displayLinkedList(list2);

    struct Node* list3 = mergeLists(list1, list2);
    printf("Merged List 3: ");
    displayLinkedList(list3);

    // Free memory used by the linked lists
    while (list3 != NULL) {
        struct Node* temp = list3;
        list3 = list3->next;
        free(temp);
    }

    return 0;
}
