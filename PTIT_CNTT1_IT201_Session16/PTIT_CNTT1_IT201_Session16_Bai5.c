#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    Node *front;
    Node *rear;
} Queue;

Queue *init()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

int empty(Queue *q)
{
    return q->front == NULL;
}

void push(Queue *q, int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;

    if (q->rear == NULL)
    {
        q->front = q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int front(Queue *q)
{
    if (empty(q))
    {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->front->data;
}

void pop(Queue *q)
{
    if (empty(q))
    {
        printf("Queue is empty! Nothing to pop!");
        return;
    }
    Node *tmp = q->front;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;
}

void display(Queue *q)
{
    if (empty(q))
    {
        printf("Queue is empty! Nothing to pop!");
        return;
    }
    printf("queue = {\nfront -> ");
    Node *tmp1 = q->front;
    Node *tmp2 = q->rear;
    while (tmp1 != NULL)
    {
        printf("%d -> ", tmp1->data);
        tmp1 = tmp1->next;
    }
    printf("NULL\n");
    printf("rear -> ");
    while (tmp2 != NULL)
    {
        printf("%d -> ", tmp2->data);
        tmp2 = tmp2->next;
    }
    printf("NULL\n}\n");
}
int main()
{
    Queue *q = init();
    for (int i = 1; i < 6; i++)
        push(q, i);
    display(q);
    pop(q);
    display(q);
    return 0;
}