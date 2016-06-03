// 先从左到右扫描一遍，使得右边比左边得分高的小朋友糖果数比左边多。
// 再从右到左扫描一遍，使得左边比右边得分高的小朋友糖果数比右边多。
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candy(ratings.size(), 1);
        for (int i=1;i<candy.size();i++)
        {
        	if (ratings[i]>ratings[i-1])
        	{
        		candy[i]=candy[i-1]+1;
        	}
        }

        for (int i=candy.size()-1-1;i>=0;i--)
        {
        	if (ratings[i]>ratings[i+1] && candy[i]<=candy[i+1])
        	{
        			candy[i]=candy[i+1]+1;
        	}
        }

        int ret=0;
        for (int i=0;i<candy.size();i++)
        {
        	ret+=candy[i];
        }

        return ret;
    }
};