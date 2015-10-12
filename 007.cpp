class Solution {
public:
    int reverse(int x) {
        long long sum=0;
        while (x)
        {
            int temp=x%10;
            sum=sum*10+temp;
            if (sum>INT_MAX || sum<INT_MIN)
            {
                return 0;
            }
            x/=10;
        }
        return sum;
    }
};
