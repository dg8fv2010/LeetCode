// 首先对数组排序，然后在数组头尾分别设两个指针，向中间移动
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
       sort(nums.begin(), nums.end());

       int ans=0;
       bool first=true;
       for (int i=0;i<nums.size();i++)
       {
       	int j=i+1;
       	int k=nums.size()-1;
     		while (j<k)
     		{
      		int sum=nums[i]+nums[j]+nums[k];
       		if (first==true)
       		{
       			ans=sum;
       			first=false;
       		}
       		else
       		{
       			if (abs(sum-target)<abs(ans-target))
       			{
       				ans=sum;
       			}
       		}

       		if (ans==target)
       		{
       			return ans;
       		}
       		if (sum<target)
       		{
       			j++;
       		}
       		else
       		{
       			k--;
       		}
       	}
       }

       return ans;
    }
};