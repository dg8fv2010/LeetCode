// 先遍历四条边，把O标记为S
// 再对O进行BFS，把O标记为S
// 遍历board，S变为O，O变为X
// 如果边界有O，与其相连的所有O都是连通的
// 用DFS会溢出

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        int column=board.size();
        if (column==0)
        {
            return ;
        }
        int row=board[0].size();
        if (row==0)
        {
            return ;
        }
        
        queue<pair<int,int>> q;
        set<pair<int,int>> unique;
        for (int i=0;i<row;i++)
        {
            if (board[0][i]=='O')
            {
                board[0][i]='S';
                q.push(make_pair(0,i));
            }
            if (board[column-1][i]=='O')
            {
                board[column-1][i]='S';
                q.push(make_pair(column-1,i));
            }
        }
        for (int i=1;i<column-1;i++)
        {
            if (board[i][0]=='O')
            {
                board[i][0]='S';
                q.push(make_pair(i,0));
            }
            if (board[i][row-1]=='O')
            {
                board[i][row-1]='S';
                q.push(make_pair(i,row-1));
            }
        }
        
        while (q.empty()==false)
        {
            pair<int,int> p=q.front();
            q.pop();
            for (int i=-1;i<=1;i++)
            {
                for (int j=-1;j<=1;j++)
                {
                    if (p.first+i<0 || p.first+i>column-1 || p.second+j<0 || p.second+j>row-1 || abs(i+j)!=1) continue;
                    
                    char& c=board[p.first+i][p.second+j];
                    pair<int,int> index=make_pair(p.first+i, p.second+j);
                    if (c=='O' && unique.find(index)==unique.end())
                    {
                        c='S';
                        q.push(index);
                        unique.insert(index);
                    }
                }
            }
        }
        
        for (int i=0;i<column;i++)
        {
            for (int j=0;j<row;j++)
            {
                if (board[i][j]=='S')
                {
                    board[i][j]='O';
                }
                else if (board[i][j]=='O')
                {
                    board[i][j]='X';
                }
            }
        }
    }
};