#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insert(int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        newNode->prev = newNode;
        newNode->next = newNode;
    } else {
        struct Node* lastNode = head->prev;
        lastNode->next = newNode;
        newNode->prev = lastNode;
        newNode->next = head;
        head->prev = newNode;
    }

    printf("%d inserted into the list.\n", data);
}

void delete(int data) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node* current = head;
    int found = 0;

    do {
        if (current->data == data) {
            found = 1;
            break;
        }
        current = current->next;
    } while (current != head);

    if (found) {
        if (current == head) {
            if (current->next == current) {
                head = NULL;
            } else {
                struct Node* lastNode = head->prev;
                head = current->next;
                lastNode->next = head;
                head->prev = lastNode;
            }
        } else {
            struct Node* prevNode = current->prev;
            struct Node* nextNode = current->next;
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
        }
        free(current);
        printf("%d deleted from the list.\n", data);
    } else {
        printf("%d not found in the list.\n", data);
    }
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;

    do {
        printf("%d <-> ", current->data);
        current = current->next;
    } while (current != head);

    printf("\n");
}

int main() {
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Display the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                printf("Enter the element to delete: ");
                scanf("%d", &data);
                delete(data);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
