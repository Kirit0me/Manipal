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
    struct Stack stack;
    initialize(&stack);
    int front = 0;
    int i, choice;
    char s[MAX], b;
    while (1)
    {
        printf("1. Check palindrome \n2. Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the String\n");
            scanf("%s", s);
            for (i = 0;s[i] != '\0';i++)
            {
                b = s[i];
                push(&stack, b);
            }
            for (i = 0;i < (strlen(s) / 2);i++)
            {
                if (stack.items[stack.top] == stack.items[front])
                {
                    pop(&stack);
                    front++;
                }
                else
                {
                    printf("%s is not a palindrome\n", s);
                    break;
                }
            }
            if ((strlen(s) / 2)  ==  front)
                printf("%s is palindrome\n",  s);
            front  =  0;
            //stack.top  =  -1;
            initialize(&stack);
            break;
        case 2:
            exit(0);
        default:
            printf("Enter correct choice\n");
        }
    }
}


