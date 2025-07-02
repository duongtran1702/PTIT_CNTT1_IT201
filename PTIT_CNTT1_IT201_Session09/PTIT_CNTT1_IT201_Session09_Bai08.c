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
void displayList(Node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL");
}
Node *deleteNode(Node *head, int pos)
{
    int length = lengthList(head);
    if (pos < 1 || head == NULL || pos > length)
        return head;
    if (pos == 1)
    {
        Node *tmp = head;
        head = head->next;
        free(tmp);
        return head;
    }
    Node *current = head;
    for (int i = 1; i < pos - 1; i++)
    {
        current = current->next;
    }
    Node *tmp = current->next;
    current->next = current->next->next;
    free(tmp);
    return head;
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
    displayList(head);
    printf("\n");
    head = deleteNode(head, pos);
    displayList(head);
}