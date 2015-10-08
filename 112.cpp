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
	bool add(TreeNode* root, int sum)
	{
		if (root->left==NULL && root->right==NULL)
		{
			if (root->val==sum)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			sum-=root>val;
			if (root->left==NULL)
			{
				if (add(root->left,sum)==true)
				{
					return true;
				}
			}
			if (root->right!=NULL)
			{
				if (add(root->right,sum)==true)
				{
					return true;
				}
			}
			return false;
		}
	}
	 bool hasPathSum(TreeNode* root, int sum) {
       if (root==NULL)
       {
       	return false;
       }
       else
       	{
       		return add	(root, sum);
       	}
    }
};