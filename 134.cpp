class Solution {
public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
	    if (gas.size()==0) return -1;
	    
	    int n=0;
	    int i=0;
	    int begin=0;
	    int end=0;
	    int gasInCar=0;
	    while (n<gas.size()-1)
	    {
	        gasInCar+=gas[i]-cost[i];
	        if (gasInCar>=0)
	        {
	            end++;
	            i=end;
	        }
	        else
	        {
	            begin--;
	            if (begin<0)
	            {
	                begin=gas.size()-1;
	            }
	            i=begin;
	        }
	        n++;
	    }
	    gasInCar+=gas[i]-cost[i];
	    if (gasInCar>=0)
	    {
	        return begin;
	    }
	    else
	    {
	        return -1;
	    }
	}
};

车内油量+=车站油量-消耗
对于站点 i，我们把 gas[i] - cost[i] 当作整体考虑，我们用gasInCar[i] = gas[i] - cost[i] 表示从当前站点出发，到下一个站点后剩余的油量。
因此结合司机的经验，题目就是需要找出这么一个点，从这个点出发，diff的累加值能达到峰值。
想起了什么吗？这道题就是求diff[]数组上的 和最大连续子序列，这个最大子序列的起始点就是车的出发点！
如果车从这儿开都不能做到油箱不空，那么这个题目就该返回-1了。
因此，这道题转化成了 求循环数组的最大子序列问题。

