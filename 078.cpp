// 从nums里面取出一个数，并将其添加到ans里面每个数组的最后
// 每次迭代，更新ans原来的内容里
class Solution {
public:
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ans;
        ans.push_back(vector<int>());
        if (nums.size()==0)
        {
            return ans;
        }
        sort(nums.begin(), nums.end());
        for (int i=0;i<nums.size();i++)
        {
            int size=ans.size();
            for (int j=0;j<size;j++)
            {
                vector<int> v;
                for (int k=0;k<ans[j].size();k++)
                {
                    v.push_back(ans[j][k]);
                }
                v.push_back(nums[i]);
                ans.push_back(v);
            }
        }
        return ans;
    }
};


// 单独看某一个元素，它都有存在或者不存在这两种可能
// 因此可以遍历整个数组，递归的考虑每个元素存在和不存在这两种情况
class Solution {
public:
    vector<vector<int> > ans;
    void Func(vector<int>& nums, int start, int v)
    {
        if (start==num.size())
        {
            ans.push_back(v);
        }
        vector<int> v2;
        v2=v;
        v.push_back(nums[start]);
        Func(nums, start+1, v);
        Func(nums, start+1, v2);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.size()==0)
        {
            return ans;
        }
        sort(nums.begin(), nums.end());
        Func(nums, 0, vector<int>());
        return ans;
    }
};