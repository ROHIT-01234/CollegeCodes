#include <stdio.h>
#include <stdio.h>
#include <string.h>
#define MAX 10          //global declaration
int stack[MAX];         //global declaration
char prefix[MAX];           //global declaration
int top = -1;           //global declaration

void reverse(char arr[])   //function for reversing prefix expression
{
    int i, j = 0;
    for (i = 0; i < strlen(arr); i++)
    {
        top++;
        stack[top] = arr[i];
    }
    while (top != -1)
    {
        arr[j] = stack[top];
        j++;
        top--;
    }
    arr[j] = '\0';
}

void push(char c)  // function to push into stack
{
    top++;
    stack[top] = c;
}
char pop()  // function for pop
{
    char val = stack[top];
    top--;
    return val;
}
int isempty()  // function to check underflow condition
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int prefix_eval()  // function for prefix evaluation
{
    int i, a, b;
    for (i = 0; i < strlen(prefix); i++)
    {
        if (prefix[i] >= '0' && prefix[i] <= '9')
            push(prefix[i] - '0'); // converting character to number and pushing to stack
        else
        {
            a = pop();  // popping 2nd element and storing in variable
            b = pop();  // popping 1st element and storing in variable
            switch (prefix[i])
            {
            case '+':
                push(a + b);        //performing operation according to encountered operator
                break;
            case '-':
                push(a - b);        //performing operation according to encountered operator
                break;
            case '*':
                push(a * b);        //performing operation according to encountered operator
                break;
            case '/':
                push(a / b);        //performing operation according to encountered operator
                break;
            }
        }
    }
    return pop(); // return the result of prefix
}

void main()
{
    printf("Enter the infix Expression:");
    gets(prefix);
    reverse(prefix); //to reverse the prefix expression
    int result = prefix_eval();
    printf("\nThe evaluated prefix expression is: %d", result);
}