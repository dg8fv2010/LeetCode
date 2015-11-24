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

// 只需要时刻计算前位置和当前位置所能跳的最远长度,并始终和n作比较就可以