#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node;

void insert_end(Node* head, int data);
void insert_after(Node* node, int data);
void insert_before(Node** head, Node* current, int data);
Node* deleteNode(Node* head, int value);
void traverse();
void reverse();
void sort();
void delete_alt();
void insert_sorted();
void printList(Node* head);
Node* createNode(int data);

void main(){
	Node* head;
	head->next = NULL;
	head->data = NULL;
	insert_end(head, 2);
	printList(head);
	insert_after(head, 9);
	printList(head);
	insert_after(head, 8);
	printList(head);
	insert_after(head->next, 6);
	printList(head);
	insert_after(head, 7);
	printList(head);
	insert_before(&head, head->next, 4);
	printList(head);
	insert_before(&head, head->next->next->next, 5);
	printList(head);
	Node* whatnode = deleteNode(head, 4);
	printList(head);
	insert_end(head, 4);
	printList(head);
}

Node* createNode(int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void insert_after(Node* node, int data)
{
	Node* newNode = createNode(data);
	newNode->next = node->next;
	node->next = newNode;
}

void insert_before(Node** head, Node* current, int data)
{
	Node* newNode = createNode(data);
    // If the current node is the head of the list, update the head
    if (*head == current) {
        newNode->next = current;
        *head = newNode;
    } else {
        Node* previous = *head;
        while (previous->next != NULL && previous->next != current) {
            previous = previous->next;
        }
        previous->next = newNode;
        newNode->next = current;
    }
}

void insert_end(Node* head, int data)
{
	Node* newNode = createNode(data);
	if(head==NULL){
		head=newNode;
	} else {
		Node* current = head;
		while(current->next != NULL){
			current = current->next;
		}
		current->next = newNode;
	}
}

void printList(Node* head)
{
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

Node* deleteNode(Node* head, int value)
{
    Node* current = head;
    Node* previous = NULL;

    if (current != NULL && current->data == value) {
        head = current->next;
        free(current);
        printf("Deleted %d from the list.\n", value);
        return head;
    }

    while (current != NULL && current->data != value) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("%d not found in the list.\n", value);
        return head;
    }

    previous->next = current->next;
    free(current);
    printf("Deleted %d from the list.\n", value);
    return head;
}

