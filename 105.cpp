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
    TreeNode* Func(vector<int>& preorder, int preBeg, int preEnd, vector<int>& inorder, int inBeg, int inEnd)
    {
        if (preorder.size()==0)
        {
            return NULL;
        }
        if (inBeg>inEnd)
        {
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[preBeg]);
        int idx=0;
        for (int i=inBeg;i<=inEnd;i++)
        {
            if (inorder[i]==root->val)
            {
                idx=i;
                break;
            }
        }
        int len=idx-inBeg;
        root->left=Func(preorder, preBeg+1, preBeg+len, inorder, inBeg, idx-1);
        root->right=Func(preorder, preBeg+1+len, preEnd, inorder, idx+1, inEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return Func(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};