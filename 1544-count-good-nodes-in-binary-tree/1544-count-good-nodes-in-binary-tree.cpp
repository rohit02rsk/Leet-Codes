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
    int goodNodes(TreeNode* root, int mn = INT_MIN) {
        if(!root) return 0;
        if(root->val >= mn)
            return 1 + goodNodes(root->left, root->val) + goodNodes(root->right, root->val);
        return goodNodes(root->left, mn) + goodNodes(root->right, mn);
    }
};