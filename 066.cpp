class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size=digits.size();
        if (size==1)
        {
            digits[0]++;
             if (digits[0]>=10)
            {
                digits[0]-=10;
                digits.insert(digits.begin(),1);
            }
           
            return digits;
        }
        digits[size-1]+=1;
        for (int i=size-1;i>0;i--)
        {
            if (digits[i]>=10)
            {
                digits[i]-=10;
                digits[i-1]++;
            }
        }
        if (digits[0]>=10)
        {
            digits[0]-=10;
            digits.insert(digits.begin(),1);
        }
        
        return digits;
    }
};