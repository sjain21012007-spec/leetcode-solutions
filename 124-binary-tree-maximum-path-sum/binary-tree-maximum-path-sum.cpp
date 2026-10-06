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
    int maxi =-1e9;
    int f(TreeNode* root)
    {
        if(root==NULL) return 0;
        int right = f(root->right);
        int left = f(root->left);
        maxi = max(maxi,root->val);
        maxi = max(maxi,root->val+right+left);
        maxi = max(maxi,max(root->val+max(right,left),root->val));
        return max(root->val+max(right,left),root->val);
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        int r = f(root);
        return maxi;
    }
};