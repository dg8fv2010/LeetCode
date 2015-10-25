class Solution {
public:
    
    int getPos(int n)
    {
    	int pos=0;
    	while (!(n&0x01))
    	{
    		n=n>>1;
    		pos++;
    	}
    	return pos;
    }
    bool isOne(int n, int pos)
    {
    	n=n>>pos;
    	if (n&0x01)
    	{
    		return true;
    	}
    	else
    	{
    		return false;
    	}
    }
    vector<int> singleNumber(vector<int>& nums) {
       int ans=0;
       for (int i=0;i<nums.size();i++)
       {
       		ans^=nums[i];
       }

       int pos=getPos(ans);
       int num1=0,num2=0;
       for (int i=0;i<nums.size();i++)
       {
       		if (isOne(nums[i], pos))
       		{
       			num1^=nums[i];
       		}
       		else
       		{
       			num2^=nums[i];
       		}
       }

       vector<int> ret;
       ret.push_back(num1);
       ret.push_back(num2);
       return ret;
    }
};