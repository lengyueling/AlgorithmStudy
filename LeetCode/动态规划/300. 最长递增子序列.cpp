#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

//思路1:求出所有子序列,再进行判断是否为上升的序列O((2^n)*n)
//思路2:动态规划
//递推公式:
//LIS(i)表示以第i个数字为结尾的最长上升子序列的长度
//LIS(i)=max(1+LIS(j) if nums[i] > nums[j])(j<i)
//时间复杂度O(n^2)
class Solution
{
	public:
		int lengthOfLIS(vector<int>& nums)
		{
			if(nums.size() == 0)
			{
				return 0;
			}
			//memo[i]表示以nums[i]为结尾的最长上升子序列的长度
			vector<int> memo(nums.size(), 1);
			for(int i = 1; i < nums.size(); i++)
			{
				for(int j = 0; j < i; j++)
				{
					if(nums[j] < nums[i])
					{
						memo[i] = max(memo[i], memo[j] + 1);
					}
				}
			}
			int res = 1;
			for(int i = 0; i < nums.size(); i++)
			{
				res = max(res, memo[i]);
			}
			return res;
		}
};
//思路3:贪心+二分查找 时间复杂度O(nlog(n))
//拓展:376

//更多的动态规划问题:
//最长公共子序列(LCS):
//LCS(m,n):求S1[0…m]和S2[0…n]的最长公共子序列的长度
//递推公式:
//S1[m] == S2[n] : 
//LCS(m,n) = 1 + LCS(m-1,n-1)
//S1[m] != S2[n] :  
//LCS(m,n) = max( LCS(m-1,n) , LCS(m,n-1) )

//dijkstra单源点最短路径也是动态规划
//shortestPath(i)为从start到i的最短路径长度
//shortestPath(x) = min( shortestPath(a) + w(a->x) )

