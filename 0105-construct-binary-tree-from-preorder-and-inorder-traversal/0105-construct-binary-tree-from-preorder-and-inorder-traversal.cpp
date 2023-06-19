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
    unordered_map<int, int> mp;
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& i, int l, int r) {
        if(l > r) return NULL;
        int mid = mp[preorder[i]];
        TreeNode* root = new TreeNode(preorder[i]);

        i++;
        root->left = build(preorder, inorder, i, l, mid-1);
        root->right = build(preorder, inorder, i, mid+1, r);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        mp.clear();
        int n = inorder.size();
        for(int i=0; i<n; i++)
            mp[inorder[i]] = i;
        int i = 0;
        return build(preorder, inorder, i, 0, n - 1);
    }
};