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
    void Func(vector<TreeNode*>& v)
    {
        if (v.size()==0)
        {
            return ;
        }
        vector<int> temp;
        vector<TreeNode*> v2;
        for (int i=0;i<v.size();i++)
        {
            temp.push_back(v[i]->val);
            if (v[i]->left) v2.push_back(v[i]->left);
            if (v[i]->right) v2.push_back(v[i]->right);
        }
        if (ans.size()%2==1)
        {
            reverse(temp.begin(), temp.end());
        }
        ans.push_back(temp);
        Func(v2);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root==NULL)
        {
            return ans;
        }
        vector<TreeNode*> v;
        v.push_back(root);
        Func(v);
        return ans;
    }
};