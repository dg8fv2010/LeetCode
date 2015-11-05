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
    ListNode* swapPairs(ListNode* head) {
     if (head==NULL || head->next==NULL)
     {
        return head;
     }
     ListNode* temp=head->next;
     head->next=swapPairs(temp->next);
     temp->next=head;
     return temp;
    }
};  


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
    ListNode* swapPairs(ListNode* head) {
      if (head==NULL || head->next==NULL)
      {
            return head;
      }

      ListNode* p=head;
      ListNode* pre=NULL;
      ListNode* prepre=NULL;
      while (p!=NULL && p->next!=NULL)
      {
            pre=p;
            p=p->next;
            ListNode* next=p->next;
            if (pre==head)
            {
                head=p;
            }
            if (prepre!=NULL)
            {
                prepre->next=p;
            }
            p->next=pre;
            pre->next=next;
            prepre=pre;
            p=next;
      }
      return head;
    }
};