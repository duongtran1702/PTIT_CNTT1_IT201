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
Node *insertNode(Node *head, int pos, int x)
{
    int length = lengthList(head);
    if (pos > length + 1 || pos < 1)
    {
        printf("Invalid position");
        return head;
    }
    if (pos == 1)
    {
        Node *newNode = createNode(x);
        newNode->next = head;
        return newNode;
    }
    Node *current = head;
    for (int i = 1; i < pos - 1; i++)
    {
        current = current->next;
    }

    Node *newNode = createNode(x);
    newNode->next = current->next;
    current->next = newNode;
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
    Node *head = createNode(1);
    Node *tail = head;
    for (int i = 2; i <= 5; i++)
    {
        tail->next = createNode(i);
        tail = tail->next;
    }
    int pos, x;
    scanf("%d", &pos);
    scanf("%d", &x);
    displayList(head);
    printf("\n");
    head = insertNode(head, pos, x);
    displayList(head);
}