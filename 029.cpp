#include <iostream>
#include <limits.h>
#include <cmath>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
       int flag=true;
       if ((dividend<0&&divisor>0) || (dividend>0&& divisor<0))
       {
           flag=false;
       }

       unsigned long long a=abs((long long)dividend);
       unsigned long long b=abs((long long)divisor);

       long long final=0;
       long long count=0;
       unsigned long long sum=0;
       while (a>=b)
       {
           count=1;
           sum=b;
            while (sum+sum<=a)
            {
                sum+=sum;
                count+=count;
            }
            a-=sum;
            final+=count;
       }

       final = flag==true?final:-final;
       if (final>INT_MAX || final<INT_MIN)
       {
            return INT_MAX;
       }
       return final;
    }
};
int main()
{
    Solution s;
    s.divide(-2147483648 ,-1);
     return 0;
}
