class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int i=1;
		int count=0;
		while (i<nums.size())
		{
			if (nums[i-1]==nums[i])
			{
				count++;

				while (count>=2)
				{
					nums.erase(nums.begin()+i-1);
					count--;
					i--;
				}
				i++;
			}
			else
			{
				count=0;
				i++;
			}
		}
		return nums.size();
	}
};