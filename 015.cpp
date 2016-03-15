#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Time limit exceeded
class Solution2 {
public:
    vector<vector<int> > ret;
   void func(int cur, const vector<int>& nums, int idx, vector<int> ans)
    {
        if (cur>0)
        {
            return ;
        }
        if (ans.size()==3)
        {
            if (cur!=0)
            {
                return ;
            }
            else
            {
                if (find(ret.begin(), ret.end(), ans) == ret.end())
                {
                     ret.push_back(ans);
                }
                return ;
            }
        }
        else
        {
            for (int i=idx;i<nums.size();i++)
            {
                ans.push_back(nums[i]);
                func(cur+nums[i], nums, i+1, ans);
                ans.pop_back();
            }
        }
    }

    vector< vector<int> > threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        func(0, nums, 0, ans);

        return ret;
    }
};


//先升序排序，然后用第一重for循环确定第一个数字。
//然后在第二重循环里，第二、第三个数字分别从两端往中间扫。
//如果三个数的sum等于0，得到一组解。
//如果三个数的sum小于0，说明需要增大，所以第二个数往右移。
//如果三个数的sum大于0，说明需要减小，所以第三个数往左移。

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > ret;
        sort(nums.begin(), nums.end());
        int size=nums.size();
        for (int i=0;i<nums.size();i++)
        {
             while (i>0 && i<size && nums[i]==nums[i-1])
             {
                 i++;
             }

             int j=i+1;
             int k=size-1;
             while (j<k)
             {
                  int sum=nums[i]+nums[j]+nums[k];
                  if (sum==0)
                  {
                      vector<int> tmp;
                      tmp.push_back(nums[i]);
                      tmp.push_back(nums[j]);
                      tmp.push_back(nums[k]);
                      ret.push_back(tmp);
                      j++;
                      k--;
                      while (j<k && nums[j]==nums[j-1])
                      {
                           j++;
                      }
                      while (j<k && nums[k]==nums[k+1])
                      {
                           k--;
                      }
                  }
                  else if (sum<0)
                  {
                       j++;
                       while (j<k && nums[j]==nums[j-1])
                       {
                           j++;
                       }
                  }
                  else
                  {
                       k--;
                       while (j<k && nums[k]==nums[k+1])
                       {
                           k--;
                       }
                  }
             }
        }

        return ret;
    }
};


int main()
{
    Solution solu;
    vector<int> s;
    s.push_back(-1);
    s.push_back(0);
    s.push_back(1);
    s.push_back(2);
    s.push_back(-1);
    s.push_back(-4);
    solu.threeSum(s);
     return 0;
}
