
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	TreeNode* p;
	TreeNode* q;
	TreeNode* pre;
    void recoverTree(TreeNode* root) {
        p=q=pre=NULL;
        inorder(root);
        swap(p->val, q->val);
    }

    void inorder(TreeNode* root)
    {
    	if (root->left)
    	{
    		inorder(root->left);
    	}
    	if (pre!=NULL && pre->val>root->val)
    	{
    		if (p==NULL)
    		{
    			p=pre;
    		}
    		q=root;
    	}
    	pre=root;
    	if (root->right)
    	{
    		inorder(root->right);
    	}
    }
};