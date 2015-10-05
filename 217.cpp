class Solution {
public:

    bool containsDuplicate(vector<int>& nums) {
    	if (nums.size()==0)
    	{
    		return false;
    	}
        bool arr[999999];
        memset(arr,0,sizeof(arr));
        for (int i=0;i<nums.size();i++)
        {
        	if (arr[nums[i]]==0)
        	{
        		arr[nums[i]]=1;
        	}
        	else
        	{
        		return true;
        	}
        }

        return false;
    }
};

// 先排序，后检查
// 使用set或map