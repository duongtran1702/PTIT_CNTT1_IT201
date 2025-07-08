#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char *data;
    int top;
    int capacity;
} Stack;

Stack *init(int capacity)
{
    Stack *st = (Stack *)malloc(sizeof(Stack));
    st->top = -1;
    st->capacity = capacity;
    st->data = (char *)malloc(sizeof(char) * capacity);
    return st;
}

int isEmpty(Stack *st)
{
    return st->top == -1;
}

void push(Stack *st, int value)
{
    if (st->top + 1 >= st->capacity)
    {
        printf("Stack overflow!\n");
        return;
    }
    st->data[++st->top] = value;
}

char top(Stack *st)
{
    if (isEmpty(st))
    {
        printf("stack underflow!\n");
        return '\0';
    }
    return st->data[st->top];
}

void pop(Stack *st)
{
    if (st->top < 0)
    {
        printf("stack underflow!\n");
        return;
    }
    st->top -= 1;
}

void display(Stack *st)
{
    if (isEmpty(st))
    {
        printf("Stack is empty!");
        return;
    }
    for (int i = st->top; i >= 0; i--)
    {
        printf("%c", st->data[i]);
    }
    printf("\n");
}

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

void infixToPostfix(char *infix, char *postfix)
{
    Stack *st = init(100);
    int k = 0;
    for (int i = 0; infix[i]; i++)
    {
        char ch = infix[i];
        if (ch >= '0' && ch <= '9')
        {
            postfix[k++] = ch;
        }
        else if (ch == '(')
        {
            push(st, ch);
        }
        else if (ch == ')')
        {
            while (!isEmpty(st) && top(st) != '(')
            {
                postfix[k++] = top(st);
                pop(st);
            }
            if (!isEmpty(st) && top(st) == '(')
                pop(st);
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            while (!isEmpty(st) && precedence(top(st)) >= precedence(ch))
            {
                postfix[k++] = top(st);
                pop(st);
            }
            push(st, ch);
        }
    }

    while (!isEmpty(st))
    {
        postfix[k++] = top(st);
        pop(st);
    }

    postfix[k] = '\0';
    free(st->data);
    free(st);
}
int main()
{
    char str[30];
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    char postfix[100];
    infixToPostfix(str, postfix);
    printf("%s\n", postfix);
    return 0;
}
