class Solution {
public:
    bool isHappy(int n) {
        vector<int> v;
        vector<int> ret;
        int sum=n;
        ret.push_back(sum);
        while (1)
        {
        	n=sum;
        	sum=0;
        	v.clear();
        	while (n)
        	{
        		v.push_back(n%10);
        		n=n/10;
        	}
        	for (int i = 0; i < v.size(); ++i)
        	{
        		sum+=v[i]*v[i];
        	}
        	if (sum==1)
        	{
        		return true;
        	}
        	else if (find(ret.begin(), ret.end(), sum)!=ret.end())
        	{
        		return false;
        	}
        	ret.push_back(sum);
        }
    }
};