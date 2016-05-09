class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size()==0) return vector<int>();
        int m=matrix.size()-1;
        int n=matrix[0].size()-1;

        vector<int> ret;
        for (int x=0,y=0;x<=m&&y<=n;x++,y++)
        {
            for (int j=y;j<=n;j++)
            {
                ret.push_back(matrix[x][j]);
            }
            for (int i=x+1;i<=m;i++)
            {
                ret.push_back(matrix[i][n]);
            }
            for (int j=n-1;j>=y&&x!=m;j--)
            {
                ret.push_back(matrix[m][j]);
            }
            for (int i=m-1;i>x&&y!=n;i--)
            {
                ret.push_back(matrix[i][y]);
            }
            m--;
            n--;
        }

        return ret;
    }
};