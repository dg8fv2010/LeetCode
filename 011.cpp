// 两个指针分别指向木桶两段，向中间移动
// 比较木桶两边高度的最小值，舍弃  
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int sum=0;
        while (left<=right)
        {
            int cur=(right-left)*min(height[right], height[left]);
            sum=max(cur, sum);
            if (height[left]<height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return sum;
    }
};