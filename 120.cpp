// 到第i层的第k个顶点的最小路径长度表示为f(i,k)，则f(i,k) = min{f(i-1,k),  f(i-1,k-1)} + d(i,k); 
// 其中d(i, k)表示原来三角形数组里的第i行第k列的元素。则可以求得从第一行到最终到第length-1行第k个元素的最小路径长度，
// 最后再比较第length-1行中所有元素的路径长度大小，求得最小值。
// 同时还要注意空间复杂度为O(n)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
       int size=triangle.size();
       if (size==0)
       {
          return 0;
       }

       for (int i=1;i<size;i++)
       {
          int size2=triangle[i].size();
          for (int j=0;j<size2;j++)
          {
              if (j==0)
              {
                  triangle[i][j]=triangle[i][j]+triangle[i-1][j];
              }
              else if (j==size2-1)
              {
                  triangle[i][j]=triangle[i][j]+triangle[i-1][j-1];
              }
              else
              {
                  if (triangle[i-1][j]<triangle[i-1][j-1])
                  {
                      triangle[i][j]=triangle[i][j]+triangle[i-1][j];
                  }
                  else
                  {
                      triangle[i][j]=triangle[i][j]+triangle[i-1][j-1];
                  }
              }
          }
       }

        int sum=triangle[size-1][0];
        for (int i=1;i<triangle[size-1].size();i++)
        {
            if (sum>triangle[size-1][i])
            {
                sum=triangle[size-1][i];
            }
        }
        return sum;
       
    }
};