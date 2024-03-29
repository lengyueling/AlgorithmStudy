#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;
//经典的背包问题,在n个物品中选出一定的物品,填满sum/2的背包
//如果能则另外一部分的物品就能填满另外一个sum/2的背包

//思路1:递归+记忆化搜索
/*
class Solution
{
	private:
		//memo[i][c]表示使用索引为[0...i]的这些元素,是否可以完全填充一个容量为c的背包
		//-1是默认值,0表示不可以填充,1表示可以填充
		vector<vector<int>> memo;
		//使用nums[0...index]是否可以完全填充一个容量为sum的背包
		bool tryPartition(vector<int>& nums, int index, int sum)
		{
			if(sum == 0)
			{
				return true;
			}
			if(sum < 0 || index < 0)
			{
				return false;
			}
			
			if(memo[index][sum] != -1)
			{
				return memo[index][sum] == 1;
			}
			memo[index][sum] =  tryPartition(nums, index-1, sum) || tryPartition(nums, index-1, sum - nums[index]) ? 1 : 0;
			return memo[index][sum] == 1;
		}
		
	public:
		bool canPartition(vector<int>& nums)
		{
			int sum = 0;
			for (int i = 0; i < nums.size(); i++)
			{
				sum += nums[i];
			}
			memo = vector<vector<int>>(nums.size(),vector<int>(sum/2+1, -1));

			if (sum % 2 != 0)
			{
				return false;
			}
			return tryPartition(nums, nums.size()-1, sum/2);

		}
};
*/
//思路2:动态规划
class Solution
{
public:
	bool canPartition(vector<int>& nums)
	{
		int sum = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			sum += nums[i];
		}
		if (sum % 2 != 0)
		{
			return false;
		}
		int n = nums.size();
		int C = sum/2;
		vector<bool> memo(C+1, false);
		for(int i = 0; i <= C; i++)
		{
			memo[i] = (nums[0] == i);
		}
		
		for(int i = 1; i < n; i++)
		{
			for(int j = C; j >= nums[i]; j--)
			{
				memo[j] = memo[j] || memo[j-nums[i]];
			}
		}
		return memo[C];
	}
};

//拓展:322 377 474 139 494
