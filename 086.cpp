
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
    ListNode* partition(ListNode* head, int x) {
       ListNode* large=new ListNode(0);
       ListNode* small=new ListNode(0);
       ListNode* a=small;
       ListNode* b=large;

       while (head!=NULL)
       {
       		if (head->val < x)
       		{
       			small->next=head;
       			small=head;
       		}
       		else
       		{
       			large->next=head;
       			large=head;
       		}
       		head=head->next;
       }

       large->next=NULL;
       small->next=b->next;
       return a->next;
    }
};