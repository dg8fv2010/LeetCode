class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       for (int i=0;i<nums.size();i++)
       {
           flags.insert(nums[i]);
       }
       
       int maxLen=0;
       for (int i=0;i<nums.size();i++)
       {
           int ascLen=findConsecutiveNumbers(1,nums[i]);
           int desLen=findConsecutiveNumbers(-1, nums[i]-1);
           if (ascLen+desLen>maxLen)
           {
               maxLen=ascLen+desLen;
           }
       }
       return maxLen;
    }
    unordered_set<int> flags;
    int findConsecutiveNumbers(int dir, int value)
    {
        int maxLen=0;
        while (flags.find(value)!=flags.end())
        {
            flags.erase(value);
            maxLen++;
            value+=dir;
        }
        return maxLen;
    }
};