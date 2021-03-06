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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode* pre=NULL;
      ListNode* p=head;
      ListNode* q=head;

      for (int i=0;i<n-1;i++)
      {
        q=q->next;
      }
      while (q->next)
      {
        pre=p;
        p=p->next;
        q=q->next;
      }

      if (pre==NULL)
      {
        head=p->next;
        delete p;
      }
      else
      {
        pre->next=p->next;
        delete p;
      }
      return head;
    }
};