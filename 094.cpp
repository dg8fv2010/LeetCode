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
    void inorder(TreeNode* root)
    {
        if (root==NULL)
        {
            return ;
        }
        if (root->left)
        {
            inorder(root->left);
        }
        ans.push_back(root->val);
        if (root->right)
        {
            inorder(root->right);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if (root==NULL)
        {
            return ans;
        }
        inorder(root);
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
   vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root==NULL)
        {
            return ans;
        }

        stack<TreeNode*> s;
        TreeNode* p=root;
        while (s.empty()==false || p!=NULL)
        {
            if (p!=NULL)
            {
                s.push(p);
                p=p->left;
            }
            else
            {
                p=s.top();
                s.pop();
                ans.push_back(p->val);
                p=p->right;
            }
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
    vector<int> ans;
   vector<int> inorderTraversal(TreeNode* root) {
       vector<int> ans;
       if (root==NULL)
       {
            return ans;
       }

       stack<TreeNode*> s;
       TreeNode* p=root;
       while (s.empty()==false || p!=NULL)
       {
            if (p!=NULL)
            {
                s.push(p);
                p=p->left;
            }
            else
            {
                TreeNode* node=s.top();
                s.pop();
                ans.push_back(node->val);
                p=node->right;
            }
       }
       return ans;
    }
};