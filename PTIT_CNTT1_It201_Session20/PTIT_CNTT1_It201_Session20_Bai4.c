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

int countLeaf(TreeNode *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeaf(root->left) + countLeaf(root->right);
}

int main()
{
    TreeNode *root = create(1);
    root->left = create(2);
    root->right = create(3);
    root->left->left = create(4);
    root->left->right = create(5);

    int count = countLeaf(root);
    printf("The number of leaves in the tree: %d", count);
}