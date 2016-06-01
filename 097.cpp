// 我们从头到尾遍历这三个String，比如取名s1,s2,s3，然后取p1,p2,p3三个指针来对应每个String里当前遍历到的字符位置
// 这么想，如果s1的p1位，和s2的p2位，和s3的p3位都相等，那么在s3挑选的字符的时候，我们可以挑s1的那一位，也可以挑s2的那一位，所以在递归的时候我们用或（｜｜）把两种情况连接起来，传入s1的下一位，或者s2的下一位
// 如果只有s1的p1位和s3的p3位相等，那只能传入s1的下一位
// 如果只有s2的p2位和s3的p3位相等，那只能传入s2的下一位
// 如果没有发现相等，return false 退回到上一层
// recursion-time limit exceeded
class Solution {
public:
	bool func(string s1, int pos1, string s2, int pos2, string s3, int pos3)
	{
		if (pos3 == s3.length()) return true;
		if (pos1 == s1.length())
		{
			string t2 = s2.substr(pos2);
			string t3 = s3.substr(pos3);
			return t2 == t3;
		}
		if (pos2 == s2.length())
		{
			string t1 = s1.substr(pos1);
			string t3 = s3.substr(pos3);
			return t1 == t3;
		}

		if (s1[pos1] == s3[pos3] && s2[pos2] == s3[pos3])
		{
			return func(s1, pos1 + 1, s2, pos2, s3, pos3 + 1) ||
				func(s1, pos1, s2, pos2 + 1, s3, pos3 + 1);
		}
		else if (s1[pos1] == s3[pos3])
		{
			return func(s1, pos1 + 1, s2, pos2, s3, pos3 + 1);
		}
		else if (s2[pos2] == s3[pos3])
		{
			return func(s1, pos1, s2, pos2 + 1, s3, pos3 + 1);
		}
		else
		{
			return false;
		}
	}
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.length() + s2.length() != s3.length())
		{
			return false;
		}
		return func(s1, 0, s2, 0, s3, 0);
	}
};


// dp[i][j]表示s1取前i位，s2取前j位，是否能组成s3的前i+j位
// 举个列子，注意左上角那一对箭头指向的格子dp[1][1], 表示s1取第1位a, s2取第1位d，是否能组成s3的前两位aa
// 从dp[0][1] 往下的箭头表示，s1目前取了0位，s2目前取了1位，我们添加s1的第1位，看看它是不是等于s3的第2位，( i + j 位）
// 从dp[1][0] 往右的箭头表示，s1目前取了1位，s2目前取了0位，我们添加s2的第1位，看看它是不是等于s3的第2位，( i + j 位)
// 那什么时候取True，什么时候取False呢？
// False很直观，如果不等就是False了嘛。
// 那True呢？首先第一个条件，新添加的字符，要等于s3里面对应的位( i + j 位)，第二个条件，之前那个格子也要等于True
// 举个简单的例子s1 = ab, s2 = c, s3 = bbc ，假设s1已经取了2位，c还没取，此时是False（ab!=bb），我们取s2的新的一位c，即便和s3中的c相等，但是之前是False，所以这一位也是False
// 同理，如果s1 = ab, s2 = c, s3=abc ，同样的假设，s1取了2位，c还没取，此时是True（ab==ab），我们取s2的新的一位c,和s3中的c相等，且之前这一位就是True，此时我们可以放心置True （abc==abc）
class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.length() + s2.length() != s3.length())
		{
			return false;
		}
		vector<vector<bool> > dp;
		for (int i=0;i<s1.length()+1;i++)
		{
			vector<bool> tmp(s2.length()+1, false);
			dp.push_back(tmp);
		}
		dp[0][0]=true;
		for (int i=1;i<s1.length()+1;i++)
		{
			if (s1[i-1]==s3[i-1] && dp[i-1][0]==true)
			{
				dp[i][0]=true;
			}
		}

		for (int j=1;j<s2.length()+1;j++)
		{
			if (s2[j-1]==s3[j-1] && dp[0][j-1]==true)
			{
				dp[0][j]=true;
			}
		}

		for (int i=1;i<s1.length()+1;i++)
		{
			for (int j=1;j<s2.length()+1;j++)
			{
				if (s1[i-1]==s3[i+j-1] && dp[i-1][j]==true)
				{
					dp[i][j]=true;
				}
				if (s2[j-1]==s3[i+j-1] && dp[i][j-1]==true)
				{
					dp[i][j]=true;
				}
			}
		}

		return dp[s1.length()][s2.length()];
	}
};