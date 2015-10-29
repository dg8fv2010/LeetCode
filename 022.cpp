class Solution {
public:
    vector<string> ans;
    void Func(string& str, int l, int r)
    {
    	if (l==0 && r==0)
    	{
    		ans.push_back(str);
    	}
    	if (l>0)
    	{
    		string temp=str+'(';
    		Func(temp, l-1, r);
    	}
    	if (r>l && r>0)
    	{
    		string temp=str+')';
			Func(temp, l, r-1);
    	}
    }
	vector<string> generateParenthesis(int n) {
		string str;
		Func(str, n, n);
		return ans;
	}
};