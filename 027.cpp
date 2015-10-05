class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> ans(nums);
        nums.clear();
        int i=0,j=0;
        while (i<ans.size())
        {
            if (ans[i]==val)
            {
                i++;
            }
            else
            {
                nums.push_back(ans[i]);
                i++;
            }
        }
        
        return nums.size();
    }
};
