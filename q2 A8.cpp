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

    Node* insert(Node* node, int value) {
        if (node == NULL)
            return new Node(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else
            node->right = insert(node->right, value);

        return node;
    }

    
    Node* searchRecursive(Node* node, int key) {
        if (node == NULL || node->data == key)
            return node;

        if (key < node->data)
            return searchRecursive(node->left, key);
        else
            return searchRecursive(node->right, key);
    }

   
    Node* searchNonRecursive(int key) {
        Node* current = root;

        while (current != NULL) {
            if (current->data == key)
                return current;
            else if (key < current->data)
                current = current->left;
            else
                current = current->right;
        }
        return NULL;
    }

 
    Node* findMax(Node* node) {
        if (node == NULL) return NULL;

        while (node->right != NULL)
            node = node->right;
        return node;
    }

  
    Node* findMin(Node* node) {
        if (node == NULL) return NULL;

        while (node->left != NULL)
            node = node->left;
        return node;
    }

 
    Node* inorderSuccessor(Node* root, Node* target) {
        if (target == NULL) return NULL;

      
        if (target->right != NULL)
            return findMin(target->right);

        
        Node* successor = NULL;
        Node* ancestor = root;

        while (ancestor != NULL) {
            if (target->data < ancestor->data) {
                successor = ancestor;
                ancestor = ancestor->left;
            } else if (target->data > ancestor->data) {
                ancestor = ancestor->right;
            } else {
                break;
            }
        }
        return successor;
    }

  
    Node* inorderPredecessor(Node* root, Node* target) {
        if (target == NULL) return NULL;

       
        if (target->left != NULL)
            return findMax(target->left);

        Node* predecessor = NULL;
        Node* ancestor = root;

        while (ancestor != NULL) {
            if (target->data > ancestor->data) {
                predecessor = ancestor;
                ancestor = ancestor->right;
            } else if (target->data < ancestor->data) {
                ancestor = ancestor->left;
            } else {
                break;
            }
        }
        return predecessor;
    }
};

int main() {
    BST tree;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values to insert into BST:\n";
    while (n--) {
        cin >> value;
        tree.root = tree.insert(tree.root, value);
    }

    int key;
    cout << "\nEnter value to search: ";
    cin >> key;

    Node* rec = tree.searchRecursive(tree.root, key);
    Node* nrec = tree.searchNonRecursive(key);

    cout << "Recursive Search: ";
    cout << (rec ? "Found\n" : "Not Found\n");

    cout << "Non-Recursive Search: ";
    cout << (nrec ? "Found\n" : "Not Found\n");

    cout << "Minimum Element: " 
         << tree.findMin(tree.root)->data << endl;

    cout << "Maximum Element: " 
         << tree.findMax(tree.root)->data << endl;

    cout << "\nEnter value to find successor and predecessor: ";
    cin >> key;

    Node* target = tree.searchNonRecursive(key);

    if (!target) {
        cout << "Element not found in BST.\n";
        return 0;
    }

    Node* succ = tree.inorderSuccessor(tree.root, target);
    Node* pred = tree.inorderPredecessor(tree.root, target);

    cout << "In-order Successor: ";
    if (succ) cout << succ->data << endl;
    else cout << "No Successor\n";

    cout << "In-order Predecessor: ";
    if (pred) cout << pred->data << endl;
    else cout << "No Predecessor\n";

    return 0;
}

