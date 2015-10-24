class Solution {
public:
    void convert(string ver, vector<int>& s1)
    {
       for (int i=0;i<ver.size();i++)
       {
           string ret;
           if (ver[i]!='.')
           {
               while (i<ver.size() && ver[i]!='.')
               {
                   ret+=ver[i];
                   i++;
               }
               stringstream ss;
               ss<<ret;
               int temp;
               ss>>temp;
               s1.push_back(temp);
           }
           else
           {
               i++;
           }
       }
        
    }
    int compareVersion(string version1, string version2) {
       vector<int> s1;
       vector<int> s2;
       convert(version1, s1);
       convert(version2, s2);
       int i=0,j=0;
       while (s1.size()<s2.size())
       {
           s1.push_back(0);
       }
        while (s1.size()>s2.size())
       {
           s2.push_back(0);
       }
       while (i<s1.size() && j<s2.size())
       {
           if (s1[i]>s2[j])
           {
               return 1;
           }
           else if (s1[i]<s2[j])
           {
               return -1;
           }
           else
           {
               i++;
               j++;
           }
       }
       return 0;
       
    }

};