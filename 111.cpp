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
    int minDepth(TreeNode* root) {
       if (root==NULL)
       {
        return 0;
       }
       if (root->left==NULL && root->right==NULL)
       {
        return 1;
       }
       else
       {
        int min1=9999;
        int min2=9999;
        if (root->left!=NULL)
        {
            min1=minDepth(root->left);
        }
        if (root->right!=NULL)
        {
            min2=minDepth(root->right);
        }
        return min(min1,min2)+1;
       }
    }
};