#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int isbn;
    float price;
} Book;

typedef struct TreeNode {
    Book info;
    struct TreeNode* left;
    struct TreeNode* right;
    int balanceFactor;
} TreeNode;


Book read_book() {
    Book b;

    printf("Enter ISBN: ");
    scanf("%d", &b.isbn);

    printf("Enter price: ");
    scanf("%f", &b.price);

    return b;
}

void print_book(Book b) {
    printf("ISBN: %d | Price: %.2f\n", b.isbn, b.price);
}


TreeNode* create_node(Book b) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));

    if (node != NULL) {
        node->info = b;
        node->left = NULL;
        node->right = NULL;
        node->balanceFactor = 0;
    }

    return node;
}


void print(TreeNode* root) {
    if (root != NULL) {
        print_book(root->info);

        print(root->left);
        print(root->right);
    }
}

int tree_height(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = tree_height(root->left);
    int rightHeight = tree_height(root->right);

    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    }
    else {
        return rightHeight + 1;
    }
}

int balance_factor(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    return tree_height(root->left) - tree_height(root->right);
}

int main() {
    Book b1 = read_book();

    TreeNode* root = create_node(b1);
    root->balanceFactor = balance_factor(root);

    printf("\nPreorder Traversal:\n");
    print(root);

    printf("\nTree Height: %d\n", tree_height(root));
    printf("Balance Factor: %d\n", balance_factor(root));

    return 0;
}