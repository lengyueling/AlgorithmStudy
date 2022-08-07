#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

//思路1:暴力解法
//检查所有房子的组合,对每一个组合,检查是否有相邻的房子,如果没有则记录其价值,找其中的最大值
//O((2^n)*n)
/*
class Solution
{
private:
	//memo[i]表示考虑抢劫nums[i...n]所能获得的最大利益
	vector<int> memo;	
	//考虑抢劫nums[index...nums.size()]这个范围内的所有房子
	int tryRob(vector<int>& nums, int index)
	{
		if(index >= nums.size())
		{
			return 0;
		}
		if(memo[index] != -1)
		{
			return memo[index];
		}
		int res = 0;
		for(int i = index; i < nums.size(); i++)
		{
			res = max(res, nums[i] + tryRob(nums, i + 2));
		}
		memo[index] = res;
		return res;
	}
public:
	int rob(vector<int>& nums)
	{
		memo = vector<int>(nums.size(), -1); 
		return tryRob(nums, 0);
	}
};
*/

//思路2:动态规划
//状态转移方程:f(0) = max{ v(0) + f(2) , v(1) + f(3) , v(2) + f(4) , … , v(n-3) + f(n-1) , v(n-2) , v(n-1) }
class Solution
{
public:
	int rob(vector<int>& nums)
	{
		int n = nums.size();
		if(n == 0)
		{
			return 0;
		}
		//memo[i]表示考虑抢劫nums[i...n-1]所能获得的最大利益
		vector<int> memo(n, -1);
		memo[n-1] = nums[n-1];
		for(int i = n-2; i >= 0; i--)
		{
			//求memo[i]
			for(int j = i; j < n; j++)
			{
				memo[i] = max(memo[i], nums[j] + (j + 2 < n ? memo[j+2] : 0));
			}
		}
		return memo[0];
	}
};
//拓展: 213 337 309  
