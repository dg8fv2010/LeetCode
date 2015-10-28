class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int len=nums.size();
       int n=len*(len+1)/2;
       for (int i=0;i<len;i++)
       {
       		n-=nums[i];
       }
       return n;
    }
};