class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> v;
        
        for (int i=0;i<m;i++)
        {
            bool flag=false;
            for (int j=0;j<n;j++)
            {
                if (matrix[i][j]==0)
                {
                    flag=true;
                    v.push_back(j);
                }
            }
            if (flag==true)
            {
                for (int j=0;j<n;j++)
                {
                    matrix[i][j]=0;
                }
            }
        }
        
        for (int i=0;i<v.size();i++)
        {
            for (int j=0;j<m;j++)
            {
                matrix[j][v[i]]=0;
            }
        }
    }
};

// 使用第一行和第一列来保存检测结果
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        bool firstColumn=false;
        for (int i=0;i<m;i++)
        {
            if (matrix[i][0]==0)
            {
                firstColumn=true;
                break;
            }
        }
        bool firstRow=false;
        for (int i=0;i<n;i++)
        {
            if (matrix[0][i]==0)
            {
                firstRow=true;
                break;
            }
        }
        
        for (int i=1;i<m;i++)
        {
            for (int j=1;j<n;j++)
            {
                if (matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        
        for (int i=1;i<m;i++)
        {
            if (matrix[i][0]==0)
            {
                for (int j=0;j<n;j++)
                {
                    matrix[i][j]=0;
                }
            }
        }
        for (int i=1;i<n;i++)
        {
            if (matrix[0][i]==0)
            {
                for (int j=0;j<m;j++)
                {
                    matrix[j][i]=0;
                }
            }
        }
        
        if (firstColumn==true)
        {
            for (int i=0;i<m;i++)
            {
                matrix[i][0]=0;
            }
        }
        if (firstRow==true)
        {
            for (int i=0;i<n;i++)
            {
                matrix[0][i]=0;
            }
        }
    }
};