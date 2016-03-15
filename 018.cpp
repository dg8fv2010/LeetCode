class Solution{
public:
    vector< vector<int> > fourSum(vector<int>& nums, int targeet){
        vector<vector<int> > ans;
        sort(nums.begin(), nums.end());
        int size=nums.size();
        for (int i=0;i<size;i++)
        {
            for (int j=i+1;j<size;j++)
            {
                int begin=j+1;
                int end=size-1;
                while (begin<end)
                {
                     int cur=nums[i]+nums[j]+nums[begin]+nums[end];
                     if (cur==targeet)
                     {
                         vector<int > tmp;
                         tmp.push_back(nums[i]);
                         tmp.push_back(nums[j]);
                         tmp.push_back(nums[begin]);
                         tmp.push_back(nums[end]);
                         if (find(ans.begin(), ans.end(), tmp) == ans.end())
                         {
                              ans.push_back(tmp);
                         }
                         begin++;
                         end--;
                     }
                     else if (cur<targeet)
                     {
                          begin++;
                     }
                     else
                     {
                          end--;
                     }
                }
            }
        }

        return ans;
    }
};
