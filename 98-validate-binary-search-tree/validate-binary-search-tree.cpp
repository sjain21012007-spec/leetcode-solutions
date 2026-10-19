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
    bool validate(TreeNode* root, long long up,long long low)
    {
        if(root==NULL) return true;
        if(root->val>=up || root->val<=low) return false;
        if(!validate(root->left,root->val,low))
        {
            return false;
        }
        if(!validate(root->right,up,root->val))
        {
            return false;
        }
        return true;
    }
    bool isValidBST(TreeNode* root) {
        long long up = (long long)INT_MAX+1;
        long long low = (long long)INT_MIN-1;
        return validate(root,up,low);
    }
};