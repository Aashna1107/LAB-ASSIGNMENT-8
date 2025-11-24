#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    unordered_map<int, int> inIndex;   // Maps element ? its index in inorder
    int prePos = 0;                    // Current position in preorder

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd) {
        if (inStart > inEnd) return NULL;

        // Pick current root from preorder
        int rootVal = preorder[prePos++];
        TreeNode* root = new TreeNode(rootVal);

        // Index of this root in inorder[]
        int idx = inIndex[rootVal];

        // Recursively build left and right subtrees
        root->left = build(preorder, inorder, inStart, idx - 1);
        root->right = build(preorder, inorder, idx + 1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        inIndex.clear();
        prePos = 0;

        // Store index of inorder elements for O(1) lookup
        for (int i = 0; i < inorder.size(); i++)
            inIndex[inorder[i]] = i;

        return build(preorder, inorder, 0, inorder.size() - 1);
    }
};

