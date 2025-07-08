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
void isPalindrome(char *str)
{
    Stack *st = init(30);
    size_t len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        push(st, str[i]);
    }
    for (int i = 0; i < len; i++)
    {
        if (str[i] == top(st))
            pop(st);
        else
        {
            printf("False");
            return;
        }
    }
    printf("True");
}
int main()
{
    char str[30];
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    isPalindrome(str);
    return 0;
}
