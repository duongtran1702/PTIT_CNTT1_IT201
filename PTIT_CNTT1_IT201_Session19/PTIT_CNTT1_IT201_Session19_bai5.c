#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *right;
    struct TreeNode *left;
} TreeNode;

TreeNode *createNode(int val)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preOrder(TreeNode *root)
{
    // Node → Left → Right
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

TreeNode *searchTree(TreeNode *root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->data == key)
        return root;

    TreeNode *result = searchTree(root->left, key);
    if (result != NULL)
        return result;

    return searchTree(root->right, key);
}

int main()
{
    TreeNode *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    TreeNode *result = searchTree(root, 5);

    if (result != NULL)
        printf("True");
    else
        printf("False");
}
