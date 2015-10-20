class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> ans;
		if (nums.size()==0)
		{
			return ans;
		}

		int i=0;
		if (nums.size()==1)
		{
			string str;
			stringstream ss;
			ss<<nums[i];
			string tmp;
			ss>>tmp;
			str+=tmp;
			ans.push_back(str);
			return ans;
		}

		while (i<nums.size())
		{
			string str;
			stringstream ss;
			ss<<nums[i];
			string temp;
			ss>>temp;
			ss.clear();
			str+=temp;
			int j=i+1;
			if (j<nums.size() && nums[j]-nums[i]==1)
			{
				while (j<nums.size() && nums[j]-nums[i]==1)
				{
					i++;
					j++;
				}
				str+="->";
				ss.clear();
				string temp;
				ss<<nums[i];
				ss>>temp;
				str+=temp;
				i++;
				if (j==nums.size())
				{
					ans.push_back(str);
					return ans;
				}
			}
			else
			{
				i++;
			}
			ans.push_back(str);
		}

		return ans;
	}
};
