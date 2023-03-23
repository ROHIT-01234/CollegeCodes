#include <stdio.h>
#include <stdio.h>
#include <string.h>
#define MAX 10          //global declaration
int stack[MAX];     //global declaration
char postfix[MAX];      //global declaration
int top = -1;       //global declaration

void push(char c)  // function to push into stack
{
    top++;
    stack[top] = c;
}
char pop() // function for pop
{
    char val = stack[top];
    top--;
    return val;
}
int isempty() // function to check underflow condition
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int postfix_eval() // function for postfix evaluation
{
    int i, a, b;
    for (i = 0; i < strlen(postfix); i++) // sacning postfix expression
    {
        if (postfix[i] >= '0' && postfix[i] <= '9')
            push(postfix[i] - '0'); // converting character to number and pushing to stack
        else
        {
            b = pop();  // popping 2nd element and storing in variable
            a = pop();  // popping 1st element and storing in variable
            switch (postfix[i])
            {
            case '+':
                push(a + b);    //performing operation according to encountered operator
                break;
            case '-':
                push(a - b);    //performing operation according to encountered operator
                break;
            case '*':
                push(a * b);    //performing operation according to encountered operator
                break;
            case '/':
                push(a / b);    //performing operation according to encountered operator
                break;
            }
        }
    }
    return pop(); // return the result of postfix
}

void main()
{
    printf("Enter the infix Expression:");
    gets(postfix);
    int result = postfix_eval();
    printf("\nThe evaluated postfix expression is: %d", result);
}