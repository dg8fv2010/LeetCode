class Solution {
public:
    vector<vector<int> > ans;
    void Func(int n)
    {
        vector<vector<int> > v;
        for (int i=0;i<ans.size();i++)
        {
            for (int j=0;j<=ans[i].size();j++)
            {
                vector<int> temp=ans[i];
                temp.insert(temp.begin()+j, n);
                v.push_back(temp);
            }
        }
        ans.clear();
        ans=v;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[0]);
        ans.push_back(temp);
        for (int i=1;i<nums.size();i++)
        {
            Func(nums[i]);
        }
        return ans;
    }
};