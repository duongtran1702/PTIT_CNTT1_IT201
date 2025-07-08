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
        printf("%d ", st->data[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int *a = malloc(sizeof(int) * n);
    printf("Enter array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    Stack *st = init(n);
    for (int i = 0; i < n; i++)
    {
        push(st, *(a + i));
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = top(st);
        pop(st);
    }
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    free(a);
    free(st->data);
    free(st);
}