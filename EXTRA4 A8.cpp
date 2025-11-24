#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// -------- Function to build the tree from level order with -1 as NULL --------
TreeNode* buildTree(vector<int>& arr) {
    if (arr.empty() || arr[0] == -1) return NULL;

    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < arr.size()) {
        TreeNode* curr = q.front();
        q.pop();

        // left child
        if (i < arr.size() && arr[i] != -1) {
            curr->left = new TreeNode(arr[i]);
            q.push(curr->left);
        }
        i++;

        // right child
        if (i < arr.size() && arr[i] != -1) {
            curr->right = new TreeNode(arr[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

// -------- Function to get the Right View of the Binary Tree --------
vector<int> rightView(TreeNode* root) {
    vector<int> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        int rightMost = -1;

        for (int i = 0; i < size; i++) {
            TreeNode* curr = q.front();
            q.pop();

            rightMost = curr->val;  // Last node in this level becomes the right view

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }

        result.push_back(rightMost);
    }

    return result;
}

// ------------------------ MAIN ------------------------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        TreeNode* root = buildTree(arr);

        vector<int> ans = rightView(root);

        for (int x : ans) cout << x << " ";
        cout << "\n";
    }

    return 0;
}

