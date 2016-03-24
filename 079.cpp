class Solution {
public:
	bool func(string curStr, string word, int idx, int i, int j, vector<vector<char>>& board, vector<vector<bool>>& flag)
	{
		if (curStr == word) return true;
		if (curStr[curStr.size()-1] != word[idx]) return false;
		if (curStr.size() > word.size()) return false;

		if (i<board.size()-1 && flag[i+1][j]==false)
		{
			string str=curStr;
			str+=board[i+1][j];
			flag[i+1][j]=true;
			bool ret=func(str, word, idx+1, i+1, j, board, flag);
			flag[i+1][j]=false;
			if (ret) return true;
		}
		if (i>0 && flag[i-1][j]==false)
		{
			string str=curStr;
			str+=board[i-1][j];
			flag[i-1][j]=true;
			bool ret=func(str, word, idx+1, i-1, j, board, flag);
			flag[i-1][j]=false;
			if (ret) return true;
		}
		if (j<board[0].size()-1 && flag[i][j+1]==false)
		{
			string str=curStr;
			str+=board[i][j+1];
			flag[i][j+1]=true;
			bool ret=func(str, word, idx+1, i, j+1, board, flag);
			flag[i][j+1]=false;
			if (ret) return true;
		}
		if (j>0 && flag[i][j-1]==false)
		{
			string str=curStr;
			str+=board[i][j-1];
			flag[i][j-1]=true;
			bool ret=func(str, word, idx+1, i, j-1, board, flag);
			flag[i][j-1]=false;
			if (ret) return true;
		}

		return false;
	}
	bool exist(vector<vector<char>>& board, string word) {
		vector<bool> tmp(board[0].size(), false);
		vector<vector<bool> > flag;
		for (int i=0;i<board.size();i++)
		{
			flag.push_back(tmp);
		}

		for (int i=0;i<board.size();i++)
		{
			for (int j=0;j<board[0].size();j++)
			{
				if (board[i][j] == word[0])
				{
					string curStr;
					curStr+=(board[i][j]);
					flag[i][j]=true;
					bool ans=func(curStr, word, 0, i, j, board, flag);
					flag[i][j]=false;
					if (ans) return true;
				}
			}
		}

		return false;
	}
};