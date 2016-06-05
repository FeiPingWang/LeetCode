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
    vector<int> preorderTraversal(TreeNode* root) {
       vector<int> res;
        if(root == NULL)
            return res;
        stack<TreeNode*> st;
        while(root != NULL || !st.empty())
        {
            while(root != NULL)
            {
                res.push_back(root->val);
                st.push(root);
                root = root->left;
            }
            if(!st.empty())
            {
                TreeNode* t = st.top();
                st.pop();
                root = t->right;
            }
        }
        return res;
    }
};