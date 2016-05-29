// 把prices[] 分成两部分prices[0...m] 和 prices[m...length]  ，分别计算在这两部分内做交易的做大收益
// 上面的方法会超时
// 那就是第一步扫描，先计算出子序列[0,...,i]中的最大利润，用一个数组保存下来，那么时间是O(n)。计算方法也是利用第一个问题的计算方法。
// 第二步是逆向扫描，计算子序列[i,...,n-1]上的最大利润，这一步同时就能结合上一步的结果计算最终的最大利润了，这一步也是O(n)。 所以最后算法的复杂度就是O(n)的。
// 以第i天为分界线，计算第i天之前进行一次交易的最大收益preProfit[i]，和第i天之后进行一次交易的最大收益postProfit[i]，最后遍历一遍，max{preProfit[i] + postProfit[i]} (0≤i≤n-1)就是最大收益
// 全局最优 = 当前元素之前的所有元素里面的最优 or 包含当前元素的最优
// 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if (n==0) return 0;
        
        vector<int> opt(n,0);
        int low=prices[0];
        int curAns=0;
        for (int i=1;i<n;i++)
        {
            if (low>prices[i])
            {
                low=prices[i];
            }
            if (curAns < prices[i]-low)
            {
                curAns=prices[i]-low;
            }
            opt[i]=curAns;
        }
        
        vector<int> optReverse(n,0);
        int high=prices[n-1];
        curAns=0;
        for (int i=n-2;i>=0;i--)
        {
            if (high<prices[i])
            {
                high=prices[i];
            }
            if (curAns < high-prices[i])
            {
                curAns=high-prices[i];
            }
            optReverse[i]=curAns;
        }
        
        int ret=0;
        for (int i=0;i<n;i++)
        {
            int tmp=opt[i]+optReverse[i];
            if (tmp>ret)
            {
                ret=tmp;
            }
        }
        return ret;
    }
};