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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p and !q) return true;
        else if(!p or !q) return false;
        else if(p->val == q->val) {
            return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
        } 
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root and !subRoot) return true;
        else if(!root or !subRoot) return false;
        else if(isSameTree(root, subRoot)) {
            return true;
        } else {
            return isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
        }
    }
};