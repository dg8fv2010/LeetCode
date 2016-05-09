/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 // 通常而言，也就是针对数组而言，归并排序的空间复杂度为O(N), 你需要开出O(N)的额外空间来容纳数组，来表示归并后的顺序。
 // 但是，对于链表而言，你可以省下这部分空间的开销，你只需要改变节点的next指针的指向，就可以表示新的归并后的顺序了，
 // 所以空间复杂度陡然降到了O(1)。
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head==NULL || head->next==NULL)
        {
            return head;
        }
        
        ListNode* head1=head;
        ListNode* head2=getMid(head);
        head1=sortList(head1);
        head2=sortList(head2);

        return merge(head1, head2);
    }

    ListNode* merge(ListNode* head1, ListNode* head2)
    {
    	ListNode* newhead=new ListNode(-1);
    	ListNode* newtail=newhead;
    	while (head1!=NULL && head2!=NULL)
    	{
    		if (head1->val <= head2->val)
    		{
    			newtail->next=head1;
    			head1=head1->next;
    		}
    		else
    		{
    			newtail->next=head2;
    			head2=head2->next;
    		}
    		newtail=newtail->next;
    		newtail->next=NULL;
    	}
    	if (head1!=NULL)
    	{
    		newtail->next=head1;
    	}
    	if (head2!=NULL)
    	{
    		newtail->next=head2;
    	}
    	return newtail->next;
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