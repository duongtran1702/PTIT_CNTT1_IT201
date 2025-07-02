#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void checkNum(Node *head, int x)
{

    while (head != NULL)
    {
        if (head->data == x)
        {
            printf("True");
            return;
        }
        head = head->next;
    }
    printf("False");
}

int main()
{
    Node *head = createNode(1);
    Node *tail = head;
    for (int i = 2; i <= 5; i++)
    {
        tail->next = createNode(i);
        tail = tail->next;
    }
    int x;
    scanf("%d", &x);
    checkNum(head, x);
    return 0;
}
