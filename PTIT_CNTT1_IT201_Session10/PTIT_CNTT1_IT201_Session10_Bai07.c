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

void displayList(Node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
void swap(Node *a, Node *b)
{
    int tmp = a->data;
    a->data = b->data;
    b->data = tmp;
}
void arrangeList(Node *head)
{
    for (Node *i = head; i != NULL; i = i->next)
    {
        Node *min = i;
        for (Node *j = i->next; j != NULL; j = j->next)
        {
            if (j->data < min->data)
            {
                min = j;
            }
        }
        if (min != i)
            swap(i, min);
    }
}

int main()
{
    int a[] = {2, 5, 4, 1, 3};
    Node *head = createNode(a[0]);
    Node *tail = head;
    for (int i = 1; i <= 4; i++)
    {
        tail->next = createNode(a[i]);
        tail = tail->next;
    }
    displayList(head);
    arrangeList(head);
    displayList(head);
}