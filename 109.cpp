/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    
    TreeNode* Func(vector<int>& v)
    {
        int s=0;
        int e=v.size()-1;
        if (s>e)
        {
            return NULL;
        }
        if (s==e)
        {
            TreeNode* node=new TreeNode(v[s]);
            return node;
        }
        int mid=s+(e-s)/2;
        TreeNode* node=new TreeNode(v[mid]);
        if (mid-1>=s)
        {
            vector<int> left(v.begin(), v.begin()+mid);
            node->left=Func(left);
        }
        if (mid+1<=e)
        {
            vector<int>right(v.begin()+mid+1, v.end());
            node->right=Func(right);
        }
        return node;
    }
    TreeNode* sortedListToBST(ListNode* head) {
       vector<int> nums;
       while (head!=NULL)
       {
            nums.push_back(head->val);
            head=head->next;
       }

       return Func(nums);
    }
};