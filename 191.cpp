#include <iostream>
#include <stdint.h>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while (n)
        {
        	count+=n&1;
        	n=n>>1;
        }
        return count;
    }
};

int main()
{
	Solution solu;
	solu.hammingWeight(11);
	return 0;
}