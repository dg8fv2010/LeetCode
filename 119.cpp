class Solution {
public:
    vector<int> getRow(int rowIndex) {
      vector<int> ans(rowIndex,0);
      ans[0]=1;
      for (int i=1;i<=rowIndex;i++)
      {
        for (int j=i;j>=0;j--)
        {
          if (j==i)
          {
            a[j]=a[j-1];
          }
          else if (j==0)
          {
            a[j]=a[j];
          }
          else
          {
            a[j]=a[j-1]+a[j];
          }
        }
      }

      return ans;
    }
};