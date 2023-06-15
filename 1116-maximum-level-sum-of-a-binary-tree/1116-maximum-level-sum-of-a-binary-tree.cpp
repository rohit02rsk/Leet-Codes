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
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        int res = 0;
        int max_sum = INT_MIN;
        int i = 1;
        queue<TreeNode*> q;
        
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            int curr_sum = 0;
            for(int i=0; i<n; i++) {
                auto x = q.front();
                q.pop();
                curr_sum += x->val;
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }
            if(curr_sum > max_sum) {
                res = i;
                max_sum = curr_sum;
            }
            i++;
        }

        return res;
    }
};