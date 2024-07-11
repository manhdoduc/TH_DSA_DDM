#include <stdio.h>
#include <stdlib.h>

typedef struct NodeType {
    int data;
    struct NodeType* left, * right;
} TreeNode;
typedef struct BinaryTreeType {
    struct NodeType* root;
} BinaryTree;

TreeNode* makeNode(int data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
// Hàm trả về số phần tử ở level l của cây nhị phân
int countNodesAtLevel(BinaryTree* tree, int l) {
    // Nếu cây rỗng, trả về 0
    if (tree == NULL || tree->root == NULL) {
        return 0;
    }
    // Nếu level là 0, trả về 1 (chỉ có gốc)
    if (l == 0) {
        return 1;
    }
    // Khởi tạo một hàng đợi để duyệt cây theo chiều rộng
    TreeNode* queue[100]; // Giả sử số phần tử tối đa là 100
    int front = 0; // Chỉ số đầu của hàng đợi
    int rear = 0; // Chỉ số cuối của hàng đợi
    int level = 0; // Biến lưu level hiện tại
    int count = 0; // Biến đếm số phần tử ở level l
    // Thêm gốc vào hàng đợi và tăng rear lên 1
    queue[rear++] = tree->root;
    // Lặp cho đến khi hàng đợi rỗng
    while (front != rear) {
        // Lấy số phần tử hiện có trong hàng đợi
        int size = rear - front;
        // Duyệt qua các phần tử trong hàng đợi ở cùng một level
        for (int i = 0; i < size; i++) {
            // Lấy phần tử đầu tiên trong hàng đợi
            TreeNode* node = queue[front++];
            // Nếu level hiện tại bằng l, tăng biến đếm lên 1
            if (level == l) {
                count++;
            }
            // Nếu level hiện tại nhỏ hơn l, thêm các con của node vào hàng đợi
            if (level < l) {
                if (node->left != NULL) {
                    queue[rear++] = node->left;
                }
                if (node->right != NULL) {
                    queue[rear++] = node->right;
                }
            }
        }
        // Tăng level lên 1 sau khi duyệt xong một level
        level++;
    }
    // Trả về kết quả
    return count;
}

void print(TreeNode* node) {
    if (node == NULL)
        return;
    printf("%d\n", node->data);
    print(node->left);
    print(node->right);
}
TreeNode* search(TreeNode* node, int val) {
//    while (1) {
        if (node == NULL || node->data == val)
            return node;
        else if (val < node->data)
            return search(node->left, val);
        else if (val > node->data)
            return search(node->right, val);
//    }
}
void init(BinaryTree* tree) {
    tree->root = NULL;
}
int isLeaf(TreeNode* node) {
    return (node != NULL && node->left == NULL && node->right == NULL);
}

void insert(BinaryTree* tree, int data) {
    TreeNode* node = makeNode(data);
    if (tree->root == NULL) // empty tree
        tree->root = node;
    else {
        TreeNode* curr = tree->root;
        TreeNode* prev = NULL;
        while (curr != NULL) {
            prev = curr;
            if (curr->data > data)
                curr = curr->left;
            else
                curr = curr->right;
        }
        if (prev->data > data)
            prev->left = node;
        else
            prev->right = node;
    }
}

void delete(BinaryTree* tree, int val) {
    // search the val
    TreeNode* curr = tree->root;
    TreeNode* prev = NULL;
    while (1) {
        if (curr == NULL)    // not found
            return;
        if (curr->data == val) {    // found
            // delete the curr node

            // case 1: no child / leaf
            if (curr->left == NULL && curr->right == NULL) {
                free(curr);
                if (prev == NULL) {
                    tree->root = NULL;
                }
                else {
                    if (prev->data > val) {
                        prev->left = NULL;
                    }
                    else {
                        prev->right = NULL;
                    }
                }
                return;
            }
            // case 2: one child
            if (curr->left == NULL) {
                if (prev == NULL) {
                    tree->root = curr->right;
                }
                else {
                    if (prev->data > val) {
                        prev->left = curr->right;
                    }
                    else {
                        prev->right = curr->right;
                    }
                }
                free(curr);
                return;
            } 
            if (curr->right == NULL) {
                if (prev == NULL) {
                    tree->root = curr->left;
                }
                else {
                    if (prev->data > val) {
                        prev->left = curr->left;
                    }
                    else {
                        prev->right = curr->left;
                    }
                }
                free(curr);
                return;
            }

            // case 3: 2 children (leafs)
            if (isLeaf(curr->right)) {
                // copy data from the right
                curr->data = curr->right->data;
                TreeNode* temp = curr->right;
                curr->right = NULL;
                free(temp);
                return;
            }
            // case 4: curr->right is not a leaf
            if (!isLeaf(curr->right)) {
                TreeNode* leftMost = curr->right;
                TreeNode* parent = curr;
                while (leftMost->left != NULL) {
                    parent = leftMost;
                    leftMost = leftMost->left;
                }
                curr->data = leftMost->data;
                parent->left = leftMost->right; // Adjust the parent's link
                free(leftMost);
                return;
            }
        }
        prev = curr;
        if (curr->data > val) {
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }
    }
}
int main() {
    BinaryTree tree;

    init(&tree);
    insert(&tree, 15);
    insert(&tree, 11);
    insert(&tree, 26);
    insert(&tree, 9);
    insert(&tree, 8);
    insert(&tree, 12);
    insert(&tree, 20);
    insert(&tree, 30);
    insert(&tree, 9);
    insert(&tree, 16);
    insert(&tree, 14);
    insert(&tree, 35);
    print(tree.root);
    int cnt=countNodesAtLevel(&tree, 2);
    printf("%d ", cnt);
    return 0;
}