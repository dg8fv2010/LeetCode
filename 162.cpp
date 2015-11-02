// 假设左边的元素小于右边的元素
// 如果左边的元素大于右边的元素，则一定是peak
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        while (left<right)
        {
            if (left==right)
            {
                return left;
            }
            int mid=left+(right-left)/2;
            if (nums[mid]<nums[mid+1])
            {
                left=mid+1;
            }
            else
            {
                right=mid;
            }
        }
    }
};