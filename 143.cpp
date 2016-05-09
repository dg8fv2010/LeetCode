/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 // 分割，反转，插入
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head==NULL || head->next==NULL || head->next->next==NULL)
        {
            return ;
        }
        
        ListNode* l1=head;
        ListNode* l2=getMid(head);
        ListNode* reverseL2=reverseList(l2);
        
		ListNode* newhead=new ListNode(-1);
        ListNode* tail=newhead;
        while (l1!=NULL && reverseL2!=NULL)
        {
			tail->next=l1;
            l1=l1->next;
			tail=tail->next;
            tail->next=reverseL2;
			tail=tail->next;
            reverseL2=reverseL2->next;
        }
       if (l1!=NULL)
       {
		   tail->next=l1;
       }
	   if (reverseL2!=NULL)
	   {
		   tail->next=reverseL2;
	   }
	   head=newhead->next;
    }
    ListNode* reverseList(ListNode* head)
    {
        if (head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode* newhead=new ListNode(-1);
        newhead->next=head;
        ListNode* pre=newhead;
        ListNode* cur=pre->next;
        ListNode* next=cur->next;
        while (next!=NULL)
        {
            cur->next=pre;
            pre=cur;
            cur=next;
            next=next->next;
        }
		cur->next=pre;
        head->next=NULL;
        return cur;
    }
    ListNode* getMid(ListNode* head)
    {
        ListNode* fast=head->next;
        ListNode* slow=head->next;
        ListNode* prev=head;
        while (true)
        {
            if (fast!=NULL)
            {
                fast=fast->next;
            }
            else
            {
                break;
            }
            if (fast!=NULL)
            {
                fast=fast->next;
            }
            else
            {
                break;
            }
            prev=slow;
            slow=slow->next;
        }
        prev->next=NULL;
        return slow;
    }
};