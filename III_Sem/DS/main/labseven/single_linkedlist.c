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
Node* traverse(Node* head, int data);
void reverse(Node** head_ref);
Node* merge(Node* left, Node* right);
Node* mergeSort(Node* head); 
void deleteAlternate(Node* head);
Node* insert_sorted(Node* head, int c);
void printList(Node* head);
Node* createNode(int data);
Node* sort(Node* head);

void main(){
	Node* head = createNode(2);
	/*printList(head);
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
	printList(sort(head));
	deleteAlternate(head);
	printList(head);
	head = insert_sorted(head, 1);
	head = insert_sorted(head, 6);
	printList(head);*/
    char choice = 'y';
    while(choice == 'y'){
        int num ,data;
        printf("1. INSERT AT THE END\n");
        printf("2. INSERT AFTER\n");
        printf("3. INSERT BEFORE\n");
        printf("4. DELETE\n");
        printf("5. REVERSE NODE\n");
        printf("6. MERGE SORT\n");
        printf("7. DELETE ALTERNATE NODES\n");
        printf("8. INSERT SORTED\n");
        printf("9. SORT\n");
        printf("10. DISPLAY\n");
        printf("Enter the number");
        scanf("%d",&num);
        switch(num){
            case 1:
                printf("Enter number");
                scanf("%d",&data);
                insert_end(head, data);
                break;
            case 2:
                printf("Enter number");
                scanf("%d",&data);
                insert_after(head, data);
                break;
            case 3:
                printf("Enter number");
                scanf("%d",&data);
                insert_before(&head,head->next->next, data);
                break;
            case 4:
                printf("Enter number");
                scanf("%d",&data);
                head = deleteNode(head,data);
                break;
            case 5:
                reverse(&head);
                break;
            case 6:
                head = mergeSort(head);
                break;
            case 7:
                deleteAlternate(head);
                break;
            case 8:
                printf("Enter number");
                scanf("%d",&data);
                head = insert_sorted(head, data);
                break;
            case 9:
                head =  sort(head);
                break;
            case 10:
                printList(head);
                break;
            default:
                printf("Invalid input");
                break;
        }
        printf("Enter your choice (y/n) : ");
        getchar();
        scanf("%c",&choice);
    }
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

    // Check if the value to be deleted is in the head node
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

    // Unlink the node to be deleted
    previous->next = current->next;
    free(current);
    printf("Deleted %d from the list.\n", value);
    return head;
}

void reverse(Node** head_ref)
{
    Node* prev = NULL;
    Node* current = *head_ref;
    Node* next = NULL;
    while (current != NULL) {
        // Store next
        next = current->next;
        // Reverse current node's pointer
        current->next = prev;
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

Node* merge(Node* left, Node* right)
{
    Node dummy;
    Node* tail = &dummy;
    dummy.next = NULL;
    while (left && right) {
        if (left->data <= right->data) {
            tail->next = left;
            left = left->next;
        } else {
            tail->next = right;
            right = right->next;
        }
        tail = tail->next;
    }

    tail->next = (left != NULL) ? left : right;
    return dummy.next;
}

// Function to perform Merge Sort on a linked list
Node* mergeSort(Node* head) 
{
    if (head == NULL || head->next == NULL) {
        return head; // Base case: list is empty or has only one element
    }
    // Split the list into two halves
    Node* slow = head;
    Node* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* left = head;
    Node* right = slow->next;
    slow->next = NULL;
    // Recursively sort both halves
    left = mergeSort(left);
    right = mergeSort(right);
    // Merge the sorted halves
    return merge(left, right);
}

Node* trasverse(Node* head, int data)
{
	Node* current = head;
	while(current->data!=data){
		current=current->next;
	}
	return current;
}

void deleteAlternate(Node* head)
{
    if (head == NULL) {
        return; // Nothing to delete
    }
    Node* current = head;
    Node* temp;

    while (current != NULL && current->next != NULL) {
        temp = current->next; // Node to be deleted
        // Update the next pointer of the current node to skip the next node
        current->next = temp->next;
        // Free the memory of the deleted node
        free(temp);
        // Move to the next pair of nodes
        current = current->next;
    }
}

Node* insert_sorted(Node* head, int c)
{
	Node* newNode = createNode(c);
	Node* current = head;
	if(head == NULL||head->data > c) {
		newNode->next = head;
		head = newNode;
		return head;
	}
	while(current->next!=NULL&&current->next->data<c) {
		current = current->next;
	}
	newNode->next = current->next;
	current->next = newNode;
	return head;
}

Node* sort(Node* head)
{
	Node* i;
	Node* j;
	Node* current = head;
	for(i=head;i->next!=NULL;i=i->next){
		for(j=head;j->next!=NULL;j=j->next){
			if(j->data > j->next->data){
				int temp = j->data;	
				j->data = j->next->data;
				j->next->data = temp;
			}
		}
	}
	return head;
}
