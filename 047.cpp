class Solution {
public:
    void Func(vector<int>& num, vector<int>& path, vector<bool>& used, vector<vector<int> >& ans)
    {
        if (num.size()==path.size())
        {
            ans.push_back(path);
            return ;
        }
        for (int i=0;i<num.size();i++)
        {
            if (i>=1 && num[i-1]==num[i] && used[i-1]==false) continue;
            if (used[i]==false)
            {
                used[i]=true;
                path.push_back(num[i]);
                Func(num,path,used,ans);
                path.pop_back();
                used[i]=false;
            }
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> > ans;
        vector<int> path;
        vector<bool> used(num.size(), false);
        Func(num,path,used,ans);
        return ans;
    }
};