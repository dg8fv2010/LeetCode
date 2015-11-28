class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string> > ans;
		if (strs.size()==0)
		{
			return ans;
		}

		map<string, vector<string> > m;
		for (int i=0;i<strs.size();i++)
		{
			string temp=strs[i];
			sort(temp.begin(), temp.end());
			m[temp].push_back(strs[i]);
		}

		map<string, vector<string> >::iterator it=m.begin();
		while (it!=m.end())
		{
			ans.push_back(it->second);
			int size=ans.size()-1;
			sort(ans[size].begin(), ans[size].end());
			it++;
		}

		return ans;
	}
};
