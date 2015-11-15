class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	    int m=obstacleGrid.size();
	    int n=obstacleGrid[0].size();
	    vector<vector<int> > ans;
	    ans.resize(m);
	    for (int i=0;i<m;i++)
	    {
	        ans[i].resize(n);
	    }
	    int token=1;
	    for (int i=0;i<m;i++)
	    {
	        if (obstacleGrid[i][0]==1)
	        {
	            token=0;
	        }
	        ans[i][0]=token;
	    }
	    token=1;
	    for (int i=0;i<n;i++)
	    {
	        if (obstacleGrid[0][i]==1)
	        {
	            token=0;
	        }
	        ans[0][i]=token;
	    }
	    for (int i=1;i<m;i++)
	    {
	        for (int j=1;j<n;j++)
	        {
	            if (obstacleGrid[i][j]==1)
	            {
	                ans[i][j]=0;
	            }
	            else
	            {
	                int temp=obstacleGrid[i-1][j]==1?0:ans[i-1][j];
	                temp=obstacleGrid[i][j-1]==1?temp:temp+ans[i][j-1];
	                ans[i][j]=temp;
	            }
	        }
	    }
	    
	    return ans[m-1][n-1];
	}
};