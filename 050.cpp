class Solution {
public:
    double func(double x, int n)
    {
        if (n==0)
        {
            return 1;
        }
        double half=func(x, n/2);
        if (n%2==0)
        {
            return half*half;
        }
        else
        {
            return half*half*x;
        }
    }
    double myPow(double x, int n) {
        if (n<0)
        {
            return 1.0/func(x, -n);
        }
        else
        {
            return func(x, n);
        }
    }
};