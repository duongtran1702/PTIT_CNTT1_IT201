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

int findLevelHelper(TreeNode *root, int value, int level)
{
    if (root == NULL)
        return 0;

    // printf("Visiting node %d at level %d\n", root->data, level);

    if (root->data == value)
        return level;

    // Tìm ở cây con bên trái
    int left = findLevelHelper(root->left, value, level + 1);
    if (left != 0)
        return left;

    // Tìm ở cây con bên phải
    int right = findLevelHelper(root->right, value, level + 1);
    return right;
}

int findLevel(TreeNode *root, int value)
{
    return findLevelHelper(root, value, 1);
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

    int level = findLevel(root, 3);
    printf("Element %d in level: %d", 3, level);
}