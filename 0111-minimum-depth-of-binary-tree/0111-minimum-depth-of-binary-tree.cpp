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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int res = 1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            for(int i=0; i<sz; i++) {
                auto x = q.front();
                q.pop();
                if(!x->left and !x->right) return res;
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }
            res++;
        }
        return res;
    }
};