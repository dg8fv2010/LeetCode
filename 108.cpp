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
    TreeNode* Build(vector<int>& nums, int begin, int end)
    {
        if (begin>end)
        {
            return NULL;
        }
        int mid=begin+(end-begin)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=Build(nums, begin, mid-1);
        root->right=Build(nums, mid+1, end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
       return Build(nums, 0, nums.size()-1);
    }
};