/*recursive*/
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string tmp;
        if(root == NULL)
            return res;
        Depth_first(root,res,tmp);
        return res;
    }
    
    void Depth_first(TreeNode* root,vector<string> &res,string tmp)
    {
        if(tmp.size() != 0)
            tmp = tmp + "->";
        stringstream ss;        //convert int to string 
        ss << root->val;
        string s;
        ss >> s;
        tmp += s;
        if(root->left == NULL && root->right == NULL)
            res.push_back(tmp);
        if(root->left != NULL)
            Depth_first(root->left,res,tmp);
        if(root->right != NULL)
            Depth_first(root->right,res,tmp);
    }
};


/*no recursive*/
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        stack<string> path;			//key 
        stack<TreeNode*> st;
        if(root == NULL)
            return res;
        st.push(root);
        path.push(to_string(root->val));
        while(!st.empty())
        {
            TreeNode* node = st.top();
            st.pop();
            string tmp = path.top();
            path.pop();
            
            if(node->left == NULL && node->right == NULL)
                res.push_back(tmp);
            if(node->right != NULL)
            {
                path.push(tmp+"->"+to_string(node->right->val));
                st.push(node->right);
            }
            if(node->left != NULL)
            {
                path.push(tmp + "->" + to_string(node->left->val));
                st.push(node->left);
            }
        }
        return res;
    }
};