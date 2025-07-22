#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *right;
    struct TreeNode *left;
} TreeNode;

TreeNode *create(int val)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

typedef struct QueueNode
{
    TreeNode *treeNode;
    struct QueueNode *next;
} QueueNode;

typedef struct
{
    QueueNode *front;
    QueueNode *back;
} Queue;

Queue *createQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->back = q->front = NULL;
    return q;
}

int empty(Queue *q)
{
    return q->front == NULL;
}

void push(Queue *q, TreeNode *node)
{
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    newNode->treeNode = node;
    newNode->next = NULL;

    if (q->back == NULL)
    {
        q->back = q->front = newNode;
        return;
    }
    q->back->next = newNode;
    q->back = newNode;
}

TreeNode *pop(Queue *q)
{
    if (q->front == NULL)
        return NULL;
    QueueNode *tmp = q->front;
    q->front = tmp->next;
    TreeNode *node = tmp->treeNode;
    if (q->front == NULL)
        q->back = NULL;
    free(tmp);
    return node;
}

void levelOrder(TreeNode *root)
{
    if (root == NULL)
        return;
    Queue *q = createQueue();
    push(q, root);
    while (!empty(q))
    {
        TreeNode *cur = pop(q);
        printf("%d ", cur->data);
        if (cur->left)
            push(q, cur->left);
        if (cur->right)
            push(q, cur->right);
    }
}

void preOrder(TreeNode *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(TreeNode *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void postOrder(TreeNode *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

int main()
{
    TreeNode *root = create(1);
    root->left = create(2);
    root->right = create(3);
    root->left->left = create(4);
    root->left->right = create(5);
    root->right->left = create(6);
    root->right->right = create(7);

    levelOrder(root);
    printf("\n");

    preOrder(root);
    printf("\n");

    inOrder(root);
    printf("\n");

    postOrder(root);
}