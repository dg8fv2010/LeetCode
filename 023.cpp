/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 以借鉴归并排序的方法，自顶向下，先递归的对链表的前半部分和后半部分进行归并排序，最后再merge
class Solution {
public:
    ListNode* merge2List(ListNode* l1, ListNode* l2)
    {
    	ListNode* head=new ListNode(-1);
    	ListNode* cur=head;
    	while (l1!=NULL && l2!=NULL)
    	{
    		if (l1->val < l2->val)
    		{
    			cur->next=l1;
    			l1=l1->next;
    		}
    		else
    		{
    			cur->next=l2;
    			l2=l2->next;
    		}
    		cur=cur->next;
    	}
    	if (l1!=NULL)
    	{
    		cur->next=l1;
    	}
    	else
    	{
    		cur->next=l2;
    	}
    	return head->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size()==0) return NULL;
        if (lists.size()==1) return lists[0];

        int size=lists.size();
        int mid=(size)/2;
        vector<ListNode*> l11 = vector<ListNode*>(lists.begin(), lists.begin()+mid);
        ListNode* l1=mergeKLists(l11);
        vector<ListNode*> l22 = vector<ListNode*>(lists.begin()+mid, lists.end());
        ListNode* l2=mergeKLists(l22);

        ListNode* ret = merge2List(l1, l2);
        return ret;
    }
};