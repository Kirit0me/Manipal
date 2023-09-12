#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define SIZE 50

struct MultStack {
    int top[SIZE];
    int items[SIZE][MAX];
};

void initialize(struct MultStack *stack)
{
    int i;
    for(i = 0; i < SIZE; i++){
        stack->top[i] = -1;
    }
}

int isEmpty(struct MultStack *stack, int stack_no)
{
    return stack->top[stack_no] == -1;
}

int isFull(struct MultStack *stack, int stack_no)
{
    return stack->top[stack_no] == MAX - 1;
}

void push(struct MultStack *stack, int stack_no, int a)
{
    if (isFull(stack, stack_no)) {
        printf("Stack overflow, cannot push %d\n", a);
        return;
    }

    stack->top[stack_no]++;
    stack->items[stack_no][stack->top[stack_no]] = a;

}

int pop(struct MultStack *stack, int stack_no)
{
    if (isEmpty(stack, stack_no)) {
        printf("Stack underflow, cannot pop\n");
        return -1;
    }
    int poppedItem = stack->items[stack_no][stack->top[stack_no]];
    stack->top[stack_no]--;
    return poppedItem;
}

void main()
{
    struct Multstack iamtired;
    initialize(&iamtired);
    push(&iamtired, 1, 2);
    push(&iamtired, 2, 1);
    push(&iamtired, 3, 3);
    push(&iamtired, 1, 4);
    int a = pop(&iamtired, 2);
    int b = pop(&iamtired, 1);
    printf("%d\t%d", a, b);
}
