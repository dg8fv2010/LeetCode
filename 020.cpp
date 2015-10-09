class Solution {
public:
    bool isValid(string s) {
        stack<char> par;
        for (int i=0;i<s.size();i++)
        {
            if (s[i]=='(' || s[i]=='[' || s[i]=='{')
            {
                par.push(s[i]);
            }
            else
            {
                if (par.empty()==true)
                {
                    return false;
                }
                switch (par.top())
                {
                    case '(':
                        if (s[i]==')')
                        {
                            par.pop();
                        }
                        else
                        {
                            return false;
                        }
                        break;
                    case '[':
                        if (s[i]==']')
                        {
                            par.pop();
                        }
                        else
                        {
                            return false;
                        }
                        break;
                    case '{':
                        if (s[i]=='}')
                        {
                            par.pop();
                        }
                        else
                        {
                            return false;
                        }
                        break;
                }
               
            }
        }
        
        if (par.empty()==true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};