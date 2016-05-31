// 交换数组元素，使得数组中第i位存放数值(i+1)。最后遍历数组，寻找第一个不符合此要求的元素，返回其下标。整个过程需要遍历两次数组，复杂度为O(n)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    	if (nums.size()==0) return 1;
        
        int n=nums.size();
        int pos=0;
        while (pos<n)
        {
        	if (nums[pos]>0 && nums[pos]!=pos+1 && nums[pos]-1<n && nums[pos]!=nums[nums[pos]-1])
        	{
        		swap(nums[pos], nums[nums[pos]-1]);
        	}
        	else
        	{
        		pos++;
        	}
        }

        for (int i=0;i<n;i++)
        {
        	if (nums[i]!=i+1)
        	{
        		return i+1;
        	}
        }
        return n+1;
    }
};