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

// Stack Implementation using Singly Linked List
struct Stack {
    struct Node* top;
};

// Initialize an empty stack
void initStack(struct Stack* stack) {
    stack->top = NULL;
}

// Push an element onto the stack
void push(struct Stack* stack, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Pop an element from the stack
int pop(struct Stack* stack) {
    if (stack->top == NULL) {
        fprintf(stderr, "Stack is empty.\n");
        exit(1);
    }

    struct Node* poppedNode = stack->top;
    int data = poppedNode->data;
    stack->top = poppedNode->next;
    free(poppedNode);
    return data;
}

// Queue Implementation using Singly Linked List
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Initialize an empty queue
void initQueue(struct Queue* queue) {
    queue->front = queue->rear = NULL;
}

// Enqueue an element into the queue
void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = createNode(data);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

// Dequeue an element from the queue
int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        fprintf(stderr, "Queue is empty.\n");
        exit(1);
    }

    struct Node* dequeuedNode = queue->front;
    int data = dequeuedNode->data;
    queue->front = dequeuedNode->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(dequeuedNode);
    return data;
}

int main() {
    struct Stack stack;
    struct Queue queue;
    initStack(&stack);
    initQueue(&queue);

    // Push elements onto the stack
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    // Pop elements from the stack
    printf("Stack: %d ", pop(&stack));
    printf("%d ", pop(&stack));
    printf("%d\n", pop(&stack));

    // Enqueue elements into the queue
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    // Dequeue elements from the queue
    printf("Queue: %d ", dequeue(&queue));
    printf("%d ", dequeue(&queue));
    printf("%d\n", dequeue(&queue));

    return 0;
}
