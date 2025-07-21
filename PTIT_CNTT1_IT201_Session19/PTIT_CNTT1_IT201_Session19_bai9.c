#include <stdio.h>
#include <stdlib.h>

// Cấu trúc một node trong cây
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Tạo một node mới
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Chèn phần tử vào cây nhị phân tìm kiếm
TreeNode* insert(TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    // Nếu value == root->data thì không làm gì (không chèn trùng)

    return root;
}

// Duyệt cây theo thứ tự trung thứ tự (Inorder)
void inorderTraversal(TreeNode* root) {
    if (root == NULL)
        return;

    inorderTraversal(root->left);         // Duyệt trái
    printf("%d ", root->data);            // In node hiện tại
    inorderTraversal(root->right);        // Duyệt phải
}

// Giải phóng bộ nhớ cây
void freeTree(TreeNode* root) {
    if (root == NULL)
        return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    TreeNode* root = NULL;

    // Chèn phần tử vào cây
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 80);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 10);

    printf("Inorder Traversal (duyet trung thu tu): ");
    inorderTraversal(root);  
    printf("\n");

    // Giải phóng bộ nhớ
    freeTree(root);

    return 0;
}
