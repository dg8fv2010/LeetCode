class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int start=0;
        int end=0;
        int sum=0;
        int minL=nums.size();
        bool flag=false;

        while (start<nums.size() && end<nums.size())
        {
            while (sum<s && end<nums.size())
            {
                sum += nums[end++];
            }
            while (sum>=s && start<=end)
            {
                flag = true;
                minL = min(minL, end-start);
                sum -=nums[start++];
            }
        }

        if (flag == true)
        {
            return minL;
        }
        else
        {
            return 0;
        }
    }
};