class Solution {
public:
    vector<vector<int> > ans;
    void Func(vector<int>& candidates, int target, vector<int>& v, int curIdx)
    {
        if (target<0)
        {
            return ;
        }
        else if (target==0)
        {
            ans.push_back(v);
            return ;
        }
        else
        {
            for (int i=curIdx;i<candidates.size();i++)
            {
                v.push_back(candidates[i]);
                Func(candidates, target - candidates[i], v, i+1);
                v.pop_back();
                while (i<candidates.size()-1 && candidates[i]==candidates[i+1])
                {
                    i++;
                }
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        Func(candidates, target, v, ans, 0);
        return ans;
    }
};