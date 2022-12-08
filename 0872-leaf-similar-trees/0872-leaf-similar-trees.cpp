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
    void dfs(vector<int> &vec, TreeNode* root) {
        if(!root) return;
        if(!root->left && !root->right) vec.push_back(root->val);
        dfs(vec, root->left);
        dfs(vec, root->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return true;
        if(!root1 || !root2) return false;
        vector<int> r1, r2;
        dfs(r1, root1);
        dfs(r2, root2);
        return r1 == r2;
    }
};