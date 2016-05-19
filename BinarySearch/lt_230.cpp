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
	/*time complexity O(height of tree)*/
    int kthSmallest(TreeNode* root, int k) {
        int res;
        if(root == NULL)
            return 0;
        return Search(root,k);
    }
    int sumTree(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        return sumTree(root->left) + sumTree(root->right)+1;
    }
    int Search(TreeNode* root,int k)
    {
        if(root == NULL)
            return 0;
        int len = sumTree(root->left);
        if(k <= len)
            return Search(root->left,k);
        else if(k == len+1)
            return root->val;
        else 
            return Search(root->right,k-len-1);     //在右子树这边
    }
};