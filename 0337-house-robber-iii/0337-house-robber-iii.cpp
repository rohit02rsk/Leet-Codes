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
    int dfs(TreeNode* root, int &l, int &r) {
        if(!root) {
            return 0;   
        }
        int left_l = 0, left_r = 0;
        int right_l = 0, right_r = 0;
        
        l = dfs(root->left, left_l, left_r);
        r = dfs(root->right, right_l, right_r);
        
        return max(l + r, left_l + left_r + right_l + right_r + root->val);
    }
    int rob(TreeNode* root) {
        int left, right;
        return dfs(root, left, right);
    }
};