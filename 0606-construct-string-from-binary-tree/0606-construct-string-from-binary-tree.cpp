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
    vector<string> res;
    void preorder(TreeNode* root) {
        if(!root) return;
        
        res.push_back("(");
        
        res.push_back(to_string(root->val));
        
        if(!root->left and root->right) 
            res.push_back("()");
        preorder(root->left);
        preorder(root->right);
        
        res.push_back(")");
    }
    string tree2str(TreeNode* root) {
        string ans = "";
        preorder(root);
        for(int i=1; i<res.size()-1; i++) ans += res[i];
        return ans;
    }
};