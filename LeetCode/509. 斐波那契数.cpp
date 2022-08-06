#include <iostream>
#include <cassert>
#include <algorithm>
#include <unordered_map>
using namespace std;


//思路2:动态规划
//自下而上的解决问题
class Solution
{
public:
	int fib(int n)
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
//思路1的优化1:记忆化搜索
//记录每一个斐波那契数列减少重复的计算
/*
class Solution
{
private:
	//题目中n最多为30
	vector<int> memo = vector<int>(31,-1);;
public:
	int fib(int n)
	{
		if (n == 0)
		{
			return 0;
		}
		if (n == 1)
		{
			return 1;
		}
		if(memo[n] == -1)
		{
			memo[n] = fib(n-1) + fib(n-2);
		}
		return memo[n];
	}
};
*/

//思路1:递归
/*
class Solution
{
	public:
		int fib(int n)
		{
			if (n == 0)
			{
				return 0;
			}
			if (n == 1)
			{
				return 1;
			}
			return fib(n - 1) + fib(n - 2);
		}
};
*/
