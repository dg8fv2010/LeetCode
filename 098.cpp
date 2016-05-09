/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 // 直接中序遍历即可
class Solution {
public:
    vector<int> v;
    bool isValidBST(TreeNode* root) {
        if (root==NULL)
        {
            return true;
        }
        
        inOrderTraversal(root);
        for (int i=1;i<v.size();i++)
        {
            if (v[i]<=v[i-1])
            {
                return false;
            }
        }
        
        return true;
    }
    void inOrderTraversal(TreeNode* root)
    {
        if (root==NULL)
        {
            return ;
        }
        inOrderTraversal(root->left);
        v.push_back(root->val);
        inOrderTraversal(root->right);
    }
    
    
};