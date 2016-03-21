class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1=="0" || num2=="0")
		{
			return "0";
		}
		 
		int size1=num1.size();
		int size2=num2.size();
		if (size1<size2)
		{
			string tmp=num2;
			num2=num1;
			num1=tmp;
		}

		vector<string> ret;
		int count=0;
		for (int i=num2.size()-1;i>=0;i--)
		{
			string tmp;
			int a=0,b=0;
			for (int j=num1.size()-1;j>=0;j--)
			{
				int mul=(num1[j]-'0')*(num2[i]-'0');
				mul+=a;
				a=mul/10;
				b=mul%10;
				tmp.push_back('0'+b);
			}
			if (a!=0)
			{
				tmp.push_back('0'+a);
			}
			reverse(tmp.begin(), tmp.end());
			for (int j=0;j<count;j++)
			{
				tmp.push_back('0');
			}
			count++;
			ret.push_back(tmp);
		}

		for (int i=0;i<ret.size()-1;i++)
		{
			while (ret[i].size()<ret[ret.size()-1].size())
			{
				ret[i].insert(ret[i].begin(), '0');
			}
		}
		string ans;
		int a=0,b=0;
		for (int i=ret[0].size()-1;i>=0;i--)
		{		
			int conutTmp=0;
			for (int j=0;j<ret.size();j++)
			{
				int tmp=(ret[j][i]-'0');
				conutTmp+=tmp;	
			}
			conutTmp+=a;
			a=conutTmp/10;
			b=conutTmp%10;	
			ans.push_back('0'+b);
		}
		if (a!=0)
		{
			ans.push_back('0'+a);
		}
		reverse(ans.begin(), ans.end());
		
		return ans;

	}
};


class Solution2 {
public:
	string multiply(string num1, string num2) {
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());

		if (("0" == num1) || ("0" == num2)) 
		{
			return "0";
		}

		string result = "";
		int i, j;
		int flag = 0, steps = 0;

		for (int i = 0; i < num1.length(); ++i) 
		{
			int position = steps;

			for (int j = 0; j < num2.length(); ++j) 
			{
				int v = (num1[i] - '0') * (num2[j] - '0') + flag;

				if (position < result.length()) 
				{
					v += result[position] - '0';
					result[position] = (v % 10) + '0';
				}
				else 
				{
					result.append(1, (v % 10) + '0');
				}

				flag = v / 10;
				++position;
			}

			if (flag > 0) 
			{
				result.append(1, flag + '0');
			}

			flag = 0;
			++steps;
		}

		reverse(result.begin(), result.end());

		return result;
	}
};