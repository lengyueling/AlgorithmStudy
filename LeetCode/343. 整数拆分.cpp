#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;
//思路1:暴力搜索,使用回溯法,O(n^2)的时间复杂度.同时通过记忆化搜索来优化
/*
class Solution
{
	private:
	    //存放了
		vector<int> memo;
		//将n进行分割(至少分割2部分),可以获得的最大乘积
		int breakInteger(int n)
		{
			if(n == 1)
			{
				return 1;
			}
			if(memo[n] != -1)
			{
				return memo[n];
			}
			int res = -1;
			for(int i = 1; i <= n-1; i++)
			{
				res = max(res, max(i * (n - i), i * breakInteger(n-i)));
				memo[n] = res;
			}
			return res;
		}
	public:
		int integerBreak(int n)
		{
			memo = vector<int>(n+1, -1);
			return breakInteger(n);
		}
};
*/
//思路2:使用动态规划
class Solution
{
public:
	int integerBreak(int n)
	{
		vector<int> memo(n+1, -1);
		memo[1] = 1;
		for(int i = 2; i <= n; i++)
		{
			//求解memo[i]
			for(int j = 0; j < i; j++)
			{
				//i分割为j+(i-j)
				memo[i] = max(max(memo[i],j*(i-j)),j*memo[i-j]);
			}
		}
		return memo[n];
	}
};

//拓展:279 91 62 63
