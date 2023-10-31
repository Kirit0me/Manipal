#include <stdio.h>
#include <stdlib.h>

typedef struct dnode{
	int data;
	struct dnode* prev;
	struct dnode* next;
}dnode;

dnode* create_dnode(int data);
dnode* insert_begin(dnode* head, int data);

dnode* insert_end(dnode* head, int data);
dnode* delete_end(dnode* head);
dnode* insert(dnode* head, int pos, int data);
dnode* delete(dnode* head, int pos);
void insert_before(dnode* node, int data);
void insert_after(dnode* node, int data);
dnode* reverseList(dnode* head);
void display(dnode* head);

int main()
{
	dnode* head = create_dnode(-1);
    char choice = 'y';
    while(choice == 'y'){
        int num,data;
        printf("1. INSERTING NODE AT THE BEGINNING\n");
        printf("2. INSERTING NODE AT THE END\n");
        printf("3. DELETING NODE AT THE END\n");
        printf("4. INSERTING AT A PARTICULAR POSITION\n");
        printf("5. DELETING AT A PARTICULAR POSITION\n");
        printf("6. INSERTING BEFORE A NODE\n");
        printf("7. INSERTING AFTER A NODE\n");
        printf("8. REVERSING A LINKED LIST\n");
        printf("9. DISPLAY\n");
        printf("Enter number : ");
        scanf("%d",&num);
        switch(num){
            case 1:
                printf("Enter the number : ");
                scanf("%d",&data);
                head = insert_begin(head,data);
                break;
            case 2:
                printf("Enter the number : ");
                scanf("%d",&data);
                head = insert_end(head, data);
                break;
            case 3:
                head = delete_end(head);
                break;
            case 4:
                printf("Enter the position and number: ");
                int pos;
                scanf("%d %d",&pos,&data);
                head = insert(head,pos,data);
                break;
            case 5:
                printf("Enter the position : ");
                scanf("%d",&pos);
                head = delete(head, pos);
                break;
            case 6:
                printf("Enter the number : ");
                scanf("%d",&data);
                dnode* node = head->next->next;
                insert_before(node,data);
                break;
            case 7:
                printf("Enter the number : ");
                scanf("%d",&data);
                node = head->next->next->next;
                insert_after(node, data);
                break;
            case 8:
                head = reverseList(head);
                break;
            case 9:
                display(head);
                break;
            default:
                printf("Invlaid input");
                break;
        }
        printf("Enter your choice(y/n) : ");
        getchar();
        scanf("%c",&choice);
    }

}

dnode* create_dnode(int data)
{
	dnode *temp = malloc(sizeof(dnode));
	temp->data = data;
	temp->prev=temp->next=NULL;
	return temp;
}

dnode* insert_begin(dnode* head, int data)
{
	dnode *temp = create_dnode(data);
	if(head==NULL) {
		head = temp;
		return head;
	} else {
		temp->next = head;
		head->prev = temp;
		return temp;
	}
}

dnode* insert_end(dnode* head, int data)
{
	dnode* newdnode = create_dnode(data);
	dnode* current = head;
	while(current->next != NULL){
		current = current->next;
	}
	current->next = newdnode;
	newdnode->prev = current;
	return head;
}

dnode* delete_end(dnode* head)
{
	dnode* current = head;
	while(current->next != NULL){
		current = current->next;
	}
	dnode* temp = current->prev;
	temp->next = NULL;
	free(current);
	return head;
}


void display(dnode* head)
{
	if(head->next == NULL){
		printf("Doubly linked list is empty");
		return;
	}
	dnode* current = head;
	printf("Doubly Linked elements:");
	while(current!=NULL){
		printf("%d->", current->data);
		current = current->next;
	}
    printf("NULL");
	printf("\n");
}

void insert_after(dnode* node, int data)
{
	dnode* temp = create_dnode(data);
	temp->next = node->next;
	node->next->prev = temp;
	temp->prev = node;
	node->next = temp;
}

void insert_before(dnode* node, int data)
{
	dnode* temp = create_dnode(data);
	temp->prev = node->prev;
	node->prev->next = temp;
	temp->next = node;
	node->prev = temp;
}

dnode* insert(dnode* head, int pos, int data)
{
	dnode* newdnode = create_dnode(data);
	dnode* current = head;
	for(int i = 0;i<pos;i++){
		current = current->next;
	}
    newdnode->next = current->next;
    current->next->prev = newdnode;
	current->next = newdnode;
	newdnode->prev = current;
	return head;
}

dnode* delete(dnode* head, int pos)
{
	dnode* current = head;
	for(int i = 0;i<pos;i++){
		current = current->next;
	}
	dnode* temp = current->prev;
	dnode* nextn = current->next;
	temp->next = nextn;
	nextn->prev = temp;
	free(current);
	return head;
}

dnode* reverseList(dnode* head) {
    dnode* current = head;
    dnode* temp = NULL;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    return temp->prev;

    /*if (temp != NULL) {
        head = temp->prev;
    }*/
}

//
//
//
//
//
//
//
//
//
//
//
//