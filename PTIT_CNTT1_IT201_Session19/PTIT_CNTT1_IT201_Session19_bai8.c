#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct QueueNode {
    TreeNode *node;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue {
    QueueNode *front;
    QueueNode *rear;
} Queue;

// Tạo hàng đợi mới
Queue *createQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Kiểm tra hàng đợi rỗng
int isEmpty(Queue *q) {
    return (q->front == NULL);
}

// Thêm node vào hàng đợi
void pushQueue(Queue *q, TreeNode *treeNode) {
    QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
    temp->node = treeNode;
    temp->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

// Lấy node ra khỏi hàng đợi
TreeNode *popQueue(Queue *q) {
    if (isEmpty(q)) return NULL;

    QueueNode *temp = q->front;
    TreeNode *treeNode = temp->node;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return treeNode;
}

// Tạo node mới
TreeNode *makeNode(int value) {
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->val = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Thêm phần tử vào cây nhị phân theo level (BFS)
TreeNode *addNode(TreeNode *root, int value) {
    TreeNode *newNode = makeNode(value);
    if (root == NULL) return newNode;

    Queue *q = createQueue();
    pushQueue(q, root);

    while (!isEmpty(q)) {
        TreeNode *curr = popQueue(q);

        if (curr->left == NULL) {
            curr->left = newNode;
            break;
        } else {
            pushQueue(q, curr->left);
        }

        if (curr->right == NULL) {
            curr->right = newNode;
            break;
        } else {
            pushQueue(q, curr->right);
        }
    }

    free(q);
    return root;
}

// Tính chiều cao cây nhị phân
int getHeight(TreeNode *root) {
    if (root == NULL)
        return 0;

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main() {
    TreeNode *root = NULL;

    root = addNode(root, 1);
    root = addNode(root, 2);
    root = addNode(root, 3);
    root = addNode(root, 4);
    root = addNode(root, 5);
    root = addNode(root, 6);

    printf("Height of Tree: %d\n", getHeight(root));
    return 0;
}
