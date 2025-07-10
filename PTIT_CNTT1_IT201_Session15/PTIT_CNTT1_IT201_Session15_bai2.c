#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int *data;
    int front;
    int rear;
    int cap;
} Queue;

// Khởi tạo queue
Queue *init(int cap)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = 0;
    q->rear = -1;
    q->cap = cap;
    q->data = malloc(cap * sizeof(int));
    return q;
}

// empty(): kiểm tra rỗng
int empty(Queue *q)
{
    return q->front > q->rear;
}

// push(): thêm phần tử vào cuối
void push(Queue *q, int val)
{
    if (q->rear == q->cap - 1)
    {
        printf("Queue is full!\n");
        return;
    }
    ++q->rear;
    q->data[q->rear] = val;
}

// pop(): loại bỏ phần tử đầu
void pop(Queue *q)
{
    if (empty(q))
    {
        printf("Queue is empty!\n");
        return;
    }
    q->front++;
}

// front(): trả về phần tử đầu
int front(Queue *q)
{
    if (empty(q))
    {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->data[q->front];
}

// back(): trả về phần tử cuối
int back(Queue *q)
{
    if (q->front > q->rear)
    {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->data[q->rear];
}

// size(): trả về số phần tử hiện tại
int size(Queue *q)
{
    if (empty(q))
        return 0;
    return q->rear - q->front + 1;
}

int main()
{
    Queue *q = init(5);
    for (int i = 0; i < 6; i++)
        push(q, i);
    printf("queue = {\n  array = [");
    for (int i = 0; i < 5; i++)
    {
        printf("%d", q->data[i]);
        if (i != 4)
            printf(", ");
    }
    printf("],\n  front = %d,\n  rear = %d,\n  cap = %d \n},", q->front, q->rear, q->cap);
    return 0;
}