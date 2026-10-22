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
        unordered_map<int,int> m;
        stack<TreeNode*> st;
        TreeNode* node = root;
        while(true)
        {
            if(node!=NULL)
            {
                st.push(node);
                node = node->left;
            }
            else{
                if(st.empty()) return false;
                node = st.top();
                if(m[k-node->val]>0) return true;
                st.pop();
                m[node->val]++;
                node = node->right;
            }
        } 
        return false;
    }
};