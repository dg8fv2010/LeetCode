class Solution {
public:
	vector<vector<string> > ans;
	void func(vector<string> curList, string restStr)
	{
		if (curList.size()==3)
		{
			stringstream ss;
			ss<<restStr;
			int rest;
			ss>>rest;
			if (rest>255)
			{
				return ;
			}
			if (restStr[0]=='0' && restStr.size()>1)
			{
			    return ;
			}
			curList.push_back(restStr);
			ans.push_back(curList);
			return ;
		}

		for (int i=1;i<=3 && i<restStr.size();i++)
		{
			string tmpStr=restStr.substr(0,i);
			stringstream ss;
			ss<<tmpStr;
			int tmp;
			ss>>tmp;
			if (tmp>255)
			{
				continue ;
			}
			if (tmpStr[0]=='0' && tmpStr.size()>1)
			{
			    continue;
			}
			curList.push_back(tmpStr);
			string restStr2=restStr.substr(i);
			func(curList, restStr2);
			curList.pop_back();
		}
	}
	vector<string> restoreIpAddresses(string s) {
		vector<string> ret;
		if (s.size()<4 || s.size()>12)
		{
			return ret;
		}

		vector<string> curList;
		func(curList, s);

		for (int i=0;i<ans.size();i++)
		{
			string tmp=ans[i][0];
			for (int j=1;j<ans[i].size();j++)
			{
				tmp+=".";
				tmp+=ans[i][j];
			}
			ret.push_back(tmp);
		}

		return ret;

	}
};