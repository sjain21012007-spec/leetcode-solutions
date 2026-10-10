/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans = NULL;
    int f(TreeNode* root,TreeNode* p,TreeNode*q)
    {
        if(root==NULL) return 0;
        int s = f(root->left,p,q)+f(root->right,p,q);
        if(s==2) 
        {
            if(ans==NULL) 
            {
                ans = root;
                return s;
            }
            return s;
        }
        else if(root==p || root==q) 
        {  
            if(s==1) 
            {
                ans = root;
                return s;
            }
            return 1;
        }         
        return s;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         int s = f(root,p,q);
         return ans;
    }
};