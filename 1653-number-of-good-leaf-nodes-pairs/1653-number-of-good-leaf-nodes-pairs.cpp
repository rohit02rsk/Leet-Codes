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
    int res = 0;
    int d;
    
    vector<int> f(TreeNode* root) {
        if (!root)
            return {};

        if (!root->left && !root->right)
            return {1};

        auto l = f(root->left);
        auto r = f(root->right);
        vector<int> tmp;

        for (auto i1 : l) {
            for (auto i2 : r)
                if (i1 + i2 <= d)
                    res++;
            if (++i1 < d)
                tmp.push_back(i1);
        }
        
        for (auto i2 : r)
            if (++i2 < d)
                tmp.push_back(i2);

        return tmp;
    }

    int countPairs(TreeNode* root, int distance) {
        d = distance;
        f(root);
        return res;
    }
};