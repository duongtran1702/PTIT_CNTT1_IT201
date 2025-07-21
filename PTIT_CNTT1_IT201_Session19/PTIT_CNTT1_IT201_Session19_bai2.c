#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *right;
    struct TreeNode *left;
} TreeNode;

TreeNode *creatNode(int val)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode *buildTree()
{
    int val;
    printf("Enter node value (< 0 for NULL): ");
    scanf("%d", &val);
    if (val < 0)
        return NULL;
    TreeNode *node = creatNode(val);
    printf("->Enter left child of %d:\n", val);
    node->left = buildTree();
    printf("-> Enter right child of %d:\n", val);
    node->right = buildTree();
    return node;
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

int main()
{
    TreeNode *root = buildTree();
    preOrder(root);
}
