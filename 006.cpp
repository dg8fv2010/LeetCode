class Solution {
public:
    string convert(string s, int numRows) {
       if (numRows<=1 || s.length()==0)
       {
        return s;
       }

       string ans;
       int len=s.length();
       int i=0;
       while (i<len && i<numRows)
       {
        int idx=i;
        ans+=s[idx];

        for (int k=1;idx<len;k++)
        {
            if (i==0 || i==numRows-1)
            {
                idx+=2*numRows-2;
            }
            else
            {
                if (k&0x01)
                {
                    idx+=2*(numRows-1-i);
                }
                else
                {
                    idx+=2*i;
                }
            }
            if (idx<len)
            {
                ans+=s[idx];
            }
        }
        i++;
       }

       return ans;
    }
};