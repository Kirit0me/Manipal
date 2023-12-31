#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20

char stack[MAX][MAX];
int top=-1;

void push(char *item)
{
    if(isFull()) printf("Overflow detected!\n");
    else{
        top++;
        strcpy(stack[top],item);
    }
}

int isFull()
{
    return top==MAX-1;
}

int isEmpty()
{
    return top == -1;
}

int isOperator(char sym)
{
    return (sym=='+'||sym=='-'||sym=='*'||sym=='/'||sym=='^');

}

char *pop()
{
    if(isEmpty()) exit(0);
    return stack[top--];
}

int isOperand(char sym)
{
    return (sym>='A'&&sym<='Z'||sym>='a'&&sym<='z');
}

int main()
{
    char postfix[MAX],temp[2],op[2]={'(','\0'},cl[2]={')','\0'};
    int i=0,j=0;
    printf("Enter an postfix expression: ");
    gets(postfix);
    while(postfix[i]!='\0'){
        char exp[MAX]={'\0'},op1[MAX]={'\0'},op2[MAX]={'\0'};
        temp[0]=postfix[i];
        temp[1]='\0';
        if(isOperand(temp[0])) push(temp);
        else if(isOperator(temp[0])){
            strcpy(op2,pop()); strcpy(op1,pop());
            strcat(exp,op); strcat(exp,op1);
            strcat(exp,temp); strcat(exp,op2);
            strcat(exp,cl); push(exp);
        }
        else{ printf("Invalid Arithmetic expression!\n"); exit(0); }
        i++;
    }
    printf("The infix expression is: ");
    puts(stack[0]);
}
