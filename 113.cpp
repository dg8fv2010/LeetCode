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
    vector<vector<int> > ans;
    void Func(TreeNode* root, int curSum, int sum, vector<int> v)
    {
        if (root->left==NULL && root->right==NULL)
        {
            curSum+=root->val;
            if (curSum==sum)
            {
                v.push_back(root->val);
                ans.push_back(v);
            }
            return ;
        }
        else
        {
            curSum+=root->val;
            v.push_back(root->val);
            if (root->left!=NULL)
            {
                Func(root->left, curSum, sum, v);
            }
            if (root->right!=NULL)
            {
                Func(root->right, curSum, sum, v);
            }
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root==NULL)
        {
            return ans;
        }

        Func(root, 0, sum, vector<int>());
        return ans;
    }
};