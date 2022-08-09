#include <iostream>
#include <cassert>
#include <algorithm>
#include <unordered_map>
using namespace std;
//思路1:动态规划
//和求最长上升子序列思路类似
/*
class Solution
{
	private:
	    //按照开头的大小排序,若开头相同则按结尾大小排序
		static bool compare (const vector<int>& a, const vector<int>& b)
		{
			if(a[0] != b[0])
			{
				return a[0] < b[0];
			}
			return a[1] < b[1];
		}
	public:
		int eraseOverlapIntervals(vector<vector<int>>& intervals)
		{
			if (intervals.size() == 0)
			{
				return 0;
			}
			sort(intervals.begin(), intervals.end(), compare);
			//momo[i]存放了memo[0...i]之间能构成的最长不重叠序列
			vector<int>memo(intervals.size(), 1);
			for(int i = 1; i < intervals.size(); i++)
			{
				//求momo[i]
				for(int j  = 0; j < i; j++)
				{
					//不重叠的条件
					if(intervals[i][0] >= intervals[j][1])
					{
						memo[i] = max(memo[i], 1 + memo[j]);
					}
				}
			}
			//最长不重叠序列的长度
			int res = 0;
			for(int i = 0; i < memo.size(); i++)
			{
				res = max(res, memo[i]);
			}
			return intervals.size() - res;
		}
};
*/

//思路2:贪心
//按照区间的结尾排序,然后在一次循环汇总找结尾最早且和上一个区间不重叠的区间
class Solution
{
private:
	static bool compare (const vector<int>& a, const vector<int>& b)
	{
		if(a[1] != b[1])
		{
			return a[1] < b[1];
		}
		return a[0] < b[0];
	}
public:
	int eraseOverlapIntervals(vector<vector<int>>& intervals)
	{
		if (intervals.size() == 0)
		{
			return 0;
		}
		sort(intervals.begin(), intervals.end(), compare);
		int res = 1;
		//当前选择intervals的结尾
		int pre = 0;
		for(int i = 1; i < intervals.size(); i++)
		{
			if(intervals[i][0] >= intervals[pre][1])
			{
				pre = i;
				res++;
			}
		}
		return intervals.size() - res;
	}
};
