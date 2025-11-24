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
    unordered_map<int, int> inIndex;   // map value ? index in inorder[]
    int postPos;                       // index in postorder, moving from end to start

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd) {
        if (inStart > inEnd) return NULL;

        // Pick current root from postorder
        int rootVal = postorder[postPos--];
        TreeNode* root = new TreeNode(rootVal);

        // Find position in inorder
        int idx = inIndex[rootVal];

        // Build right subtree first, then left subtree
        root->right = build(inorder, postorder, idx + 1, inEnd);
        root->left = build(inorder, postorder, inStart, idx - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        inIndex.clear();
        
        // Fill inIndex map for fast lookup
        for (int i = 0; i < inorder.size(); i++)
            inIndex[inorder[i]] = i;

        postPos = postorder.size() - 1;   // Postorder root starts at last position

        return build(inorder, postorder, 0, inorder.size() - 1);
    }
};

