class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n==0)
        {
            return 0;
        }
        else if (n==1)
        {
            return nums[0];
        }
        else
        {
             vector<int> maxV(n,0);
             maxV[0]=nums[0];
             maxV[1]=max(nums[0], nums[1]);
             for (int i=2;i<n;i++)
             {
                 maxV[i]=max(maxV[i-2]+nums[i], maxV[i-1]);
             }
             return maxV[n-1];
        }
    }
};
