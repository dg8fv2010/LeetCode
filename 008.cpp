class Solution {
public:
	int myAtoi(string str) {
	    if (str.size()==0)
	    {
	        return 0;
	    }
	    long long ans=0;
	    bool flag=true;
	    int i=0;
	    while (i<str.size() && str[i]==' ')
	    {
	        i++;
	    }
	    if (str[i]=='+')
	    {
	        i++;
	    }
	    else if (str[i]=='-')
	    {
	        i++;
	        flag=false;
	    }
	    
	    for (int j=i;j<str.size();j++)
	    {
	        if (str[j]<='9' && str[j]>='0')
	        {
	            int num=str[j]-'0';
	            ans=ans*10+num;
	            if (ans>INT_MAX)
	            {
	                if (flag==true) return INT_MAX;
	                else return INT_MIN;
	            }
	        }
	        else
	        {
	            break;
	        }
	    }
	    if (flag==false)
	    {
	        ans*=-1;
	    }
	    return ans;
	}
};