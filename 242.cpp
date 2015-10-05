class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size()!=t.size())
        {
        	return	false;
        }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for (int i = 0; i < s.size(); ++i)
        {			
        	if (s[i]!=t[i])
        	{
        		return false;
        	}
        }
        return true;
    }
};

// 题目说是检查回文，但只需要统计每个英文字母是否同样出现即可
// 还可以统计每个英文字母出现的次数是否相同