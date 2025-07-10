#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    Node *top;
} Stack;

Stack *init()
{
    Stack *st = (Stack *)malloc(sizeof(Stack));
    st->top = NULL;
    return st;
}

int empty(Stack *st)
{
    return st->top == NULL;
}

void push(Stack *st, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = st->top;
    st->top = newNode;
}
void pop(Stack *st)
{
    if (empty(st))
    {
        printf("Stack underflow!\n");
        return;
    }
    Node *tmp = st->top;
    st->top = tmp->next;
    free(tmp);
}

int top(Stack *st)
{
    if (empty(st))
    {
        printf("Stack is empty!\n");
        return -1;
    }
    return st->top->data;
}
int size(Stack *st)
{
    int i = 0;
    Node *tmp = st->top;
    while (tmp != NULL)
    {
        i++;
        tmp = tmp->next;
    }
    return i;
}
void display(Stack *st)
{
    if (empty(st))
    {
        printf("Stack underflow!\n");
        return;
    }
    int length = size(st);
    for (int i = 0; i < length; i++)
    {
        int tmp = top(st);
        pop(st);
        printf("%d ", tmp);
    }
}

int main()
{
    Stack *st = init();
    for (int i = 0; i < 5; i++)
    {
        push(st, i);
    }
    display(st);
    return 0;
}