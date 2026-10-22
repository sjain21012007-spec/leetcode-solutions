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
    bool findTarget(TreeNode* root, int k) {
        vector<int> s;
        getSortedOrder(root,s);
        int i=0,j=s.size()-1;
        while(i<j)
        {
            int sum=s[i]+s[j];
            if(sum==k)return true;

            else if(sum>k)j--;
            else i++;
        }
        return false;
    }
    void getSortedOrder(TreeNode *root, vector<int> &sorted) 
    {
        if(!root)return;

        getSortedOrder(root->left,sorted);
        sorted.push_back(root->val);
        getSortedOrder(root->right,sorted);
    }
};