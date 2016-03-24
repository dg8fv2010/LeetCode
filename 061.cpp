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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        
        ListNode* temp=head;
        int count=0;
        while (temp!=NULL)
        {
            temp=temp->next;
            count++;
        }
        count=k%count;
        
        ListNode* h=head;
        while (count--)
        {
            ListNode* p=h;
            ListNode* q=h;
            ListNode* pre=h;
            q=q->next;
            while (q->next!=NULL)
            {
                q=q->next;
                pre=pre->next;
            }
            q->next=p;
            pre->next=NULL;
            h=q;
        }
        return h;
    }
};