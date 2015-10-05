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
    ListNode* reverseList(ListNode* head) {
    	   if (head==NULL || head->next==NULL)
    	   {
    	   		return head;
    	   }
    	   ListNode* ans=head;
    	   while (ans->next!=NULL)
    	   {
    	   		ans=nas->next;
    	   }
    	   reverse(head);
    	   return ans;
    }
    ListNode* reverse(ListNode* head)
    {
    	if (head->next==NULL)
    	{
    		return head;
    	}
    	else
    	{
    		ListNode* tail=reverse(head->next);
    		tail->next=head;
    		tail=tail->next;
    		tail->next=NULL;
    		return tail;
    	}
    }
};

class Solution
{
public:
	ListNode* reverseList(ListNode* head)
	{
		if (head==NULL || head->next==NULL)
		{
			return head;
		}
		if (head->next->next==NULL)
		{
			ListNode* newHead=head;
			newHead->next=head;
			head->next=NULL;
			return newHead;
		}
		else
		{
			ListNode* pre=head;
			ListNode* cur=pre->next;
			ListNode* post=cur->next;
			pre->next=NULL;
			while (post!=NULL)
			{
				cur->next=pre;
				pre=cur;
				cur=post;
				post=post->next;
			}
			cur->next=pre;
			return cur;
		}
	}
};