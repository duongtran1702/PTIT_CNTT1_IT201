#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // Để dùng INT_MIN và INT_MAX

// Cấu trúc Node của cây nhị phân
typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

// Hàm tạo một node mới
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*) malloc(sizeof(TreeNode));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Hàm chèn phần tử vào cây nhị phân tìm kiếm
TreeNode* insert(TreeNode* root, int value) {
    if (root == NULL)
        return createNode(value);
    
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    // Không cho phép giá trị trùng
    return root;
}

// Hàm kiểm tra BST (sử dụng khoảng giá trị min/max)
int isBST(TreeNode* root, int min, int max) {
    if (root == NULL)
        return 1;

    if (root->data <= min || root->data >= max)
        return 0;

    return isBST(root->left, min, root->data) &&
           isBST(root->right, root->data, max);
}

// Hàm gọi chính kiểm tra cây có phải BST không
int checkBST(TreeNode* root) {
    return isBST(root, INT_MIN, INT_MAX);
}

// Hàm duyệt trung thứ tự (Inorder)
void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Hàm main để chạy thử
int main() {
    TreeNode* root = NULL;

    // Tạo cây tìm kiếm nhị phân
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 2);
    insert(root, 7);

    // In cây theo thứ tự trung thứ tự
    printf("Duyet Inorder: ");
    inorderTraversal(root);
    printf("\n");

    // Kiểm tra BST
    if (checkBST(root))
        printf("Day la cay nhi phan tim kiem.\n");
    else
        printf("Day KHONG phai cay nhi phan tim kiem.\n");

    return 0;
}
