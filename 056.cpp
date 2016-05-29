/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool cmp(const Interval& a, const Interval& b)
    {
    	return a.start<b.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
    	vector<Interval> ret;
    	if (intervals.size()==0) return ret;
        sort(intervals.begin(), intervals.end(), cmp);       

        Interval tmp=intervals[0];
        for (int i=1;i<intervals.size();i++)
        {
        	if (tmp.end<intervals[i].start)
        	{
        		ret.push_back(tmp);
        		tmp=intervals[i];
        	}
        	else
        	{
        	    tmp.start=min(tmp.start, intervals[i].start);
        		tmp.end=max(tmp.end, intervals[i].end);
        	}
        }
        ret.push_back(tmp);
        return ret;
    }
};