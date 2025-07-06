#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *pre;
} Node;

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->pre = NULL;
    newNode->next = NULL;
    return newNode;
}

void displayList(Node *head)
{
    printf("NULL <- ");
    while (head != NULL)
    {
        printf("%d ", head->data);
        if (head->next != NULL)
            printf("<--> ");
        head = head->next;
    }
    printf("-> NULL\n");
}

Node *swapPairs(Node *head)
{
    // Nếu danh sách rỗng hoặc chỉ có 1 phần tử thì không cần đổi
    if (head == NULL || head->next == NULL)
        return head;

    Node *current = head;

    // Sau khi đổi chỗ node 1 và 2, node 2 sẽ thành head mới
    Node *newHead = head->next;

    while (current != NULL && current->next != NULL)
    {
        Node *first = current;             // node đầu trong cặp
        Node *second = current->next;      // node thứ hai trong cặp
        Node *prev = first->pre;           // node trước cặp hiện tại
        Node *next = second->next;         // node sau cặp hiện tại

        // 1. Nối node trước cặp với node thứ hai (second)
        if (prev != NULL)
            prev->next = second;
        second->pre = prev;

        // 2. Nối node thứ hai với node đầu (đổi chỗ)
        second->next = first;
        first->pre = second;

        // 3. Nối node đầu với node sau cặp
        first->next = next;
        if (next != NULL)
            next->pre = first;

        // 4. Di chuyển sang cặp tiếp theo
        current = next;
    }

    return newHead;
}

int main()
{
    Node *head = createNode(1);
    Node *current = head;
    for (int i = 2; i <= 5; i++)
    {
        Node *newNode = createNode(i);
        current->next = newNode;
        newNode->pre = current;
        current = newNode;
    }
    displayList(head);
    head = swapPairs(head);
    displayList(head);
}