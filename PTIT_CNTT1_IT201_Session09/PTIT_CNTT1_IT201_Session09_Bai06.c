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
Node *deleteNodehead(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *tmp = head;
    head = head->next;
    free(tmp);
    return head;
}
void displayList(Node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL");
}
int main()
{
    Node *head = createNode(0);
    Node *tail = head;
    for (int i = 1; i <= 5; i++)
    {
        tail->next = createNode(i);
        tail = tail->next;
    }
    displayList(head);
    printf("\n");
    head = deleteNodehead(head);
    displayList(head);
}