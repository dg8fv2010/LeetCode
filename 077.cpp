class Solution {
public:
	vector<vector<int> > ans;
	void Func(vector<int>& nums, int cur, int n, int k)
	{
		if (nums.size()==k)
		{
			ans.push_back(nums);
		}
		for (int i=cur;i<=n;i++)
		{
			vector<int> temp;
			temp=nums;
			temp.push_back(i);
			Func(temp, i+1, n, k);
		}
	}
	vector<vector<int>> combine(int n, int k) {
		for (int i=0;i<n;i++)
		{
			vector<int> nums;
			nums.push_back(i+1);
			Func(nums, i+2, n, k);
		}
		return ans;
	}
};