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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA==NULL || headB==NULL)
        {
        	return NULL;
        }

        ListNode* h1=headA;
        ListNode* h2=headB;
        int flag1=1;
        int flag2=1;
        while (headA!=NULL && headB!=NULL)
        {
        	if (headA==headB)
        	{
        		return headA;
        	}
        	headA=headA->next;
        	headB=headB->next;

        	if (headA==NULL && flag1==1)
        	{
        		headA=h2;
        		flag1=0;
        	}
        	if (headB==NULL && flag2==1)
        	{
        		headB=h1;
        		flag2=0;
        	}
        }

        return NULL;
    }
};