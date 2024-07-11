#include<stdio.h>
#include <stdlib.h>

typedef struct NodeType {
    int data;
    struct NodeType* left, * right;
} TreeNode;

typedef struct BinaryTreeType {
    struct NodeType* root;
} BinaryTree;

TreeNode* makeNode(int data) {
    TreeNode *newTree = (TreeNode*)malloc(sizeof(TreeNode));
    newTree->data=data;
    newTree->left=NULL;
    newTree->right=NULL;
    return newTree;
}

void print(TreeNode* node) {
    if(node==NULL) return;
    print(node->left);
    printf("%d ", node->data);
    print(node->right);
}

void init(BinaryTree* tree) {
    tree->root=NULL;
}

void insert(BinaryTree* tree, int data) {
    TreeNode* new=makeNode(data);
    if (tree->root == NULL) {
        tree->root = new;
    }
    if (tree->root->data == data) {
        return;
    }
    if (data < tree->root->data) {
        if (tree->root->left == NULL) {
            tree->root->left = makeNode(data);
        } else {
            insert(tree->root->left, data);
        }
    }
    else {
        if (tree->root->right == NULL) {
            tree->root->right = makeNode(data);
        } else {
            insert(tree->root->right, data);
        }
    }
}

int main() {
    BinaryTree tree;
    init(&tree);
    insert(&tree,4);
    insert(&tree,6);
    insert(&tree,2);
    insert(&tree,3);
    insert(&tree,5);
    insert(&tree,1);
    insert(&tree,7);
    //insert các cây ở câu 1.1
    print(tree.root);
    return 0;
}
