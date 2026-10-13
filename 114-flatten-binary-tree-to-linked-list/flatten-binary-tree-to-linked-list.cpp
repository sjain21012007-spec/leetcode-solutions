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
    void flatten(TreeNode* root) {
        if(root==NULL) return ;
        stack<TreeNode*> st;
        st.push(root);
        while(st.size()!=0)
        {
            TreeNode* node = st.top();
            st.pop();
            while(node->left!=NULL)
            {
                if(node->right!=NULL) st.push(node->right);
                node->right= node->left;
                node->left=NULL;
                node= node->right;
            }
            if(node->right!=NULL) st.push(node->right);
            if(st.size()!=0) node->right = st.top();
        }
    }
};