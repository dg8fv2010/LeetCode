#include<iostream>

using namespace std;

struct TreeNode {
 int val;
 TreeNode *left;
 TreeNode *right;
 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==NULL)
        {
            return NULL;
        }
        if (p!=NULL && q==NULL)
        {
            return NULL;
        }
        if (p==NULL && q!=NULL)
        {
            return NULL;
        }
        // Error
     /*   if (p->left->val==q->val || p->right->val==q->val)
        {
             return p;
        }
        if (q->left->val==p->val || q->right->val==p->val)
        {
             return q;
        }*/
        if (q->val<root->val && p->val>root->val)
        {
             return root;
        }
        if (q->val<root->val && p->val>root->val)
        {
             return root;
        }
        if (q->val<root->val && p->val<root->val)
        {
            return lowestCommonAncestor(root->left,p,q);
        }
        if (q->val>root->val && p->val>root->val)
        {
            return lowestCommonAncestor(root->right,p,q);
        }

    }
};
