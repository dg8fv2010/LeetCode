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
    vector<int> ans;
    void Func(TreeNode* root, int sum)
    {
        if (root==NULL)
        {
            ans.push_back(sum);
            return ;
        }
        sum=sum*10+root->val;
        if (root->left==NULL && root->right==NULL)
        {
            ans.push_back(sum);
        }
        if (root->left!=NULL)
        {
            Func(root->left, sum);
        }
        if (root->right)
        {
            Func(root->right, sum);
        }
    }
    int sumNumbers(TreeNode* root) {
        int sum=0;
        Func(root, sum);
        for (int i=0;i<ans.size();i++)
        {
            sum+=ans[i];
        }
        return sum;
    }
};