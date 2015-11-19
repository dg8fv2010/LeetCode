class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int len=nums.size()-1;
		vector<int> ans;
		if (len<0 || nums[0]>target || nums[size]<target)
		{
			ans.push_back(-1);
			ans.push_back(-1);
			return ans;
		}

		int i=0,j=size;
		while (i<=size && nums[i]<target)
		{
			i++;
		}
		while (j>=0 && nums[j]>target)
		{
			j--;
		}

		if (i<=j)
		{
			ans.push_back(i);
			ans.push_back(j);
		}
		else
		{
			ans.push_back(-1);
			ans.push_back(-1);
		}
		return ans;
	}
};



class Solution {
public:
	int Func(vector<int> nums, int target, int s, int e, bool findLeft)
	{
		if (s>e)
		{
			return -1;
		}
		int mid=s+(e-s)/2;
		if (nums[mid]==target)
		{
			int pos=-1;
			if (findLeft==true)
			{
				pos=Func(nums, target, s, mid-1, findLeft);
			}
			else
			{
				pos=Func(nums, target, mid+1, e, findLeft);
			}
			if (pos==-1)
			{
				pos=mid;
			}
			return pos;
		}
		else if (nums[mid]<target)
		{
			return Func(nums, target, mid+1, e, findLeft);
		}
		else
		{
			return Func(nums, target, s, mid-1, findLeft);
		}
	}
	vector<int> searchRange(vector<int>& nums, int target) {
	    int left=Func(nums, target, 0, nums.size()-1, true);
	    int right=Func(nums, target, 0, nums.size()-1, false);
	    vector<int> ans;
	    ans.push_back(left);
	    ans.push_back(right);
	    
	    return ans;
	}
};
