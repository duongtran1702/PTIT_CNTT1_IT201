#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *newNode(int val)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Queue
typedef struct QueueNode
{
    TreeNode *data;
    struct QueueNode *next;
} QueueNode;

typedef struct
{
    QueueNode *front;
    QueueNode *rear;
} Queue;

Queue *newQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

int empty(Queue *q)
{
    return q->front == NULL;
}

void push(Queue *q, TreeNode *node)
{
    QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
    temp->data = node;
    temp->next = NULL;

    if (q->rear == NULL)
    {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

TreeNode *pop(Queue *q)
{
    if (empty(q))
        return NULL;

    QueueNode *temp = q->front;
    TreeNode *node = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return node;
}

// ✅ Hàm chèn phần tử theo chiều BFS (level-order)
void insert(TreeNode *root, int val)
{
    if (root == NULL)
        return;

    Queue *q = newQueue();
    push(q, root);

    while (!empty(q))
    {
        TreeNode *current = pop(q);

        if (current->left == NULL)
        {
            current->left = newNode(val);
            return;
        }
        else
        {
            push(q, current->left);
        }

        if (current->right == NULL)
        {
            current->right = newNode(val);
            return;
        }
        else
        {
            push(q, current->right);
        }
    }
}

void printConnections(TreeNode *root)
{
    if (root == NULL)
        return;

    printf("Node %d : ", root->data);

    if (root->left != NULL)
        printf("\n->Left: %d", root->left->data);
    else
        printf("\n->Left: NULL");

    if (root->right != NULL)
        printf("\n->Right: %d", root->right->data);
    else
        printf("\n->Right: NULL");

    printf("\n");

    printConnections(root->left);
    printConnections(root->right);
}

int main()
{
    TreeNode *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Pre-order before insert:\n");
    printConnections(root);
    printf("\n");

    insert(root, 6);
    insert(root, 7);
    insert(root, 8);

    printf("Pre-order after insert:\n");
    printConnections(root);
    printf("\n");

    return 0;
}
