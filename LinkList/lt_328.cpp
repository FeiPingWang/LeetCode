class Solution {
public:
    /*解题策略是奇数为一个链表，偶数一个，最后合起来*/
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL)
            return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* tmp = even;
        while(even && even->next)
        {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = tmp;
        return head;
    }
};