class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size()==0)
        {
          return 0;
        }
        if (haystack.size()<needle.size())
        {
          return -1;
        }
        int idx=0;
        int i=0;
        while (i<haystack.size())
        {
          if (haystack[i]==needle[0])
          {
            idx=i;
            int j=0;
            while (i<haystack.size() && j<needle.size() && haystack[i]==needle[j])
            {
              i++;
              j++;
            }
            if (j==needle.size())
            {
              return idx;
            }
            if (i>=haystack.size())
            {
              return -1;
            }
            i=idx+1;

          }
          else
          {
            i++;
          }
        }

        return -1;
    }
};