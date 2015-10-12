class Solution {
public:
	bool isIsomorphic(string s, string t) {
		map<char, char> m;
		if (s.size()!=t.size())
		{
			return false;
		}

		int i=0;
		while (i<s.size())
		{
			if (m.find(s[i])==m.end())
			{
				map<char,char>::iterator it=m.begin();
				while (it!=m.end())
				{
					if (it->second==t[i])
					{
						return false;
					}
					it++;
				}
				m[s[i]]=t[i];
			}
			else
			{
				if (m[s[i]]!=t[i])
				{
					return false;
				}
			}
			i++;
		}
		return true;
	}
};