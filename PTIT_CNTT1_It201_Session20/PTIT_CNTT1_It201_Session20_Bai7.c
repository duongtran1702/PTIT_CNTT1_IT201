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
void deleteDeepest(TreeNode *root, TreeNode *delNode)
{
    if (!root)
        return;
    if (root->left)
    {
        if (root->left == delNode)
        {
            free(root->left);
            root->left = NULL;
            return;
        }
        else
            deleteDeepest(root->left, delNode);
    }
    if (root->right)
    {
        if (root->right == delNode)
        {
            free(root->right);
            root->right = NULL;
            return;
        }
        else
            deleteDeepest(root->right, delNode);
    }
}

void deleteNode(TreeNode *root, int key)
{
    if (!root)
        return;

    TreeNode *target = NULL, *last = NULL;
    TreeNode **q = malloc(100 * sizeof(TreeNode *));
    int front = 0, rear = 0;
    q[rear++] = root;

    while (front < rear)
    {
        TreeNode *curr = q[front++];
        last = curr;
        if (curr->data == key)
            target = curr;
        if (curr->left)
            q[rear++] = curr->left;
        if (curr->right)
            q[rear++] = curr->right;
    }

    free(q);

    if (!target)
    {
        printf("Node %d not found.\n", key);
        return;
    }

    target->data = last->data;
    deleteDeepest(root, last);
}

void levelOrder(TreeNode *root)
{
    if (root == NULL)
        return;

    TreeNode **queue = malloc(100 * sizeof(TreeNode *));
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear)
    {
        TreeNode *curr = queue[front++];
        printf("%d ", curr->data);

        if (curr->left)
            queue[rear++] = curr->left;
        if (curr->right)
            queue[rear++] = curr->right;
    }

    free(queue);
}

int main()
{
    TreeNode *root = create(1);
    root->left = create(2);
    root->right = create(3);
    root->left->left = create(4);
    root->left->right = create(5);

    levelOrder(root);
    deleteNode(root, 3);
    printf("\n");
    levelOrder(root);
}