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

void lengthListNode(Node *head)
{
    int i = 0;
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        i++;
        head = head->next;
    }
    printf("NULL\n");
    printf("Danh sach lien ket co: %d phan tu", i);
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
    lengthListNode(head);
}
