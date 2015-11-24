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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
       if (head==NULL) return NULL;
       ListNode* p=head;
       for (int i=1;i<m;i++)
       {
          p=p->next;
       }
       for (int i=m;i<n;i++)
       {
          ListNode* q=p;
          for (int j=i;j<n;j++)
          {
            q=q->next;
          }
          swap(p->val, q->val);
          n--;
          p=p->next;
       }
       return head;
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
       if (head==NULL) return NULL;

       ListNode* p=head;
       ListNode* q=NULL;
       for (int i=1;i<m;i++)
       {
          q=p;
          p=p->next;
       }
       ListNode* end=p;
       ListNode* pPre=p;
       p=p->next;
       for (int i=m;i<n;i++)
       {
          ListNode* pNext=p->next;
          p->next=pPre;
          pPre=p;
          p=pNext;
       }
       end->next=p;
       if (q)
       {
          q->next=pPre;
       }
       else
       {
          head=pPre;
       }
       return head;
    }
};