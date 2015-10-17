class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char> > mat;
        for (int i=0;i<numRows;i++)
        {
            vector<char> v;
            mat.push_back(v);
        }
        int i=0;
        int column=0;
        int row=0;
        while (i<s.size())
        {
            if (row%2==0)
            {
                for (column=0;column<numRows;column++)
                {
                    if (i<s.size())
                    {
                        mat[column].push_back(s[i++]);
                    }
                    else
                    {
                        mat[column].push_back(' ');
                    }
                }
                row++;
            }
            else
            {
                for (column=0;column<numRows;column++)
                {
                    if (column==numRows/2)
                    {
                        if (i<s.size())
                        {
                            mat[column].push_back(s[i++]);
                        }
                        else
                        {
                            mat[column].push_back(' ');
                        }
                    }
                    else
                    {
                        mat[column].push_back(' ');
                    }
                }
                row++;
            }
        }
        
        string ans;
        for (int i=0;i<mat.size();i++)
        {
            for (int j=0;j<mat[i].size();j++)
            {
                if (mat[i][j]!=' ')
                {
                    ans+=mat[i][j];
                }
            }
        }
        return ans;
    }
};