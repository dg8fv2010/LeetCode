class Solution {
public:
	bool wordBreak(string s, unordered_set<string>& wordDict) {
		vector<bool> wordB(s.size()+1, false);
		wordB[0]=true;
		for (int i=1;i<s.size()+1;i++)
		{
			for (int j=i-1;j>=0;j--)
			{
				string temp=s.substr(j, i-j);
				if (wordB[j] && wordDict.find(temp)!=wordDict.end())
				{
					wordB[i]=true;
					break; //只要找到一种切分方式就说明长度为i的单词可以成功切分，因此可以跳出内层循环。
				}
			}
		}

		return wordB[s.size()];
	}
};
