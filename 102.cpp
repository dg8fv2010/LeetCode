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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> >ans;
        if (root==NULL)
        {
            return ans;
        }

        vector<int> line;
        int count=1;
        queue<TreeNode*> q;
        q.push(root);

        while (q.empty()==false)
        {
            line.clear();
            int level=0;
            for (int i=0;i<count;i++)
            {
                TreeNode* tmp=q.front();
                q.pop();
                line.push_back(tmp->val);

                if (tmp->left!=NULL)
                {
                    q.push(tmp->left);
                    level++;
                }
                if (tmp->right!=NULL)
                {
                    q.push(tmp->right);
                    level++;
                }
            }
            count=level;
            ans.push_back(line);
        }

        return ans;
    }
};