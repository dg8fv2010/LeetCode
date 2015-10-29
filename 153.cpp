class Solution {
public:
   
    int findMin(vector<int>& nums) {
        if (nums.size()==0)
        {
        	return 0;
        }
        vector<int>::iterator it=min_element(nums.begin(), nums.end());
        return *it;
    }
};

class Solution {
public:
   
    int findMin(vector<int>& nums) {
        if (nums.size()==0)
        {
        	return 0;
        }
       if (nums.size()==1)
       {
           return nums[0];
       }
       for (int i=1;i<nums.size();i++)
       {
           if (nums[i-1]>nums[i])
           {
               return nums[i];
           }
       }
       return nums[0];
    }
};

class Solution {
public:
   
    int findMin(vector<int>& nums) {
      int left=0;
      int right=nums.size()-1;
      int mid=0;
      while (nums[left]>nums[right])
      {
      		if (right-left==1)
      		{
      			mid=right;
      			break;
      		}
      		mid=left+(right-left)/2;
      		if (nums[mid]>nums[left])
      		{
      			left=mid;
      		}
      		else
      		{
      			right=mid;
      		}
      }
      return nums[mid];
    }
};