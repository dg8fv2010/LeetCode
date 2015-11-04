class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int m=matrix.size();
       int n=matrix[0].size();

       int i=0;
       int j=n-1;
       while (i<m && j>=0)
       {
            if (matrix[i][j]==target)
            {
                return true;
            }
            else if (matrix[i][j]>target)
            {
                j--;
            }
            else
            {
                i++;
            }
       }
       return false;
    }
};

// 从右上角开始比较，
// 如果matrix[i][j]大于target，则此列不可能有target
// 如果matrix[i][j]小于target，则此行不可能有target