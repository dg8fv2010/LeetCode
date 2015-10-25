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
    void pre(TreeNode* root)
    {
        if (root==NULL)
        {
            return ;
        }
        ans.push_back(root->val);
        if (root->left)
        {
            pre(root->left);
        }
        if (root->right)
        {
            pre(root->right);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        if (root==NULL)
        {
            return ans;
        }
        pre(root);
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root==NULL)
        {
            return ans;
        }
       stack<TreeNode*> s;
       s.push(root);
       while (s.empty()==false)
       {
           TreeNode* node=s.top();
           s.pop();
           ans.push_back(node->val);
           if (node->right)
           {
               s.push(node->right);
           }
           if (node->left)
           {
               s.push(node->left);
           }
       }
       return ans;
    }
};