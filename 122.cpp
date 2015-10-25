class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int ans=0;
       for (int i = 1; i < prices.size(); ++i)
       {
           int temp=prices[i]-prices[i-1];
           if (temp>0)
           {
                ans+=temp;
           }
       }
       return ans;
    }
};