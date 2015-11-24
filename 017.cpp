class Solution {
public:
	vector<string> ans;
	void Func(string strT[], string& digits, int curIdx, string curStr)
	{
		if (curIdx==digits.size() && curIdx==curStr.size())
		{
			ans.push_back(curStr);
			return ;
		}
		for (int i=curIdx;i<digits.size();i++)
		{
			int idx=digits[curIdx]-'0';
			for (int j=0;j<strT[idx].size();j++)
			{
				string strTemp=curStr;
				strTemp+=strT[idx][j];
				Func(strT, digits, i+1, strTemp);
			}
		}
	}
	vector<string> letterCombinations(string digits) {
		if (digits.size()==0)
		{
			return ans;
		}
		string strT[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
		Func(strT, digits, 0, string());
		return ans;
	}
};