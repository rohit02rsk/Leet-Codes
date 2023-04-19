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
    void help(TreeNode* root, int l , int r, int& res) {
        if(!root) return;
        res = max(max(res, l), r);
        help(root->left, 0, l+1, res);
        help(root->right, r+1, 0, res);
    }
    int longestZigZag(TreeNode* root) {
        int l=0, r=0, res=0;
        help(root, l, r, res);
        return res;
    }
};