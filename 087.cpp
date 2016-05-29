class Solution {
public:
    bool isScramble(string s1, string s2) {
        int len1=s1.length();
        int len2=s2.length();
        if (len1!=len2) return false;
        if (len1==1) return s1==s2;
        string ss1=s1;
        string ss2=s2;
        sort(ss1.begin(), ss1.end());
        sort(ss2.begin(), ss2.end());
        if (ss1!=ss2) return false;
        
        bool ret=false;
        for (int i=1;i<len1&&ret==false;i++)
        {
            string s11=s1.substr(0,i);
            string s12=s1.substr(i,len1-i);
            string s21=s2.substr(0,i);
            string s22=s2.substr(i,len1-i);
            ret=isScramble(s11,s21)&&isScramble(s12,s22);
            if (ret==false)
            {
                s21=s2.substr(0,len1-i);
                s22=s2.substr(len1-i,i);
                ret=isScramble(s11,s22)&&isScramble(s12,s21);
            }
        }
        return ret;
    }
};