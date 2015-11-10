// 任何一个自然数最多只要四个自然数就可以表示
// https://leetcode.com/discuss/56982/o-sqrt-n-in-ruby-and-c
// A natural number is
// a square if and only if each prime factor occurs to an even power in the number's prime factorization.
// a sum of two squares if and only if each prime factor that's 3 modulo 4 occurs to an even power in the number's prime factorization.
// a sum of three squares if and only if it's not of the form 4a(8b+7) with integers a and b.
// a sum of four squares. Period. No condition. You never need more than four.
class Solution {
public:
    int numSquares(int n) {
        while (n%4==0)
        {
            n=n/4;
        }
        if (n%8==7)
        {
            return 4;
        }
        for (int a=0;a*a<n;a++)
        {
            int b=sqrt(n-a*a);
            if (a*a+b*b==n)
            {
                return 1+!!a;
            }
        }
        return 3;
    }
};


// dp[i+j*j]=min(dp[i+j*j], dp[i]+1)
class Solution {
public:
    int numSquares(int n) {
       vector<int> num(n+1, INT_MAX);
       for (int i=1;i*i<=n;i++)
       {
          num[i*i]=1;
       }
       for (int i=1;i<=n;i++)
       {
          for (int j=1;i+j*j<=n;j++)
          {
              num[i+j*j]=min(num[i+j*j], num[i]+1);
          }
       }
       return num[n];
    }
};