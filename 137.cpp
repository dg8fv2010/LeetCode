class Solution {
public:
    int singleNumber(vector<int>& nums) {
    	int n=nums.size();
        int bitnum[32]={0};
        int res=0;
        for (int i=0;i<32;i++)
        {
        	for (int j=0;j<n;j++)
        	{
        		bitnum[i]+=(nums[j]>>i)&1;
        	}
        	res|=(bitnum[i]%3)<<i;
        }
        return res;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
    	int ones=0;
    	int twos=0;
    	int threes=0;
    	for (int i=0;i<nums.size();i++)
    	{
    		twos |= ones&nums[i];
    		ones ^= nums[i];// 异或3次 和 异或 1次的结果是一样的
       		//对于ones 和 twos 把出现了3次的位置设置为0 （取反之后1的位置为0）
    		threes = ones&twos;
    		ones &= ~threes;
    		twos &= ~threes;
    	}
    	return ones;
    }
};