#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        int countZero=0;
        while(i!=nums.size()-countZero)
        {
            if (nums[i]==0)
            {
                nums.erase(nums.begin()+i);
                nums.push_back(0);
                countZero++;
            }
            else
            {
             i++;
            }
        }
    }
};

int main()
{
    return 0;
}
