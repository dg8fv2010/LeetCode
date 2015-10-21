// 超时
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       int n=nums.size();
       for (int step=0;step<k;step++)
       {
          int temp=nums[n-1];
          for (int i = n-1; i > 0; i--)
          {
              nums[i]=nums[i-1];
          }
          nums[0]=temp;
       }
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
      int n=nums.size();
      k=k%n;
      reverse(nums.begin(), nums.begin()+n);
      reverse(nums.begin(), nums.begin()+k);
      reverse(nums.begin()+k, nums.begin()+n);
    }
};