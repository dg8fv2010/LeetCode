class Solution {
public:
	vector<vector<int> > ans;
	void Func(vector<int>& candidates, int target, vector<int>& nums, int sum, int cur)
	{
		if (sum==target)
		{
			ans.push_back(nums);
			return;
		}
		if (sum+candidates[cur]==target)
		{
			nums.push_back(candidates[cur]);
			ans.push_back(nums);
		}
		else if (sum+candidates[cur]>target)
		{
			return ;
		}
		else
		{
			for (int i=cur;i<candidates.size();i++)
			{
				vector<int> temp=nums;
				temp.push_back(candidates[i]);
				Func(candidates, target, temp, sum+candidates[i], i);
			}
		}
	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		for (int i=0;i<candidates.size();i++)
		{
			vector<int> nums;
			nums.push_back(candidates[i]);
			Func(candidates, target, nums, candidates[i], i);
		}
		return ans;
	}
};