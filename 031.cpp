class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size=nums.size()-1;
        for (int i=size-1;i>=0;i--)
        {
            if (nums[i+1]>nums[i])
            {
                int j=0;
                for (j=size;j>=i-1;j--)
                {
                    if (nums[j]>nums[i])
                    {
                        break;
                    }
                }
                swap(nums[i], nums[j]);
                reverse(nums.begin()+i+1, nums.end());
                return ;
            }
        }

        reverse(nums.begin(), nums.end());
        return ;
    }
};
