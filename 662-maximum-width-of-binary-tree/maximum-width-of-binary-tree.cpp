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
    long long ans =0;
    void f(TreeNode* root,long long col,long long level,vector<pair<long long,long long>>& a)
    {
        if(root==NULL) return ;
        if(a.size()<level)
        {
            a.push_back({col,col});
        } 
        if(col<a[level-1].first) a[level-1].first = col;
        if(col>a[level-1].second) a[level-1].second = col;
        ans  = max(ans,a[level-1].second-a[level-1].first);
       col = col - a[level - 1].first + 1;
       if(root->left!=NULL) f(root->left,2*col-1,level+1,a);
       if(root->right!=NULL) f(root->right,2*col,level+1,a);
    }
    int widthOfBinaryTree(TreeNode* root) {
        vector<pair<long long,long long>> a;
        f(root,1,1,a);
        return ans+1;
    }
};