
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m=matrix.size();
		int n=matrix[0].size();

		int top=0;
		int down=m-1;
		while (top<=down)
		{
			int mid=top+(down-top)/2;
			if (matrix[mid][0]<target)
			{
				top=mid+1;
			}
			else if (matrix[mid][0]>target)
			{
				down=mid-1;
			}
			else
			{
				return true;
			}
		}
		if (down==-1)
		{
			return false;
		}

		int left=0;
		int right=n-1;
		while (left<=right)
		{
			int mid=left+(right-left)/2;
			if (matrix[down][mid]<target) // 此处使用下限，down
			{
				left=mid+1;
			}
			else if (matrix[down][mid]>target)
			{
				right=mid-1;
			}
			else
			{
				return true;
			}
		}
		return false;

	}
};

// 初始点为数组左下角，
// 当前值小于target，j++
// 当前值大于target，i--
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
	    int m=matrix.size();
	    int n=matrix[0].size();
	    
	    int i=m-1;
	    int j=0;
	    while (i>=0 && j<n)
	    {
	        if (matrix[i][j]==target)
	        {
	            return true;
	        }
	        else if (matrix[i][j]<target)
	        {
	            j++;
	        }
	        else
	        {
	            i--;
	        }
	    }
	    return false;

	}
};