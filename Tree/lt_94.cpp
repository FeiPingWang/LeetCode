/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        if(root == NULL)
            return res;
        while(root != NULL || !st.empty())
        {
            while(root!=NULL)
            {
                st.push(root);
                root = root->left;
            }
           // st.pop();
            if(!st.empty())
            {
                TreeNode* t = st.top();
                res.push_back(t->val);
                st.pop();
                root = t->right;
            }
        }
        return res;
    }
};