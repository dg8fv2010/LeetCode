class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rowValid[10]={0};
        int columnValid[9][10]={0};
        int subBoardValid[9][10]={0};

        for (int i=0;i<9;i++)
        {
            memset(rowValid, 0, sizeof(rowValid));
            for (int j=0;j<9;j++)
            {
                if (board[i][j]!='.')
                {
                     if (check(rowValid, board[i][j]-'0')==false)
                     {
                         return false;
                     }
                     if (check(columnValid[j], board[i][j]-'0')==false)
                     {
                          return false;
                     }
                     if (check(subBoardValid[i/3*3+j/3], board[i][j]-'0')==false)
                     {
                         return false;
                     }
                }
            }
        }
        return true;
    }
       bool check(int vec[], int val)
       {
            if (vec[val]==1)
            {
                return false;
            }
            vec[val]=1;
            return true;
       }
};
