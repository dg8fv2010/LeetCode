class Solution {
public:
  map<int, int> m;
    int majorityElement(vector<int>& nums) {
        int temp=0;
        if (nums.size()%2==0)
        {
            temp=nums.size()/2;
        }
        else
        {
            temp=(nums.size()+1)/2;
        }
        for (int i=0;i<nums.size();i++)
        {
        	m[nums[i]]++;
        	if (m[nums[i]]>=temp)
        	{
        		return nums[i];
        	}
        }
    }
};