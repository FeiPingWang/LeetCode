class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        if(abs(maxDepth(root->left) - maxDepth(root->right)) > 1)
            return false;
        return (isBalanced(root->left) && isBalanced(root->right));
    }
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right == NULL)
            return 1;
        int MAX = max(maxDepth(root->left),maxDepth(root->right))+1;
        return MAX;
    }
};
