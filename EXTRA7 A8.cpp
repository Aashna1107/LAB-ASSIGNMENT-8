#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct DLLNode {
    int val;
    DLLNode *prev, *next;
    DLLNode(int x) : val(x), prev(NULL), next(NULL) {}
};

// ----------------- Convert BST to sorted DLL (inorder) -----------------
void bstToDLL(TreeNode* root, DLLNode*& head, DLLNode*& tail) {
    if (!root) return;

    bstToDLL(root->left, head, tail);

    DLLNode* node = new DLLNode(root->val);
    if (!head) {
        head = tail = node;
    } else {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }

    bstToDLL(root->right, head, tail);
}

// ----------------- Merge two sorted DLLs -----------------
DLLNode* mergeDLL(DLLNode* h1, DLLNode* h2) {
    if (!h1) return h2;
    if (!h2) return h1;

    DLLNode* head = NULL;
    DLLNode* tail = NULL;

    // Standard merge of sorted lists
    while (h1 && h2) {
        DLLNode* node;
        if (h1->val <= h2->val) {
            node = h1;
            h1 = h1->next;
        } else {
            node = h2;
            h2 = h2->next;
        }

        if (!head) {
            head = tail = node;
            node->prev = NULL;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    // Append remaining elements
    DLLNode* rem = (h1 ? h1 : h2);
    while (rem) {
        tail->next = rem;
        rem->prev = tail;
        tail = rem;
        rem = rem->next;
    }

    return head;
}

// ----------------- MAIN MERGE FUNCTION -----------------
DLLNode* mergeBSTs(TreeNode* root1, TreeNode* root2) {
    DLLNode *h1 = NULL, *t1 = NULL;
    DLLNode *h2 = NULL, *t2 = NULL;

    // Convert both BSTs to sorted DLL
    bstToDLL(root1, h1, t1);
    bstToDLL(root2, h2, t2);

    // Merge the two sorted DLLs
    return mergeDLL(h1, h2);
}

// ----------------- Utility: Print DLL -----------------
void printDLL(DLLNode* head) {
    while (head) {
        cout << head->val << " <—> ";
        head = head->next;
    }
    cout << "null\n";
}

int main() {
    // Example BST 1 (you can build manually or using helper functions)
    TreeNode* t1 = new TreeNode(20);
    t1->left = new TreeNode(10);
    t1->right = new TreeNode(30);
    t1->left->left = new TreeNode(5);
    t1->left->right = new TreeNode(25);
    t1->right->right = new TreeNode(100);
    t1->right->left = new TreeNode(50);

    // Example BST 2
    TreeNode* t2 = new TreeNode(70);

    DLLNode* merged = mergeBSTs(t1, t2);

    printDLL(merged);

    return 0;
}

