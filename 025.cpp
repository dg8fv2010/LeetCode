/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct Node
{
	ListNode* begin;
	ListNode* end;
	Node(ListNode* begin, ListNode* end):begin(begin),end(end){}
};
class Solution {
public:
	Node reverse(ListNode* begin, ListNode* end)
	{
		ListNode* pPre=NULL;
		ListNode* p=begin;
		while (p!=end)
		{
			ListNode* q=p->next;
			p->next=pPre;
			pPre=p;
			p=q;
		}
		p->next=pPre;
		return Node(end, begin);
	}
    ListNode* reverseKGroup(ListNode* head, int k) {
    	if (head==NULL) return head;

    	ListNode* pPre=NULL;
    	ListNode* p=head;
    	while (p)
    	{
    		ListNode* q=p;
    		for (int i=0;i<k-1;i++)
    		{
    			q=q->next;
    			if (q==NULL) return head;
    		}
    		ListNode* qNext=q->next;
    		Node ret=reverse(p, q);

    		if (pPre)
    		{
    			pPre->next=ret.begin;
    		}
    		else
    		{
    			head=ret.begin;
    		}
    		p->next=qNext;
    		pPre=p;
    		p=qNext;
    	}
    	return head;
    }
};