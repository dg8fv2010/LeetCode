class Solution {
public:
    int numDistinct(string s, string t) {
        int **dp=new int*[s.length()+1];
        for (int i=0;i<s.length()+1;i++)
        {
            dp[i]=new int[t.length()+1];
        }

        dp[0][0]=1;
        for (int i=1;i<=s.length();i++)
        {
            dp[i][0]=1;
        }
        for (int j=1;j<=t.length();j++)
        {
            dp[0][j]=0;
        }

        for (int i=1;i<=s.length();i++)
        {
            for (int j=1;j<=t.length();j++)
            {
                dp[i][j]=dp[i-1][j];
                if (s[i-1]==t[j-1])
                {
                    dp[i][j]+=dp[i-1][j-1];
                }
            }
        }

        return dp[s.length()][t.length()];
        
    }
};