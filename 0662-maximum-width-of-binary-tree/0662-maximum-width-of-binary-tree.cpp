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
    int widthOfBinaryTree(TreeNode* root) {
        int res = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(!q.empty()) {
            int sz = q.size();
            int f = q.front().second;
            int l = q.back().second;
            res = max(res, l - f + 1);
            for(int i=0; i<sz; i++) {
                auto [node, ind] = q.front();
                q.pop();
                if(node->left)
                    q.push({node->left, (2LL*ind + 1)});
                if(node->right)
                    q.push({node->right, (2LL*ind + 2)});
            }
        }

        return res;
    }
};