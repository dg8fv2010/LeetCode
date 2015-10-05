class Solution {
public:
    int climbStairs(int n) {
        if (n==1)
        {
        	return 1;
        }
        if (n==2)
        {
        	return 2;
        }
        // 递归会超时
        //return climbStairs(n-1)+climbStairs(n-2);
    	
        int *ret=new int[n+1];
        ret[1]=1;
        ret[2]=2;
    	for (int i = 3; i <= n; ++i)
    	{
    		ret[i]=ret[i-1]+ret[i-2];
    	}
    	int ans=ret[n];
    	delete ret;
    	return ans;
    }
};