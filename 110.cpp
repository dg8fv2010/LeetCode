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
    bool isBalanced(TreeNode* root) {
        if (root==NULL)
        {
        	return true;
        }

        int lh=getHeight(root->left);
        int rh=getHeight(root->right);
        if (abs(lh-rh)>1)
        {
        	return false;
        }
        if (isBalanced(root->left)==true && isBalanced(root->right)==true)
        {	
        	return true;
        }
        return false;
    }
    int getHeight(TreeNode* root)
    {
    	if (root==NULL)
    	{
    		return 0;
    	}
    	else
    	{
    		return max(getHeight(root->left), getHeight(root->right))+1;
    	}
    }
};