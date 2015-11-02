class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
	    vector<vector<int> > ans;
	    ans.resize(n);
	    for (int i=0;i<n;i++)
	    {
	        ans[i].resize(n);
	    }
	    int start=0;
	    int end=n-1;
	    int cnt=1;
	    while (cnt<n*n)
	    {
	        for (int i=start;i<end;i++)
	        {
	            ans[start][i]=cnt++;
	        }
	        for (int i=start;i<end;i++)
	        {
	            ans[i][end]=cnt++;
	        }
	        for (int i=end;i>start;i--)
	        {
	            ans[end][i]=cnt++;
	        }
	        for (int i=end;i>start;i--)
	        {
	            ans[i][start]=cnt++;
	        }
	        start++;
	        end--;
	    }
	    if (start==end)
	    {
	        ans[start][end]=cnt;
	    }
	    return ans;
	}
};