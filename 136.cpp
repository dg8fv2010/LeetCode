class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> m;
        for (int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
       map<int, int>::iterator it=m.begin();
       while (it!=m.end())
       {
           if (it->second!=2)
           {
               return it->first;
           }
           it++;
       }
    }
};

// 异或
// 因为A XOR A = 0，且XOR运算是可交换的，于是，对于实例{2,1,4,5,2,4,1}就会有这样的结果：
// (2^1^4^5^2^4^1) => ((2^2)^(1^1)^(4^4)^(5)) => (0^0^0^5) => 5
class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int ans=0;
       for (int i=0;i<nums.size();i++)
       {
           ans^=nums[i];
       }
       return ans;
    }
};

/*
本题扩展

1.一个数组中有两个元素只出现一次，其他所有元素都出现两次，求这两个只出现一次的元素

[解题思路]

将数组所有元素都进行异或得到一个不为0的结果，根据这个结果中的不为0的某一位将数组分成两组

将两组中的元素进行异或，如两个数组的异或值都不为0，则得到最后结果

 

2.一个数组中有一个元素只出现1次，其他所有元素都出现k次，求这个只出现1次的元素

[解题思路]

当k为偶数时，同lss

当k为奇数时，将数组中每个元素的每一位相加mod k，得到结果即位出现1次的元素，时间复杂度O(nlen)，空间复杂度为O(1)
*/