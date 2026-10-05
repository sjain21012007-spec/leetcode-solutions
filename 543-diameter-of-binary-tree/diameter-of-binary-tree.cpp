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
     int depth(TreeNode* root , int level)
      {
           if(root==NULL) return level;
           return max(depth(root->left,level+1),depth(root->right,level+1));
      }
      int f(TreeNode* root)
      {
         if(root==NULL) return 0;
         int rightmax = f(root->right);
         int leftmax =  f(root->left);
         int curr  = depth(root->right,0)+ depth(root->left,0);
         return max(curr,max(rightmax,leftmax));
      }
     int diameterOfBinaryTree(TreeNode* root) {
       return f(root);
    }
};