#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50


struct Stack {
    int top;
    char items[MAX];
};

void initialize(struct Stack *stack)
{
    stack->top = -1;
}
// Function to check if the stack is empty
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}
// Function to check if the stack is full
int isFull(struct Stack *stack)
{
    return stack->top == MAX - 1;
}
// Function to push an item onto the stack
void push(struct Stack *stack, char item)
{
    if (isFull(stack)) {
        printf("Stack overflow, cannot push %c\n", item);
        return;
    }

    stack->top++;
    stack->items[stack->top] = item;
}
// Function to pop an item from the stack
char pop(struct Stack *stack)
{
    if (isEmpty(stack)) {
        printf("Stack underflow, cannot pop\n");
        return -1; // Return an error value
    }
    char poppedItem = stack->items[stack->top];
    stack->top--;
    return poppedItem;
}

void main()
{
    int i, c;
    char s[MAX];
    struct Stack stack;
    initialize(&stack);
    //while (1){
        //printf("1. Enter Expression \n2. Exit\n");
        //printf("Enter your choice\n");
        //scanf("%d", &c);
        //switch (c){
        //case 1:
            printf("Enter the Expression\n");
            gets(s);
            for (i = 0;s[i] != '\0';i++){
                if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                    push(&stack, s[i]);
                }
                if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
                    char lparan = pop(&stack);
                    char rparan = s[i];
                    if( (lparan == '(' && rparan == ')') || (lparan == '[' && rparan == ']') || (lparan == '{' && rparan == '}') ) continue;
                    else{
                        printf("Unmatched");
                        break;
                    }
                }
            }
            if(isEmpty(&stack)){
                printf("Balanced Stack");
            }
            else{
                printf("Unbalanced Stack");
            }
        //}
    //}
}


