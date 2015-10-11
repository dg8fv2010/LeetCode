#include <iostream>

using namespace std;


struct ListNode {
 int val;
 ListNode *next;
 ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head==NULL)
        {
            return NULL;
        }
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* p=dummy;
        ListNode* q=head;
        while (q!=NULL)
        {
             if (q->val==val)
             {
                 p->next=q->next;
             }
             else
             {
                  p=p->next;
             }
             q=q->next;
        }
        return dummy->next;
    }
};

int main()
{
    ListNode* p=new ListNode(1);
    Solution solu;
    solu.removeElements(p,1);
     return 0;
}
