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
    bool isValidBST(TreeNode* root, long int high = LONG_MAX, long int low = LONG_MIN) {
        if(!root) return true;
        if(root->val > low and root->val < high) 
            return isValidBST(root->left, root->val, low) and isValidBST(root->right, high, root->val);
        return false;
    }
};