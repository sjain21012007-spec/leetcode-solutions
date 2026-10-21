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
class BSTIterator {
public: 
    stack<TreeNode*> st;
    TreeNode* node ;
    BSTIterator(TreeNode* root) {
          node = root;
    }
    
    int next() {
          while(node!=NULL)
          {
             st.push(node);
            node=node->left;
          }
            TreeNode* curr = st.top();
            st.pop();
            int s = curr->val;
            node = curr->right;
            return s;
    }
    
    bool hasNext() {
        if(st.empty()==true && node ==NULL) return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */