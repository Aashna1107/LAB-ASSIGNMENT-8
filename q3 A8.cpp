#include <iostream>
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

class BST {
public:
    Node* root;

    BST() {
        root = NULL;
    }

    // (a) Insert (No duplicates allowed)
    Node* insert(Node* node, int key) {
        if (node == NULL)
            return new Node(key);

        if (key < node->data)
            node->left = insert(node->left, key);
        else if (key > node->data)
            node->right = insert(node->right, key);
        else {
            cout << "Duplicate value " << key << " not allowed.\n";
        }
        return node;
    }

    // Helper: Find minimum value node
    Node* findMin(Node* node) {
        while (node && node->left != NULL)
            node = node->left;
        return node;
    }

    // (b) Delete an existing element
    Node* deleteNode(Node* node, int key) {
        if (node == NULL) {
            cout << "Element not found.\n";
            return node;
        }

        if (key < node->data) {
            node->left = deleteNode(node->left, key);
        }
        else if (key > node->data) {
            node->right = deleteNode(node->right, key);
        }
        else {
            // Node found
            if (node->left == NULL && node->right == NULL) {
                delete node;
                return NULL;
            }
            else if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            else {
                // Node with two children
                Node* temp = findMin(node->right);
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data);
            }
        }
        return node;
    }

    // (c) Maximum depth (height) of BST
    int maxDepth(Node* node) {
        if (node == NULL)
            return 0;

        int leftDepth = maxDepth(node->left);
        int rightDepth = maxDepth(node->right);

        return max(leftDepth, rightDepth) + 1;
    }

    // (d) Minimum depth of BST
    int minDepth(Node* node) {
        if (node == NULL)
            return 0;

        // If leaf node
        if (node->left == NULL && node->right == NULL)
            return 1;

        // If one subtree is missing
        if (node->left == NULL)
            return minDepth(node->right) + 1;
        if (node->right == NULL)
            return minDepth(node->left) + 1;

        // Both subtrees exist
        return min(minDepth(node->left), minDepth(node->right)) + 1;
    }
};

int main() {
    BST tree;
    int choice, value;

    while (true) {
        cout << "\n---- BST Operations ----\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Maximum Depth\n";
        cout << "4. Minimum Depth\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            tree.root = tree.insert(tree.root, value);
            break;

        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            tree.root = tree.deleteNode(tree.root, value);
            break;

        case 3:
            cout << "Maximum Depth of BST = " 
                 << tree.maxDepth(tree.root) << endl;
            break;

        case 4:
            cout << "Minimum Depth of BST = " 
                 << tree.minDepth(tree.root) << endl;
            break;

        case 5:
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}

