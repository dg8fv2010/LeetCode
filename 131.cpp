class Solution {
public:
    bool isPalindrome(string str)
    {
        int i=0;
        int j=str.size()-1;
        while (i<j)
        {
            if (str[i]!=str[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void Func(vector<vector<string> >& ans, vector<string>& v, string str)
    {
        if (str.size()==0)
        {
            ans.push_back(v);
        }
        int len=str.size();
        for (int i=1;i<=len;i++)
        {
            string subStr=str.substr(0, i);
            if (isPalindrome(subStr)==true)
            {
                v.push_back(subStr);
                string restSubStr=str.substr(i);
                Func(ans, v, restSubStr);
                v.pop_back();
            }
        }
    }
	vector<vector<string>> partition(string s) {
		vector<vector<string> > ans;
        vector<string> v;
        if (s.size()==0)
        {
            return ans;
        }
        Func(ans, v, s);
        return ans;
	}
};