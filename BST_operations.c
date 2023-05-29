#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for a node in BST
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node
struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in BST
struct node* insertNode(struct node* root, int value) {
    if (root == NULL)
        return createNode(value);
    
    if (value < root->data)
        root->left = insertNode(root->left, value);
    else if (value > root->data)
        root->right = insertNode(root->right, value);
    
    return root;
}

// Function to search for a node in BST
struct node* searchNode(struct node* root, int value) {
    if (root == NULL || root->data == value)
        return root;
    
    if (value < root->data)
        return searchNode(root->left, value);
    
    return searchNode(root->right, value);
}

// Function to find the minimum value in BST
struct node* minValueNode(struct node* node) {
    struct node* current = node;
    
    while (current && current->left != NULL)
        current = current->left;
    
    return current;
}

// Function to delete a node from BST
struct node* deleteNode(struct node* root, int value) {
    if (root == NULL)
        return root;
    
    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        
        struct node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    
    return root;
}

// Function to perform in-order traversal of BST
void inorderTraversal(struct node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to perform pre-order traversal of BST
void preorderTraversal(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to perform post-order traversal of BST
void postorderTraversal(struct node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}


// Function to find the minimum value in BST
int minValue(struct node* root) {
    if (root == NULL) {
        printf("BST is empty.\n");
        return -1;
    }
    
    struct node* current = root;
    
    while (current->left != NULL)
        current = current->left;
    
    return current->data;
}

// Function to find the maximum value in BST
int maxValue(struct node* root) {
    if (root == NULL) {
        printf("BST is empty.\n");
        return -1;
    }
    
    struct node* current = root;
    
    while (current->right != NULL)
        current = current->right;
    
    return current->data;
}

int main() {
    struct node* root = NULL;
    int ch, val, key;
    
    while (1) {
        printf("1. Insert\n2. Delete\n3. Search\n4. Inorder Traversal\n5. Preorder Traversal\n6. Postorder Traversal\n7. Minimum Value\n8. Maximum Value\n9. Exit\n");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1:
                printf("Enter value to be inserted: ");
                scanf("%d", &val);
                root = insertNode(root, val);
                break;
            case 2:
                printf("Enter value to be deleted: ");
                scanf("%d", &val);
                root = deleteNode(root, val);
                break;
            case 3:
                printf("Enter value to be searched: ");
                scanf("%d", &val);
                struct node* searchResult = searchNode(root, val);
                if (searchResult != NULL)
                    printf("Element %d found in the BST.\n", val);
                else
                    printf("Element %d not found in the BST.\n", val);
                break;
            case 4:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Preorder Traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 6:
                printf("Postorder Traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 7:
                printf("Minimum Value: %d\n", minValue(root));
                break;
            case 8:
                printf("Maximum Value: %d\n", maxValue(root));
                break;
            case 9:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
                break;
        }
    }
    
    return 0;
}

