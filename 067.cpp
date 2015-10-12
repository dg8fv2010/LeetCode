class Solution {
public:
	string addBinary(string a, string b) {	
		if (a.size()<b.size())
		{
			while (a.size()<b.size())
			{
				a.insert(a.begin(),'0');
			}
		}
		else
		{
			while (b.size()<a.size())
			{
				b.insert(b.begin(),'0');
			}
		}
		
		int len=a.size();
		string ans(len,'0');

		int i=len-1;
		while (i>=1)
		{
			ans[i]+=a[i]-'0'+b[i]-'0';
			if (ans[i]=='2')
			{
				ans[i]='0';
				ans[i-1]++;
			}
			else if (ans[i]=='3')
			{
				ans[i]='1';
				ans[i-1]++;
			}
			i--;
		}

		ans[0]+=a[0]-'0'+b[0]-'0';
		if (ans[0]=='2')
		{
			ans[0]='0';
			ans.insert(ans.begin(),'1');
		}
		else if (ans[0]=='3')
		{
			ans[0]='1';
			ans.insert(ans.begin(),'1');
		}
		
		return ans;
	}
};