/*   DFS   */
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

/*  BFS   */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        queue<TreeNode*> lq;
        queue<TreeNode*> rq;
        if(root->left != NULL && root->right != NULL)
        {
            lq.push(root->left);
            rq.push(root->right);
            while(!lq.empty() && !rq.empty())
            {
                TreeNode *tl = lq.front();
                TreeNode *tr = rq.front();
                lq.pop();
                rq.pop();
                if(tl->val != tr->val)
                    return false;
                if(tl->left != NULL && tr->right != NULL)
                {
                    lq.push(tl->left);
                    rq.push(tr->right);
                }
                else if((tl->left != NULL && tr->right == NULL) || (tl->left == NULL && tr->right != NULL) )
                    return false;
                if(tl->right != NULL && tr->left != NULL)
                {
                    lq.push(tl->right);
                    rq.push(tr->left);
                }
                else if((tr->left != NULL && tl->right == NULL) || (tr->left == NULL && tl->right != NULL) )
                    return false;
            }
            return (lq.empty() && rq.empty());
        }
        else if(root->left == NULL && root->right == NULL)
            return true;
        else
            return false; 
    }
};