#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}node;

node* create(int data);
void display(node* head);
node* insert(node* head, int data);
void sort(node* head);

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
	sort(head);	
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

void sort(node* head)
{
	node* head1 = create(-1); node* head2 = create(-1);
	node* current = head;
	int i = 0;
	while(current->next != NULL){
		if(i%2 == 0){
			head1 = insert(head1, current->next->data);
			i++;
		} else {
			head2 = insert(head2, current->next->next->data);
			i++;
		}
		current = current->next;
	}
	display(head1);
	printf("\n");
	display(head2);
	printf("\n");
}

