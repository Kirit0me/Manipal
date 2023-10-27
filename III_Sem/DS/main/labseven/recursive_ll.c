#include <stdio.h>
#include <stdlib.h>

// Define the structure for a single node in the linked list
struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* createLinkedList() {
    int data;
    printf("Enter data for the node (enter -1 to stop): ");
    scanf("%d", &data);

    if (data == -1) {
        return NULL; // Base case: return NULL for an empty list
    }

    struct Node* newNode = createNode(data);
    newNode->next = createLinkedList(); // Recursive call to create the rest of the list

    return newNode; // Return the new node, which becomes the head of the list
}

void traverseLinkedList(struct Node* current) {
    if (current == NULL) {
        return;
    }

    printf("%d -> ", current->data);
    traverseLinkedList(current->next);
}


int main() {
    struct Node* head = NULL;
    head = createLinkedList();
    printf("Linked List: ");
    traverseLinkedList(head);
    printf("NULL\n");

    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}





