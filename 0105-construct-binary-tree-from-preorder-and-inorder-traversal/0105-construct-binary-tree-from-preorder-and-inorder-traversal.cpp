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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int &i, int l, int r) {
        if (l > r) return NULL;
        TreeNode* root = new TreeNode(preorder[i]);
        
        int k = 0;
        for(int it=0; it<inorder.size(); it++) {
            if(preorder[i] == inorder[it]) {
                k = it;
                break;
            }
        }
        
        i++;
        root->left = build(preorder, inorder, i, l, k-1);
        root->right = build(preorder, inorder, i, k+1, r);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i = 0;
        return build(preorder, inorder, i, 0, inorder.size()-1);
    }
};