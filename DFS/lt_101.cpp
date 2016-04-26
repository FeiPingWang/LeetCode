class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return isEqual(root->left,root->right);
    }
    
    bool isEqual(TreeNode* l,TreeNode* r)
    {
        if(l == NULL && r == NULL)
            return true;
        if((l == NULL && r != NULL) || (l != NULL && r == NULL))
            return false;
        if(l->val != r->val)
            return false;
        return (isEqual(l->left,r->right) && isEqual(l->right,r->left));
        
    }
};