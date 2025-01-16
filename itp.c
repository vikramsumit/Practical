#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 534654

char stack[MAX];
int top = -1;

void push(char ch)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = ch;
}

char pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack[top--];
}

char peek()
{
    if (top == -1)
    {
        return '\0';
    }
    return stack[top];
}

int isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int precedence(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    if (ch == '*' || ch == '/')
    {
        return 2;
    }
    return 0;
}

void infixToPostfix(char infix[], char postfix[])
{
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++)
    {
        char ch = infix[i];

        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (top != -1 && peek() != '(')
            {
                postfix[j++] = pop();
            }
            pop();
        }
        else if (isOperator(ch))
        {
            while (top != -1 && precedence(peek()) >= precedence(ch))
            {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while (top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int main()
{
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
