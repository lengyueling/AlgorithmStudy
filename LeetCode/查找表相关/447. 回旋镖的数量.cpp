#include <iostream>
#include <cassert>
#include <algorithm>
#include <unordered_map>
using namespace std;
//思路1:暴力O(n^3)
//思路2:i是一个枢纽,遍历其余点到i的距离O(n^2)

class Solution
{
	public:
		int numberOfBoomerangs(vector<vector<int>>& points)
		{
			int res = 0;
			for(int i = 0; i < points.size(); i++)
			{
				//距离 对应距离出现的频率
				unordered_map<int, int> record;
				for(int j = 0; j < points.size(); j++)
				{
					if(j != i)
					{
						//i到j的距离的平方(规避浮点数造成误差)
						int dis = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
						record[dis]++;
					}
				}
				//计算出record中距离相同的数量
				for(unordered_map<int, int>::iterator iter = record.begin(); iter != record.end(); iter++)
				{
					if(iter->second >= 2)
					{
						res += (iter->second)*(iter->second-1);
					}
				}
			}
			return res;
		}
};
//拓展:149
