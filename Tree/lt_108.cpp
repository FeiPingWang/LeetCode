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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0)
			return NULL;
		int len = nums.size()-1;
		//height balanced，应该就是左右子树的高度相同，节点个数相同
		return bulidTree(nums,0,len);
    }
	TreeNode* bulidTree(vector<int>& num,int start,int end)
	{
		if(start == end)
		{
			TreeNode* res = new TreeNode(num[start]);
			res->left = NULL;
			res->right =NULL;
			return res;
		}	
		int len = end-start;
		int mid = start+(end-start)/2;
		if((len & 1) == 1)
			mid = mid+1;
		TreeNode* root = new TreeNode(num[mid]);
		if(mid > start)
			root->left = bulidTree(num,start,mid-1);
		if(mid < end)
		root->right = bulidTree(num,mid+1,end);
		
		return root;
	}
};