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
    ListNode *detectCycle(ListNode *head) {
        if (head==NULL || head->next==NULL)
        {
            return NULL;
        }
        ListNode* p=head;
        ListNode* q=head;
        int count=0;
        bool flag=false;
        while (q->next!=NULL)
        {
            count++;
            p=p->next;
            q=q->next;
            if (q->next!=NULL)
            {
                q=q->next;
            }
            else
            {
                return NULL;
            }
            if (p==q)
            {
                flag=true;
               break;
            }
        }
        if (flag==true)
        {
            p=head;
            while (p!=q)
            {
                p=p->next;
                q=q->next;
            }
            return p;
        }
        return NULL;
    }
};

// http://blog.sina.com.cn/s/blog_6f611c300101fs1l.html