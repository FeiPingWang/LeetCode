class Solution {
public:
    /*most importance is avoid operate NULL point */
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* res = dummy;
        ListNode* tmp = dummy;
        if(head == NULL)
            return dummy->next;
        while(res != NULL)
        {
            if(res->next != NULL && res->next->val < x)
            {
                res = res->next;
                tmp = tmp->next;
            }
            else
                break;
        }
        while(res != NULL)
        {
            if(res->next == NULL)
                break;
            if(res->next->val >= x)
                res = res->next;
            else
            {
                ListNode* pre = res->next;
                res->next = res->next->next;
                pre->next = tmp->next;
                tmp->next = pre;
                tmp = tmp->next;
            }
        }
        return dummy->next;
        
    }
};