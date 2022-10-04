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
    
   
    bool flag= false; 
    
   void dfs(TreeNode* root,int sum,int csum){
       if(root==NULL)return ; 
       csum +=root->val ; 
       if(csum==sum && root->left==NULL &&root->right==NULL)flag =true ;
       dfs(root->left,sum,csum) ; 
       dfs(root->right,sum,csum) ; 
       
       
   }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
       int sum = 0 ; 
        dfs(root,targetSum,sum);
      return flag;     
    
    }
};