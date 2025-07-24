#include <Stdio.h>
#include <Stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
    char phone[15];
    char time[30];
} Call;
typedef struct Node
{
    Call call;
    struct Node *next;
} Node;

typedef struct
{
    Node *top;
} Stack;

typedef struct
{
    Node *front;
    Node *rear;
} Queue;

Stack *initStack()
{
    Stack *st = (Stack *)malloc(sizeof(Stack));
    st->top = NULL;
    return st;
}

int emptyStack(Stack *st)
{
    return st->top == NULL;
}

void pushStack(Stack *st, Call call)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->call.phone, call.phone);
    strcpy(newNode->call.time, call.time);
    newNode->next = st->top;
    st->top = newNode;
}

void popStack(Stack *st)
{
    if (emptyStack(st))
    {
        printf("Stack underflow!\n");
        return;
    }
    Node *tmp = st->top;
    st->top = tmp->next;
    free(tmp);
}

Call top(Stack *st)
{
    Call emptyCall = {"", ""};
    if (emptyStack(st))
    {
        printf("Stack is empty!\n");
        return emptyCall;
    }
    return st->top->call;
}

Queue *initQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int emptyQueue(Queue *q)
{
    return q->front == NULL;
}

void pushQueue(Queue *q, Call call)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->next = NULL;
    strcpy(newNode->call.phone, call.phone);
    strcpy(newNode->call.time, call.time);
    if (q->rear == NULL)
        q->front = q->rear = newNode;
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

void display(Queue *q)
{
    Node *cur = q->front;
    int i = 1;
    printf("History call: \n");
    while (cur != NULL)
    {
        printf("%2d. Phone: %s\n", i, cur->call.phone);
        printf("   Time: %s\n", cur->call.time);
        cur = cur->next;
        i++;
    }
    printf("\n");
}

char *getCurrentTime()
{
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    static char buffer[30];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info);
    return buffer;
}

int main()
{
    Stack *backStack = initStack();
    Stack *forwardStack = initStack();
    Queue *historyQueue = initQueue();

    int choice;
    do
    {
        printf("1. Call\n");
        printf("2. Back\n");
        printf("3. Redial\n");
        printf("4. History\n");
        printf("0. Exit\n");
        printf("Please enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            Call call;
            printf("Enter phone number: ");
            scanf("%s", call.phone);
            printf("Enter time: ");
            scanf("%s", call.time);
            pushStack(backStack, call);
            pushQueue(historyQueue, call);
            forwardStack->top = NULL; // Clear forward stack
            break;
        }
        case 2:
        {
            if (!emptyStack(backStack))
            {
                Call lastCall = top(backStack);
                pushStack(forwardStack, lastCall);
                popStack(backStack);
                printf("Back to previous call: %s at %s\n", lastCall.phone, lastCall.time);
            }
            else
            {
                printf("No previous calls.\n");
            }
            break;
        }
        case 3:
        {
            if (!emptyStack(forwardStack))
            {
                Call redialCall = top(forwardStack);
                pushStack(backStack, redialCall);
                popStack(forwardStack);
                printf("Redialing: %s at %s\n", redialCall.phone, redialCall.time);
            }
            else
            {
                printf("No calls to redial.\n");
            }
            break;
        }
        case 4:
        {
            display(historyQueue);
            break;
        }
        case 0:
        {
            printf("Exiting...\n");
            break;
        }
        default:
        {
            printf("Invalid choice. Please try again.\n");
        }
        }
    } while (choice != 0);
}