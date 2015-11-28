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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* pre=dummy;
        ListNode* p=pre->next;
        ListNode* q=p->next;
        while (q!=NULL)
        {
            if (p->val!=q->val)
            {
                pre=pre->next;
                p=p->next;
                q=q->next;
            }
            else
            {
                while (q!=NULL && p->val==q->val)
                {
                    q=q->next;
                }
                p=q;
                pre->next=p;
                if (p==NULL)
                {
                    q=NULL;
                }
                else
                {
                    q=p->next;
                }
            }
        }

        return dummy->next;
    }
};