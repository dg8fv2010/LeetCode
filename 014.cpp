class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string ans;
		int len=0;
		if (strs.size()==0)
		{
			return ans;
		}

		while (1)
		{
			if (len>=ans[0].size())
			{
				return ans;
			}
			ans+=strs[0][len];
			for (int i=0;i<strs.size();i++)
			{
				if (len<strs[i].size())
				{
					if (ans[len]!=strs[i][len])
					{
						return string(ans.begin(), ans.begin()+len);
					}
				}
				else
				{
					return string(ans.begin(), ans.begin()+len);
				}
			}
			len++;
		}

	}
};
