#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char fullname[30];
    int age;
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
Customers *enterInformation()
{
    Customers *cus = malloc(sizeof(Customers));
    printf("Enter the fullname customer: ");
    fgets(cus->fullname, 30, stdin);
    cus->fullname[strcspn(cus->fullname, "\n")] = '\0';
    printf("Enter age: ");
    scanf("%d", &cus->age);
    return cus;
}
void push(Queue *q_old, Queue *q_normal, Customers *cus)
{
    if (q_old->rear == q_old->cap - 1)
    {
        printf("Queue normal customers is full!\n");
        return;
    }
    if (q_normal->rear == q_normal->cap - 1)
    {
        printf("Queue old customers is full!\n");
        return;
    }
    if (cus->age >= 60)
        q_old->list[++q_old->rear] = cus;
    else
        q_normal->list[++q_normal->rear] = cus;
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
int front(Queue *q_old, Queue *q_normal)
{
    if (!empty(q_old))
    {
        return 1;
    }
    if (!empty(q_normal))
    {
        return 2;
    }
    return 0;
}

void display(Queue *q, char *type)
{
    if (empty(q))
    {
        printf("Queue is empty!\n");
        return;
    }
    int idx = 1;
    printf("List of waiting %s customers:\n", type);
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
    Queue *q_old = init();
    Queue *q_normal = init();
    int tmp = -1;
    while (tmp != 4)
    {
        tmp = menu();
        if (tmp == 1)
        {
            int c;
            while ((c = getchar()) != '\n')
                ;
            push(q_old, q_normal, enterInformation());
        }
        else if (tmp == 2)
        {
            int tmp1 = front(q_old, q_normal);
            if (tmp1 == 1)
            {
                printf("Serving: %s\n", q_old->list[q_old->front]->fullname);
                pop(q_old);
            }
            else if (tmp1 == 2)
            {
                printf("Serving: %s\n", q_normal->list[q_normal->front]->fullname);
                pop(q_normal);
            }
            else
            {
                printf("No customer to serve!\n");
            }
        }
        else if (tmp == 3)
        {
            display(q_old, "old");
            display(q_normal, "normal");
        }
    }
    
    for (int i = q_old->front; i <= q_old->rear; i++)
    {
        free(q_old->list[i]);
    }
    free(q_old->list);
    free(q_old);

    // Free all customers in q_normal
    for (int i = q_normal->front; i <= q_normal->rear; i++)
    {
        free(q_normal->list[i]);
    }
    free(q_normal->list);
    free(q_normal);
    return 0;
}