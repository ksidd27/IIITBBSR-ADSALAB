#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *left, *right;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

// Traversals
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node* root = NULL;
    int n, value, choice;

    // Step 1: Input from user
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    // Step 2: Ask which traversal to display
    printf("\nChoose traversal to display sorted output:\n");
    printf("1. Inorder (Sorted Order)\n");
    printf("2. Preorder\n");
    printf("3. Postorder\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("\nTraversal Result: ");
    switch (choice) {
        case 1:
            inorder(root);    // Sorted output
            break;
        case 2:
            preorder(root);
            break;
        case 3:
            postorder(root);
            break;
        default:
            printf("Invalid choice!");
    }
    printf("\n");

    return 0;
}