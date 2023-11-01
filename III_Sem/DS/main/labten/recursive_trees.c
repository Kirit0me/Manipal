#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to create a new tree node
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Recursive function to create a binary tree
TreeNode* createTree() {
    int data;
    printf("Enter data (or -1 for NULL): ");
    scanf("%d", &data);

    if (data == -1) {
        return NULL;
    }

    TreeNode* newNode = createNode(data);

    printf("Enter left child of %d:\n", data);
    newNode->left = createTree();

    printf("Enter right child of %d:\n", data);
    newNode->right = createTree();

    return newNode;
}

// Recursive function to print a binary tree in inorder traversal
void printTreeInorder(TreeNode* root) {
    if (root == NULL) return;

    printTreeInorder(root->left);
    printf("%d ", root->data);
    printTreeInorder(root->right);
}

// Driver function to test the functions
int main() {
    TreeNode* root = NULL;

    printf("Create Binary Tree:\n");
    root = createTree();

    printf("\nInorder Traversal:\n");
    printTreeInorder(root);
    printf("\n");

    // Remember to free the allocated memory for the tree (not shown in this example)

    return 0;
}

