/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
		if(pRoot == NULL)
			return vector<vector<int>>();
		stack<TreeNode*> st;
		queue<TreeNode*> qu;
		vector<vector<int>> res;
		int num = 0;
		q.push(pRoot);
		while(!st.empty() || !q.empty())
		{
			vector<int> tmp;
			if(num %2 == 0)	//使用队列
			{
				int size = q.size();
				for(int i = 0;i<size;i++)
				{
					TreeNode* t = q.front();
					q.pop();
					tmp.push_back(t->val);
					if(t->left != NULL)
						st.push(t->left);
					if(t->right != NULL)
						st.push_back(t->right);
				}
			}
			else
			{
				int size = st.size();
				for(int i = 0;i<size;i++)
				{
					TreeNode* t = st.top();
					st.pop();
					tmp.push_back(t->val);
					if(t->left != NULL)
						q.push(t->left);
					if(t->right != NULL)
						q.push_back(t->right);
				}
			}
			num++;
			if(t.size() != 0)
				res.push_back(tmp);
		}
		return res;
    }
    
};