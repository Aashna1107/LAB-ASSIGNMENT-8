/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    // Function to generate trees from range [start, end]
    vector<TreeNode*> generate(int start, int end) {
        vector<TreeNode*> trees;

        // Base case: no numbers left ? return vector containing NULL
        if (start > end) {
            trees.push_back(nullptr);
            return trees;
        }

        // Pick every number as root
        for (int root = start; root <= end; root++) {
            
            // All possible left subtrees using values < root
            vector<TreeNode*> leftTrees = generate(start, root - 1);

            // All possible right subtrees using values > root
            vector<TreeNode*> rightTrees = generate(root + 1, end);

            // Combine left and right subtrees with the current root
            for (auto left : leftTrees) {
                for (auto right : rightTrees) {
                    TreeNode* newRoot = new TreeNode(root);
                    newRoot->left = left;
                    newRoot->right = right;
                    trees.push_back(newRoot);
                }
            }
        }
        return trees;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return generate(1, n);
    }
};

