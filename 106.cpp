/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* Func(vector<int>& inorder, int inBeg, int inEnd, vector<int>& postorder, int postBeg, int postEnd)
    {
        if (inBeg>inEnd)
        {
            return NULL;
        }

        TreeNode* root=new TreeNode(postorder[postEnd]);

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
        root->left=Func(inorder, inBeg, idx-1, postorder, postBeg, postBeg+len-1);
        root->right=Func(inorder, idx+1, inEnd, postorder, postBeg+len, postEnd-1);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return Func(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
   
};