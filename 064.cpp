class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
       vector<vector<int> > ans;
       int m=grid.size();
       int n=grid[0].size();
       ans.resize(m);
       for (int i=0;i<m;i++)
       {
            ans[i].resize(n);
       }
       ans[0][0]=grid[0][0];
       for (int i=1;i<m;i++)
       {
            ans[i][0]=ans[i-1][0]+grid[i][0];
       }
       for (int i=1;i<n;i++)
       {
            ans[0][i]=ans[0][i-1]+grid[0][i];
       }
        for (int i=1;i<m;i++)
        {
            for (int j=1;j<n;j++)
            {
                ans[i][j]=min(ans[i-1][j], ans[i][j-1])+grid[i][j];
            }
        }

        return ans[m-1][n-1];
    }
};