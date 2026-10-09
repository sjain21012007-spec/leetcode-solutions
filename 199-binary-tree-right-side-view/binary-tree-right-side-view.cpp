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
    vector<int> rightSideView(TreeNode* root) {
       if(root==NULL) return {}; 
       queue<pair<TreeNode*,int>> q;
       map<int,int> m;
       TreeNode* node  = root;
       q.push({node,0});
       while(q.size()!=0)
       {
           node  = q.front().first;
           int level = q.front().second; 
           q.pop();
           m[level] = node->val;

           if(node->left!=NULL) 
           {
              q.push({node->left,level+1});
           }
            if(node->right!=NULL) 
           {
              q.push({node->right,level+1});
           }
       }
       vector<int> ans;
       for(auto it:m)
       {
          ans.push_back(it.second);
       }
       return ans;
    }
};