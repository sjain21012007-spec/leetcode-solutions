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
    TreeNode* f(vector<int>&preorder,int prestart,int preend,vector<int>&inorder,int instart,int inend ,map<int,int> & m)
    {
        if(prestart>preend || instart>inend) return NULL;
          
        TreeNode* root = new  TreeNode(preorder[prestart]);
         
        int inRoot = m[root->val];
        int numsleft = inRoot- instart;
        root->left = f(preorder,prestart+1,prestart+numsleft,inorder,instart,inRoot-1,m);
        root->right = f(preorder,prestart+numsleft+1,preend,inorder,inRoot+1,inend,m);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         map<int,int> m;
         int n = preorder.size();
         for(int i=0;i<n;i++)
         {
            m[inorder[i]] = i; 
         }
         int root = m[preorder[0]];
         return f(preorder,0,n-1,inorder,0,n-1,m);
    }
};