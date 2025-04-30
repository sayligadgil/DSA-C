#include <stdio.h>
#include <stdlib.h>

// Structure for Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Preorder Traversal
void preorder(struct Node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Inorder Traversal
void inorder(struct Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Postorder Traversal
void postorder(struct Node* root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Function to insert node into the tree (simple for manual input)
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }
    // For simplicity, insert nodes in the left subtree first (e.g., level-order)
    if (root->left == NULL) {
        root->left = newNode(data);
    } else if (root->right == NULL) {
        root->right = newNode(data);
    }
    return root;
}

int main() {
    struct Node* root = NULL;
    int n, data;

    // Number of nodes to be entered
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Input for the root node
    printf("Enter the value for root node: ");
    scanf("%d", &data);
    root = newNode(data);

    // Insert remaining nodes
    for (int i = 1; i < n; i++) {
        printf("Enter the value for node %d: ", i+1);
        scanf("%d", &data);
        root = insertNode(root, data);
    }

    // Display Traversals
    printf("\nPreorder Traversal: ");
    preorder(root);
    printf("\n");

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}
