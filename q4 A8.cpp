#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// Function to check BST property using min–max rule
bool isBSTUtil(Node* node, int minVal, int maxVal) {
    if (node == NULL)
        return true;

    // Check current node
    if (node->data <= minVal || node->data >= maxVal)
        return false;

    // Check left and right subtrees
    return isBSTUtil(node->left, minVal, node->data) &&
           isBSTUtil(node->right, node->data, maxVal);
}

// Wrapper function
bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

// Insert into BST (to easily build tree)
Node* insert(Node* root, int value) {
    if (root == NULL)
        return new Node(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

int main() {
    Node* root = NULL;
    int n, x;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values to create a binary tree (BST-style insert used):\n";
    while (n--) {
        cin >> x;
        root = insert(root, x);
    }

    if (isBST(root))
        cout << "The given binary tree IS a BST.\n";
    else
        cout << "The given binary tree is NOT a BST.\n";

    return 0;
}

