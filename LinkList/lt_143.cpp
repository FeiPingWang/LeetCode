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
    void reorderList(ListNode* head) {
        if(head == NULL)
            return;
        ListNode* laterHalf = NULL;
        ListNode* p = head;
        int len = 0;
        while(p)
        {
            p = p->next;
            len++;
        }
        if(len < 3)             //长度不够，直接返回
            return;
        int lenHalf = len/2;
        
        ListNode* half = head;
        while(lenHalf--)
            half = half->next;
        laterHalf = half->next;     //后半段的头指针
        half->next = NULL;          //断开成2个链表
        ListNode* resRev = reverseList(laterHalf);  //反转
        // ListNode* resRev = laterHalf;
        ListNode* h = head;
        while(resRev != NULL)
        {
            ListNode* tmp = resRev->next;
            ListNode* next = h->next;
            
            resRev->next = next;
            h->next = resRev;
            
            resRev = tmp;
            h = next;
        }
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* l = head;
        ListNode* dummy = new ListNode(0);
        ListNode* res = dummy;
        ListNode* pre = NULL;
        while(l != NULL)
        {
            ListNode *next = l->next;
            l->next = pre;
            res->next = l; 
            pre = l;
            l = next;
        }
        return dummy->next;
    }
};
