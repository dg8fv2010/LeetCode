// 因为是一个环，所以抢了第一家就不能抢第二家了
// 需要抢两次
// 第一次抢，从第一个开始，到倒数第二个结束
// 第二次抢，从第二个开始，到最后一个结束
class Solution {
public:
    int rob(vector<int>& nums) {
        int size=nums.size();
        if (size==0)
        {
            return 0;
        }
        else if (size==1)
        {
            return nums[0];
        }
        else
        {
            vector<int> dp(size);
            dp[0]=nums[0];
            for (int i=1;i<size-1;i++)
            {
                dp[i]=max(dp[i-1], (i==1?0:dp[i-2])+nums[i]);
            }
            int res=dp[size-2];

            dp[1]=nums[1];
            for (int i=2;i<size;i++)
            {
                dp[i]=max(dp[i-1], (i==2?0:dp[i-2])+nums[i]);
            }

            return max(res, dp[size-1]);
        }
    }
};