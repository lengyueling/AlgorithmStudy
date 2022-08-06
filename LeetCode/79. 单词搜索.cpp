#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution
{
	private:
		int d[4][2] = {{-1,0},{0,1},{1,0},{-0,-1}};
		int m, n;
		vector<vector<bool>> visited;
		
		//判断是否在board内
		bool inArea(int x, int y)
		{
			return x >= 0 && x < m && y >=0 && y < n;
		}
		
		//board[startx][starty]开始,寻找word[index..word.size]与是否匹配
		bool searchWord(const vector<vector<char>>& board, const string& word, int index, int startx, int starty)
		{
			if(index == word.size() - 1)
			{
				return board[startx][starty] == word[index];
			}
			if(board[startx][starty] == word[index])
			{
				visited[startx][starty] = true;
				for(int i = 0; i < 4; i++)
				{
					int newx = startx + d[i][0];
					int newy = starty + d[i][1];
					if(inArea(newx, newy) && !visited[newx][newy])
					{
						if(searchWord(board, word, index + 1, newx, newy))
						{
							return true;
						}
					}
				}
				visited[startx][starty] = false;
			}
			return false;
		}
	public:
		bool exist(vector<vector<char>>& board, string word)
		{
			m = board.size();
			assert(m > 0);
			n = board[0].size();
			visited = vector<vector<bool>>(m, vector<bool>(n, false));
			
			for(int i = 0; i < board.size(); i++)
			{
				for(int j = 0; j < board[i].size(); j++)
				{
					if(searchWord(board, word, 0, i, j))
					{
						return true;
					}
				}
			}
			return false;
		}
};
