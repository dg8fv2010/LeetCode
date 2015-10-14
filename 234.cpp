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
    bool isPalindrome(ListNode* head) {
       if (head==NULL || head->next==NULL)
       {
        return true;
       }
       ListNode* mid=getMid(head);
       ListNode* h1=reverse(mid);
       while (head && h1)
       {
        if (head->val != h1->val)
        {
          return false;
        }
        head=head->next;
        h1=h1->next;
       }

       return true;
    }
    ListNode* getMid(ListNode* head)
    {
      ListNode* preSlow=NULL;
      ListNode* slow=head;
      ListNode* fast=head;
      do 
      {
        fast=fast->next;
        if (fast)
        {
          fast=fast->next;
          preSlow=slow;
          slow=slow->next;
        }
      } while (fast!=NULL);

      preSlow->next=NULL;
      return slow;
    }
    ListNode* reverse(ListNode* head)
    {
      if (head==NULL || head->next==NULL)
      {
        return head;
      }
      else if (head->next->next==NULL)
      {
        ListNode* h1=head;
        ListNode* h2=head->next;
        h1->next=NULL;
        h2->next=h1;
        return h2;
      }
      else
      {
        ListNode* pre=head;
        ListNode* cur=pre->next;
        ListNode* post=cur->next;
        pre->next=NULL;
        while (post)
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