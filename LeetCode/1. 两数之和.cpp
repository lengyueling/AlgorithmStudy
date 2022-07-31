#include <iostream>
#include <cassert>
#include <algorithm>
#include <unordered_map>
using namespace std;
//思路1:暴力O(n^2)
//思路2:先排序 然后索引对撞O(nlogn)
//思路3:查找表 O(n)

class Solution
{
	public:
		vector<int> twoSum(vector<int>& nums, int target)
		{
			unordered_map<int,int> record;
			for(int i = 0; i < nums.size(); i++)
			{
				int complement = target - nums[i];
				//元素存在
				if(record.find(complement) != record.end())
				{
					int res[] = {i, record[complement]};
					return vector<int>(res, res+2);
				}
				record[nums[i]] = i;
			}
			return vector<int>(-1, -1);
		}
};

//拓展:15 18 16
