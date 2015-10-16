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
    string int2str(int n)
    {
        stringstream ss;
        ss<<n;
        string ret;
        ss>>ret;
        return ret;
    }
    void func(TreeNode* root, string& str, vector<string>& ans)
    {
        if (root->left==NULL && root->right==NULL)
        {
            if (str.size()!=0)
            {
                str+="->";
            }
            str+=int2str(root->val);
            ans.push_back(str);
            return ;
        }
        else
        {
            if (str.size()!=0)
            {
                str+="->";
            }
            str+=int2str(root->val);
            if (root->left!=NULL)
            {
                string strl=str;
                func(root->left, strl, ans);
            }
            if (root->right!=NULL)
            {
                string strr=str;
                func(root->right, strr, ans);
            }
            
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string str;
        vector<string> ans;
        if (root==NULL)
        {
            return ans;
        }
        func(root,str,ans);
        return ans;
    }
};