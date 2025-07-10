#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char fullname[30];
} Customers;

typedef struct Queue
{
    Customers **list; // Mảng khách,mỗi khách là Customer*
    int front;
    int rear;
    int cap;
} Queue;

// Khởi tạo queue
Queue *init()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = 0;
    q->rear = -1;
    q->cap = 50;
    q->list = (Customers **)malloc(sizeof(Customers *) * q->cap);
    return q;
}

// empty(): kiểm tra rỗng
int empty(Queue *q)
{
    return q->front > q->rear;
}

// push(): thêm phần tử vào cuối
Customers *enterName()
{
    Customers *cus = malloc(sizeof(Customers));
    printf("Enter the fullname customer: ");
    fgets(cus->fullname, 30, stdin);
    cus->fullname[strcspn(cus->fullname, "\n")] = '\0';
    return cus;
}
void push(Queue *q, Customers *cus)
{
    if (q->rear == q->cap - 1)
    {
        printf("Queue is full!\n");
        return;
    }
    q->list[++q->rear] = cus;
}

// pop(): loại bỏ phần tử đầu
void pop(Queue *q)
{
    if (empty(q))
    {
        printf("Queue is empty!\n");
        return;
    }
    free(q->list[q->front]);
    q->front++;
}

// front(): trả về phần tử đầu
char *front(Queue *q)
{
    if (empty(q))
    {
        printf("Queue is empty!\n");
        return NULL;
    }
    return q->list[q->front]->fullname;
}

// back(): trả về phần tử cuối
char *back(Queue *q)
{
    if (q->front > q->rear)
    {
        printf("Queue is empty!\n");
        return NULL;
    }
    return q->list[q->rear]->fullname;
}

// size(): trả về số phần tử hiện tại
int size(Queue *q)
{
    if (empty(q))
        return 0;
    return q->rear - q->front + 1;
}

void display(Queue *q)
{
    if (empty(q))
    {
        printf("Queue is empty!\n");
        return;
    }
    int idx = 1;
    printf("List of waiting customers:\n");
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d. %s\n", idx, q->list[i]->fullname);
        idx++;
    }
    printf("\n");
}

int menu()
{
    printf("1. Add a new customer\n");
    printf("2. Serve\n");
    printf("3. Display the list of waiting customers\n");
    printf("4. Exit\n");
    int option;
    do
    {
        printf("Please enter option: ");
        scanf("%d", &option);
    } while (option < 1 || option > 4);
    return option;
}

int main()
{
    Queue *q = init();
    int tmp = -1;
    while (tmp != 4)
    {
        tmp = menu();
        if (tmp == 1)
        {
            int c;
            while ((c = getchar()) != '\n')
                ;
            push(q, enterName());
        }
        else if (tmp == 2)
        {
            if (!empty(q))
            {
                printf("Serving: %s\n", front(q));
                pop(q);
            }
            else
            {
                printf("No customer to serve!\n");
            }
        }
        else if (tmp == 3)
        {
            display(q);
        }
    }
    for (int i = q->front; i <= q->rear; i++)
        free(q->list[i]);
    free(q->list);
    free(q);
    return 0;
}