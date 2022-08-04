#include <iostream>
#include <cassert>
#include <algorithm>
#include <queue>
using namespace std;

//这个问题无法使用贪心算法来解决
//将这个问题转换为一个图论的问题,变成最短路径的问题
class Solution
{
	public:
		int numSquares(int n)
		{
			queue<pair<int, int>> q;
			q.push(make_pair(n, 0));
			vector<bool> visited(n+1, false);
			visited[n] = false;
			
			while(!q.empty())
			{
				int num = q.front().first;
				int step = q.front().second;
				q.pop();
				
				if(num == 0)
				{
					return step;
				}
				for(int i = 1; num - i * i >= 0 ; i++)
				{
					if(!visited[num-i*i])
					{
						q.push(make_pair(num - i * i, step + 1));
						visited[num-i*i] = true;
					}
					
				}
			}
			return -1;
		}
};
