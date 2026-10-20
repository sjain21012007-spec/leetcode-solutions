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
    TreeNode* f(vector<int>& preorder)
    {
        if(preorder.size()==0) return NULL;
        TreeNode* node = new TreeNode(preorder[0]);
        vector<int> left ;
        vector<int> right;
        for(int i=1;i<preorder.size();i++)
        {
            if(preorder[i]>preorder[0])
            {
                right.push_back(preorder[i]);
            }
            else{
                left.push_back(preorder[i]);
            }
        }
        node->right = f(right);
        node->left = f(left);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
          return f(preorder);
    }
};