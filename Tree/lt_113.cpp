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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        vector<int> tmp;
        IsPath(root,res,tmp,0,sum);
        return res;
    }
    //tmp不可引用
    void IsPath(TreeNode* root,vector<vector<int>> &res,vector<int> tmp,int cur,int sum)
    {
        bool isBeaf = (root->left == NULL && root->right == NULL);
        cur += root->val;
        tmp.push_back(root->val);
        if(isBeaf && cur == sum)
        {
            res.push_back(tmp);
           // tmp.clear();
            return;
        }
        if(isBeaf && cur != sum)
        {
            return;
        }
        if(root->left != NULL)
            IsPath(root->left,res,tmp,cur,sum);
        if(root->right != NULL)
            IsPath(root->right,res,tmp,cur,sum);
        tmp.pop_back();
    }
};
