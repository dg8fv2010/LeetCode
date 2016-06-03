class Solution {
public:
    int longestValidParentheses(string s) {
        vector<bool> a(s.length(), false);
        stack<int> sta;
        for (int i=0;i<s.length();i++)
        {
        	if (s[i]=='(')
        	{
        		sta.push(i);
        	}
        	else if (s[i]==')' && sta.empty()==false)
        	{
        		a[i]=true;
        		a[sta.top()]=true;
        		sta.pop();
        	}
        }

        int maxLen=0;
        int curLen=0;
        for (int i=0;i<s.length();i++)
        {
        	if (a[i]==true)
        	{
        		curLen++;
        	}
        	else
        	{
        		curLen=0;
        	}
        	maxLen=max(curLen, maxLen);
        }

        return maxLen;
    }
};