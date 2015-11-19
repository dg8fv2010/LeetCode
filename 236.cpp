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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==NULL)
        {
            return NULL;
        }
        if (root==p || root==q)
        {
            return root;
        }
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        if (left!=NULL && right!=NULL)
        {
            return root;
        }
        else if (left!=NULL)
        {
            return left;
        }
        else
        {
            return right;
        }
    }
};
// 节点a和节点b有公共祖先c，则a和b一定分别出现在c的左右子树上



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
    void Func(TreeNode* root, vector<TreeNode*>& path, vector<TreeNode*>& pathP, vector<TreeNode*>& pathQ, TreeNode* p, TreeNode* q)
    {
        if (root==NULL)
        {
            return ;
        }
        path.push_back(root);
        if (root==p) pathP=path;
        if (root==q) pathQ=path;
        if (pathP.empty()==false && pathQ.empty()==false) return ;
        Func(root->left, path, pathP, pathQ, p, q);
        Func(root->right, path, pathP, pathQ, p, q);
        path.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path, pathP, pathQ;
        Func(root, path, pathP, pathQ, p, q);
        TreeNode* ans=root;
        int idx=0;
        while (idx<pathP.size() && idx<pathQ.size())
        {
            if (pathP[idx]!=pathQ[idx]) break;
            else ans=pathP[idx++];
        }
        return ans;
    }
};
// 记录由root到p和q的路径，再比较两条路径，找到第一个不相同的地方；