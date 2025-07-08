#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *data;
    int top;
    int capacity;
} Stack;

Stack *init(int capacity)
{
    Stack *st = (Stack *)malloc(sizeof(Stack));
    st->top = -1;
    st->capacity = capacity;
    st->data = (int *)malloc(sizeof(int) * capacity);
    return st;
}

int isEmpty(Stack *st)
{
    return st->top == -1;
}

void push(Stack *st, int value)
{
    if (st->top + 1 > st->capacity)
    {
        printf("Stack overflow!\n");
        return;
    }
    st->data[++st->top] = value;
}

int top(Stack *st)
{
    if (isEmpty(st))
    {
        printf("stack underflow!\n");
        return -1;
    }
    return st->data[st->top];
}

int pop(Stack *st)
{
    if (st->top < 0)
    {
        printf("stack underflow!\n");
        return -1;
    }
    return st->data[st->top--];
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
        printf("%d ", st->data[i]);
    }
    printf("\n");
}
int main()
{
    Stack *st = init(5);
    for (int i = 0; i < 5; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        push(st, tmp);
    }
    display(st);
    printf("top: %d\ncap: %d", st->top, st->capacity);
    
}