/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
// 如果新区间的end < 当前区间的start，不用找下去了，把新区间插入到当前区间的前面，然后返回。
// 如果当前区间的end小于新区间的start，继续遍历找下一个区间。
// 如果当前区间和新区间发生重合，则start取两者最小的start，end取两者最大的end，生成一个新的区间。
// 继续遍历。
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int n=intervals.size();

        vector<Interval> ret;
        for (int i=0;i<n;i++)
        {
        	Interval cur=intervals[i];
        	if (cur.end < newInterval.start)
        	{
        		ret.push_back(cur);
        	}
        	else if (cur.start > newInterval.end)
        	{
        		ret.push_back(newInterval);
        		ret.insert(ret.end(), intervals.begin()+i, intervals.end());
        		return ret;
        	}
        	else
        	{
        		newInterval.start=min(newInterval.start, cur.start);
        		newInterval.end=max(newInterval.end, cur.end);
        	}
        }
        ret.push_back(newInterval);
        return ret;
    }
};