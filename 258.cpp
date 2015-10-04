#include<iostream>

using namespace std;

class Solution {
    public:
    int addDigits(int num) {
        int sum=0;
        sum=num;
        while (sum>=10)
        {
            sum=0;
            int temp=num;
            while (temp!=0)
            {
                 sum+=temp%10;
                 temp/=10;
            }
            num=sum;
        }
        return sum;
    }
};

class Solution {
public:
    int addDigits(int num) {
        if (num==0)
        {
         return  0;
        }
        else if (num!=0 && num%9==0)
        {
            return 9;
        }
        else
        {
            return num%9;
        }
    }
};

int main()
{
    Solution solu;
    cout<<solu.addDigits(38)<<endl;
    return 0;
}
