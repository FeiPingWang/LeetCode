/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
    	if(pRoot == NULL)
            return 0;
		if(pRoot->left == NULL && pRoot->right == NULL)
			return 1;
		return max(TreeDepth(pRoot->left),TreeDepth(pRoot->right))+1;
    }
};