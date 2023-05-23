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
    unordered_map<int, vector<TreeNode*>> dp;
    vector<TreeNode*> backtrack(int n) {
        if (n == 0) return {};
        if (n == 1) return {new TreeNode(0)};
        if (dp.count(n)) return dp[n];
        
        vector<TreeNode*> res;
        for (int l=0; l<n; l++) {
            int r = n - l - 1;
            vector<TreeNode*> leftTrees = backtrack(l);
            vector<TreeNode*> rightTrees = backtrack(r);
            
            for (auto lt : leftTrees) {
                for (auto rt : rightTrees) {
                    res.push_back(new TreeNode(0, lt, rt));
                }
            }
        }
        
        dp[n] = res;
        return res;
    }
    vector<TreeNode*> allPossibleFBT(int n) {        
        return backtrack(n);
    }
};