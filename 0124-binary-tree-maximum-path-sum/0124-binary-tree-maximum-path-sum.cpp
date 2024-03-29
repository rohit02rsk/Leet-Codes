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
    int m_sum = INT_MIN;
    int maxSum(TreeNode* root) {
        if(!root) return 0;
        int l = max(0, maxSum(root->left));
        int r = max(0, maxSum(root->right));
        m_sum = max(m_sum, l + r + root->val);
        return root->val + max(l, r);
    }
    int maxPathSum(TreeNode* root) {
        maxSum(root);
        return m_sum;
    }
};