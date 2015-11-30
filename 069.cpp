class Solution {
public:
    int mySqrt(int x) {
        unsigned long long start=0;
        unsigned long long end=(x+1)/2;
        unsigned long long mid=0;
        unsigned long long temp=0;
        while (start<end)
        {
            mid=start+(end - start)/2;
            temp=mid*mid;
            if (temp==x)
            {
                return mid;
            }
            else if (temp<x)
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        temp=end*end;
        if (temp>x)
        {
            return end-1;
        }
        else
        {
            return end;
        }
        
    }
};


// 牛顿迭代法 xi+1= (xi + n/xi) / 2
class Solution {
public:
    int mySqrt(int x) {
        if (x==0)
        {
            return 0;
        }
        double pre;
        double cur=1;
        do
        {
            pre=cur;
            cur=(pre+x/pre)/2.0f;
        } while (abs(pre-cur)>1e-10);

        return (int)cur;
    }
};