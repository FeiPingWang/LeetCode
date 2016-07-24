class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)       //如果这句话放到9行的后面，就runtime error 为何？
										//原因是如果不事先判断，可能会出现空指针的操作，导致未知操作
            return true;
        if((p == NULL && q != NULL) || (p != NULL && q == NULL))
            return false;
        if(p->val != q->val)
            return false;
        return (isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
    }
};
