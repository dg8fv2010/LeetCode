#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

// use set instead of vector
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, string> m;
        for (int i=0;i<pattern.size();i++)
        {
            m[pattern[i]]="0";
        }
        int i=0;
        vector<string> s;
        while (i<str.size())
        {
            if (str[i]!=' ')
            {
                string tmp;
                while (str[i]!=' ' && i<str.size())
                {
                    tmp+=(str[i]);
                    i++;
                }
                s.push_back(tmp);
            }
            else
            {
                 i++;
            }
        }

        if  (s.size()!=pattern.size())
        {
            return false;
        }
        for (int i=0;i<pattern.size();i++)
        {
            if (m[pattern[i]]=="0")
            {
                for (int j=0;j<i;j++)
                {
                     if (m[pattern[j]]==s[i])
                     {
                         return false;
                     }

                }
                m[pattern[i]]=s[i];
            }
             if (m[pattern[i]]!=s[i])
             {
                  return false;
             }
        }

        return true;

    }
};


int main()
{
    Solution solu;
    string s1,s2;
    s1=string("abba");
    s2=string("dog dog dog dog");
    solu.wordPattern(s1,s2);
     return 0;
}
