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
                    printf("\nDelete at root");
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
                    printf("\nDelete at root");
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
            if (isLeaf(curr->left) && isLeaf(curr->right)) {
                // copy data from the right
                curr->data = curr->right->data;
                free(curr->right);
                curr->right = NULL;
                return;
            }
            // case 4: curr->right is not a leaf
            if (!isLeaf(curr->right)) {
                TreeNode* leftMost = curr->right;
                TreeNode* parent = NULL;
                while (!isLeaf(leftMost)) {
                    parent = leftMost;
                    leftMost = leftMost->left;
                }
                printf("\nLeaf data %d", leftMost->data);
                curr->data = leftMost->data;
                free(leftMost);
                parent->left = NULL;
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
    insert(&tree, 50);
    insert(&tree, 25);
    insert(&tree, 10);
    insert(&tree, 33);
    insert(&tree, 60);
    insert(&tree, 11);
    insert(&tree, 56);
    insert(&tree, 61);
    print(tree.root);

    delete(&tree, 61);
    printf("\n");
    print(tree.root);
    return 0;
}