#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50


struct Stack {
    int top;
    int items[MAX];
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
void push(struct Stack *stack, int item)
{
    if (isFull(stack)) {
        printf("Stack overflow, cannot push %d\n", item);
        return;
    }

    stack->top++;
    stack->items[stack->top] = item;
}
// Function to pop an item from the stack
int pop(struct Stack *stack)
{
    if (isEmpty(stack)) {
        printf("Stack underflow, cannot pop\n");
        return -1; // Return an error value
    }
    int poppedItem = stack->items[stack->top];
    stack->top--;
    return poppedItem;
}

void disp(struct Stack *stack)
{
    int i;
    for(i = stack->top; i >=0; i--){
        if(stack->items[i] >=10){
            printf("%c", stack->items[i] + 55);
        }
        else printf("%d", stack->items[i]);
    }

}


void main()
{
    struct Stack decimal;
    initialize(&decimal);
    int a, b;
    printf("Enter Number to convert : ");
    scanf("%d", &a);
    printf("Base : ");
    scanf("%d", &b);
    while(a != 0) {
        push(&decimal, a%b);
        a = a/b;
    }
    printf("The number is : ");
    disp(&decimal);
}
