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
    int lev(TreeNode* root)
    {
        if(root==NULL) return 0;
        return 1+ lev(root->left);
    }
    int ri ;
    bool f(TreeNode* root,int level,int curr,int right)
    {
        if(root==NULL) return false;
        if(curr==level) 
        {
            ri = right;
            return true;
        }
        if(f(root->right,level,curr+1,2*right)) return true;
        if(f(root->left,level,curr+1,2*right-1)) return true;
        return false;
    } 
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int level = lev(root);
        bool mil = f(root,level,1,1);
        int ans =0;
        int s = 1;
        for(int i=0;i<level-1;i++)
        {
             ans+=s;
             s=s*2;
        }
        return ans+ri;
    }
};