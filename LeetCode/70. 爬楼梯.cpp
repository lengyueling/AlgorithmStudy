#include <iostream>
#include <cassert>
#include <algorithm>
#include <unordered_map>
using namespace std;


//动态规划
class Solution
{
public:
	int climbStairs(int n)
	{
		if (n < 2) 
		{
			return n;
		}
		vector<int> memo(n+1,-1);
		memo[0] = 0;
		memo[1] = 1;
		for(int i = 2; i <= n; i++)
		{
			memo[i] = memo[i-1] + memo[i-2];
		}
		return memo[n];
	}
};

//该题可以理解为和斐波那契数列(509)一样
//如果不对递归方法做优化会超时
/*
class Solution
{
	private:
		//题目中n最多为45
		vector<int> memo = vector<int>(46,-1);
	public:
		int climbStairs(int n)
		{
			if(n <= 2)
			{
				return n;
			}
			if(memo[n] == -1)
			{
				memo[n] = climbStairs(n-1) + climbStairs(n-2);
			}
			return memo[n];
		}
};
*/
//拓展:120 64
