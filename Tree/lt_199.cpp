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
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> v;
        vector<int> result;
        if(root == NULL)
            return result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> res;
            int len = q.size();
            TreeNode* tmp;
            for(int i= 0;i<len;i++)
            {
                tmp = q.front();
                q.pop();
                if(tmp->left != NULL)
                {
                    q.push(tmp->left);
                }
                if(tmp->right != NULL)
                {
                    q.push(tmp->right);
                }
            }
            result.push_back(tmp->val);
        }
        //result.insert(result.begin(),root->val);
        return result;
    }
};