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
// void searchNodeAtMid(Node *head, int *pos, int *value)
// {
//     if (head == NULL)
//     {
//         *pos = 0;
//         *value = -1;
//         return;
//     }
//     int count = 0;
//     Node *tmp = head;
//     while (tmp != NULL)
//     {
//         count++;
//         tmp = tmp->next;
//     }
//     *pos = count / 2 + 1;
//     for (int i = 1; i < *pos; i++)
//     {
//         head = head->next;
//     }
//     *value = head->data;
// } ver1
void searchNodeAtMid(Node *head, int *pos, int *value)
{
    if (head == NULL)
    {
        *pos = 0;
        *value = -1;
        return;
    }
    Node *slow = head, *fast = head;
    int idx = 1;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        ++idx;
    }
    *pos = idx;
    *value = slow->data;
}
int main()
{
    Node *head = createNode(5);
    Node *tail = head;
    for (int i = 4; i >= 1; i--)
    {
        tail->next = createNode(i);
        tail = tail->next;
    }
    displayList(head);
    int pos, value;
    searchNodeAtMid(head, &pos, &value);
    printf("Node %d: %d", pos, value);
}