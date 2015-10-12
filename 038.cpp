class Solution {
public:
    string HelpFunc(string s)
    {
       string ans;
       int count=1;
       char pre=s[0];
       for (int i=1;i<s.size();i++)
       {
        if (pre==s[i])
        {
            count++;
        }
        else
        {
            char temp=count+'0';
            ans=ans+temp+pre;
            pre=s[i];
            count=1;
        }
       }
        char temp=count+'0';
        ans=ans+temp+pre;
        return ans;
    }
    string countAndSay(int n) {
       string ans("1");

       for (int i=1;i<n;i++)
       {
        ans=HelpFunc(ans);
       }
       return ans;
    }
};