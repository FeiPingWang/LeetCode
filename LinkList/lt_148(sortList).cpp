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
    //use MergeSort
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        return mergeSort(head);
	}
	//返回终点的下一个节点，前面断开
	ListNode* getMidNode(ListNode* head)
	{
		if(head == NULL)
			return head;
		ListNode* fast = head;
		ListNode* slow = head;
	    ListNode* pre = NULL;
		while(fast && fast->next)
		{
		    pre = slow;
			fast = fast->next->next;
			slow = slow->next;
		}
		pre->next = NULL;           //从中间的前一个节点断开，否则错误
		//ListNode* midNext = slow->next;
	//	slow->next = NULL;		    //从中间断开
		
		return slow;
	}
	
	ListNode* mergeSort(ListNode* head)
	{
		if(head == NULL || head->next == NULL)
			return head;
		ListNode* begin = head;
		ListNode* midNext = getMidNode(head);
		
		ListNode* left = mergeSort(begin);
		ListNode* right = mergeSort(midNext);
		return Merge(left,right);		//合并排序的链表
		
	}
	
	ListNode* Merge(ListNode* left,ListNode* right)
	{
		ListNode* dummy = new ListNode(0);
		ListNode* res = dummy;
		if(left == NULL && right != NULL)
			return right;
		if(left != NULL && right == NULL)
			return left;
		while(left && right)
		{
			if(left->val < right->val)
			{
				res->next = left;
				left = left->next;
			}
			else
			{
				res->next = right;
				right = right->next;
			}
			res = res->next;
		}
		if(left)
			res->next = left;
		else
			res->next = right;
		return dummy->next;
	}
};