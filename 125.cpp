#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(char c)
    {
        if (c>='A' && c<='Z')
        {
            return true;
        }
        if (c>='a' && c<='z')
        {
            return true;
        }
        if (c>='0' && c<='9')
        {
            return true;
        }
        
        return false;
    }
    bool isPalindrome(string s) {
        if (s.size()==0)
        {
            return true;
        }
        
        int i=0;
        int j=s.size()-1;
        while (i<j)
        {
            
            while (isValid(s[i])==false && i<j)
            {
                i++;
            }
            if (s[i]>='A' && s[i]<='Z')
            {
                s[i]=s[i]-'A'+'a';
            }
            
            
            while (isValid(s[j])==false && i<j)
            {
                j--;
            }
            if (s[j]>='A' && s[j]<='Z')
            {
                s[j]=s[j]-'A'+'a';
            }
            
            if (i>=j)
            {
                return true;
            }
            if (s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
           
        }
        return true;
    }
};

int main()
{
    Solution solu;
    solu.isPalindrome(string("Live on evasions? No I save no evil."));
    return 0;
}
