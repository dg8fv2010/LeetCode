/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // BST的中序遍历是递增序列
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
       stack<TreeNode*> s;
       if (root==NULL)
       {
            return 0;
       }
       TreeNode* p=root;
       int cnt=1;
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
                if (cnt==k)
                {
                    return node->val;
                }
                cnt++;
                p=node->right;
            }
       }
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
 // 计算左子树的个数leftSize
 // leftSize+1>k，说明第k小的值在左子树里面
 // 否则，第k小的值在右子树里面
class Solution {
public:
    int cal(TreeNode* root)
    {
        if (root==NULL)
        {
            return 0;
        }
        return 1+cal(root->left)+cal(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        if (root==NULL)
        {
            return 0;
        }
        int leftSize=cal(root->left);
        if (leftSize+1==k)
        {
            return root->val;
        }
        else if (leftSize+1>k)
        {
            return kthSmallest(root->left, k);
        }
        else
        {
            return kthSmallest(root->right, k-leftSize-1);
        }
    }
};