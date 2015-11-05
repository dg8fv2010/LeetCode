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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root==NULL)
        {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        int count=1;
        while (q.empty()==false)
        {
            int curCount=0;
            vector<int> level;
            while (count>0)
            {
                count--;
                TreeNode* node=q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left)
                {
                    q.push(node->left);
                    curCount++;
                }
                if (node->right)
                {
                    q.push(node->right);
                    curCount++;
                }
            }
            count=curCount;
            ans.push_back(level[level.size()-1]);
        }
        return ans;
    }
};

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root==NULL)
        {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (q.empty()==false)
        {
            int val=q.back()->val;
            ans.push_back(val);
            int size=q.size();
            for (int i=0;i<size();i++)
            {
                TreeNode* node=q.front();
                q.pop();
                if (node->left!=NULL)
                {
                    q.push(node->left);
                }
                if (node->right!=NULL)
                {
                    q.push(node->right);
                }
            }
        }
        return ans;
    }
};