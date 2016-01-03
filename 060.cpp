class Solution {
public:
    void next_permutation(vector<int>& nums)
    {
        int size=nums.size()-1;
        for (int i=size-1;i>=0;i--)
        {
            if (nums[i+1]>nums[i])
            {
                int j=0;
                for (j=size;j>=i-1;j--)
                {
                    if (nums[j]>nums[i])
                    {
                        break;
                    }
                }
                swap(nums[i], nums[j]);
                reverse(nums.begin()+i+1, nums.end());
                return ;
            }
        }
    }
    string getPermutation(int n, int k) {
        vector<int> nums;
        for (int i=0;i<n;i++)
        {
            nums.push_back(i+1);
        }
        for (int i=0;i<k;i++)
        {
            next_permutation(nums);
        }
        string s;
        for (int i=0;i<nums.size();i++)
        {
            s+='0'+nums[i];
        }
        
        return s;
    }
}; // 超时


class Solution {
public:
    int factorial(int n)
    {
        int ans=1;
        for (int i=2;i<=n;i++)
        {
            ans*=i;
        }
        return ans;
    }
    char func(string& s, int& k)
    {
        int temp=factorial(s.size()-1);
        int i=(k-1)/temp;
        char ans=s[i];
        s.erase(i, 1);
        k-=temp*i;
        return ans;
    }
    string getPermutation(int n, int k) {
        string str=string("123456789").substr(0, n);
        string ans(n, ' ');
        for (int i=0;i<n;i++)
        {
            ans[i]=func(str, k);
        }
        return ans;
    }
};