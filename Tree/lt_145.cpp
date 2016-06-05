/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 typedef struct node{
     TreeNode* Node;
     bool isFirst;
 }node;
 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<node*> st;
        vector<int> res;
        if(root == NULL)
            return res;
        while(root != NULL || !st.empty())
        {
            while(root != NULL)
            {
                node* t = (node*)malloc(sizeof(node));
                t->Node = root;
                t->isFirst = true;
                st.push(t);
                root = root->left;
            }
            if(!st.empty())
            {
                node* tmp = st.top();
                st.pop();
                if(tmp->isFirst == true)
                {
                    tmp->isFirst = false;
                    st.push(tmp);
                    root = tmp->Node->right;
                }
                else
                {
                    res.push_back(tmp->Node->val);
                    root = NULL;
                }
            }
        }
        return res;
    }
//private:
//    node* Node;
};