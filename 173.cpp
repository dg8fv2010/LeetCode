/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> s;
    int minVal;
    BSTIterator(TreeNode *root) {
        while (root)
        {
            s.push(root);
            root=root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
       if (s.empty()==true)
       {
            return false;
       }
       TreeNode* top=s.top();
       s.pop();
       minVal=top->val;
       if (top->right)
       {
            TreeNode* node=top->right;
            while (node)
            {
                s.push(node);
                node=node->left;
            }
       }
       return true;
    }

    /** @return the next smallest number */
    int next() {
        return minVal;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

 // 最简单的方法是使用数组存储BST中序遍历的结果
 // O(1) time 并且 O(h) memory的方法是使用stack存储BST的左节点