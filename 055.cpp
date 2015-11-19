class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size()==0 || nums.size()==1)
        {
            return true;
        }

        int maxStep=nums[0];
        for (int i=1;i<nums.size();i++)
        {
            if (maxStep==0) return false;
            maxStep--;
            maxStep=max(maxStep, nums[i]);
            if (maxStep+i>=nums.size()-1)
            {
                return true;
            }
        }

        return false;
    }
};