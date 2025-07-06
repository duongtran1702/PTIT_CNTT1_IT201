#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *pre;
} Node;

Node *creatNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->pre = NULL;
    newNode->next = NULL;
}

int lengthList(Node *head)
{
    int i = 0;
    while (head != NULL)
    {
        i++;
        head = head->next;
    }
    return i;
}

int main()
{
    Node *head = creatNode(1);
    Node *current = head;
    for (int i = 2; i <= 10; i++)
    {
        Node *newNode = creatNode(1);
        current->next = newNode;
        newNode->pre = current;
        current = newNode;
    }
    printf("%d", lengthList(head));
}