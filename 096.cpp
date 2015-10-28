class Solution {
public:
    int numTrees(int n) {
     	if (n==1)
     	{
     		return 1;
     	}
     	if (n==2)
     	{
     		return 2;
     	}

     	vector<int> ans(n+1,0);
     	ans[0]=1;
     	ans[1]=1;
     	ans[2]=2;

     	for (int i=3;i<=n;i++)
     	{
     		for (int j=0;j<i;j++)
     		{
     			ans[i]+=ans[j]*ans[i-j-1];
     		}
     	}
     	return ans[n];
    }
};

/*
如果集合为空，只有一种BST，即空树，
UniqueTrees[0] =1
如果集合仅有一个元素，只有一种BST，即为单个节点UniqueTrees[1] = 1
UniqueTrees[2] = UniqueTrees[0] * UniqueTrees[1]   (1为根的情况)+ UniqueTrees[1] * UniqueTrees[0]  (2为根的情况。
再看一遍三个元素的数组，可以发现BST的取值方式如下：
UniqueTrees[3] = UniqueTrees[0]*UniqueTrees[2]  (1为根的情况)
			   + UniqueTrees[1]*UniqueTrees[1]  (2为根的情况)
			   + UniqueTrees[2]*UniqueTrees[0]  (3为根的情况)
*/