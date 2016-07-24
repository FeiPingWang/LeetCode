/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL)
            return NULL;
        int flag = 0,fhead=0;
        
        ListNode *res = new ListNode(0);
        ListNode *result;
        
        while(l1 != NULL && l2 != NULL)
        {
            int bit = l1->val + l2->val + flag;
            if(bit >= 10)
            {
                bit = bit - 10;
                flag = 1;
            }
            else
                flag = 0;
            ListNode* tmp = new ListNode(0);
            tmp->val = bit;
            tmp->next = NULL;
            if(fhead == 0)
            {
                res = tmp;
                result = res;
                fhead = 1;
            }
            else
                res->next = tmp;
            res = tmp;   //此句如果是res = res->next则会错误,有可能会对NULL操作
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1)
        {
            ListNode *t = new ListNode(0);
            int bit = l1->val + flag;
            if(bit >= 10)
            {
                bit = bit - 10;
                flag = 1;
            }
            else
                flag = 0;
            t->val = bit;
            t->next = NULL;
            res->next = t;
            res = res->next;
            l1 = l1->next;
        }
        while(l2)
        {
            ListNode *t = new ListNode(0);
            int bit = l2->val + flag;
            if(bit >= 10)
            {
                bit = bit - 10;
                flag = 1;
            }
            else
                flag = 0;
            t->val = bit;
            t->next = NULL;
            res->next = t;
            res = res->next;
            l2 = l2->next;
        }
        if(flag == 1)
        {
            ListNode *t = new ListNode(1);
            t->next = NULL;
            res->next = t;
        }
        return result;
    }
};