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
    vector<TreeNode*> Func(int s, int e)
    {
        vector<TreeNode*> ans;
        if (s>e)
        {
            ans.push_back(NULL);
            return ans;
        }

        for (int i=s;i<=e;i++)
        {
            vector<TreeNode*> left=Func(s,i-1);
            vector<TreeNode*> right=Func(i+1,e);
            for (int j=0;j<left.size();j++)
            {
                for (int k=0;k<right.size();k++)
                {
                    TreeNode* node=new TreeNode(i);
                    node->left=left[j];
                    node->right=right[k];
                    ans.push_back(node);
                }
            }
        }

        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return Func(1, n);
    }
};