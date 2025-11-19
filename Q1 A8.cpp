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

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = NULL;
    }

    Node* insert(Node* node, int value) {
        if (node == NULL) {
            return new Node(value);
        }
        if (value < node->data)
            node->left = insert(node->left, value);
        else
            node->right = insert(node->right, value);
        return node;
    }


    void preorder(Node* node) {
        if (node == NULL) return;

        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    
    void inorder(Node* node) {
        if (node == NULL) return;

        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }


    void postorder(Node* node) {
        if (node == NULL) return;

        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
};

int main() {
    BinaryTree bt;

    bt.root = bt.insert(bt.root, 50);
    bt.insert(bt.root, 30);
    bt.insert(bt.root, 70);
    bt.insert(bt.root, 20);
    bt.insert(bt.root, 40);
    bt.insert(bt.root, 60);
    bt.insert(bt.root, 80);

    cout << "Preorder Traversal: ";
    bt.preorder(bt.root);
    cout << endl;

    cout << "Inorder Traversal: ";
    bt.inorder(bt.root);
    cout << endl;

    cout << "Postorder Traversal: ";
    bt.postorder(bt.root);
    cout << endl;

    return 0;
}

