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

int findMax(TreeNode *root)
{
    if (root == NULL)
        return -9999;
    int maxleft = findMax(root->left);
    int maxright = findMax(root->right);
    int tmp = (maxleft > maxright ? maxleft : maxright);
    return (root->data > tmp ? root->data : tmp);
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
    
    int max = findMax(root);
    printf("Node max in the tree: %d", max);
}