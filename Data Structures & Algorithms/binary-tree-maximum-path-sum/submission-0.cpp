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
    int maxSum = INT_MIN;

    int dfs(TreeNode* root) {
        if (!root) return 0;

        // Get max gain from left and right (ignore negative paths)
        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));

        // Path passing through this node
        int currentPath = left + right + root->val;

        // Update global max
        maxSum = max(maxSum, currentPath);

        // Return max gain if continuing the same path
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};