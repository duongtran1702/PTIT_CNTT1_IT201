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
    printf("NULL <-");
    while (head != NULL)
    {
        printf(" %d ", head->data);
        if (head->next != NULL)
            printf("<-->");
        head = head->next;
    }
    printf("-> NULL\n");
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

Node *removeMinNode(Node **start)
{
    if (*start == NULL)
        return NULL;
    Node *minNode = *start;
    Node *curNode = *start;
    // Duyệt danh sách để tìm node có data nhỏ nhất
    while (curNode != NULL)
    {
        if (curNode->data < minNode->data)
        {
            minNode = curNode;
        }
        curNode = curNode->next;
    }

    // Gỡ minNode ra khỏi danh sách
    if (minNode->pre)
        minNode->pre->next = minNode->next;
    if (minNode->next)
        minNode->next->pre = minNode->pre;

    // Nếu minNode là node đầu tiên (start)
    if (*start == minNode)
        *start = minNode->next;

    minNode->next = minNode->pre = NULL;

    return minNode;
}

void insertBefore(Node **headRef, Node *current, Node *min)
{
    if (current == NULL)
        return;
    // Bước 1: Gán liên kết từ min tới current
    min->next = current;
    min->pre = current->pre;
    // Bước 2: Cập nhật liên kết của node đứng trước current (nếu có)
    if (current->pre != NULL)
        // Nếu current không phải là node đầu → node trước đó sẽ trỏ tới min
        current->pre->next = min;
    else
        // Nếu current là node đầu tiên → cần cập nhật head trỏ tới min
        *headRef = min;
    // Bước 3: Cập nhật pre của current để current trỏ ngược lại về min
    current->pre = min;
}

void selectionSortInPlace(Node **headRef, int length)
{
    if (*headRef == NULL || length <= 1)
        return;

    Node *current = *headRef;

    for (int i = 0; i < length - 1 && current != NULL; i++)
    {
        // printf("\nIteration %d - Current list:\n", i + 1);
        // displayList(*headRef);

        // Gỡ node nhỏ nhất từ đoạn bắt đầu tại current
        Node *minNode = removeMinNode(&current);

        // printf("After removing the minimum node (value = %d):\n", minNode->data);
        // displayList(*headRef);

        // Nếu current chính là node nhỏ nhất thì không cần chèn
        if (minNode != current)
        {
            // Gỡ current khỏi danh sách hiện tại
            if (current->pre)
                current->pre->next = current->next;
            if (current->next)
                current->next->pre = current->pre;

            // Nếu current là node đầu
            if (*headRef == current)
                *headRef = current->next;

            // printf("After removing current node (value = %d):\n", current->data);
            // displayList(*headRef);
            
            // Chèn minNode vào trước vị trí current
            insertBefore(headRef, current, minNode);

            // printf("Inserted node %d before node %d:\n", minNode->data, current->data);
            // displayList(*headRef);

            // Sau khi chèn, current vẫn nằm sau minNode, nên ta giữ current như cũ
            // Vì vậy không cần gán current = current->next;
        }
        else
        {
            current = current->next;
        }
    }
}

int main()
{
    int a[10] = {2, 8, 9, 5, 1, 3, 4, 0, 6, 7};
    Node *head = createNode(a[0]);
    Node *cur = head;

    for (int i = 1; i < 10; i++)
    {
        Node *newNode = createNode(a[i]);
        cur->next = newNode;
        newNode->pre = cur;
        cur = newNode;
    }
    int length = lengthList(head);
    printf("List node before sorting:\n");
    displayList(head);
    selectionSortInPlace(&head, length);
    printf("List node after sorting:\n");
    displayList(head);
}