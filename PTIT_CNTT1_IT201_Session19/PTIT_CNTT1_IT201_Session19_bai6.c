#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *newNode(int val) {
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Queue
typedef struct QueueNode {
    TreeNode *data;
    struct QueueNode *next;
} QueueNode;

typedef struct {
    QueueNode *front;
    QueueNode *rear;
} Queue;

Queue *newQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

int empty(Queue *q) {
    return q->front == NULL;
}

void push(Queue *q, TreeNode *node) {
    QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
    temp->data = node;
    temp->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

TreeNode *pop(Queue *q) {
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
//BFS
TreeNode *bfsSearch(TreeNode *root, int key) {
    if (root == NULL)
        return NULL;

    Queue *q = newQueue();
    push(q, root);

    while (!empty(q)) {
        TreeNode *current = pop(q);
        if (current->data == key)
            return current;

        if (current->left != NULL)
            push(q, current->left);
        if (current->right != NULL)
            push(q, current->right);
    }

    return NULL;
}

int main() {
    TreeNode *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    int key = 8;
    TreeNode *result = bfsSearch(root, key);

    if (result != NULL)
        printf("True");
    else
        printf("False");

    return 0;
}
