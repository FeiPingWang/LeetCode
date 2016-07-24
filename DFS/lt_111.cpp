/* First submission */
/* 最开使采用下面这种方式，会超时*/ 
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right == NULL)
            return 1;
        return min(minDepth(root->left),minDepth(root->right)) == 0 ? max(minDepth(root->left),minDepth(root->right))+1 :\
        min(minDepth(root->left),minDepth(root->right))+1;
    }
};

/* Second submission */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        return findDepth(root); 
    }
    
    int findDepth(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right == NULL)
            return 1;
        int l = findDepth(root->left);
        int r = findDepth(root->right);
        if(l != 0 && r != 0)
            return min(l,r)+1;
        else if(l == 0 && r != 0)
            return r+1;
        else
            return l+1;
    }
};


