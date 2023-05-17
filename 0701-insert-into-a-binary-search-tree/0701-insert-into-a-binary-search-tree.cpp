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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        
        //iterative
        // TreeNode* curr = root;
        // while(curr) {
        //     if(val > curr->val) {
        //         if(!curr->right) {
        //             curr->right = new TreeNode(val);
        //             return root;
        //         }
        //         curr = curr->right;
        //     } 
        //     else {
        //         if(!curr->left) {
        //             curr->left = new TreeNode(val);
        //             return root;
        //         }
        //         curr = curr->left;
        //     }
        // }
        
        //recursive
        if(val > root->val) {
            root->right = insertIntoBST(root->right, val);
        } 
        else if(val < root->val) {
            root->left = insertIntoBST(root->left, val);
        }
        
        return root;
    }
};