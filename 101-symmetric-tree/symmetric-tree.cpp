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
    bool f(TreeNode* rootr,TreeNode* rootl)
    {
        if(rootr==NULL)
        {
            if(rootl!=NULL) return 0;
            return 1;
        }
         if(rootl==NULL)
        {
            if(rootr!=NULL) return 0;
            return 1;
        }

        if(rootr->val!=rootl->val) return 0;

        return (f(rootr->right,rootl->left) && f(rootr->left,rootl->right));
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return 1;
        return f(root->right,root->left);
    }
};