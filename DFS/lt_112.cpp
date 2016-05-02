class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return false;
        int cur=0;
        return intPathSum(root,cur,sum);
    }
    bool intPathSum(TreeNode* root,int cur,const int &sum)
    {
        if(root == NULL)
            return false;
        cur += root->val;
        if(root->left == NULL && root->right == NULL && cur == sum)
            return true;
        if(root->left == NULL && root->right == NULL && cur != sum)
            return false;
        return (intPathSum(root->left,cur,sum) || intPathSum(root->right,cur,sum)); 
    }
};