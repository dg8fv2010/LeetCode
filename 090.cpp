class Solution {
public:
    vector<vector<int> > ans;
    void Func(vector<int>& nums, int start, vector<int>& v)
    {
        if (start==nums.size())
        {
            if (find(ans.begin(), ans.end(), v) == ans.end())
            {
                ans.push_back(v);
            }
            return ;
        }
        vector<int> v2=v;
        v.push_back(nums[start]);
        Func(nums, start+1, v);
        Func(nums, start+1, v2);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.size()==0)
        {
            return ans;
        }
        sort(nums.begin(), nums.end());
        Func(nums, 0, vector<int>());

        return ans;
    }
};