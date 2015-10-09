class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int i=n-1;
        int count=0;
        while (i>=0)
        {
            if (s[i]!=' ')
            {
                while (s[i]!=' ' && i>=0)
                {
                    count++;
                    i--;
                }
                return count;
            }
            else
            {
                i--;
            }
        }
        
        return count;
    }
};