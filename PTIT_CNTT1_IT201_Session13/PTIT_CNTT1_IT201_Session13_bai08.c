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

int eval(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b == 0)
        {
            return 0;
        }
        return a / b;
    default:
        return 0;
    }
}

void calPostfix(char *s)
{
    Stack *st = init(30);
    size_t len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            push(st, s[i] - '0');
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            int tmp1 = top(st);
            pop(st);
            int tmp2 = top(st);
            pop(st);

            push(st, eval(tmp2, tmp1, s[i]));
        }
    }
    printf("%d", top(st));
}
int main()
{
    char str[30];
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    calPostfix(str);
    return 0;
}
