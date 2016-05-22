/*
每次对于当前的字符判断是否属于1-9（0肯定不行，因为0不在1-26中），如果属于，那么当前的字符可以被decode，并且和f[n-1]组合，f[n] += f[n-1]
然后对于当前字符和前一个字符组成的字符串判断是否属于10-26，如果属于，那么这两个字符可以被decode，并且和f[n-2]组合，f[n] += f[n-2]
*/

class Solution {
public:
    int numDecodings(string s) {
        if (s=="")
        {
            return 0;
        }

        vector<int> f;
        f.resize(s.length());
        int i=0;
        while (i<s.length())
        {
            f[i]=0;
            if (i>=1)
            {
                string tmp(s, i-1, 2);
                if (tmp>="10" && tmp<="26")
                {
                    if (i>1)
                    {
                        f[i]+=f[i-2];
                    }
                    else
                    {
                        f[i]+=1;
                    }
                }
                if (s[i]>='1' && s[i]<='9')
                {
                    f[i]+=f[i-1];
                }
            }
            else
            {
                if (s[i]>='1' && s[i]<='9')
                {
                    f[i]=1;
                }
            }
            i++;
        }

        return f[i-1];
    }
};