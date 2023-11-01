#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Function to perform Inorder traversal (Iterative)
void inorderIterative(TreeNode* root) {
    if (root == NULL) return;

    TreeNode* stack[100]; // Assuming a maximum of 100 nodes for simplicity
    int top = -1;
    TreeNode* current = root;

    while (true) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        if (top >= 0) {
            current = stack[top--];
            printf("%d ", current->data);
            current = current->right;
        } else {
            break;
        }
    }
}

// Function to perform Postorder traversal (Iterative)
void postorderIterative(TreeNode* root) {
    if (root == NULL) return;

    TreeNode* stack1[100]; // Stack for processing
    TreeNode* stack2[100]; // Stack for final output
    int top1 = -1, top2 = -1;
    TreeNode* current = root;

    stack1[++top1] = current;

    while (top1 >= 0) {
        current = stack1[top1--];
        stack2[++top2] = current;

        if (current->left != NULL)
            stack1[++top1] = current->left;
        if (current->right != NULL)
            stack1[++top1] = current->right;
    }

    while (top2 >= 0) {
        current = stack2[top2--];
        printf("%d ", current->data);
    }
}

// Function to perform Preorder traversal (Iterative)
void preorderIterative(TreeNode* root) {
    if (root == NULL) return;

    TreeNode* stack[100]; // Assuming a maximum of 100 nodes for simplicity
    int top = -1;
    TreeNode* current = root;

    stack[++top] = current;

    while (top >= 0) {
        current = stack[top--];
        printf("%d ", current->data);

        if (current->right != NULL)
            stack[++top] = current->right;
        if (current->left != NULL)
            stack[++top] = current->left;
    }
}

// Function to print the parent of a given element
void printParent(TreeNode* root, int element) {
    if (root == NULL) return;

    TreeNode* stack[100]; // Assuming a maximum of 100 nodes for simplicity
    int top = -1;
    TreeNode* current = root;

    stack[++top] = current;

    while (top >= 0) {
        current = stack[top--];

        if ((current->left != NULL && current->left->data == element) ||
            (current->right != NULL && current->right->data == element)) {
            printf("Parent of %d is %d\n", element, current->data);
            return;
        }

        if (current->right != NULL)
            stack[++top] = current->right;
        if (current->left != NULL)
            stack[++top] = current->left;
    }

    printf("Element %d not found in the tree.\n", element);
}

// Function to find the depth of the tree
int findDepth(TreeNode* root) {
    if (root == NULL) return 0;

    int leftDepth = findDepth(root->left);
    int rightDepth = findDepth(root->right);

    return (leftDepth > rightDepth) ? (leftDepth + 1) : (rightDepth + 1);
}

// Function to print ancestors of a given element
bool printAncestors(TreeNode* root, int element) {
    if (root == NULL) return false;

    if (root->data == element) return true;

    if (printAncestors(root->left, element) || printAncestors(root->right, element)) {
        printf("%d ", root->data);
        return true;
    }

    return false;
}

// Function to count the number of leaf nodes in a binary tree
int countLeafNodes(TreeNode* root) {
    if (root == NULL) return 0;

    if (root->left == NULL && root->right == NULL) return 1;

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Driver function to test the functions
int main() {
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Inorder Traversal: ");
    inorderIterative(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorderIterative(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorderIterative(root);
    printf("\n");

    int parentElement = 5;
    printf("Parent of %d: ", parentElement);
    printParent(root, parentElement);

    printf("Depth of the tree: %d\n", findDepth(root));

    int ancestorElement = 5;
    printf("Ancestors of %d: ", ancestorElement);
    printAncestors(root, ancestorElement);
    printf("\n");

    printf("Number of leaf nodes: %d\n", countLeafNodes(root));

    // Free the memory allocated for the tree (not shown in this example)

    return 0;
}

