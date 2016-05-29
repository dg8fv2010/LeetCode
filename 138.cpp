// 首先指向在原链表的每个节点后面，复制一个新的节点，原链表长度变为 2 倍
// 将链表拆成两个 lists
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode* tHead=head;
        RandomListNode* next=NULL;
        while (tHead)
        {
            RandomListNode* node=new RandomListNode(tHead->label);
            next=tHead->next;
            tHead->next=node;
            node->next=next;
            tHead=next;
        }
        
        tHead=head;
        while (tHead)
        {
            if (tHead->random)
            {
                tHead->next->random=tHead->random->next; //  copy random
            }
            tHead=tHead->next->next;
        }
        
        RandomListNode* retHead=NULL;
        RandomListNode* tRet=NULL;
        tHead=head;
        RandomListNode* next2=NULL;
        while (tHead)
        {
            if (retHead==NULL)
            {
                retHead=tHead->next;
                tRet=retHead;
                next2=tHead->next->next;
                tHead->next=next2;
                tHead=next2;
            }
            else
            {
                next2=tHead->next->next;
                tRet->next=tHead->next;
                tRet=tRet->next;
                tHead->next=next2;
                tHead=next2;
            }
        }
        
        return retHead;
    }
};