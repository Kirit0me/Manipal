#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}node;

node* create(int data);
void display(node* head);
node* insert(node* head, int data);
node* reverse(node* head);

int main()
{
	node* head = create(-1);
	head = insert(head, 1);
	head = insert(head, 4);
	head = insert(head, 5);
	head = insert(head, 0);
	head = insert(head, 9);
	head = insert(head, 6);
	head = insert(head, 7);
	display(head);
	printf("\n");
	head = reverse(head);
	display(head);	
	printf("\n");
}

node* create(int data)
{
	node* new = (node* )malloc(sizeof(node));
	new->data = data;
	new->next = NULL;
	return new;
}

node* insert(node* head, int data)
{
	node* new = create(data);
	node* current = head;
	while(current->next != NULL){
		current = current->next;
	}
	current->next = new;
	return head;
}

void display(node* head)
{
	node* current = head;
	while(current != NULL){
		printf("%d->", current->data);
		current = current->next;
	}
	printf("NULL");
}

node* reverse(node* head)
{
	node* current = head;
	node* prev = NULL;
	node* nextn = NULL;
	while(current!=NULL){
		nextn = current->next;
		current->next = prev;
		prev = current;
		current = nextn;
	}
	return prev;
}