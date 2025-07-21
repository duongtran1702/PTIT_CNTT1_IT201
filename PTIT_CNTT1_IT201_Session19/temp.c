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

void printConnections(TreeNode *root)
{
    if (root == NULL)
        return;

    printf("Node %d : ", root->data);

    if (root->left != NULL)
        printf("\n->Left: %d", root->left->data);
    else
        printf("\n->Left: NULL");

    // In node phải
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
    TreeNode *root = buildTree();
    printConnections(root);
}
