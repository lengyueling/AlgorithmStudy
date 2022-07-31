#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution 
{
public:
	int minSubArrayLen(int target, vector<int>& nums) 
	{
		//nums[l..r]为滑动窗口
		int l = 0, r = -1;
		int sum = 0;
		int res = nums.size() + 1;
		while(l < nums.size())
		{
			if(r + 1 < nums.size() && sum < target)
			{
				r++;
				sum += nums[r];
			}
			else
			{
				sum -= nums[l];
				l++;
			}
			if(sum >= target)
			{
				res = min(res, r-l+1);
			}
		}
		if(res == nums.size()+1)
		{
			return 0;
		}
		return res;
	}
};

int main()
{

	return 0;
}

//版本1:暴力解 
//遍历所有连续子数组,计算其和sum,验证sum>=s,时间复杂度O(n^2)
//leetcode直接超时了
/*
class Solution 
{
public:
	int minSubArrayLen(int target, vector<int>& nums) 
	{
		if(nums.size() == 0)
		{
			return 0;
		}
		int sum = 0;
		int res = INT_MAX;
		for(int i = 0; i < nums.size(); i++)
		{
			sum = 0;
			for(int j = i; j < nums.size(); j++)
			{
				sum += nums[j];
				if(sum >= target)
				{
					res = min(res, j-i+1);
					break;
				}
			}
		}
		if(res == INT_MAX)
		{
			return 0;
		}
		return res;
	}
};
*/

//版本2:滑动窗口
/*
class Solution 
{
public:
	int minSubArrayLen(int target, vector<int>& nums) 
	{
		//nums[l..r]为滑动窗口
		int l = 0, r = -1;
		int sum = 0;
		int res = nums.size() + 1;
		while(l < nums.size())
		{
			if(r + 1 < nums.size() && sum < target)
			{
				r++;
				sum += nums[r];
			}
			else
			{
				sum -= nums[l];
				l++;
			}
			if(sum >= target)
			{
				res = min(res, r-l+1);
			}
		}
		if(res == nums.size()+1)
		{
			return 0;
		}
		return res;
	}
};
*/

