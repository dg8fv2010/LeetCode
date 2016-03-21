class Solution {
public:
	string longestPalindrome(string s) {
		int n=s.size();
		////////////////////////////////
		// 用vector会超时
		////////////////////////////////
		//vector<bool> tmp(n+1,false);
		//vector<vector<bool> > table;
		//for (int i=0;i<n+1;i++)
		//{
		//	table.push_back(tmp);
		//	table[i][i]=true;
		//}

		bool table[1000][1000]={false};
		for (int i=0;i<n;i++)
		{
			table[i][i]=true;
		}

		int start=0;
		int maxLen=1;
		for (int i=0;i<n-1;i++)
		{
			if (s[i]==s[i+1])
			{
				table[i][i+1]=true;
				maxLen=2;
				start=i;
			}
		}

		for (int len=3;len<=n;len++)
		{
			for (int i=0;i<n-len+1;i++)
			{
				int j=i+len-1;
				if (s[i]==s[j] && table[i+1][j-1]==true)
				{
					table[i][j]=true;
					maxLen=len;
					start=i;
				}
			}
		}

		return s.substr(start, maxLen);
	}
};
