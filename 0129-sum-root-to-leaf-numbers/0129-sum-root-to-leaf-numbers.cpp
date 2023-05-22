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
    void help(TreeNode* root, int &res, int num) {
        if(!root->left and !root->right) {
            res += num;
            return;
        }
        if(root->left) help(root->left, res, num*10+root->left->val);
        if(root->right) help(root->right, res, num*10+root->right->val);
    }
    int sumNumbers(TreeNode* root) {
        int res = 0;
        help(root, res, root->val);
        return res;
    }
};