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
	/*记得考虑k大于链表长度的情况*/
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return NULL;
        ListNode* f = head;
        ListNode* s = head;
        ListNode* dummy = new ListNode(0);
        int num = 0;
        dummy->next = head;
        ListNode* res = dummy;
        for(ListNode* t = head;t!= NULL;)
        {
            num++;
            t = t->next;
        }
        k = k % num;
        while(k-- && f != NULL)
            f = f->next;
        if(f == NULL)
            return head; 
        while(f->next != NULL)
        {
            f = f->next;
            s = s->next;
        }
        while(s->next != NULL)
        {
            ListNode* pre = s->next;
            s->next = s->next->next;
            pre->next = res->next;
            res->next = pre;
            res = res->next;
        }
        return dummy->next;    
        
    }
};