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

// Hàm trả về số phần tử của nhánh ngắn nhất đi từ root đến leaf
int countMin(BinaryTree* tree) {
    // Nếu cây rỗng, trả về 0
    if (tree == NULL || tree->root == NULL) {
        return 0;
    }
    // Khởi tạo một hàng đợi để duyệt cây theo chiều rộng
    TreeNode* queue[100]; // Giả sử số phần tử tối đa là 100
    int front = 0; // Chỉ số đầu của hàng đợi
    int rear = 0; // Chỉ số cuối của hàng đợi
    int level = 0; // Biến lưu level hiện tại
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
            // Nếu node là node lá, trả về level hiện tại cộng 1
            if (node->left == NULL && node->right == NULL) {
                return level + 1;
            }
            // Nếu không, thêm các con của node vào hàng đợi
            if (node->left != NULL) {
                queue[rear++] = node->left;
            }
            if (node->right != NULL) {
                queue[rear++] = node->right;
            }
        }
        // Tăng level lên 1 sau khi duyệt xong một level
        level++;
    }
    // Nếu không tìm thấy node lá nào, trả về 0
    return 0;
}

// Hàm trả về số phần tử của nhánh dài nhất đi từ root đến leaf
// int countMax(BinaryTree* tree) {
//     // Nếu cây rỗng, trả về 0
//     if (tree == NULL || tree->root == NULL) {
//         return 0;
//     }
//     // Khởi tạo một biến lưu level cao nhất và số phần tử ở level đó
//     int maxLevel = -1;
//     int maxCount = 0;
//     // Khởi tạo một hàm đệ quy để duyệt cây theo chiều sâu
//     void dfs(TreeNode* node, int level) {
//         // Nếu node là NULL, dừng hàm
//         if (node == NULL) {
//             return;
//         }
//         // Nếu level cao hơn level cao nhất hiện tại, cập nhật level cao nhất và số phần tử ở level đó
//         if (level > maxLevel) {
//             maxLevel = level;
//             maxCount = 1;
//         }
//         // Nếu level bằng level cao nhất hiện tại, tăng số phần tử ở level đó lên 1
//         else if (level == maxLevel) {
//             maxCount++;
//         }
//         // Gọi đệ quy cho các con của node với level tăng lên 1
//         dfs(node->left, level + 1);
//         dfs(node->right, level + 1);
//     }
//     // Gọi hàm đệ quy cho gốc với level bằng 0
//     dfs(tree->root, 0);
//     // Trả về kết quả là số phần tử ở level cao nhất cộng 1
//     return maxCount + 1;
// }

int main() {
    BinaryTree tree;

    init(&tree);
    insert(&tree, 50);
    insert(&tree, 17);
    insert(&tree, 76);
    insert(&tree, 9);
    insert(&tree, 23);
    insert(&tree, 54);
    insert(&tree, 14);
    insert(&tree, 19);
    insert(&tree, 72);
    insert(&tree, 12);
    insert(&tree, 67);
    print(tree.root);
    int cntMin=countMin(&tree);
    printf("Min= %d ", cntMin);
    // int cntMax=countMax(&tree);
    // printf("Max= %d ", cntMax);
    return 0;
}