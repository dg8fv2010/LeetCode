// http://www.cnblogs.com/lichen782/p/leetcode_Jump_Game_II.html
class Solution {
public:
    int jump(vector<int>& nums) {
        int ret=0;
        int cur=0;
        int last=0;
        for (int i=0;i<nums.size();i++)
        {
        	if (i>last)
        	{
        		last=cur;
        		ret++;
        	}
        	cur=max(cur, nums[i]+i);
        }

        return ret;
    }
};

// Time limit exceeded
class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if (n<=1) return 0;

        vector<int> dp(n+1, INT_MAX);
        dp[0]=0;
        for (int i=1;i<n;i++)
        {
        	for (int j=0;j<i;j++)
        	{
        		if (nums[j]+j>=i)
        		{
        			if (dp[j]+1<dp[i])
        			{
        				dp[i]=dp[j]+1;
        				break;
        			}
        		}
        	}
        }

        return dp[n-1];
    }
};