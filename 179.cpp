/*
要想比较两个数在最终结果中的先后位置，何不直接比较一下不同组合的结果大小？
举个例子：要比较3和34的先后位置，可以比较334和343的大小，而343比334大，所以34应当在前。
这样，有了比较两个数的方法，就可以对整个数组进行排序。然后再把排好序的数拼接在一起就好了。
*/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for (int i=0;i<nums.size();i++)
        {
        	arr.push_back(to_string((long long)nums[i]));
        }

        sort(arr.begin(), arr.end(), cmp);

        string ret="";
        for (int i=0;i<arr.size();i++)
        {
        	ret+=arr[i];
        }

        if (ret.length()>0 && ret[0]=='0')
        {
        	return "0";
        }

        return ret;
    }

    static bool cmp(const string& s1, const string& s2)
    {
    	return s1+s2>s2+s1;
    }
};