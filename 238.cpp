// 基本思路是用两个数组left和right，left保存从最左侧到当前数之前的所有数字的乘积，right保存从最右侧到当前之后的所有数字的乘积，
// 然后，结果数组就是把这两个数组对应位置相乘即可
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len=nums.size();
        vector<int> res;
        if (len<2) return res;

        vector<int> l;
        l.resize(len);
        vector<int> r;
        r.resize(len);

        l[0]=1;
        r[len-1]=1;
        for (int i=len-1;i>0;i--)
        {
        	r[i-1]=r[i]*nums[i];
        }
        for (int i=0;i<len-1;i++)
        {
        	l[i+1]=l[i]*nums[i];
        }
        for (int i=0;i<len;i++)
        {
        	res.push_back(l[i]*r[i]);
        }
        return res;
    }
};


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
     int len=nums.size();
     vector<int> ans;
     if (len<2)
     {
     	return ans;
     }
     ans.resize(len);
     ans[len-1]=1;
     for (int i=len-1;i>0;i--)
     {
     	ans[i-1]=ans[i]*nums[i];
     }

     int left=1;
     for (int i=0;i<len;i++)
     {
     	ans[i]*=left;
     	left*=nums[i];
     }
     return ans;
    }
};